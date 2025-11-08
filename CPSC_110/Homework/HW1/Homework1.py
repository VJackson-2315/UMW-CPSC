#greeting.py
name = input("What is your name?  ")
day_of_week = input("What is the day of the week?\n")
print("Hello", name, "today is", day_of_week)

#age.py
name = input("What is your name?  ")
age = input("How old are you?  ")
print ("Hello", name, "you are", age, "years old.")

#favorites.py
name = input("What is your name?  ")
color = input("What is your favorite color?  ")
animal = input("What is your favorite animal?  ")
print("Hello", name, "your favorite color is", color, "and your favorite animal is a", animal)

#temperature.py
degreeF = int(input ("What's the temperature in Fahrenheit?  "))
degreeC = int((degreeF - 32) * (5/9))
print("The temperature is", degreeC, "degrees Celsius.")

#bill.py
sub = float(input("What is your subtotal?  "))
tax = float(input("What percentage is your tax rate?  "))
total = (sub * (tax/100)) + sub
print("Your subtotal is", sub, "and your tax rate is", tax, "and your total is", total)