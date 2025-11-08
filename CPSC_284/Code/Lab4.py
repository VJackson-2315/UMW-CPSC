from sympy import *
from sympy.interactive.printing import init_printing
import math
import numpy as np

f0 = 0.0 #fertility rate of age 0 rabbits
f1 = 1.3 #fertility rate of age 1 rabbits
f2 = 0.9 #fertility rate of age 2 rabbits
f3 = 0.4 #fertility rate of age 3 rabbits
s0 = 0.4 #survival rate of age 0 rabbits
s1 = 0.8 #survival rate of age 1 rabbits
s2 = 0.6 #survival rate of age 2 rabbits

A = Matrix([[f0,f1,f2,f3],[s0,0.0,0.0,0.0],[0.0,s1,0.0,0.0],[0.0,0.0,s2,0.0]])

r0 = 0 #initial number of age 0 rabbits
r1 = 20 #initial number of age 1 rabbits
r2 = 0 #initial number of age 2 rabbits
r3 = 0 #initial number of age 3 rabbits
numyear = 30 #number of years in the study

b = Matrix([[r0],[r1],[r2],[r3]])

print('Year 0')
print('Age 0 =',r0)
print('Age 0 =',r1)
print('Age 0 =',r2)
print('Age 0 =',r3)
print()

for i in range(numyear):
    b = A*b
    print('Year',i+1)
    print('Age 0 = ',round(b[0]))
    print('Age 1 = ',round(b[1]))
    print('Age 2 = ',round(b[2]))
    print('Age 3 = ',round(b[3]))
    total = round(b[0]+b[1]+b[2]+b[3])
    print("Total Population: ", total)
    print()
