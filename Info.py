import os.path

path = os.path.dirname(os.path.realpath(__file__))

from PyQt5.QtWidgets import *
from PyQt5 import uic

info_form = uic.loadUiType("info.ui")[0]

class infoWindow(QDialog):
    def __init__(self,parent):
        super(infoWindow, self).__init__(parent)
        uic.loadUi(path+'\\info.ui',self)
        self.setFixedSize(self.width(),self.height())
        self.Button_close.clicked.connect(self.close)
        self.show()
