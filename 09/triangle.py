import turtle

t = turtle.Turtle()
t.shape("turtle")

def triangle(length):
    for i in range(3):
        t.forward(length)
        t.left(120)

triangle(100)
