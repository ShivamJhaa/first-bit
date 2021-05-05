import turtle


turtle.bgcolor("black")
turtle.pensize(2)
turtle.speed(10)
for i in range(6):
   for colours in ["red","gold","green","pink","blue","silver","cyan"]:
        turtle.color(colours)
        turtle.circle(100)
        turtle.left(10)

turtle.hideturtle()