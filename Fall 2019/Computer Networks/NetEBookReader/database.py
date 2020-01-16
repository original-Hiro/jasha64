import os
import sqlite3
from collections import namedtuple
from utils import Book, DBManger


book_db = 'PDF.db'
book_info = namedtuple('info',  'path page flag md5')


def maintain_db():
    if not os.path.exists("PDF.db"):
        os.rename("PDF_1.db", "PDF.db")
        return
    with DBManger('PDF_1.db') as conn1:
        book_name_md5_list = tuple(row for row in conn1.execute('SELECT path, md5 FROM book_info'))
    with DBManger(book_db) as conn:
        db_book_list = []
        for row in conn.execute('SELECT path, md5 FROM book_info'):
            if row not in book_name_md5_list:  # 删除不属于新数据库的书籍或是MD5相对新数据库已经过时的书籍的信息
                print('[database]delete', row[0], 'md5:', row[1])
                conn.execute("DELETE FROM book_info WHERE path = '" + row[0] + "'")
                if os.path.exists(row[0]):
                    os.remove(row[0])
            else:
                db_book_list.append(row)
        for each in book_name_md5_list:
            if each not in db_book_list:  # 插入不属于现在数据库的内容
                print('[database]insert', each)
                conn.execute('INSERT INTO book_info Values (?,?,?,?)', (each[0], 0, 0, each[1]))
        conn.commit()  # 两数据库中都有的书，既有数据库中的书签和flag值得到保留
    os.remove("PDF_1.db")


def read_db():
    # 将路径更改为该文件所处路径
    os.chdir(os.path.dirname(os.path.realpath(__file__)))
    if not os.path.exists(book_db):
        with DBManger(book_db) as conn:
            conn.execute("CREATE TABLE book_info(path, page, flag, md5)")
            conn.commit()

    with DBManger(book_db) as conn:
        for row in conn.execute('SELECT * FROM book_info'):
            info = book_info(*row)
            try:
                book = Book(info.path)
            except RuntimeError:
                continue
            book.page = info.page
            book.flag = info.flag
            book.md5 = info.md5
            yield book

  
  
    

def remove_db():
    with DBManger(book_db) as conn:
        conn.execute('DELETE FROM book_info')
        conn.commit()


def save2db(booklist):
    with DBManger(book_db) as conn:
        conn.executemany("INSERT INTO book_info Values (?,?,?,?)",
                    ((book.fname[book.fname.rfind('/')+1:], book.page, book.flag, book.md5) for book in booklist))
        conn.commit()

    
    
if __name__ == '__main__':
    pass
