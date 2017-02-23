import os
import operator
import itertools
import math
import random
import scipy.special
import scipy.integrate
from scipy import *

def myInt(a,b,oneOrTwo):
    gamma = scipy.special.gamma
    ans = oneOrTwo*gamma((a+1.0)/2.0)*gamma((b+1.0)/2.0)/gamma((a+b+2.0)/2.0)
    print(ans)

def definiteIntegral(a,b,oneOrTwo):
    def actual(a,b,x):
        return scipy.sin(x)**a*scipy.cos(x)**b
    ans = scipy.integrate.quad(lambda x: actual(a,b,x),0,oneOrTwo*scipy.pi)
    print(ans)

def testInt(a,b,oneOrTwo):
    myInt(a,b,oneOrTwo)
    definiteIntegral(a,b,oneOrTwo)

def tripleIntegral(t,a,b,c):
    def toInt(x,y,z):
        return x+y

    ans = scipy.integrate.tplquad(toInt,0,1,lambda x: 0, lambda x:1-x, lambda x,y:0, lambda x,y: 1-x-y)
    print(ans)

def doubleIntPls(t,a,b,c):
    def toInt(x,y):
        return (sin(x)**2*sin(y)**2 + sin(x)**2*cos(y)**2)*sin(x)/(4*pi)

    ans = scipy.integrate.dblquad(toInt, 0, 2*pi, lambda x: 0, lambda x: pi)
    print(ans)

def doubleInt(t,a,b,c):
    def toInt(x,y):
        return (t*(sin(x)**2*sin(y)**2 + sin(x)**2*cos(y)**2) + (1-t)*cos(x)**2)*sin(x)**(2*(a+b)+1)*sin(y)**(2*a)*cos(x)**(2*c)*cos(y)**(2*b)/4/pi

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

    return ans

def myAddIndex(oldAns,index,t,oldA,oldB,oldC):
    if(index == 'a'):
        top = oldA+0.5
        other = 3*t+1.0
    elif(index == 'b'):
        top = oldB+0.5
        other = 3*t+1.0
    else:
        top = oldC+0.5
        other = -t+3.0

    p1 = oldAns*top/(oldA+oldB+oldC+2.5)
    p2 = (2*t*(oldA+oldB)+2*oldC*(1-t)+other)
    p3 = (2*t*(oldA+oldB)+2*oldC*(1-t)+t+1)
    return p1*p2/p3

def incrementalInt(t,a,b,c):

    PRINT = False

    currentAns = 4.0/3.0*scipy.pi*(t+1.0)

    _a = 0.0
    _b = 0.0
    _c = 0.0

    if(PRINT):
        print('a: '+str(_a)+' b: '+str(_b)+' c: '+str(_c)+' actual: '+str(myDoubleInt2(t,_a,_b,_c))+' myyAns: '+str(currentAns))

    while(_a < a):
        currentAns = myAddIndex(currentAns,'a',t,_a,_b,_c)
        _a += 1
        if(PRINT):
            print('a: '+str(_a)+' b: '+str(_b)+' c: '+str(_c)+' actual: '+str(myDoubleInt2(t,_a,_b,_c))+' myyAns: '+str(currentAns))

    while(_b < b):
        currentAns = myAddIndex(currentAns,'b',t,_a,_b,_c)
        _b += 1
        if(PRINT):
            print('a: '+str(_a)+' b: '+str(_b)+' c: '+str(_c)+' actual: '+str(myDoubleInt2(t,_a,_b,_c))+' myyAns: '+str(currentAns))

    while(_c < c):
        currentAns = myAddIndex(currentAns,'c',t,_a,_b,_c)
        _c += 1
        if(PRINT):
            print('a: '+str(_a)+' b: '+str(_b)+' c: '+str(_c)+' actual: '+str(myDoubleInt2(t,_a,_b,_c))+' myyAns: '+str(currentAns))


    return currentAns


# def partOfInt(b):
#     def toInt(x):
#         return sin(x)**(2*b)
#     ans = scipy.integrate.quad(toInt,0,2*scipy.pi)
#     print(ans)

# def partOfIntCompare(b):
#     ans = 2*sqrt(pi)*scipy.special.gamma(b+0.5)/scipy.special.gamma(b+1.0)
#     print(ans)



# testInt(a,b)

# RE WRITE EVERYTHING WITH 4 COMPONENTS!!!!!! DONT LET Aa = aA!!!!!!!
t = 1.0
a = 1.0
b = 2.0
c = 3.0
# doubleInt(t,a,b,c)
# doubleIntPls(t,a,b,c)
# tripleIntegral(t,a,b,c)

testInt(a,c,1)

# t = 1.0
# a = 3.0
# b = 2.0
# c = 5.0
# incrementalInt(t,a,b,c)

# print('\n\n--------\n\n')

# t = 1.0
# a = 0.0
# b = 0.0
# c = 0.0
# ans = myAddIndex(myDoubleInt2(t,a,b,c),'a',t,a,b,c)

# a += 1
# print('a: '+str(a)+' b: '+str(b)+' c: '+str(c)+' actual: '+str(myDoubleInt2(t,a,b,c))+' myyAns: '+str(ans))

# print('\n')

# factor2 = myAddIndex('b',t,a+1,b,c)
# print(ans0*factor1*factor2)
# print(myDoubleInt2(t,a+1,b+1,c))
# print('\n')

# factor3 = myAddIndex('c',t,a+1,b+1,c)
# print(ans0*factor1*factor2*factor3)
# print(myDoubleInt2(t,a+1,b+1,c+1))
# print('\n')


# allT = [1.0]
# allA = [x for x in range(0,5)]
# allB = [x for x in range(0,5)]
# allC = [x for x in range(0,5)]

# allAns = {}

# for t,a,b,c in itertools.product(allT,allA,allB,allC):
#     ans = round(myDoubleInt2(t,a,b,c),105)
#     toPutIn = [a+b+c,sorted([a,b,c])]
#     if(ans not in allAns):
#         allAns[ans] = [[a+b+c,[a,b,c]]]
#     elif(toPutIn not in allAns[ans]):
#         allAns[ans].append([a+b+c,[a,b,c]])

# for k,v in sorted(allAns.items(),key=lambda x: x[1][0]):
#     print(str(k)+' -> '+str(v))





