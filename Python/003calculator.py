from tkinter import *

root=Tk()

root.geometry("400x500")
scvalue=StringVar()
scvalue.set("")
screen=Entry(root,textvar=scvalue,font="Verdana 40")
screen.pack(fill=X,padx=10,pady=10,ipadx=8)

def click(event):
    global scvalue
    text=event.widget.cget("text")
    if text=="C":
        scvalue.set("")
        screen.update()
    elif text=="=":
        if scvalue.get().isdigit():
            value=int(scvalue.get())
        else:
            try:
                value=eval(screen.get())
            except Exception as e:
                print(e)
                value="----ERROR----"
        scvalue.set(value)
        screen.update()
    else:
        scvalue.set(scvalue.get()+text)
        screen.update()

f=Frame(root)
b=Button(f,text="C",padx=47,pady=0,fg="red",font="arial 25 bold")
b.pack(side=LEFT,padx=10,pady=5)
b.bind("<Button-1>",click)
b=Button(f,text="%",padx=10,pady=0,fg="red",font="arial 25 bold")
b.pack(side=LEFT,padx=10,pady=5)
b.bind("<Button-1>",click)
b=Button(f,text="/",padx=10,pady=0,fg="red",font="arial 25 bold")
b.pack(side=LEFT,padx=10,pady=5)
b.bind("<Button-1>",click)
f.pack()

f=Frame(root)
b=Button(f,text="7",padx=10,pady=0,font="arial 25 bold")
b.pack(side=LEFT,padx=10,pady=5)
b.bind("<Button-1>",click)
b=Button(f,text="8",padx=10,pady=0,font="arial 25 bold")
b.pack(side=LEFT,padx=10,pady=5)
b.bind("<Button-1>",click)
b=Button(f,text="9",padx=10,pady=0,font="arial 25 bold")
b.pack(side=LEFT,padx=10,pady=5)
b.bind("<Button-1>",click)
b=Button(f,text="*",padx=10,pady=0,fg="red",font="arial 25 bold")
b.pack(side=LEFT,padx=10,pady=5)
b.bind("<Button-1>",click)
f.pack()

f=Frame(root)
b=Button(f,text="4",padx=10,pady=0,font="arial 25 bold")
b.pack(side=LEFT,padx=10,pady=5)
b.bind("<Button-1>",click)
b=Button(f,text="5",padx=10,pady=0,font="arial 25 bold")
b.pack(side=LEFT,padx=10,pady=5)
b.bind("<Button-1>",click)
b=Button(f,text="6",padx=10,pady=0,font="arial 25 bold")
b.pack(side=LEFT,padx=10,pady=5)
b.bind("<Button-1>",click)
b=Button(f,text="-",padx=10,pady=0,fg="red",font="arial 25 bold")
b.pack(side=LEFT,padx=10,pady=5)
b.bind("<Button-1>",click)
f.pack()

f=Frame(root)
b=Button(f,text="1",padx=10,pady=0,font="arial 25 bold")
b.pack(side=LEFT,padx=10,pady=5)
b.bind("<Button-1>",click)
b=Button(f,text="2",padx=10,pady=0,font="arial 25 bold")
b.pack(side=LEFT,padx=10,pady=5)
b.bind("<Button-1>",click)
b=Button(f,text="3",padx=10,pady=0,font="arial 25 bold")
b.pack(side=LEFT,padx=10,pady=5)
b.bind("<Button-1>",click)
b=Button(f,text="+",padx=6,pady=0,fg="red",font="arial 25 bold")
b.pack(side=LEFT,padx=10,pady=5)
b.bind("<Button-1>",click)
f.pack()

f=Frame(root)
b=Button(f,text="00",padx=0,pady=0,font="arial 25 bold")
b.pack(side=LEFT,padx=5,pady=5)
b.bind("<Button-1>",click)
b=Button(f,text="0",padx=8,pady=0,font="arial 25 bold")
b.pack(side=LEFT,padx=12,pady=5)
b.bind("<Button-1>",click)
b=Button(f,text=".",padx=10,pady=0,fg="red",font="arial 25 bold")
b.pack(side=LEFT,padx=10,pady=5)
b.bind("<Button-1>",click)
b=Button(f,text="=",padx=10,pady=0,fg="red",bg="orange",font="arial 25 bold")
b.pack(side=LEFT,padx=10,pady=5)
b.bind("<Button-1>",click)
f.pack()


root.mainloop()
