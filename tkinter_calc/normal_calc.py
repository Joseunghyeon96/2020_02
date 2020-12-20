import tkinter as tk

calc = tk.Tk()
calc.title("Calculator")
calc.geometry("300x300")


def func(event):
    result = eval(tk.Entry.get(display))
    print(result)
    display.delete(0,tk.END) 
    display.insert(0,result)

    
display = tk.Entry(calc, width=20)
display.pack()
calc.bind('<Return>', func)
calc.mainloop()
