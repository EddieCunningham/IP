import os
import operator
import itertools
import math
import random
from vals import *
from preprocess import *
import numpy as np


USE_DEBUG2 = False
OUTER_RATIO_TEST = True
PRINT_EVERY_TIME = False

RANDOM_SEED = 1
np.random.seed(seed=RANDOM_SEED)



class counter():
    def __init__(self,productCounter,stochastic=False,numSamples=1000,bootstrap=False):
        self._stochastic = stochastic
        self.productCounter = productCounter
        self._bootstrap = bootstrap

        if(self._stochastic):
            _,total = self.getTotal()
            self._nSamples = 0
            self._totalSamples = min(total,numSamples)
            self._allChoices = self._getChoices(total)#np.random.choice(total,self._totalSamples,replace=False)

            self._effectiveVals = [0 for _ in productCounter]
            multiplier = 1
            for i,p in enumerate(reversed(self.productCounter)):
                self._effectiveVals[len(self._effectiveVals)-i-1] = multiplier
                multiplier *= p[1]

    def _getChoices(self,total):
        # self._totalSamples
        used = {}
        for i in range(self._totalSamples):
            val = int(np.random.random()*total)
            while(not self._bootstrap and val in used):
                val = int(np.random.random()*total)
            used[val] = 1
        return used.keys()


    def _deterministicChoice(self,i):
        if(i < 0):
            i = len(self.productCounter)+i
        for j in range(i+1,len(self.productCounter)):
            self.productCounter[j][0] = 0

        while(i >= 0):
            index,maxIndex = self.productCounter[i]
            if(index == maxIndex-1):
                self.productCounter[i][0] = 0
                i -= 1
                continue
            self.productCounter[i][0] += 1
            return True
        return False

    def _updateBasedOnVal(self,choice):

        self.productCounter = [[0,p[1]] for p in self.productCounter]
        i=0
        while(i < len(self.productCounter)):
            if(choice < self._effectiveVals[i]):
                i += 1
                continue
            self.productCounter[i][0] += 1
            choice -= self._effectiveVals[i]


    def _stochasticChoice(self):

        currentChoice = self._allChoices[self._nSamples]
        self._updateBasedOnVal(currentChoice)
        self._nSamples += 1
        return self._nSamples < self._totalSamples

    def incrementCounter(self,i):
        if(self._stochastic):
            return self._stochasticChoice()
        return self._deterministicChoice(i)

    def getTotal(self):
        current = 0
        multiplier = 1
        for p in reversed(self.productCounter):
            current += p[0]*multiplier
            multiplier *= p[1]
        return current,multiplier

def partitionIterator(setPartitions,partitionRatios,types,theCounter,dynamicSpeedup,otherInfo,EPSILON=0.0):

    if(USE_DEBUG2):
        print('\ntypes: '+str(types))

    if(PRINT_EVERY_TIME):
        total = theCounter.getTotal()
        print(str(total[0])+' / '+str(total[1])+' -> '+str(float(total[0])/total[1]))
        print('productCounter: '+str(theCounter.productCounter))

    currentPartitions = [setPartitions[i][j[0]] for i,j in enumerate(theCounter.productCounter)]

    # see if the partitions we have have a high chance of being 0
    # if so, increment productCounter by 1
    indexToIncrement = ratioTest(currentPartitions,types,partitionRatios,EPSILON)

    if(OUTER_RATIO_TEST and indexToIncrement != -1):
        # this means that we failed the ratio test

        if(USE_DEBUG2):
            print('indexToIncrement: '+str(indexToIncrement))
        if(not theCounter.incrementCounter(indexToIncrement)):
            return False
        return 'continue'


    # then return the current partitions
    if(not theCounter.incrementCounter(-1)):
        return False

    return currentPartitions


def ratioTest(currentPartitions,types,partitionRatios,EPSILON):

    if(USE_DEBUG2):
        print('currentPartitions: '+str(currentPartitions))
        print('types: '+str(types))

    mult = 1
    typeIndexToIncrement = -1
    for i,t in enumerate(types):
        relevantPartitions = [currentPartitions[j[0]] for j in t[1]]
        stringToAdd = str(t[0])+str(relevantPartitions)

        if(stringToAdd not in partitionRatios):
            updatePartitionRatios(str(t[0]),relevantPartitions,partitionRatios)


        nonZero,total = partitionRatios[stringToAdd]
        mult *= float(nonZero)/float(total)

        if(mult <= EPSILON):
            typeIndexToIncrement = i
            break
    if(typeIndexToIncrement == -1):
        return -1
    return max([x[0] for x in types[typeIndexToIncrement][1]]) 


def ratioTest2(currentPartitions,types,assignedIndices,EPSILON):
    _partitionRatios = {}

    if(USE_DEBUG2):
        print('currentPartitions: '+str(currentPartitions))
        print('types: '+str(types))
        print('assignedIndices: '+str(assignedIndices))
        print('\n\n')

    mult = 1
    typeIndexToIncrement = -1
    for i,t in enumerate(types):
        relevantPartitions = [currentPartitions[j[0]] for j in t[1]]
        stringToAdd = str(t)+str(relevantPartitions)

        if(stringToAdd not in _partitionRatios):
            updatePartitionRatios(t,relevantPartitions,_partitionRatios,assignedIndices)

        nonZero,total = _partitionRatios[stringToAdd]
        mult *= float(nonZero)/float(total)

        if(mult <= EPSILON):
            typeIndexToIncrement = i
            break


    if(typeIndexToIncrement == -1):
        return -1
    return max([x[0] for x in types[typeIndexToIncrement][1]]) 

plshelp = {}
def calcProbOfZero(currentType,currentPartitions,assignedIndices={}):
    global plshelp

    if(currentType[0] == 'g'):
        valsDict = valsGDict
    elif(currentType[0] == 's'):
        valsDict = valsSDict
    elif(currentType[0] == 'n'):
        valsDict = valsNDict
    elif(currentType[0] == 'p'):
        valsDict = valsPDict
    else:
        assert 0,'invalid type of sequence'

    # list out all of the different values we can have for
    # these partitions

    if(USE_DEBUG2):
        print('currentType: '+str(currentType))
        print('assignedIndices:')
        for a in sorted(assignedIndices.items(),key=operator.itemgetter(0)):
            print(str(a[0])+' -> '+str(a[1]))
        print('currentPartitions: '+str(currentPartitions))

    # so that we can rebuild the indices later
    assignedInOrder = []

    forIteration = []
    for j,p in enumerate(currentPartitions):
        if(len(currentType) > 1 and currentType[1][j][1] in assignedIndices):
            assignedInOrder.append(assignedIndices[currentType[1][j][1]])
            continue

        assignedInOrder.append(-1)
        adding = []
        for i,_x in enumerate(p):
            if(_x != 0):
                adding.append([_x,i])
        forIteration.append(adding)

    if(USE_DEBUG2):
        print('forIteration: '+str(forIteration))

    key = str(currentType[0]+str(forIteration))
    if(key in plshelp):
        # assert 0
        return plshelp[key]

    allIndices = [x for x in itertools.product(*forIteration)]

    if(USE_DEBUG2):
        print('allIndices: '+str(allIndices))

    totalCount = 0
    aboveZero = 0
    def multVal(aList):
        if(len(aList) == 0):
            return 1
        return aList[0][0]*multVal(aList[1:])
    for a in allIndices:
        # print('a: '+str(a))
        # assert 0
        val = multVal(a)
        totalCount += val
        theIndices = []
        count = 0
        for x in assignedInOrder:
            if(x == -1):
                theIndices.append(a[count][1])
                count += 1
            else:
                theIndices.append(x)
        # theIndices = tuple([x[1] for x in a])
        if(valsDict[str(tuple(theIndices))] > 0):
            aboveZero += val

    plshelp[key] = [aboveZero,totalCount]

    return aboveZero,totalCount

def updatePartitionRatios(typeString,currentPartitions,partitionRatios,assignedIndices={}):

    if(USE_DEBUG2):
        print('currentPartitions: '+str(currentPartitions))

    numbNonZero,totalNumb = calcProbOfZero(typeString,currentPartitions,assignedIndices=assignedIndices)

    if(USE_DEBUG2):
        print('Number of non zero vals: '+str(numbNonZero)+'/'+str(totalNumb))

    typePartitionString2 = str(typeString)+str(currentPartitions)
    if(typePartitionString2 not in partitionRatios):
        partitionRatios[typePartitionString2] = [numbNonZero,totalNumb]
    else:
        assert [numbNonZero,totalNumb] == partitionRatios[typePartitionString2], 'Look here'
