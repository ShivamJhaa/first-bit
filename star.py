import turtle

spiral = turtle.Turtle()
turtle.bgcolor("black")
spiral.speed(5)
spiral.color("cyan")

for i in range(50):
    spiral.forward(i * 10)
    spiral.right(144)

turtle.done()