#1
speed_limit = int(input("What is the speed limit? "))
clocked_speed = int(input("How fast was your car going? "))

if clocked_speed > speed_limit:
    if clocked_speed <= 70:
        fine = int((clocked_speed - speed_limit) + 40)
    else:
        fine = int((clocked_speed - speed_limit) + 140)
    print("That is illegal. Your fine is $", fine, sep = "")
else:
    print("Your speed was okay.")

#2
def sum_cubes(n):
    total = 0
    for i in range(1, n + 1):
        cubed = i ** 3
        total += cubed
    print(total)