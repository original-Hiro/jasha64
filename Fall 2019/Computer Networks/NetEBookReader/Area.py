from PyQt5.QtWidgets import QScrollArea, QShortcut, QLabel, QInputDialog
from PyQt5.QtCore import Qt
from PyQt5.QtGui import QKeySequence

class MyArea(QScrollArea):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.widget = parent
        self.initUi()

        
    
    def initUi(self):
        self.init_action()
    
    
        
    def init_action(self):
        zoom_minus = QShortcut(QKeySequence("Ctrl+-"), self)
        zoom_minus.activated.connect(self.minus)       
        zoom_plus = QShortcut(QKeySequence("Ctrl+="), self)
        zoom_plus.activated.connect(self.plus) 
        
        switch_left = QShortcut(QKeySequence(Qt.Key_Left), self)
        switch_left.activated.connect(self.left)       
        switch_right = QShortcut(QKeySequence(Qt.Key_Right), self)
        switch_right.activated.connect(self.right)

        ctrl_g = QShortcut(QKeySequence(Qt.CTRL + Qt.Key_G), self)
        ctrl_g.activated.connect(self.jmp)

    # 鼠标左键翻页
    def mousePressEvent(self, event):
        pos = event.pos().x()
        width = self.size().width()
        if event.button() == Qt.LeftButton:
            if pos > width * 2 / 3:
                self.right()
            elif pos < width / 3:
                self.left()
            
    # 放大
    def plus(self):
        self.widget.zoom_book(plus=True)
    
    # 缩小
    def minus(self):
        self.widget.zoom_book(plus=False)
     
    # 下一页
    def right(self):
        self.widget.switch_page(right=True)
    
    # 前一页
    def left(self):
        self.widget.switch_page(right=False)

    # 跳页
    def jmp(self):
        pgnum, ok_pressed = QInputDialog.getInt(self,
            "跳页", "请输入页码(1~%d):(下框中初值为当前所在页码)" % (self.widget.get_read_book().total_page+1),
                                                self.widget.get_read_book().page+1)
        if not ok_pressed:
            return
        self.widget.jmp_page(new_page=pgnum-1)
