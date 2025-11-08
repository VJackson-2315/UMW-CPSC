#1
num = int(input("Pick a number.  "))
count = 1

while count <= num:
    print(count)
    count += 1

#2
m = int(input("Pick a number.  "))
n = int(input("Pick another number.  "))
ans = m + 1

while n < m:
    n = int(input("Too low. Pick another number.  "))

while n >= m:
    fib = int(ans + m)
    print(m, "+", ans, "=", fib)
    ans = fib
    m += 1

#3
number = int(input("Pick a number.  "))
fact = number - 1
n = number

for i in range (fact, 0, -1):
    ans = i * n
    n = ans

print (number, "! = ", n, sep = "")

#4
num = int(input("Pick a number.  "))
count = 1

while count <= 10:
    print(count, "*", num, "=", count * num)
    count += 1

#5
passcode = str("Jumper")
guess = input("Enter passcode:  ")

while guess != passcode:
    print("Incorrect passcode. Try again.")
    guess = input("Enter passcode:  ")
    
print("Welcome back.")