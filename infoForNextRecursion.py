import os
import operator
import itertools
import math
import random
from vals import *
from preprocess import *
from partitionIterator import *


USE_DEBUG = False
DYNAMIC_PROGRAMMING = True
RATIO_TEST = True

def getInfoHelper(depth,currentType_1,remainingPartitions,runningAns,assignedIndices,partitionRatios,dynamicSpeedup,otherInfo):

    if(len(currentType_1) == 0):
        return [runningAns]

    otherInfo['subCount'] += 1


    infoHelperString = str(depth)+','+str(currentType_1)+','+str(remainingPartitions)+','+str(runningAns)+','+str(assignedIndices)
    if(DYNAMIC_PROGRAMMING and infoHelperString in dynamicSpeedup):
        otherInfo['infoHelperStringUsed'] += 1
        return dynamicSpeedup[infoHelperString]

    setNumber,uVal = currentType_1[0]
    partition = remainingPartitions[0]

    if(USE_DEBUG):
        print('\n====================================================\nremainingPartitions: '+str(remainingPartitions))
        print('depth: '+str(depth))
        print('partition: '+str(partition))
        print('runningAns: '+str(runningAns))

    if(uVal in assignedIndices):
        newRunningAns = list(runningAns)
        newRunningAns.append([assignedIndices[uVal],list(partition)])

        infoHelperStringDownOne = str(depth+1)+','+str(currentType_1[1:])+','+str(remainingPartitions[1:])+','+str(newRunningAns)+','+str(assignedIndices)
        if(DYNAMIC_PROGRAMMING and infoHelperStringDownOne in dynamicSpeedup):
            otherInfo['infoHelperStringUsed'] += 1
            theAns = dynamicSpeedup[infoHelperStringDownOne]
        else:
            theAns = getInfoHelper(depth+1,currentType_1[1:],remainingPartitions[1:],newRunningAns,assignedIndices,partitionRatios,dynamicSpeedup,otherInfo)
            dynamicSpeedup[infoHelperStringDownOne] = theAns

        return theAns

    else:
        allPossible = []

        for i,val in enumerate(partition):
            if(val > 0):
                newPartition = list(partition)
                newPartition[i] -= 1
                newRunningAns = list(runningAns)
                newRunningAns.append([i,newPartition])

                newRemainingPartitions = list(remainingPartitions[1:])

                # check the remaining partitions for the same setNumb
                for j,c in enumerate(currentType_1[1:]):
                    if(c[0] == setNumber):
                        newRemainingPartitions[j] = newPartition

                infoHelperStringDownOne = str(depth+1)+','+str(currentType_1[1:])+','+str(newRemainingPartitions)+','+str(newRunningAns)+','+str(assignedIndices)
                if(DYNAMIC_PROGRAMMING and infoHelperStringDownOne in dynamicSpeedup):
                    otherInfo['infoHelperStringUsed'] += 1
                    currentPossibility = dynamicSpeedup[infoHelperStringDownOne]
                else:
                    currentPossibility = getInfoHelper(depth+1,currentType_1[1:],newRemainingPartitions,newRunningAns,assignedIndices,partitionRatios,dynamicSpeedup,otherInfo)
                    dynamicSpeedup[infoHelperStringDownOne] = currentPossibility

                # if there is a partition with the same setNumb in the currentPossibility, update
                # the runningAns accordingly
                if(USE_DEBUG):
                    print('\ncurrentPossibility: '+str(currentPossibility))
                newCurrentPossibility = list(currentPossibility)
                for anIndex,legitCurrentPossibility in enumerate(currentPossibility):
                    if(USE_DEBUG):
                        print('legitCurrentPossibility: '+str(legitCurrentPossibility))
                    for j,c in enumerate(reversed(currentType_1[1:])):
                        if(c[0] == setNumber):
                            k = len(legitCurrentPossibility)-1-j
                            if(USE_DEBUG):
                                print('c: '+str(c))
                                print('k: '+str(k))
                            newCurrentPossibility[anIndex][depth] = legitCurrentPossibility[k]
                            break

                if(USE_DEBUG):
                    print('newCurrentPossibility: '+str(newCurrentPossibility))

                allPossible.extend(newCurrentPossibility)
        
        dynamicSpeedup[infoHelperString] = allPossible
        return allPossible

def getInfoForNextRecursion(remainingTypes,currentPartitions,assignedIndices,partitionRatios,useBaseCase,dynamicSpeedup,otherInfo):

    currentType = remainingTypes[0]
    if(USE_DEBUG):
        print('-------------------------------------')
        print('remainingTypes: '+str(remainingTypes))
        print('currentPartitions: '+str(currentPartitions))
        print('assignedIndices: '+str(assignedIndices))
        print('useBaseCase: '+str(useBaseCase))


    # for the current type, assign all possible values to it and update
    # partitions and assigned indices accordingly

    # have to narrow down from vals which values we should recurse on and
    # update the index counts for currentPartitions
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

    relevantPartitions = [currentPartitions[i[0]] for i in currentType[1]]

    if(USE_DEBUG):
        print('relevantPartitions: '+str(relevantPartitions))

    # have to choose a number from each partition for an index

    if(USE_DEBUG):
        print('~~~~~~~~~\n')
    possibleIndices = getInfoHelper(0,currentType[1],relevantPartitions,[],assignedIndices,partitionRatios,dynamicSpeedup,otherInfo)
    if(USE_DEBUG):
        print('\n~~~~~~~~~')


    if(USE_DEBUG):
        print('possibleIndices: ')
        for p in possibleIndices:
            print(p)

    # assert len(possibleIndices) == 1

    ans = []
    alreadyUsed = {}
    for index,x in enumerate(possibleIndices):

        indices = [_x[0] for _x in x]
        val = valsDict[str(tuple(indices))]

        if(useBaseCase):
            assert len(possibleIndices) == 1,'val is: '+str(val)+'\npossibleIndices is:\n'+str(possibleIndices)
            return val
        newPartitions = list(currentPartitions)
        for ip,typeIndices in zip(x,currentType[1]):
            chosenIndex,partition = ip
            typeIndex,uVal = typeIndices
            newPartitions[typeIndex] = partition
        newAssignedIndices = dict(assignedIndices)
        for uVal,i in zip([x[1] for x in currentType[1]],indices):
            assert uVal not in newAssignedIndices or newAssignedIndices[uVal] == i
            newAssignedIndices[uVal] = i


        # check to see if it is worth going down this branch
        if(not RATIO_TEST or ratioTest2(newPartitions,remainingTypes[1:],newAssignedIndices,EPSILON=0.0) == -1):
            usedString = str(newPartitions)+','+str(newAssignedIndices)
            if(usedString in alreadyUsed):
                ans[alreadyUsed[usedString]][0] += val
            else:
                alreadyUsed[usedString] = index
                ans.append([val,newPartitions,newAssignedIndices])

    if(USE_DEBUG):
        print('ans: '+str(ans))
        # assert 0
        print('-------------------------------------')

    return ans