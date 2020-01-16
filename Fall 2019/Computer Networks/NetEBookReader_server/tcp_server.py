import socket
import _thread as thread
import os
import chardet
import json
import struct


def child_connection(no, conn):
    print('begin connection', no)
    fp = None  # 文件指针，用于处理txt文件
    buffsize = 1024
    txtpagesz = 180  # txt文件"页"大小的规定值，单位：字节

    # 循环处理当前连接发来的信息
    while True:
        try:
            rq = conn.recv(buffsize).decode('utf-8')
            print('request:', rq)
            
            # 如果收到空字符串，说明客户端关闭连接，则服务器端也关闭
            if rq == '':
                break
            
            # 用请求信息的首位判断请求类别
            if rq[0] == '0':  # 下载文件，格式：'0 filename'
                # 获得文件名和文件大小
                filename = rq[2:]
                print("客户端请求文件", filename)
                filesize = os.path.getsize(filename)  # 文件大小，单位：字节

                # 发送报头给客户端，报头内容为文件名和文件大小
                head_dic = {'filename': filename, 'filesize': filesize}  # 报头（字典）
                head_raw = json.dumps(head_dic)  # 字典转换成字符串（当然也可以使用eval进行转换，但使用eval有安全性问题）
                head_len_struct = struct.pack('i', len(head_raw))  # 报头的长度，转换为字符串
                conn.sendall(head_len_struct)  # 发送报头长度
                conn.sendall(head_raw.encode('utf-8'))  # 发送报头（字符串）

                # 发送文件内容
                with open(filename, 'rb') as fp:
                    data = fp.read()
                    conn.sendall(data)

                print('发送文件完毕')

            elif rq[0] == '1':  # 打开txt，格式：'1 filename_without_extension.txt'
                filename = rq[2:]
                print('客户端打开文档', filename)
                fpagenum = (os.path.getsize(filename) + txtpagesz - 1) // txtpagesz  # txt的总页数
                fp = open_text(filename)
                conn.sendall(str(fpagenum).encode('utf-8'))  # 把总页数返回给客户端

            elif rq[0] == '2':  # txt跳页及翻页，格式：'2 0'（下一页）或'2 pgnum'（跳页）
                pgnum = int(rq[2:])
                if pgnum != 0:
                    fp.seek((pgnum - 1) * txtpagesz)  # 跳页用文件指针的seek()实现
                content = fp.read(txtpagesz)
                conn.sendall(content.encode('utf-8'))
                '''
                以下代码用于处理中文文本文件中seek()可能导致的问题，但使用后仍然可能报错，遂废弃。
                使用本程序时请尽量使用英文文本文件。
                try:
                    content = fp.read(txtpagesz)
                except:
                    try:
                        content = fp.read(txtpagesz + 1)
                    except:
                        try:
                            content = fp.read(txtpagesz + 2)
                        except:
                            content = fp.read(txtpagesz + 3)
                print(content)
                '''

            elif rq[0] == '3':  # 关闭当前打开的txt，格式：'3'
                print("客户端关闭文档")
                fp.close()
                conn.sendall('已关闭文件'.encode('utf-8'))

            else:  # 若都不满足，说明请求格式有误
                conn.sendall('Syntax error, check your request'.encode('utf-8'))

        except Exception as e:  # 简单的异常处理：将异常信息发给客户端
            conn.sendall(str(e).encode('utf-8'))

    # 打印结束信息，关闭连接和文件指针，退出线程
    print('end connection', no)
    conn.close()
    if fp:
        fp.close()
    thread.exit_thread()


# txt处理
def detect_code(filename):  # 探测编码方式
    fp = open(filename, 'rb')
    line1 = fp.readline()
    encf = chardet.detect(line1)
    encode = encf['encoding']
    print(encode)

    lines = fp.readlines()
    if encode == 'ascii':
        for line in lines:
            enc = chardet.detect(line)
            if enc['encoding'] != encode:
                if enc['encoding'] == 'ISO-8859-9':
                    encode = 'GBK'
                    break
                else:
                    encode = enc['encoding']
                    print(encode)
                    break

    fp.close()
    return encode


def open_text(filename):  # 打开文件，并返回打开的文件指针，打开失败则返回None
    print(filename)
    encode = detect_code(filename)
    if encode == 'GB2312':
        encode = 'GBK'
    print(encode)

    fp = None
    try:
        fp = open(filename, 'r', encoding=encode)
    except Exception as e:
        print('opentext error', e)
    return fp


if __name__ == '__main__':
    print('Server start')

    # 创建套接字，绑定套接字到本地IP与端口，并开始监听连接
    ip_port = ('127.0.0.1', 8998)
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.bind(ip_port)
    sock.listen()
    print("Server is listening " + str(ip_port[0]) + ':' + str(ip_port[1]))

    # 轮询socket状态，一旦有传入连接，就启动一个子线程去处理
    no = 0
    while True:
        conn, addr = sock.accept()
        no += 1
        thread.start_new_thread(child_connection, (no, conn))
        # if index > 10:  # 最多处理10个连接，然后服务器退出
        #    break

    sock.close()
