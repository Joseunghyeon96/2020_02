import tkinter as tk

calc = tk.Tk()
calc. title("Calculator")
calc.geometry("300x300")

def calculate(event):
    value = tk.Entry.get(display)
    if value != '':
        result = eval(value)
        print(result)
        display.delete(0,tk.END)
        display.insert(0,result)


def clear(event):
    display.delete(0,tk.END)

display = tk.Entry(calc,width=20)
display.pack()
button_e = tk.Button(calc,text='=',width=5)
button_e.bind('<Button-1>',calculate)
button_e.pack()

button_c =tk.Button(calc,text ='c',width =5)

button_c.bind('<Button-1>',clear)
button_c.pack()

calc.bind('<Return>',calculate)

calc.bind('<Escape>',clear)
calc.mainloop()
