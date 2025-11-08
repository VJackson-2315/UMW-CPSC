#1
def chaos_a():
    print("This program illustrates a chaotic function.")
    x = eval(input("Enter a number between 0 and 1: "))
    for i in range(100):
        x = 3.9 * x * (1 - x)
        print(x)
        
def chaos_b():
    print("This program illustrates a chaotic function.")
    x = eval(input("Enter a number between 0 and 1: "))
    for i in range(100):
        x = 3.9 * (x - x * x)
        print(x)

def chaos_c():
    print("This program illustrates a chaotic function.")
    x = eval(input("Enter a number between 0 and 1: "))
    for i in range(100):
        x = 3.9 * x - 3.9 * x * x
        print(x)

chaos_a()
chaos_b()
chaos_c()

#2
def average_3():
    print("This program computes the average of three exam scores.")
    
    score1, score2, score3 = eval(input("Enter three scores separated by commas: "))
    average = (score1 + score2 + score3) / 3
    
    print("The average of the scores is:", average)
    
average_3()

#3
def convert_table():
    for celsius in range (0, 110, 10):       
        fahrenheit = 9/5 * celsius + 32
        print(celsius, "degrees Celsius is", fahrenheit, "degrees Fahrenheit.")

convert_table()

#4
def fut_val():
    print("This program calculates the future value")
    print("of a 10-year investment.")
    
    principal = eval(input("Enter the initial principal: "))
    apr = eval(input("Enter the annual interest rate: "))
    years = eval(input("Enter the amount of years: "))
    
    for i in range(years):
        principal = principal * (1 + apr)
        
    print("The value in", years, "years is:", principal)
    
fut_val()