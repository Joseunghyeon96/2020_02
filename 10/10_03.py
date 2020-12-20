from tkinter import *

window = Tk()
window.title("B677035 조승현")

label1 = Label(window,text= "Cookbook~~ Python 을")
label2 = Label(window,text= "열심히",font=("궁서체",30),fg ="blue")
label3 = Label(window,text= "공부중임다",bg= "magenta",width= 20, height = 5
               ,anchor = SE)

label1.pack()
label2.pack()
label3.pack()


window.mainloop()
