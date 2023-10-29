# import math
from cmath import sqrt

def quad_computer():
    '''computing the roots of a quadratic equation with valid inputs.'''
    try:
        global a, b, c
        a, b, c = input("Enter a: "), input("Enter b: "), input("Enter c: ")

        for parameter in a, b, c:
            float(parameter)
    except ValueError: #check for strings as inputs and reject if true
        print(f"'{parameter}' has to be a number! Kindly restart the process.")
        quad_computer()
    else:
        a, b, c = float(a), float(b), float(c)
        try:
            global alpha_root, beta_root
            alpha_root = lambda a, b, c: (-b + (sqrt((b**2) - (4*a*c))))/(2*a) 
            beta_root = lambda a, b, c: (-b - (sqrt((b**2) - (4*a*c))))/(2*a)
        except Exception:
            print("The equation has no solutions!") 
        else:
            print(f"The roots of the equation are: {alpha_root(a, b, c)} and {beta_root(a, b, c)}")

quad_computer()
# help(quad_computer)