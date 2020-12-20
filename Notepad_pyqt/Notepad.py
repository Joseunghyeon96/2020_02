
#참조
#https://www.youtube.com/watch?v=Ss7dDDS-DhU&list=PLnIaYcDMsScwsKo1rQ18cLHvBdjou-kb5&ab_channel=%EC%9E%AC%EC%A6%90%EB%B3%B4%ED%94%84
import sys
import os.path

from PyQt5.QtWidgets import *
from PyQt5.QtGui import QTextCursor
from PyQt5.QtGui import QTextCharFormat
from PyQt5 import uic
from PyQt5 import QtCore
from PyQt5.QtGui import QIcon
from PyQt5.QtCore import QDate, QTime


import Info,change

form_class = uic.loadUiType("MyNotepad.ui")[0]
find_form = uic.loadUiType("find.ui")[0]

class findWindow(QDialog):
    def __init__(self,parent):
        super(findWindow, self).__init__(parent)
        uic.loadUi("find.ui",self)
        self.parent = parent
        self.parent_pt = parent.plainTextEdit

        self.setFixedSize(self.width(),self.height())
        self.setSizePolicy(0,0)

        self.cancel.clicked.connect(self.close)
        self.find_next.clicked.connect(self.findNextFunc)
        self.find_dir_up.clicked.connect(self.dirUpdown)
        self.find_dir_down.clicked.connect(self.dirUpdown)

        self.bUpdown = True ## 아래로 검색시 true
        self.show()

    def findNextFunc(self):
        pattern = self.find_str_text.text()
        text = self.parent_pt.toPlainText()+' '

        if self.check_capital.isChecked(): ## 대소문자 구분 체크
            cs = QtCore.Qt.CaseSensitive
        else:
            cs = QtCore.Qt.CaseInsensitive
        self.parent.pCs = cs
        self.parent.pPattern = pattern

        reg = QtCore.QRegExp(pattern)
        reg.setCaseSensitivity(cs)
        pos = self.parent.plainTextEdit.textCursor().position()
        print(pos,pattern)

        if self.bUpdown:
            idx = reg.indexIn(text, pos)
            print(idx, idx + len(pattern))
            if idx != -1:  ## 검색결과 있음
                self.parent.setCursor(idx, len(pattern) + idx)
            else:
                self.notFoundMsgbox(pattern)
        else:
            text = text[0:pos]
            idx = reg.lastIndexIn(text, pos,reg.CaretAtOffset)
            print(idx+len(pattern),len(pattern))
            if idx != -1:  ## 검색결과 있음
                self.parent.setCursor(idx+len(pattern),len(pattern))
            else:
                self.notFoundMsgbox(pattern)

    def notFoundMsgbox(self,str):
        msgBox = QMessageBox()
        msgBox.setWindowTitle('메모장')
        msgBox.setIcon(QMessageBox.Information)
        msgBox.setText('''"{}"을 찾을 수 없습니다.'''.format(str))
        msgBox.addButton('확인',QMessageBox.YesRole)
        ret = msgBox.exec_()


    def dirUpdown(self):
        if self.find_dir_up.isChecked():
            print("up")
            self.bUpdown = False
        elif self.find_dir_down.isChecked():
            print("down")
            self.bUpdown = True
        self.parent.findDir = self.bUpdown

    def keyReleaseEvent(self, event):
        if self.find_str_text.text():
            self.find_next.setEnabled(True)
        else:
            self.find_next.setEnabled(False)


class MyNotepad(QMainWindow, form_class):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("제목 없음 - My Notepad")
        self.setupUi(self)
## 설정
        self.opened = False
        self.opened_file_path = '제목 없음'
        fmt = QTextCharFormat()
        self.setWindowIcon(QIcon('icon.png'))
        self.Magnification = 1
        self.pCs = QtCore.Qt.CaseInsensitive
        self.plainTextEdit.setLineWrapMode(QPlainTextEdit.WidgetWidth)
        self.pPattern = ''
        self.findDir = True;
## 커스텀 함수 바인딩
        self.action_open.triggered.connect(self.openFunc)
        self.action_save.triggered.connect(self.saveFunc)
        self.action_saveAs.triggered.connect(self.saveAsFunc)
        self.action_close.triggered.connect(self.close)
        self.action_create.triggered.connect(self.newCreate)
        self.action_find.triggered.connect(self.my_find)
        self.action_delete.triggered.connect(self.my_delete)
        self.action_next_find.triggered.connect(self.next_find)
        self.action_prev_find.triggered.connect(self.prev_find)
        self.action_replace.triggered.connect(self.my_replace)
        self.action_time.triggered.connect(self.printTime)
        self.action_auto_newline.triggered.connect(self.autoLine)
        self.action_closeup.triggered.connect(self.closeUp)
        self.action_reduction.triggered.connect(self.reduction)
        self.action_zoom_default.triggered.connect(self.magnificationDefault)
        self.action_go.triggered.connect(self.moveLine)
        self.action_information.triggered.connect(self.showInfo)
        self.action_font.triggered.connect(self.font)




## 기존라이브러리 함수 바인딩
        self.action_undo.triggered.connect(self.plainTextEdit.undo)
        self.action_copy.triggered.connect(self.plainTextEdit.copy)
        self.action_cut.triggered.connect(self.plainTextEdit.cut)
        self.action_paste.triggered.connect(self.plainTextEdit.paste)
        self.action_all_select.triggered.connect(self.plainTextEdit.selectAll)

## 이동
    def moveLine(self):
        print('move')
## 다음,이전 찾기
    def notFoundMsgbox(self,str):
        msgBox = QMessageBox()
        msgBox.setWindowTitle('메모장')
        msgBox.setIcon(QMessageBox.Information)
        msgBox.setText('''"{}"을 찾을 수 없습니다.'''.format(str))
        msgBox.addButton('확인',QMessageBox.YesRole)
        ret = msgBox.exec_()

    def findStr(self):
        if self.pPattern == '':
            self.my_find()
            return
        text = self.plainTextEdit.toPlainText() + ' '
        reg = QtCore.QRegExp(self.pPattern)
        reg.setCaseSensitivity(self.pCs)
        pos = self.plainTextEdit.textCursor().position()

        if self.findDir:
            idx = reg.indexIn(text, pos)
            print(idx, idx + len(self.pPattern))
            if idx != -1:  ## 검색결과 있음
                self.setCursor(idx, len(self.pPattern) + idx)
            else:
                self.notFoundMsgbox(self.pPattern)
        else:
            text = text[0:pos]
            idx = reg.lastIndexIn(text, pos,reg.CaretAtOffset)
            print(idx+len(self.pPattern),len(self.pPattern))
            if idx != -1:  ## 검색결과 있음
                self.setCursor(idx+len(self.pPattern),len(self.pPattern))
            else:
                self.notFoundMsgbox(self.pPattern)

## 찾기 함수
    def next_find(self):
        self.findDir = True
        self.findStr()
    def prev_find(self):
        self.findDir = False
        self.findStr()
## 정보
    def showInfo(self):
        Info.infoWindow(self)

## 확대 / 축소
    def closeUp(self):
        self.Magnification += 1
        self.plainTextEdit.zoomIn(5)

    def reduction(self):
        if self.Magnification == 0 :
            return
        self.Magnification -= 1
        self.plainTextEdit.zoomOut(5)

    def magnificationDefault(self):
        if (self.Magnification > 1):
            for i in range(1,self.Magnification):
                self.plainTextEdit.zoomOut(5)
        else :
            for i in range(self.Magnification , 1):
                self.plainTextEdit.zoomIn(5)
        self.Magnification = 1

## 글꼴 설정
    def font(self):
        font, ok = QFontDialog.getFont()
        if ok:
            self.plainTextEdit.setFont(font)
## 자동 줄바꿈
    def autoLine(self):
        if self.plainTextEdit.lineWrapMode() == QPlainTextEdit.NoWrap:
            self.plainTextEdit.setLineWrapMode(QPlainTextEdit.WidgetWidth)
            self.action_go.setEnabled(True)
        elif self.plainTextEdit.lineWrapMode() == QPlainTextEdit.WidgetWidth:
            self.plainTextEdit.setLineWrapMode(QPlainTextEdit.NoWrap)
            self.action_go.setEnabled(False)

## 시간 날짜 프린트함수
    def printTime(self):
        date = QDate.currentDate()
        time = QTime.currentTime()
        str = time.toString('ap h:mm') + ' ' + date.toString('yyyy-MM-dd')
        cursor = self.plainTextEdit.textCursor()
        cursor.insertText(str)
        cursor.setPosition(cursor.position() + len(str))
        self.plainTextEdit.setTextCursor(cursor)

## 바꾸기 함수
    def my_replace(self):
        change.changeWindow(self)
## 찾기 함수
    def my_find(self):
        findWindow(self)

##커서 지정
    def setCursor(self, start, end):
        cursor = self.plainTextEdit.textCursor()
        if end>start:
            cursor.setPosition(start)
            cursor.movePosition(QTextCursor.Right,QTextCursor.KeepAnchor,end-start)
            print(cursor.anchor())
        else :
            cursor.setPosition(start)
            cursor.movePosition(QTextCursor.Left, QTextCursor.KeepAnchor, end)
            print(cursor.anchor())
        self.plainTextEdit.setTextCursor(cursor)

##오른쪽 문자 또는 지정부분 삭제 함수
    def my_delete(self):
        tc = self.plainTextEdit.textCursor()
        tc.deleteChar()


## 데이터가 바뀌었는지 확인하는 함수
    def is_changed_data(self):
        if self.opened == True:
            with open(self.opened_file_path, encoding='UTF8') as ofp:
                data = ofp.read()
            if data == self.plainTextEdit.toPlainText():
                return False
            else:
                return True
        else:
            if self.plainTextEdit.toPlainText() == '':
                return False
            else:
                return True
## 닫을 때 메세지 박스
    def closeEventMsgBox(self):
        msgBox = QMessageBox()
        msgBox.setText("변경 내용을 {}에 저장하시겠습니까?".format(self.opened_file_path))
        msgBox.addButton('저장',QMessageBox.YesRole)
        msgBox.addButton('저장 안 함',QMessageBox.NoRole)
        msgBox.addButton('취소',QMessageBox.RejectRole)
        ret = msgBox.exec_()
        return ret
## 새로 만들기
    def newCreate(self):
        if self.is_changed_data() == True:
            i = self.closeEventMsgBox()
            if i == 0:
                self.saveFunc()
        self.opened = False
        self.opened_file_path = '제목 없음'
        self.plainTextEdit.setPlainText('')
        self.setWindowTitle("제목 없음 - My Notepad")

## 종료 함수
    def closeEvent(self,event,bignore = False):
        if self.is_changed_data() == False:
            if bignore:
                event.ignore()
            return
        i = self.closeEventMsgBox()
        if i == 0:
            self.saveFunc()
        elif i == 1:
            if bignore:
                event.ignore()
            return
        elif i == 2:
            event.ignore()

## 저장 함수
    def save_file(self,fname):
        data = self.plainTextEdit.toPlainText()
        with open(fname, 'w', encoding='UTF8') as f:
            f.write(data)
        print("save {}!!".format(fname))
        self.setWindowTitle(fname[fname.rfind('/') + 1:])

## 저장 함수
    def saveFunc(self):
        if self.opened:
            self.save_file(self.opened_file_path)
        else:
            self.saveAsFunc()

## 다른 이름으로 저장
    def saveAsFunc(self):
        fname = QFileDialog.getSaveFileName(self)
        if fname[0]:
            self.save_file(fname[0])
            self.opened = True
            self.opened_file_path = fname[0]
            self.setWindowTitle(self.opened_file_path[self.opened_file_path.rfind('/') + 1:])

## 열기 함수
    def open_file(self,fname):
        with open(fname, encoding='UTF8') as f:
            data = f.read()
        self.plainTextEdit.setPlainText(data)
        print("open {}!!".format(fname))
        self.opened = True
        self.opened_file_path = fname
        self.setWindowTitle(fname[fname.rfind('/')+1:])

## 열기 함수 폴더불러오기
    def openFunc(self):
        if self.is_changed_data() == True:
            i = self.closeEventMsgBox()
            if i == 0:
                self.saveFunc()
            elif i == 2:
                return
        fname = QFileDialog.getOpenFileName(self)
        if fname[0]:
            self.open_file(fname[0])


if __name__ == '__main__':
    app = QApplication(sys.argv)
    mainWindow = MyNotepad()
    mainWindow.show()
    app.exec_()