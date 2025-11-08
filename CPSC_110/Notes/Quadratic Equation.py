import math
a = int(input("a = "))
b = int(input("b = "))
c = int(input("c = "))

discrim = b **2 - 4 * a * c
if discrim < 0:
    return None, None
else:
    sq_root = 

x = (-b + math.sqrt(b **2 - 4 * a * c)) / (2 * a)
y = (-b - math.sqrt(b **2 - 4 * a * c)) / (2 * a)

print(x)
print(y)