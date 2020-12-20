from tkinter import *

def loadImage(fname):
    global inImage, X , Y
    fp = open(fname,'rb')

    for i in range(0,X):
        tmpList = []
        for k in range(0,Y):
            data = int(ord(fp.read(1)))
            tmpList.append(data)
        inImage.append(tmpList)

    fp.close()

def displayImage(image):
    global X,Y
    rgbString = ""
    for i in range(0,X):
        tmpString = ""
        for k in range(0,Y):
            data = image[i][k]
            tmpString += "#%02x%02x%02x" %(data,data,data)
        rgbString += "{" + tmpString + "}"
    paper.put(rgbString)

window = None
canvas = None
X,Y = 256,256
inImage = []

window = Tk()
window.title("흑백사진보기")
canvas = Canvas(window,height = X , width = Y)
paper = PhotoImage(width = X, height = Y)
canvas.create_image((X/2,Y/2),image = paper, state = "normal")

filename = 'RAW/tree.raw'
loadImage(filename)

displayImage(inImage)

canvas.pack()
window.mainloop()
