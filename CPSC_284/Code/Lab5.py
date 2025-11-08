# For this lab, the main Python program needed has the following form

from sympy import *           #This makes the rref() function available


#Replace the following with the entries of the 3x3 matrix of interest (row by row)

a = 5
b = 1 
c = 3
d = -1
e = 4
f = 7
g = 6
h = 9
i = 11


AI = Matrix([[a,b,c,1,0,0],[d,e,f,0,1,0],[g,h,i,0,0,1]])             

print(AI)                                                          
print()

IB = AI.rref()                                                
print(IB[0])                                                       
print()                                                     
print(IB)