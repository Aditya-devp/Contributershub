import turtle as tl 
from tkinter import *
import mysql.connector
l =""
level={"Low":3,"Normal":5,"Hard":7}
password = ""
with open("./keys.txt","r") as dd:
    x = dd.read()
    password= x
    dd.close()

def Pong(l):
    print("level: "  +l)
    screen_1 = tl.Screen()  
    screen_1.title("Bounce Game")  
    screen_1.bgcolor("Black")  
    screen_1.setup(width = 1050, height = 650)  
       
      
    left_paddle = tl.Turtle()  
    left_paddle.speed(0)  
    left_paddle.shape("square")  
    left_paddle.color("White")  
    left_paddle.shapesize(stretch_wid = 6, stretch_len = 2)  
    left_paddle.penup()  
    left_paddle.goto(-400, 0)  
       
      
    right_paddle = tl.Turtle()  
    right_paddle.speed(0)  
    right_paddle.shape("square")  
    right_paddle.color("yellow")  
    right_paddle.shapesize(stretch_wid = 6, stretch_len = 2)  
    right_paddle.penup()  
    right_paddle.goto(400, 0)  
       
     
    hit_ball = tl.Turtle()  
    hit_ball.speed(45)  
    hit_ball.shape("circle")  
    hit_ball.color("Green")  
    hit_ball.penup()  
    hit_ball.goto(5, 5)  
    hit_ball.dx = int(level[l])
    hit_ball.dy = int(level[l])
    print(hit_ball.dy)
       
     
    left_player = 0  
    right_player = 0  
       

    sketch_1 = tl.Turtle()  
    sketch_1.speed(45)  
    sketch_1.color("Yellow")  
    sketch_1.penup()  
    sketch_1.hideturtle()  
    sketch_1.goto(0, 260)  
    sketch_1.write("Left Player : 0    Right Player: 0",  
                 align = "center", font = ('arial',24,'bold'))  

    def paddle_L_up():  
        y = left_paddle.ycor()  
        y += 20  
        left_paddle.sety(y)  
       
       
    def paddle_L_down():  
        y = left_paddle.ycor()  
        y -= 20  
        left_paddle.sety(y)  
       
       
    def paddle_R_up():  
        y = right_paddle.ycor()  
        y += 20  
        right_paddle.sety(y)  
       
       
    def paddle_R_down():  
        y = right_paddle.ycor()  
        y -= 20  
        right_paddle.sety(y)  
       
    screen_1.listen()  
    screen_1.onkeypress(paddle_L_up, "w")  
    screen_1.onkeypress(paddle_L_down, "s")  
    screen_1.onkeypress(paddle_R_up, "Up")  
    screen_1.onkeypress(paddle_R_down, "Down")  
       
       
    while True:  
        screen_1.update()  
        hit_ball.setx(hit_ball.xcor() + hit_ball.dx) 
        hit_ball.sety(hit_ball.ycor() + hit_ball.dy)
       
        if hit_ball.ycor() > 280:  
            hit_ball.sety(280)  
            hit_ball.dy *= -1  
       
        if hit_ball.ycor() < -280:  
            hit_ball.sety(-280)  
            hit_ball.dy *= -1  
       
        if hit_ball.xcor() > 500:  
            hit_ball.goto(0, 0)  
            hit_ball.dy *= -1  
            left_player += 1  
            sketch_1.clear()  
            sketch_1.write("Left_player : {}    Right_player: {}".format(  
                          left_player, right_player), align = "center",  
                          font = ("Courier", 24, "normal"))  
       
        if hit_ball.xcor() < -500:  
            hit_ball.goto(0, 0)  
            hit_ball.dy *= -1  
            right_player += 1  
            sketch_1.clear()  
            sketch_1.write("Left_player : {}    Right_player: {}".format(  
                                     left_player, right_player), align = "center",  
                                     font = ("Courier", 24, "normal")) 

        if (hit_ball.xcor() > 360 and  
                            hit_ball.xcor() < 370) and (hit_ball.ycor() < right_paddle.ycor() + 40 and  
                            hit_ball.ycor() > right_paddle.ycor() - 40):  
                            hit_ball.setx(360)  
                            hit_ball.dx *= -1  
              
        if (hit_ball.xcor() < -360 and  
                           hit_ball.xcor() > -370) and (hit_ball.ycor() < left_paddle.ycor() + 40 and  
                           hit_ball.ycor() > left_paddle.ycor() - 40):  
                           hit_ball.setx(-360)  
                           hit_ball.dx *= -1


def Sign_up():
    
    window = Tk()

    setu1 = StringVar(window)
    setu1.set("u ")

    setp1 = StringVar(window)
    setp1.set("p")


    def btn_clicked():
        print(setu1.get(),setp1.get())
        mydb = mysql.connector.connect(
        host = 'localhost',
        username = "root",
        password = "1234",
        database = "new"
        )
        cursor = mydb.cursor()
        o = setu1.get()
        l = setp1.get()

        p="insert into abc(User_name,Difficulty)values(%s,%s)"
        p2=[(o,level[l])]

        cursor.executemany(p,p2) 
        mydb.commit()
        print("winow: "+l)
        window.destroy()
        Pong(l)

    def setuu(event):
        setu1.set(event.widget.get())

    def setpp(event):
        print("hii")
        setp1.set(event.widget.get())


    window.geometry("782x520")
    window.configure(bg = "#ec1616")
    canvas = Canvas(
        window,
        bg = "#ec1616",
        height = 520,
        width = 782,
        bd = 0,
        highlightthickness = 0,
        relief = "ridge")
    canvas.place(x = 0, y = 0)

    background_img = PhotoImage(file = f"./Assets/background.png")
    background = canvas.create_image(
        391.0, 260.0,
        image=background_img)

    canvas.create_text(
        115.5, 63.5,
        text = "Log in",
        fill = "#000000",
        font = ("None", int(40.0)))

    entry0_img = PhotoImage(file = f"./Assets/img_textBox0.png")
    entry0_bg = canvas.create_image(
        204.0, 191.0,
        image = entry0_img)

    entry0 = Entry(
        bd = 0,
        bg = "#dcd4d4",
        highlightthickness = 0)

    entry0.bind("<Leave>",setuu)

    entry0.place(
        x = 51.0, y = 166,
        width = 306.0,
        height = 48)

    entry1_img = PhotoImage(file = f"./Assets/img_textBox1.png")
    entry1_bg = canvas.create_image(
        204.0, 293.0,
        image = entry1_img)

    entry1 = Entry(
        bd = 0,
        bg = "#dcd4d4",
        highlightthickness = 0)
    entry1.bind("<Leave>",setpp)
    entry1.place(
        x = 51.0, y = 268,
        width = 306.0,
        height = 48)

    canvas.create_text(
        96.5, 151.5,
        text = "Username:",
        fill = "#000000",
        font = ("None", int(24.0)))

    canvas.create_text(
        97.5, 253.5,
        text = "Difficulty:",
        fill = "#000000",
        font = ("None", int(24.0)))
    canvas.create_text(
        150.5, 340.5,
        text = "Low,Normal,Hard",
        fill = "#000000",
        font = ("None", int(15.0)))

    img0 = PhotoImage(file = "./Assets/img0.png")
    b0 = Button(
        image = img0,
        borderwidth = 0,
        highlightthickness = 0,
        command = btn_clicked,
        relief = "flat")

    b0.place(
        x = 57, y = 401,
        width = 293,
        height = 46)

    window.resizable(False, False)
    window.mainloop()

Sign_up()


