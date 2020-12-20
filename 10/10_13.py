from tkinter import *
from tkinter import messagebox

##함수 선언
def clickLeft(event):
    messagebox.showinfo("마우스","마우스 왼쪽 버튼이 클릭됨")

##메인
window =Tk()

window.bind("<Button-1>",clickLeft)

window.mainloop()
