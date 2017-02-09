import os
import operator
import itertools
import math
import random
from preprocess import *
from partitionIterator import *
from generateSumForSetVal import *

PRINT_PARTITION = True
PRINT_RATIO = False


def calcSum(types,EPSILON=0.0):

    # first we build the information needed for the sets
    # that we pull indices from
    uniqueSets = []
    for thestr,indices in types:
        for i,uVal in indices:
            if([i,uVal] not in uniqueSets):
                uniqueSets.append([i,uVal])

    # set info has all the info we need
    setInfo = {}
    for u in uniqueSets:
        if(u[0] not in setInfo):
            setInfo[u[0]] = {'count':1,'uVals':[u[1]]}
        else:
            setInfo[u[0]]['count'] += 1
            setInfo[u[0]]['uVals'].append(u[1])


    print('\n\nsetInfo:')
    for k,v in setInfo.items():
        print(str(k)+' -> '+str(v))
    # assert 0

    # outsource the work to figure out what sets to 
    # use to a different function
    assignedIndices = {}
    dynamicSpeedup = {}
    otherInfo = {'outerCount':0,'subCount':0,'infoHelperStringUsed':0,'nonZeroMult':0,'totalMult':0}
    totalAns = 0
    totalNonZero = 0

    # setValsIterator gives us the next set of values that
    # we should use to calculate the sum for.  Note that some 
    # sets might be skipped.  For example, if a type will always 
    # return 0, or theres a high chance that a type will always return
    # 0, then we will skip over the setVal.
    # For each setVal, we can must sum over all possible assignments to 
    # the indices of each type


    # productCounter is keeps track of the current state of the setValsIterator
    setPartitions,partitionRatios = preprocessSetInfo(setInfo,types)
    productCounter = [[0,len(p)] for p in setPartitions]

    print('setPartitions:')
    for s in setPartitions:
        print(s)
    # print('partitionRatios: '+str(partitionRatios))
    # assert 0

    totalTerms = 0
    while(True):
        currentPartition = partitionIterator(setPartitions,partitionRatios,types,productCounter,dynamicSpeedup,otherInfo,EPSILON)
        if(currentPartition == 'continue'):
            continue

        if(not currentPartition):
            break

        ans = calculateSumForSets(types,currentPartition,assignedIndices,partitionRatios,dynamicSpeedup,otherInfo)

        totalTerms += 1
        if(ans != 0):
            totalNonZero += 1

        zeroRatio = '%4d / %4d -> %.4f'%(otherInfo['nonZeroMult'],otherInfo['totalMult'],float(otherInfo['nonZeroMult'])/float(otherInfo['totalMult']))

        if(PRINT_RATIO):
            total = getTotal(productCounter)
            print(str(total[0])+' / '+str(total[1])+' -> '+str(float(total[0])/total[1])+' : '+zeroRatio)

        if(PRINT_PARTITION):
            print('productCounter: '+str(productCounter)+' ans: '+str(ans)+' : '+zeroRatio)

        totalAns += ans
    
    print('\n\nFinal result: '+str(totalAns))
    print('Total number of non zero values: '+str(totalNonZero)+' / '+str(totalTerms)+' -> '+str(float(totalNonZero)/float(totalTerms)))
    print('Total size of dynamic speedup: '+str(len(dynamicSpeedup)))
    print('Number of recursions: '+str(otherInfo['outerCount']))
    print('Number of total recursions: '+str(otherInfo['subCount']))
    print('nonZeroMult: '+str(otherInfo['nonZeroMult'])+' / '+str(otherInfo['totalMult'])+' -> '+str(float(otherInfo['nonZeroMult'])/float(otherInfo['totalMult'])))
    print('Number of times dynamic programming for infoHelperString: '+str(otherInfo['infoHelperStringUsed']))



    return totalAns,otherInfo['subCount']




