import tkinter as tk
from tkinter import ttk

win=tk.Tk()
win.title('Calculator')
win.configure(background='red')

label1=ttk.Label(win,text='ENTER-->')
label1.grid(row=0,column=0, ipady=5,sticky=tk.W)
label1.configure(background='yellow',foreground='red')

entry1=tk.StringVar()
entry1=tk.Entry(win, width=14,textvariable=entry1)
entry1.grid(row=0,column=1,columnspan=2, ipadx=30, ipady=10)
entry1.focus()

entry1.delete(0,tk.END)

def action1():
     entry1.insert(entry1.index(tk.INSERT),"0")

button14=ttk.Button(win,text='0',width=8,command=action1).grid(row=4,column=0)


def action():
     entry1.insert(entry1.index(tk.INSERT),"1")
      
button1=ttk.Button(win,text='1',width=8,command=action)
button1.grid(row=3,column=2)

def action1():
     entry1.insert(entry1.index(tk.INSERT),"2")

button2=ttk.Button(win,text='2',width=8,command=action1).grid(row=3,column=1)

def action2():
     entry1.insert(entry1.index(tk.INSERT),"3")

button3=ttk.Button(win,text='3',width=8,command=action2).grid(row=3,column=0)

def action3():
     entry1.insert(entry1.index(tk.INSERT),"4")

button4=ttk.Button(win,text='4',width=8,command=action3).grid(row=2,column=2)

def action4():
     entry1.insert(entry1.index(tk.INSERT),"5")

button5=ttk.Button(win,text='5',width=8,command=action4).grid(row=2,column=1)

def action5():
     entry1.insert(entry1.index(tk.INSERT),"6")

button6=ttk.Button(win,text='6',width=8,command=action5).grid(row=2,column=0)

def action6():
     entry1.insert(entry1.index(tk.INSERT),"7")

button7=ttk.Button(win,text='7',width=8,command=action6).grid(row=1,column=2)

def action7():
     entry1.insert(entry1.index(tk.INSERT),"8")

button8=ttk.Button(win,text='8',width=8,command=action7).grid(row=1,column=1)

def action8():
     entry1.insert(entry1.index(tk.INSERT),"9")

button9=ttk.Button(win,text='9',width=8,command=action8).grid(row=1,column=0)

def action9():
     entry1.insert(entry1.index(tk.INSERT),"+")

button10=tk.Button(win,text='+',width=8,bg='lightblue',command=action9).grid(row=1,column=3)

def action10():
     entry1.insert(entry1.index(tk.INSERT),"-")

button11=tk.Button(win,text='-',width=8,bg='lightblue',command=action10).grid(row=2,column=3)

def action11():
     entry1.insert(entry1.index(tk.INSERT),"*")

button12=tk.Button(win,text='*',width=8,bg='lightblue',command=action11).grid(row=3,column=3)

def action12():
     entry1.insert(entry1.index(tk.INSERT),"/")

button13=tk.Button(win,text='/',width=8,bg='lightblue',command=action12).grid(row=4,column=1)

def action13():
     entry1.insert(entry1.index(tk.INSERT),"(")

button13=tk.Button(win,text='(',width=8,bg='lightblue',command=action13).grid(row=4,column=2)

def action14():
     entry1.insert(entry1.index(tk.INSERT),")")

button13=tk.Button(win,text=')',width=8,bg='lightblue',command=action14).grid(row=4,column=3)



def result():
        a=(eval(str(entry1.get( ))))
        b=eval(str(entry1.get( )))
        print(eval(str(entry1.get( ))))
        label2=tk.Label(win,text=a).grid(row=5,columnspan=20)
        entry1.delete(0,tk.END)
        

button13=tk.Button(win,text='==',width=8,bg='blue',foreground='yellow',command=result).grid(row=0,column=3)

label1=tk.Label(win,text='RESULT-->').grid(row=5,column=0)


def action15():
     exit()
button14=tk.Button(win,text='EXIT',width=15,bg='brown',foreground='black',command=action15).grid(row=6,columnspan=4)

win.mainloop()
