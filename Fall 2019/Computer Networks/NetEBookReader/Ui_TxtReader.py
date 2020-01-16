import sys
from PyQt5.QtGui import *
from PyQt5.QtCore import *
from PyQt5.QtWidgets import QApplication,QWidget,QGridLayout,QTextBrowser,QFileDialog,QPushButton,\
    QMenuBar, QAction, QShortcut, QInputDialog
from _functools import partial
import chardet

class txtreader(QWidget):
    def __init__(self, parent, book):
        super().__init__()
        filename = book.fname
        self.book = book
        self.book._total_page = 0
        self.widget = parent
        self.content = ""
        self.setAttribute(Qt.WA_DeleteOnClose, True)
        self.initUI()
        self.open_txt(filename)
        
    def initUI(self):
        self.setGeometry(300,300,416,234)
        self.setWindowTitle('reader')
        self.setWindowFlag(Qt.WindowStaysOnTopHint)
        self.setWindowOpacity(1)  #设置透明度
      
        self.grid=QGridLayout()   #设置布局


        opacityAction1=QAction('&25%',self)
        opacityAction1.triggered.connect(partial(self.opacity,0.25))
        opacityAction2=QAction('&50%',self)
        opacityAction2.triggered.connect(partial(self.opacity,0.5))
        opacityAction3=QAction('&75%',self)
        opacityAction3.triggered.connect(partial(self.opacity,0.75))
        opacityAction4=QAction('&100%',self)
        opacityAction4.triggered.connect(partial(self.opacity,1))

        menubar=QMenuBar()  #创建菜单
        self.setopacity=menubar.addMenu('&opacity')#设置透明度
        self.setopacity.addAction(opacityAction1)
        self.setopacity.addAction(opacityAction2)
        self.setopacity.addAction(opacityAction3)
        self.setopacity.addAction(opacityAction4)

        self.textpart=QTextBrowser()
         
        self.grid.addWidget(menubar)
        self.grid.addWidget(self.textpart)
 
        self.setLayout(self.grid)
        self.show()
        self.init_action()

    def init_action(self):
        ctrl_g = QShortcut(QKeySequence(Qt.CTRL + Qt.Key_G), self)
        ctrl_g.activated.connect(self.jmp_page)
        pgdn = QShortcut(QKeySequence(Qt.Key_PageDown), self)
        pgdn.activated.connect(self.page_down)
        pgup = QShortcut(QKeySequence(Qt.Key_PageUp), self)
        pgup.activated.connect(self.page_up)

    def setContent(self, content):
        self.content = content
        self.showText()

    def showText(self):
        self.textpart.setText(self.content)
    
    def opacity(self,num):
        self.setWindowOpacity(num)

    def open_txt(self, filename):
        totpg = int(self.widget.tcp.sendrecv('1 ' + filename))
        self.book._total_page = totpg + 1
        if self.book.page == 1:
            text = self.widget.tcp.sendrecv('2 0')
            self.setContent(text)
        else:
            self.set_page(self.book.page)

    def set_page(self, pgnum):
        if pgnum < 1 or pgnum > self.book.total_page:
            return False
        text = self.widget.tcp.sendrecv('2 ' + str(pgnum))
        self.book.page = pgnum
        self.setContent(text)
        return True

    def page_down(self):
        if self.book.page >= self.book.total_page:
            return
        text = self.widget.tcp.sendrecv('2 0')
        self.book.page = self.book.page + 1
        self.setContent(text)

    def page_up(self):
        self.set_page(self.book.page - 1)

    def close_txt(self):
        print('[Reader]txt阅读器退出，关闭文件')
        print('[Reader]', self.widget.tcp.sendrecv('3'))

    def jmp_page(self):
        i, okPressed = QInputDialog.getInt(self, "跳页", "请输入页码(1~%d):(下框中初值为当前所在页码)" % self.book.total_page, self.book.page)
        if not okPressed:
            return
        self.set_page(i)

    def closeEvent(self, event):
        self.close_txt()
