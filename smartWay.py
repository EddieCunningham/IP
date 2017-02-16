import os
import operator
import itertools
import math
import random
import Queue
import copy

def getVals(t):
    if(t[0] == 'g'):
        #       zeroTwo side         one side
        return [[0.25,0.5,0.5,1.0],[0.5,1.0,1.0,2.0]]
    elif(t[0] == 'n'):
        return [[[1,1],0.25],
                [[1,2],0.5],
                [[2,1],0.5],
                [[2,2],1]]
    elif(t[0] == 's'):
        return [[[0,0],1],[[0,2],1],
                [[0,1],1],
                [[1,0],1],[[1,2],0.5],
                [[1,1],0.75],
                [[2,0],1],
                [[2,1],0.5]]
    elif(t[0] == 'p'):
        return [[[0,0],0.5],[[0,2],0.5],
                [[0,1],0.5],
                [[1,0],0.5],[[1,2],0.25],
                [[1,1],0.5],
                [[2,0],0.5],[[2,2],0.5],
                [[2,1],0.25]]

def getTotalSum(t):
    if(t[0] == 'g'):
        return [2.25,4.5]
    elif(t[0] == 'n'):
        return 2.25
    elif(t[0] == 's'):
        return 6.75
    elif(t[0] == 'p'):
        return 4.0

class typeWrapper:
    def __init__(self,t):
        self.t = t
        self.left = None
        self.right = None
        self.vals = getVals(self.t)
        self.tPrint = [self.t[0], [_t[1] for _t in self.t[1]]]
        self.counterLeft = 0
        self.counterRight = 0
        self.totalSum = getTotalSum(self.t)

    def isRoot(self):
        return self.t[0] != 'g'

    def resetCounters(self):
        self.counterLeft = 0
        self.counterRight = 0

    def getNextVal(self,whichBranch):
        if(self.isRoot()):
            if(self.counterLeft == len(self.vals)):
                return -1

            val = self.vals[self.counterLeft]
            val = [['one' if v == 1 else 'twoZero' for v in val[0]],val[1]]
            self.counterLeft += 1
            return val
        else:
            if(whichBranch == 'twoZero'):
                counter = self.counterLeft
                self.counterLeft += 1
                valIndex = 0
            elif(whichBranch == 'one'):
                counter = self.counterRight
                self.counterRight += 1
                valIndex = 1
            else:
                assert 0,'Invalid whichBranch'

            if(counter == 4):
                return -1

            left = ['one','twoZero'][counter%2]
            right = ['one','twoZero'][int(counter/2)%2]
            val = self.vals[valIndex][counter]
            return [[left,right],val]

    def __repr__(self):
        if(self.left):
            if(self.right):
                return str(self.tPrint)+' \nleft:\n\t'+str(self.left.tPrint)+'\nright:\n\t'+str(self.right.tPrint)
            else:
                return str(self.tPrint)+' \nleft:\n\t'+str(self.left.tPrint)+'\nright:\n\t'+'None'
        else:
            if(self.right):
                return str(self.tPrint)+' \nleft:\n\t'+'None'+'\nright:\n\t'+str(self.right.tPrint)
            else:
                return str(self.tPrint)+' \nleft:\n\t'+'None'+'\nright:\n\t'+'None'


def findAnsHelper(currentType,whichBranch,depth):

    if(currentType.left == None and currentType.right == None):
        currentType.resetCounters()
        if(currentType.t[0] == 'g'):
            if(whichBranch == 'twoZero'):
                ans = currentType.totalSum[0]
            else:
                ans = currentType.totalSum[1]
        else:
            ans = currentType.totalSum


        return ans

    ans = 0
    nextVal = currentType.getNextVal(whichBranch)
    while(nextVal != -1):
        left = nextVal[0][0]
        right = nextVal[0][1]
        val = nextVal[1]
        leftBranch = 1
        rightBranch = 1
        if(currentType.left):
            leftBranch = findAnsHelper(currentType.left,left,depth+1)
        if(currentType.right):
            rightBranch = findAnsHelper(currentType.right,right,depth+1)
        ans += val*leftBranch*rightBranch
        nextVal = currentType.getNextVal(whichBranch)

    currentType.resetCounters()

    return ans

def findAns(types):

    allTypes = [typeWrapper(t) for t in types]
    for a in allTypes:
        uVals = [_t[1] for _t in a.t[1]]
        for _a in allTypes:
            if(a == _a):
                continue
            valToWorryAbout = _a.t[1][0][1]
            for i,u in enumerate(uVals):
                if(u == valToWorryAbout):
                    if(a.t[0] == 'g'):
                        if(i == 0):
                            assert 'This shouldn\'t happen!'
                        elif(i == 1):
                            a.left = _a
                        elif(i == 2):
                            a.right = _a
                    else:
                        if(i == 0):
                            a.left = _a
                        elif(i == 1):
                            a.right = _a

    roots = [a for a in allTypes if a.isRoot()]
    ans = 1
    for r in roots:
        _ans = findAnsHelper(r,-1,0)
        ans *= _ans

    print(ans)



    return ans
