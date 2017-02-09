import os
import operator
import itertools
import math
import random
from vals import *
from preprocess import *

USE_DEBUG2 = False
OUTER_RATIO_TEST = True
PRINT_EVERY_TIME = False


allRatios = []

def incrementCounter(counts,i):
    if(i < 0):
        i = len(counts)+i
    for j in range(i+1,len(counts)):
        counts[j][0] = 0

    while(i >= 0):
        index,maxIndex = counts[i]
        if(index == maxIndex-1):
            counts[i][0] = 0
            i -= 1
            continue
        counts[i][0] += 1
        return True
    return False


def partitionIterator(setPartitions,partitionRatios,types,productCounter,dynamicSpeedup,otherInfo,EPSILON=0.0):

    if(USE_DEBUG2):
        print('\ntypes: '+str(types))

    if(PRINT_EVERY_TIME):
        total = getTotal(productCounter)
        print(str(total[0])+' / '+str(total[1])+' -> '+str(float(total[0])/total[1]))
        print('productCounter: '+str(productCounter))

    currentPartitions = [setPartitions[i][j[0]] for i,j in enumerate(productCounter)]

    # see if the partitions we have have a high chance of being 0
    # if so, increment productCounter by 1
    indexToIncrement = ratioTest(currentPartitions,types,partitionRatios,EPSILON)

    if(OUTER_RATIO_TEST and indexToIncrement != -1):
        # this means that we failed the ratio test

        if(USE_DEBUG2):
            print('indexToIncrement: '+str(indexToIncrement))
        if(not incrementCounter(productCounter,indexToIncrement)):
            return False
        return 'continue'


    # then return the current partitions
    if(not incrementCounter(productCounter,-1)):
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

def getTotal(productCounter):
    current = 0
    multiplier = 1
    for p in reversed(productCounter):
        current += p[0]*multiplier
        multiplier *= p[1]

    return current,multiplier
