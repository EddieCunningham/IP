import os
import operator
import itertools
import math
import random
import Queue
import copy

globalId = 0

class gType:
    def __init__(self,theType):
        global globalId
        self._id = str(globalId)
        globalId += 1
        self.left = None
        self.right = None
        self.counterLeft = 0
        self.counterRight = 0
        self.counterMiddle = 0
        self.name = theType[0]
        self.indices = theType[1]
        self.vals = self.getVals()
        self.isRoot = False

    def resetCounters(self):
        self.counterLeft = 0
        self.counterRight = 0
        self.counterMiddle = 0

    def getVals(self):
        return [
               [1.0,0.5,0.5,0.25], # zero
               [0.5,1.0,0.5,0.5,0.5,1.0,0.5], # one
               [0.25,0.5,0.5,1.0]  # two
               ]


    def getNextVal(self,whichBranch):
        if(whichBranch == 'zero'):
            if(self.counterLeft == 4):
                self.resetCounters()
                return False

            left = ['zero','one'][self.counterLeft%2]
            right = ['zero','one'][int(self.counterLeft/2)%2]
            val = self.vals[0][self.counterLeft]

            self.counterLeft += 1
        
        elif(whichBranch == 'one'):
            if(self.counterMiddle == 7):
                self.resetCounters()
                return False
            if(self.counterMiddle == 0):
                left = 'zero'
                right = 'one'
                val = self.vals[1][0]
            elif(self.counterMiddle == 1):
                left = 'zero'
                right = 'two'
                val = self.vals[1][1]
            elif(self.counterMiddle == 2):
                left = 'one'
                right = 'zero'
                val = self.vals[1][2]
            elif(self.counterMiddle == 3):
                left = 'one'
                right = 'one'
                val = self.vals[1][3]
            elif(self.counterMiddle == 4):
                left = 'one'
                right = 'two'
                val = self.vals[1][4]
            elif(self.counterMiddle == 5):
                left = 'two'
                right = 'zero'
                val = self.vals[1][5]
            elif(self.counterMiddle == 6):
                left = 'two'
                right = 'one'
                val = self.vals[1][6]

            self.counterMiddle += 1
        
        elif(whichBranch == 'two'):
            if(self.counterRight == 4):
                self.resetCounters()
                return False

            left = ['one','two'][self.counterRight%2]
            right = ['one','two'][int(self.counterRight/2)%2]
            val = self.vals[2][self.counterRight]

            self.counterRight += 1
        
        else:
            assert 0,'Invalid whichBranch'
        
        return [left,right,val]


class nType:
    def __init__(self,theType):
        global globalId
        self._id = str(globalId)
        globalId += 1
        self.left = None
        self.right = None
        self.counterLeft = 0
        self.counterRight = 0
        self.counterMiddle = 0
        self.name = theType[0]
        self.indices = theType[1]
        self.vals = self.getVals()
        self.isRoot = True

    def resetCounters(self):
        self.counterLeft = 0
        self.counterRight = 0
        self.counterMiddle = 0

    def getVals(self):
        return [0.25,0.5,0.5,1.0]


    def getNextVal(self,whichBranch=None):
        if(self.counterLeft == 4):
            self.resetCounters()
            return False

        left = ['one','two'][self.counterLeft%2]
        right = ['one','two'][int(self.counterLeft/2)%2]
        
        val = self.vals[self.counterLeft]
        self.counterLeft += 1
        return [left,right,val]


class pType:
    def __init__(self,theType):
        global globalId
        self._id = str(globalId)
        globalId += 1
        self.left = None
        self.right = None
        self.counterLeft = 0
        self.counterRight = 0
        self.counterMiddle = 0
        self.name = theType[0]
        self.indices = theType[1]
        self.vals = self.getVals()
        self.isRoot = True

    def resetCounters(self):
        self.counterLeft = 0
        self.counterRight = 0
        self.counterMiddle = 0

    def getVals(self):
        return [1.0,1.0,1.0,1.0,0.75,0.5,1.0,0.5]

    def getNextVal(self,whichBranch=None):
        if(self.counterLeft == 8):
            self.resetCounters()
            return False

        if(self.counterLeft < 6):
            left = ['zero','one'][self.counterLeft%3]
            right = ['zero','one','two'][int(self.counterLeft/3)%3]
        elif(self.counterLeft == 6):
            left = 'two'
            right = 'zero'
        elif(self.counterLeft == 7):
            left = 'two'
            right = 'one'

        val = self.vals[self.counterLeft]
        self.counterLeft += 1
        return [left,right,val]

class sType:
    def __init__(self,theType):
        global globalId
        self._id = str(globalId)
        globalId += 1
        self.left = None
        self.right = None
        self.counterLeft = 0
        self.counterRight = 0
        self.counterMiddle = 0
        self.name = theType[0]
        self.indices = theType[1]
        self.vals = self.getVals()
        self.isRoot = True

    def resetCounters(self):
        self.counterLeft = 0
        self.counterRight = 0
        self.counterMiddle = 0

    def getVals(self):
        return [0.5,0.5,0.5,0.5,0.5,0.25,0.5,0.25,0.5]


    def getNextVal(self,whichBranch=None):
        if(self.counterLeft == 9):
            self.resetCounters()
            return False

        left = ['zero','one','two'][self.counterLeft%3]
        right = ['zero','one','two'][int(self.counterLeft/3)%3]

        val = self.vals[self.counterLeft]
        self.counterLeft += 1
        return [left,right,val]

def newSetFactor(index,t,a,b,c):
    if(index == 0):
        top = a+0.5
        other = 3*t+1.0
    elif(index == 1):
        top = b+0.5
        other = 3*t+1.0
    elif(index == 2):
        top = c+0.5
        other = -t+3.0
    else:
        assert 0,'Invalid index'
    p1 = oldAns*top/(a+b+c+2.5)
    p2 = (2*t*(a+b)+2*c*(1-t)+other)
    p3 = (2*t*(a+b)+2*c*(1-t)+t+1)
    return p1*p2/p3

class integralSet():
    def __init__(self,numb):
        self.numb = 0
        self.zero = 0
        self.one = 1
        self.two = 2


def findAnsHelper(currentType,whichBranch,setVals):

    if(currentType.left == None and currentType.right == None):
        ans = currentType.baseCaseVal(setVals)
        currentType.resetCounters()
        return ans

    ans = 0
    nextVal = currentType.getNextVal(whichBranch)
    while(nextVal != -1):
        left = nextVal[0]
        right = nextVal[1]
        val = nextVal[2]
        leftBranch = 1
        rightBranch = 1
        if(currentType.left):
            leftBranch = findAnsHelper(currentType.left,left)
        if(currentType.right):
            rightBranch = findAnsHelper(currentType.right,right)
        ans += val*leftBranch*rightBranch
        nextVal = currentType.getNextVal(whichBranch)

    currentType.resetCounters()

    return ans

def generateAllTypesAndSets(types):
    allTypes = []
    for t in types:
        if(t[0] == 'g'):
            allTypes.append(gType(t))
        elif(t[0] == 'n'):
            allTypes.append(nType(t))
        elif(t[0] == 'p'):
            allTypes.append(pType(t))
        elif(t[0] == 's'):
            allTypes.append(sType(t))
        else:
            assert 0, 'Invalid type'

    allSets = []
    setHelper = {}

    for a in allTypes:

        for _t in a.indices:
            if(_t[0] not in setHelper):
                allSets.append(integralSet(_t[0]))
                setHelper[_t[0]] = 1

        uVals = [_t[1] for _t in a.indices]
        for _a in allTypes:
            if(a == _a):
                continue
            valToWorryAbout = a.indices[0][1]
            for i,u in enumerate(uVals):
                if(u == valToWorryAbout):
                    if(a.name == 'g'):
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
    return allTypes,allSets

def findAns(types):

    allTypes,allSets = generateAllTypesAndSets(types)
    roots = [a for a in allTypes if a]
    ans = 1
    for r in roots:
        _ans = findAnsHelper(r,-1)
        ans *= _ans

    print(ans)



    return ans





