import os
import operator
import itertools
import math
import random
import scipy.special
import scipy.integrate
from scipy import *

# def myInt(a,b):
#     print(2/(a+1)*scipy.special.hyp2f1((a+1)/2.0,(1-b)/2.0,(a+3)/2.0,1))

# def definiteIntegral(a,b):
#     def actual(a,b,x):
#         return scipy.cos(x)**a*scipy.sin(x)**b
#     ans = scipy.integrate.quad(lambda x: actual(a,b,x),0,scipy.pi)
#     print(ans)

# def testInt(a,b):
#     myInt(a,b)
#     definiteIntegral(a,b)

def doubleInt(t,a,b,c):
    def toInt(x,y):
        return (t*(sin(x)**2*sin(y)**2 + sin(x)**2*cos(y)**2) + (1-t)*cos(x)**2)*sin(x)**(2*(a+b)+1)*sin(y)**(2*a)*cos(x)**(2*c)*cos(y)**(2*b)

    ans = scipy.integrate.dblquad(toInt, 0, 2*pi, lambda x: 0, lambda x: pi)
    print(ans)

# def doubleInt2(t,a,b,c):
#     def toInt(x,y):
#         return (cos(x)**2+t*(sin(x)**2-cos(x)**2))*sin(x)**(2*a+1)*sin(y)**(2*b)*cos(x)**(2*c)

#     ans = scipy.integrate.dblquad(toInt, 0, 2*pi, lambda x: 0, lambda x: pi)
#     print(ans)

# def doubleInt3(t,a,b,c):
#     def toInt1(x,y):
#         return sin(x)**(2*a+1)*sin(y)**(2*b)*cos(x)**(2*c+2)
#     def toInt2(x,y):
#         return t*sin(x)**(2*a+3)*sin(y)**(2*b)*cos(x)**(2*c)
#     def toInt3(x,y):
#         return -t*sin(x)**(2*a+1)*sin(y)**(2*b)*cos(x)**(2*c+2)

#     ans1 = scipy.integrate.dblquad(toInt1, 0, 2*pi, lambda x: 0, lambda x: pi)
#     ans2 = scipy.integrate.dblquad(toInt2, 0, 2*pi, lambda x: 0, lambda x: pi)
#     ans3 = scipy.integrate.dblquad(toInt3, 0, 2*pi, lambda x: 0, lambda x: pi)
#     print('ans1'+str(ans1))
#     print('ans2'+str(ans2))
#     print('ans3'+str(ans3))
#     print('ans: '+str(ans1[0]+ans2[0]+ans3[0]))

def myDoubleInt(t,a,b,c):
    gamma = scipy.special.gamma

    p1 = 8.0/(2*b+1.0)*gamma(b+1.5)*gamma(a+0.5)/gamma(a+b+1)/gamma(a+b+c+2.5)
    p2 = (1-t)/(2*c+3.0)*gamma(c+2.5)*gamma(a+b+1)
    p3 = t/(2*c+1)*gamma(c+1.5)*gamma(a+b+2)
    ans = p1*(p2+p3)
    # print(ans)

    return ans

def myDoubleInt2(t,a,b,c):
    gamma = scipy.special.gamma

    p1 = gamma(a+0.5)*gamma(b+0.5)*gamma(c+0.5)/gamma(a+b+c+2.5)
    p2 = 2*t*(a+b)+2*c*(1-t)+t+1
    ans = p1*p2
    # print(ans)

    return ans

# def partOfInt(b):
#     def toInt(x):
#         return sin(x)**(2*b)
#     ans = scipy.integrate.quad(toInt,0,2*scipy.pi)
#     print(ans)

# def partOfIntCompare(b):
#     ans = 2*sqrt(pi)*scipy.special.gamma(b+0.5)/scipy.special.gamma(b+1.0)
#     print(ans)

# t = 1.0
# a = 3.0
# b = 1.0
# c = 2.0

# testInt(a,b)

# doubleInt(t,a,b,c)

# myDoubleInt(t,a,b,c)
# print(myDoubleInt2(t,a,b,c))

allT = [1.0]
allA = [x for x in range(0,5)]
allB = [x for x in range(0,5)]
allC = [x for x in range(0,5)]

allAns = {}

for t,a,b,c in itertools.product(allT,allA,allB,allC):
    ans = round(myDoubleInt2(t,a,b,c),105)
    toPutIn = [a+b+c,sorted([a,b,c])]
    if(ans not in allAns):
        allAns[ans] = [[a+b+c,[a,b,c]]]
    elif(toPutIn not in allAns[ans]):
        allAns[ans].append([a+b+c,[a,b,c]])

for k,v in sorted(allAns.items(),key=lambda x: x[1][0]):
    print(str(k)+' -> '+str(v))





