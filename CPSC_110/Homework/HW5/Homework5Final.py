#1
def coffee_shop(pound):
    order = (float((pound * 0.86) + 1.50))
    print("Your total is $", order, sep="")

#2
import math

def distance(x, y, xx, yy):
    length = math.sqrt(((xx - x) ** 2) + ((yy - y) ** 2))
    print(length)

#3
def average():
    total = 0
    count = int(input("How many numbers do you want to average? "))
    
    for i in range(count):
        num = float(input("Enter a number: "))
        total += num
        
    ave = total / count
    print("Average is ", ave)

#4
import math

def approx_pi(num):
    den = 1
    approx = 0
    
    for i in range(num + 1):
        if i % 2 == 0:
            approx += 4/den
        else:
            approx -= 4/den
        den += 2
    
    print("The approximate number is:", approx)    
    print("Difference from pi:", math.pi - approx)

#5
def fibo(term):
    start = 0
    next_num = 1    
    count = 1
    
    while count <= term:
        ans = start + next_num
        start = next_num
        next_num = ans
        count += 1
    print("f_", term, " = ", ans, sep = "")