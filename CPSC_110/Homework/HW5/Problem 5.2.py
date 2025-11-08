import math

def distance(x, y, xx, yy):
    length = math.sqrt(((xx - x) ** 2) + ((yy - y) ** 2))
    print(length)