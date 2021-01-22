import os.path

path = os.path.dirname(os.path.realpath(__file__))

from PyQt5.QtWidgets import *
from PyQt5 import uic
from PyQt5 import QtCore

change_form = uic.loadUiType("change.ui")[0]

class changeWindow(QDialog):
    def __init__(self,parent):
        super(changeWindow, self).__init__(parent)
        uic.loadUi(path+'\\change.ui',self)
        self.parent = parent

        self.setFixedSize(self.width(),self.height())
        self.setSizePolicy(0,0)

        self.cancel.clicked.connect(self.close)
        self.find_next.clicked.connect(self.findNextFunc)
        self.button_change.clicked.connect(self.change)
        self.button_all_change.clicked.connect(self.all_change)

        self.bCanChange = False;
        self.changeStart = 0
        self.changeEnd = 0
        self.prevCursorPos = 0
        self.show()

    def findNextFunc(self,cursorIdx = -1):
        pattern = self.find_str_text.text()
        text = self.parent.plainTextEdit.toPlainText()+' '

        if self.check_capital.isChecked(): ## 대소문자 구분 체크
            cs = QtCore.Qt.CaseSensitive
        else:
            cs = QtCore.Qt.CaseInsensitive
        self.parent.pCs = cs
        self.parent.pPattern = pattern

        reg = QtCore.QRegExp(pattern)
        reg.setCaseSensitivity(cs)
        if cursorIdx == -1:
            pos = self.parent.plainTextEdit.textCursor().position()
        else:
            pos = cursorIdx
        idx = reg.indexIn(text, pos)
        print(idx, idx + len(pattern))
        if idx != -1:  ## 검색결과 있음
            self.parent.setCursor(idx, len(pattern) + idx)
            self.changeStart = idx
            self.changeEnd = len(pattern)+ idx
            self.prevCursorPos = idx + len(pattern)
            self.bCanChange = True
        else:
            self.notFoundMsgbox(pattern)
            self.bCanChange = False

    def notFoundMsgbox(self,str):
        msgBox = QMessageBox()
        msgBox.setWindowTitle('메모장')
        msgBox.setIcon(QMessageBox.Information)
        msgBox.setText('''"{}"을 찾을 수 없습니다.'''.format(str))
        msgBox.addButton('확인',QMessageBox.YesRole)
        ret = msgBox.exec_()


    def change(self):
        print('change')
        if self.bCanChange == False:
            self.findNextFunc()
            return
        else:
            if self.changeStart == self.changeEnd:
                self.bCanChange = False
                return
            else:
                text = self.parent.plainTextEdit.toPlainText()
                tempText1 = text[0:self.prevCursorPos - len(self.find_str_text.text())]
                tempText2 = text[self.prevCursorPos:]
                text = tempText1 + self.change_str_text.text()+tempText2
                self.parent.plainTextEdit.setPlainText(text)
                self.findNextFunc(self.prevCursorPos + (len(self.change_str_text.text()) - len(self.find_str_text.text())))

    def all_change(self):
        text = self.parent.plainTextEdit.toPlainText()
        text = text.replace(self.find_str_text.text(),self.change_str_text.text())
        self.parent.plainTextEdit.setPlainText(text)

    def keyReleaseEvent(self, event):
        if self.find_str_text.text():
            self.find_next.setEnabled(True)
            self.button_change.setEnabled(True)
            self.button_all_change.setEnabled(True)
        else:
            self.find_next.setEnabled(False)
            self.button_change.setEnabled(False)
            self.button_all_change.setEnabled(False)
