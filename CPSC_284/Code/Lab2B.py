# The following code plots the four points given in 1-3 and a polynomial of degree four or smaller
import numpy as np
import matplotlib.pyplot as plt

x = np.linspace(-1.5,3.1,num=100) #sets a plot window that includes the four points
a = -37/4 #replace these coefficients with
b = -41/24 #those resulting from your calculations
c = 33/4
d = -55/24
e = 0 #if f(x) is to be a cubic polynomial, make sure e=0
fx = []
for i in range(len(x)):
    fx.append(a + b*x[i] + c*x[i]**2 + d*x[i]**3 + e*x[i]**4)

fx2 = []
fx2.append(b + 2c + d*x[i]**3 + e*x[i]**4)
#fx is a polynomial of degree no larger than 4

plt.plot(x,fx) #plotsf(x) as given above
plt.plot(x,fx2)
plt.grid()
plt.axvline()
plt.axhline()
plt.plot([-1,1,2,3],[3,-5,2,-2],'bo') #plots the four given points
plt.annotate("(-1,3)", [-1,3])
plt.annotate("(1,-5)", [1,-5])
plt.annotate("(2,2)", [2,2])
plt.annotate("(3,-2)", [3,-2])
plt.show()