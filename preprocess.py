import os
import operator
import itertools
import math
import random
from partitionIterator import *

USE_DEBUG3 = False


def partitionGenerator(current,allPartitions):
    # return all of the possible partitions of a number
    c1,c2,c3 = current
    if(c1 < 0 or c2 < 0 or c3 < 0):
        return
    if(str(current) not in allPartitions):
        allPartitions[str(current)] = 1
    else:
        return
    partitionGenerator([c1-1,c2+1,c3],allPartitions)
    partitionGenerator([c1-1,c2,c3+1],allPartitions)
    partitionGenerator([c1,c2-1,c3+1],allPartitions)
    partitionGenerator([c1+1,c2-1,c3],allPartitions)
    partitionGenerator([c1+1,c2,c3-1],allPartitions)
    partitionGenerator([c1,c2+1,c3-1],allPartitions)


def preprocessSetInfo(setInfo,types):
    if(USE_DEBUG3):
        print('\n\nsetInfo: ')
        for k,v in setInfo.items():
            print(str(k)+' -> '+str(v))
        print('\n\ntypes: ')
        for t in types:
            print(t)

    # generate all of the setPartitions
    # this is all of the <setCount, 3> partitions for each set
    setPartitions = []
    for key,value in sorted(setInfo.items(),key=operator.itemgetter(0)):
        start = [value['count'],0,0]
        allPartitions = {}
        partitionGenerator(start,allPartitions)
        actualPartitions = [eval(k) for k,v in allPartitions.items()]
        actualPartitions = sorted(actualPartitions)
        setPartitions.append(actualPartitions)


    # remove all of the partitions that have a high probability of having a sum of 0
    partitionRatios = reducePartitions(types,setPartitions)

    return setPartitions,partitionRatios
    
def reducePartitions(types,setPartitions):

    partitionRatios = {}

    # should keep track of the unique [type,relevantPartitions]
    # so that we don't have to repeat work
    uniqueTypeAndRelevantPartition = {}

    print('\n\nsetPartitions:')
    for s in setPartitions:
        print(str(s))

    for index,currentType in enumerate(types):

        relevantPartitions = [str(setPartitions[i]) for i in [x[0] for x in currentType[1]]]
        typeAndPartitionString = currentType[0]+str(relevantPartitions)

        if(typeAndPartitionString not in uniqueTypeAndRelevantPartition):
            uniqueTypeAndRelevantPartition[typeAndPartitionString] = [index]
        else:
            uniqueTypeAndRelevantPartition[typeAndPartitionString].append(index)

    print('\n\nuniqueTypeAndRelevantPartition:')
    for k,v in uniqueTypeAndRelevantPartition.items():
        print('The unique type '+str(k)+' is seen at type indices: '+str(v))

    # next need to figure out which of the items in the relevant 
    # partitions will most likely result in 0
    if(USE_DEBUG3):
        print('\n\n--------------- Entering loop --------------')

    for k,v in uniqueTypeAndRelevantPartition.items():
        typeString = k[0]

        partitionsForIndices = [eval(x) for x in eval(k[1:])]

        print('\ntype: '+str(typeString))
        if(USE_DEBUG3):
            print('partitionsForIndices: '+str(partitionsForIndices))

        # will hash a string of the product tracker
        productTracker = [[0,len(p)] for p in partitionsForIndices]
        productTracker[-1][0] = -1
        theCounter = counter(productTracker)

        if(USE_DEBUG3):
            print('\n\n-------------- Entering product loop ---------------\n\n')
        # while(incrementCounter(productTracker,-1)):
        #     currentPartitions = [partitionsForIndices[i][j[0]] for i,j in enumerate(productTracker)]
        while(theCounter.incrementCounter(-1)):
            currentPartitions = [partitionsForIndices[i][j[0]] for i,j in enumerate(theCounter.productCounter)]
            
            updatePartitionRatios(typeString,currentPartitions,partitionRatios)

        if(USE_DEBUG3):
            print('\n\n-------------- Exiting product loop ---------------\n\n')

        if(USE_DEBUG3):
            def mult(vals):
                if(len(vals) == 0):
                    return 1
                return float(vals[0])*mult(vals[1:])
            allLoops = mult([len(p) for p in partitionsForIndices])
        
            print('totalTerms: '+str([[int(allLoops/len(p)) for _p in p] for p in partitionsForIndices]))

    print('\n\n--------------- Exiting loop --------------')

    if(USE_DEBUG3):
        print('partitionRatios:')
        for k,v in partitionRatios.items():
            print(str(k)+' -> '+str(v))

    return partitionRatios




