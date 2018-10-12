# -*- coding: utf-8 -*-
"""
Created on Fri Apr 20 16:30:27 2018

@author: user
"""
from Tkinter import *
#function click

def click():
    #entered_text1=textentry1.get()
    
    entered_text2=textentry2.get()
    print entered_text2
    entered_text3=textentry3.get()
    import pymysql
    db = pymysql.connect(host='localhost',user='root',passwd='', db = 'irvalues')
    cursor = db.cursor()
    #query = ("SHOW DATABASES")
    #query1=("SELECT * from IRVALUES WHERE TIME")
    query1="SELECT * FROM irvalues WHERE TIME BETWEEN "+"'"+entered_text2+"' "+"AND "+"'"+entered_text3+"'"
    #query1="SELECT * FROM irvalues WHERE TIME BETWEEN '2018/04/12 11:16:21' AND '2018/04/12 11:21:27'"
#    str="SELECT * FROM IRVALUES WHERE  `TIME` BETWEEN "+entered_text2+" AND "+entered_text3
#    query1=(str)
    cursor.execute(query1)
    lst1=[]
    for r in cursor:
       lst1.append(r)
       
    print lst1
    l=len(lst1)
    print l

    leftvalue=0
    rightvalue=0
    topvalue=0
    for i in range(0,l):
             rightvalue=rightvalue+lst1[i][1]+lst1[i][2]+lst1[i][3]+lst1[i][4]
             leftvalue=leftvalue+lst1[i][5]+lst1[i][6]+lst1[i][7]+lst1[i][8]
             topvalue=topvalue+lst1[i][9]+lst1[i][10]+lst1[i][11]
         #lst2=str.split(',')
    print rightvalue
    x=rightvalue
    print leftvalue
    y=leftvalue
    print topvalue
    z=topvalue
    
    right=rightvalue/l
    left=leftvalue/l
    top=topvalue/l
    if right==4:
        rightvalue="Traffic Density: "+str(right)+" hightraffic"
    if right==3:
        rightvalue="Traffic Density: "+str(right)+"  mediumtraffic"
    if right==2:
        rightvalue="Traffic Density: "+str(right)+"  lesstraffic"
    if right==1:
        rightvalue="Traffic Density: "+str(right)+"  verylesstraffic"
    if left==4:
        leftvalue="Traffic Density: "+str(left)+"  hightraffic"
    if left==3:
        leftvalue="Traffic Density: "+str(left)+"  mediumtraffic"
    if left==2:
        leftvalue="Traffic Density: "+str(left)+"  lesstraffic"
    if left==1:
        leftvalue="Traffic Density: "+str(left)+"  verylesstraffic"
    if top==4:
        topvalue="Traffic Density: "+str(top)+"  hightraffic"
    if top==3:
        topvalue="Traffic Density: "+str(top)+"  mediumtraffic"
    if top==2:
        topvalue="Traffic Density: "+str(top)+"  lesstraffic"
    if top==1:
        topvalue="Traffic Density: "+str(top)+"  verylesstraffic"

         
         
    #print lst3
    #print lst1[0][11]
    a="hi"
    
    Label(window,text="Right Road",bg="orange",fg="white",font="none 12 bold").grid(row=9,column=0)
    Label(window,text=rightvalue,bg="orange",fg="white",font="none 12 bold").grid(row=9,column=3)

    Label(window,text="Left Road",bg="orange",fg="white",font="none 12 bold").grid(row=11,column=0)
    Label(window,text=leftvalue,bg="orange",fg="white",font="none 12 bold").grid(row=11,column=3)

    Label(window,text="Top Road",bg="orange",fg="white",font="none 12 bold").grid(row=13,column=0)
    Label(window,text=topvalue,bg="orange",fg="white",font="none 12 bold").grid(row=13,column=3)
    import matplotlib.pyplot as plt; plt.rcdefaults()
    import numpy as np
    import matplotlib.pyplot as plt
     
    objects = ('right road', 'left road', 'top road')
    y_pos = np.arange(len(objects))
    performance = [right,left,top]
     
    plt.bar(y_pos, performance, align='center', alpha=0.5)
    plt.xticks(y_pos, objects)
    plt.ylabel('traffic density')
    plt.title('roads')
#    from datetime import datetime
#    rand=str(datetime.now())
    import random
    for x in range(1):
         rand=str(random.randint(1,10000000))
    plt.savefig('C:/Users/user/Desktop/png/'+rand+'.png')   # save the figure to file
    plt.show()
    plt.close()    # close the figure     

window=Tk()
window.geometry("550x200") 
window.title("smart transport system")
window.configure(background="orange")
#Label(window,text="enter the date",bg="orange",fg="white",font="none 12 bold").grid(row=0,column=0)
#textentry1=Entry(window,width=20,bg="white")
#textentry1.grid(row=0,column=3)
Label(window,text="Enter the start time",bg="orange",fg="white",font="none 12 bold").grid(row=3,column=0)
textentry2=Entry(window,width=20,bg="white")
textentry2.grid(row=3,column=3)
Label(window,text="Enter the end time",bg="orange",fg="white",font="none 12 bold").grid(row=5,column=0)
textentry3=Entry(window,width=20,bg="white")
textentry3.grid(row=5,column=3)
Button(window,text="SUBMIT",width=6,command=click).grid(row=7,column=2)


window.mainloop()
