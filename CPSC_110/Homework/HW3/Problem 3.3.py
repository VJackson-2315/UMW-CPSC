number = int(input("Pick a number.  "))
fact = number - 1
n = number

for i in range (fact, 0, -1):
    ans = i * n
    n = ans

print (number, "! = ", n, sep = "")