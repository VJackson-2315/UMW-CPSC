import numpy as np

#The data for this assignment appears below

Wins = np.array([14,12,7,3],float)
Points = np.array([463,485,350,273],float)
Rush = np.array([3048,2619,1705,1783],float)
Pass = np.array([3194,3665,3862,3228],float)
TO = np.array([15,16,28,23],float)
OP = np.array([303,391,468,415],float)

#Calculations for this assignment are as follows
#(The vector x must be changed depending on the quantity tested)

print()

x = OP
n = len(x)
sum = 0.0
for a in x:
    sum += a       
xmean = sum/n       #xmean is the average number of points scored for the four teams
for i in range(n):
    x[i] -= xmean
print('The deviation vector for Opponent Points is x =',x)
print()


y = Wins
n = len(y)
sum = 0.0
for a in y:
    sum += a
ymean = sum/n       #ymean is the average number of wins for the four teams
for i in range(n):
    y[i] -= ymean
print('The deviation vector for Wins is y =',y)
print()

dotprod = x.dot(y)
print('The dot product of x and y is',dotprod)
print()

xnorm = np.linalg.norm(x)
print('The norm of x is',xnorm)
print()

ynorm = np.linalg.norm(y)
print('The norm of y is',ynorm)
print()

r = dotprod/(xnorm * ynorm)
print('The correlation coefficient of Opponent Points vs. Wins is',r)
#Be sure to change this ^ wording depending on the quantity x
print()