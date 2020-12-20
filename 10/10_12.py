from tkinter import *
from time import *

##전역 변수

fnameList = ["jeju1.gif","jeju2.gif","jeju3.gif","jeju4.gif","jeju1.gif",
             "jeju6.gif","jeju7.gif","jeju8.gif","jeju8.gif"]

photoList = [None]*9
num =0

##함수 선언
def clickNext():
    global num
    num +=1
    if num>8:
        num = 0

    photo = PhotoImage(file= "GIF/" + fnameList[num])
    pLabel.configure(image =photo)
    pLabel.image =photo

def clickPrev():
    global num
    num -=1
    if num<0:
        num =8
    photo = Photo(file ="GIF/"+fnameList[num])
    pLabel.configure(image =photo)
    pLabel.image = photo

##메인 코드
window = Tk()
window.geometry("700x500")
window.title("사진 앨범 보기")

btnPrev = Button(window,text = "<< 이전", command = clickPrev)
btnNext = Button(window,text = "다음 >>", command = clickNext)

photo = PhotoImage(file = "GIF/" + fnameList[0])
pLabel = Label(window,image = photo)

btnPrev.place(x=250,y=10)
btnNext.place(x=400,y=10)
pLabel.place(x=15,y=50)

window.mainloop()
