import math

def approx_pi(num):
    den = 1
    approx = 0
    
    for i in range(num + 1):
        if i % 2 == 0:
            approx += 4/den
        else:
            approx -= 4/den
        den += 2
    
    print("The approximate number is:", approx)    
    print("Difference from pi:", math.pi - approx)