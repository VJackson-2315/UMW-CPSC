# For this lab, the main Python program needed has the following form

from sympy import * #This makes the rref() function available

A = Matrix([[-1,0.2,0.3,-430],[0.1,-1,0.4,-200],[0.2,0.5,-1,-260]])
#You will need to replace these entries by those of the augmented matrix that you find
#You may also need to change the number of rows and/or columns of the matrix
print(A)
print()
B = A.rref()
print(B[0]) #Prints the matrix B
print()
print(B)
