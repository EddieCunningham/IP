import os
import operator
import itertools
import math
import random
import sympy
from mpmath import *

def actual(a,b,x):
    return cos(x)**a*sin(x)**b

def oneApprox(a,b,x):
    return 1.0*(0.5*sqrt(2))**(a + b)

def twoApprox(a,b,x):
    return 1.0*(0.5*sqrt(2))**(a + b)*(-a + b)*(x - 0.25*pi) + 1.0*(0.5*sqrt(2))**(a + b)

def threeApprox(a,b,x):
    return 1.0*(0.5*sqrt(2))**(a + b)*(-a + b)*(x - 0.25*pi) + 0.5*(0.5*sqrt(2))**(a + b)*(x - 0.25*pi)**2*(-a*(-a + b + 2) + b*(-a + b - 2)) + 1.0*(0.5*sqrt(2))**(a + b)

def fourApprox(a,b,x):
    return 1.0*(0.5*sqrt(2))**(a + b)*(-a + b)*(x - 0.25*pi) + 0.166666666666667*(0.5*sqrt(2))**(a + b)*(x - 0.25*pi)**3*(-a*((-a + b)*(b + 1) - (a - 1)*(-a + b + 4)) + b*(-(-a + b)*(a + 1) + (b - 1)*(-a + b - 4))) + 0.5*(0.5*sqrt(2))**(a + b)*(x - 0.25*pi)**2*(-a*(-a + b + 2) + b*(-a + b - 2)) + 1.0*(0.5*sqrt(2))**(a + b)

def fiveApprox(a,b,x):
    return 1.0*(0.5*sqrt(2))**(a + b)*(-a + b)*(x - 0.25*pi) + 0.0416666666666667*(0.5*sqrt(2))**(a + b)*(x - 0.25*pi)**4*(-a*(-(a - 1)*(-(a - 2)*(-a + b + 6) + (b + 2)*(-a + b + 2)) + (b + 1)*(-a*(-a + b + 2) + b*(-a + b - 2))) + b*(-(a + 1)*(-a*(-a + b + 2) + b*(-a + b - 2)) + (b - 1)*(-(a + 2)*(-a + b - 2) + (b - 2)*(-a + b - 6)))) + 0.166666666666667*(0.5*sqrt(2))**(a + b)*(x - 0.25*pi)**3*(-a*((-a + b)*(b + 1) - (a - 1)*(-a + b + 4)) + b*(-(-a + b)*(a + 1) + (b - 1)*(-a + b - 4))) + 0.5*(0.5*sqrt(2))**(a + b)*(x - 0.25*pi)**2*(-a*(-a + b + 2) + b*(-a + b - 2)) + 1.0*(0.5*sqrt(2))**(a + b)

def tenApprox(a,b,x):
    return 1.0*(0.5*sqrt(2))**(a + b)*(-a + b)*(x - 0.25*pi) - 2.75573192239859e-6*(0.5*sqrt(2))**(a + b)*(a - b)*(x - 0.25*pi)**9*(a**8 - 8*a**7*b - 72*a**7 + 28*a**6*b**2 + 360*a**6*b + 1848*a**6 - 56*a**5*b**3 - 648*a**5*b**2 - 5040*a**5*b - 22176*a**5 + 70*a**4*b**4 + 360*a**4*b**3 + 3528*a**4*b**2 + 26208*a**4*b + 139440*a**4 - 56*a**3*b**5 + 360*a**3*b**4 - 672*a**3*b**3 - 4032*a**3*b**2 - 33600*a**3*b - 486528*a**3 + 28*a**2*b**6 - 648*a**2*b**5 + 3528*a**2*b**4 - 4032*a**2*b**3 + 30240*a**2*b**2 - 158592*a**2*b + 940672*a**2 - 8*a*b**7 + 360*a*b**6 - 5040*a*b**5 + 26208*a*b**4 - 33600*a*b**3 - 158592*a*b**2 + 602368*a*b - 927744*a + b**8 - 72*b**7 + 1848*b**6 - 22176*b**5 + 139440*b**4 - 486528*b**3 + 940672*b**2 - 927744*b + 354560) - 0.000198412698412698*(0.5*sqrt(2))**(a + b)*(a - b)*(x - 0.25*pi)**7*(a**6 - 6*a**5*b - 42*a**5 + 15*a**4*b**2 + 126*a**4*b + 560*a**4 - 20*a**3*b**3 - 84*a**3*b**2 - 560*a**3*b - 3080*a**3 + 15*a**2*b**4 - 84*a**2*b**3 - 280*a**2*b + 7840*a**2 - 6*a*b**5 + 126*a*b**4 - 560*a*b**3 - 280*a*b**2 + 4480*a*b - 9184*a + b**6 - 42*b**5 + 560*b**4 - 3080*b**3 + 7840*b**2 - 9184*b + 3904) - 0.00833333333333333*(0.5*sqrt(2))**(a + b)*(a - b)*(x - 0.25*pi)**5*(a**4 - 4*a**3*b - 20*a**3 + 6*a**2*b**2 + 20*a**2*b + 100*a**2 - 4*a*b**3 + 20*a*b**2 + 40*a*b - 160*a + b**4 - 20*b**3 + 100*b**2 - 160*b + 80) - 0.166666666666667*(0.5*sqrt(2))**(a + b)*(a - b)*(x - 0.25*pi)**3*(a**2 - 2*a*b - 6*a + b**2 - 6*b + 4) + 2.48015873015873e-5*(0.5*sqrt(2))**(a + b)*(x - 0.25*pi)**8*(a**8 - 8*a**7*b - 56*a**7 + 28*a**6*b**2 + 280*a**6*b + 1064*a**6 - 56*a**5*b**3 - 504*a**5*b**2 - 3024*a**5*b - 8960*a**5 + 70*a**4*b**4 + 280*a**4*b**3 + 2520*a**4*b**2 + 13440*a**4*b + 37520*a**4 - 56*a**3*b**5 + 280*a**3*b**4 - 1120*a**3*b**3 - 4480*a**3*b**2 - 29120*a**3*b - 81536*a**3 + 28*a**2*b**6 - 504*a**2*b**5 + 2520*a**2*b**4 - 4480*a**2*b**3 + 10080*a**2*b**2 + 27776*a**2*b + 86784*a**2 - 8*a*b**7 + 280*a*b**6 - 3024*a*b**5 + 13440*a*b**4 - 29120*a*b**3 + 27776*a*b**2 - 23040*a*b - 34816*a + b**8 - 56*b**7 + 1064*b**6 - 8960*b**5 + 37520*b**4 - 81536*b**3 + 86784*b**2 - 34816*b) + 0.00138888888888889*(0.5*sqrt(2))**(a + b)*(x - 0.25*pi)**6*(a**6 - 6*a**5*b - 30*a**5 + 15*a**4*b**2 + 90*a**4*b + 260*a**4 - 20*a**3*b**3 - 60*a**3*b**2 - 320*a**3*b - 840*a**3 + 15*a**2*b**4 - 60*a**2*b**3 + 120*a**2*b**2 + 360*a**2*b + 1120*a**2 - 6*a*b**5 + 90*a*b**4 - 320*a*b**3 + 360*a*b**2 - 320*a*b - 512*a + b**6 - 30*b**5 + 260*b**4 - 840*b**3 + 1120*b**2 - 512*b) + 0.0416666666666667*(0.5*sqrt(2))**(a + b)*(x - 0.25*pi)**4*(a**4 - 4*a**3*b - 12*a**3 + 6*a**2*b**2 + 12*a**2*b + 28*a**2 - 4*a*b**3 + 12*a*b**2 - 8*a*b - 16*a + b**4 - 12*b**3 + 28*b**2 - 16*b) + 0.5*(0.5*sqrt(2))**(a + b)*(x - 0.25*pi)**2*(a**2 - 2*a*b - 2*a + b**2 - 2*b) + 1.0*(0.5*sqrt(2))**(a + b)

def branch(exprA,exprB,depth,depthMax):
    if(depth == depthMax):
        return 1
    return exprB*branch(exprA+1,exprB-1,depth+1,depthMax)\
          -exprA*branch(exprA-1,exprB+1,depth+1,depthMax)

def generateTaylorSeries(n):
    a,b,x = sympy.symbols('a b x')
    totalExpr = []
    for k in range(0,n):
        expr = branch(a,b,0,k)
        totalExpr.append(expr*(sympy.sqrt(2)/2.0)**(a+b)*(x-sympy.pi/4.0)**k/fac(k))

    for t in totalExpr:
        print(t)

def compare(numPartitions,a,b,func):
    error = 0
    low = 0.0
    high = 2*pi
    for i in range(0,numPartitions):
        x = (high-low)/numPartitions*i+low
        error += (actual(a,b,x)-func(a,b,x))**2
    return error/numPartitions

numPartitions = 1000
a = 1
b = 1
#print(compare(numPartitions,a,b,fifteenApprox))

print(actual(a,b,6.0))
print(fifteenApprox(a,b,6.0))

# generateTaylorSeries(15)

