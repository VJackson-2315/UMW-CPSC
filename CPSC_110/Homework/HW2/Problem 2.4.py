number = int(input("Pick a number. "))

guess = float(number / 2)

if guess in range (-1000, 1000, 2):
    print("The number is even.")
else:
    print("The number is odd.")