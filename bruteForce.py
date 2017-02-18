import os
import operator
import itertools
import math
import random
import Queue
import scipy.special
import numpy as np
from partitionIterator import *

WINDOW = 10000
THRESHOLD = 10
USE_INTEGRALS = True

class ansChecker():
    def __init__(self,movingAverageWindow,threshold):
        self._threshold = threshold
        self._window = movingAverageWindow
        self.movingAverage = 0.0
        self._powerSumAverage = 0.0
        self.movingVariance = 0.0
        self._q = Queue.Queue(maxsize=self._window)
        self._lastX = None

    def addPoint(self,x):
        if(self._q.full()):
            firstIn = self._q.get()
            self.movingAverage += (x - firstIn)/self._window
            # self._powerSumAverage += (x**2 - self._lastX**2)
            # self.movingVariance = self._powerSumAverage + self.movingAverage**2
            self._q.put(x)
        else:
            self._q.put(x)
            self.movingAverage += x
            if(self._q.full()):
                # self._powerSumAverage += (x**2 - self._lastX**2)
                self.movingAverage /= self._window

        self._lastX = x

    def shouldStop(self):
        return False and self._q.full() and self.movingVariance < self._threshold

def theIntegral(t,a,b,c):
    return (2*t*(a+b)+2*c*(1-t)+t+1)*scipy.special.gamma(a+0.5)*scipy.special.gamma(b+0.5)*scipy.special.gamma(c+0.5)/scipy.special.gamma(a+b+c+2.5)

def getIntegralPart(setVals):
    ans = 1
    for k,v in setVals.items():
        a,b,c = v
        t = 1.0
        theInt = theIntegral(t,a,b,c)
        ans *= theInt/(2*np.pi**2)
    return ans

def bruteForce(familySize,types,d_checkpoint=0.1,stochastic=False,writeResults=False,numSamples=1000,random_seed=1):
    numUniqueIndices = 0
    uniqueMapping = {}
    if(USE_INTEGRALS):
        setVals = {}
    for t in types:
        for _t in t[1]:

            if(USE_INTEGRALS):
                if(_t[0] not in setVals):
                    setVals[_t[0]] = [0,0,0]

            if(_t[1] not in uniqueMapping):
                uniqueMapping[_t[1]] = numUniqueIndices
                numUniqueIndices += 1

    # for k,v in uniqueMapping.items():
    #     print(str(k)+' -> '+str(v))
    # assert 0

    total = 3**numUniqueIndices
    print('Total terms: '+str(total))

    count = 0
    checkpoint = 0.0
    if(d_checkpoint > 1):
        d_checkpoint = d_checkpoint/float(total)
    ans = 0

    if(writeResults):
        data = {}

    pC = [[0,3] for n in range(0,numUniqueIndices)]
    pC[-1][0] = -1

    theCounter = counter(pC,stochastic,numSamples,True)

    stopCriteria = ansChecker(WINDOW,THRESHOLD)

    iters = 0
    while(theCounter.incrementCounter(-1)):
        count += 1
        percentCompleted = count/float(total)
        flag = False
        if(percentCompleted > checkpoint):
            print('%.4f | '%(percentCompleted)+str(theCounter.productCounter)+' -> '+str(ans))
            checkpoint += d_checkpoint
            flag = True
        if(writeResults):
            data[count] = ans

        val = 1

        if(USE_INTEGRALS):
            for k in setVals:
                setVals[k] = [0,0,0]

        for t in types:
            indices = [theCounter.productCounter[uniqueMapping[_t[1]]][0] for _t in t[1]]

            if(USE_INTEGRALS):
                for i,_t in zip(indices,t[1]):
                    setVals[_t[0]][i] += 1

            if(t[0] == 'g'):
                valsDict = valsGDict
            elif(t[0] == 's'):
                valsDict = valsSDict
            elif(t[0] == 'n'):
                valsDict = valsNDict
            elif(t[0] == 'p'):
                valsDict = valsPDict
            else:
                assert 0,'invalid type of sequence'

            current = valsDict[str(tuple(indices))]
            if(current == 0):
                val = 0
                break
            val *= current

        if(USE_INTEGRALS):
            intPart = getIntegralPart(setVals)
            print('val: '+str(val)+' after: '+str(val*intPart))
            val *= intPart
        ans += val
        iters += 1

        projectedAns = ans*total/iters
        stopCriteria.addPoint(projectedAns)
        if(flag):
            pass
            # print('avg: '+str(stopCriteria.movingAverage)+' var: '+str(stopCriteria.movingVariance)+' iters: '+str(iters))
        if(stopCriteria.shouldStop()):
            break



    print('ans: '+str(ans))
    # print('ans: '+str(ans**(1.0/familySize)))
    print('count: '+str(count))
    print('Total terms: '+str(total))

    if(writeResults):
        # data['totalCount'] = count
        # data['totalSum'] = ans
        data['totalNumTerms'] = total
        return data
    return None


