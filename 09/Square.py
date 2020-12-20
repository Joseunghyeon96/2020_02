import turtle
t = turtle.Turtle()
t.shape("turtle")

def Square(length):
    for i in range(4):
        t.forward(length)
        t.left(90)

def GoToSquare(x,y,length):
    t.up()
    t.goto(x,y)
    t.down()
    Square(length)

Square(100)
GoToSquare(-200,0,100)
GoToSquare(200,0,100)
