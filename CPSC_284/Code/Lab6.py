# The following code takes a matrix A and computes both the reduced row echelon form 
# matrix B that is row equivalent to A and the reduced row echelon form matrix C 
# that is row equivalent to A^T, the transpose of A

from sympy import *                                         #This makes the rref() function available
from sympy.interactive.printing import init_printing        #This is for formatting of matrices

A = Matrix([[3,5,2],[2,1,-1],[-1,3,4],[4,5,1]])  
#A matrix is entered this way--each row is in brackets, with another pair of brackets enclosing all rows

print('Original matrix A:')                                       
print(A)                                                           #Prints the matrix A
print()

B = A.rref()     #Produces the matrix in reduced row echelon form that is row equivalent to the matrix A
print('Reduced row echelon form matrix B:')                      
print(B[0])                                                       #Prints the matrix B
print()
print(B)                                                     
print()
print()

AT = A.transpose()                                          #Transpose of matrix A
print('Transpose of A:')
print(AT)
print()

C = AT.rref()                    #reduced row echelon form matrix row equivalent to the transpose of A
print('Reduced row echelon form of A^T:')
print(C[0])
print() 
print(C)

# x = Matrix([[-1],[4],[2]])
# print(A*x)