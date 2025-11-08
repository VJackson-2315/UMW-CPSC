# For this lab, the main Python program needed has the following form
from sympy import * #This makes the rref() function available

A = Matrix([[1,-1,1,-1,3],[1,1,1,1,-5],[1,2,4,8,2],[1,3,9,27,-2]])
#A matrix is entered this way
#each row is in brackets, with another pair of brackets enclosing all rows
#You will need to replace these entries by those of the augmented matrix that you find

#You may also need to change the number of rows and/or columns of the matrix
print(A)
print()

B = A.rref()
#Produces the matrix in reduced row echelon form that is row equivalent to the matrix A

print(B[0]) #Prints the matrix B
print()