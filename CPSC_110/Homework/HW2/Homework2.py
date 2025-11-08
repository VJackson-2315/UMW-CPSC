#1
age = int(input("How old are you? "))

if age >= 18:
    print("You are allowed to vote. You are", age)
else:
    print("You are NOT allowed to vote. You are", age)

#2
number = float(input("Pick any number. "))

if number > 0:
    print("Your number is positive.")
elif number < 0:
    print("Your number is negative.")
else:
    print("Your number is neither because it is 0")

#3
temp = int(input("What is the temperature? "))

if temp >= 30: #hot
    print("It is hot outside.")
elif 30 > temp >= 20: #warm
    print("It is warm outside.")
else:
    print("It is cold outside.")

#4
number = int(input("Pick a number. "))

guess = float(number / 2)

if guess in range (-1000, 1000, 2):
    print("The number is even.")
else:
    print("The number is odd.")

#5
grade = float(input("What is your grade? "))

if grade >= 90:
    print("You got an A.")
elif 90 > grade >= 80:
    print("You got a B.")
elif 80 > grade >= 70:
    print("You got a C.")
elif 70 > grade >= 60:
    print("You got a D.")
else:
    print("You got an F.")