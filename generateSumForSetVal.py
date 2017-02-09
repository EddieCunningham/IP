import os
import operator
import itertools
import math
import random
from infoForNextRecursion import *

SKIP_ZEROS = True

def genRecur(types,currentPartitions,assignedIndices,partitionRatios,depth,dynamicSpeedup,otherInfo):
    # return 0
    otherInfo['outerCount'] += 1
    # print(currentPartitions)

    remainingTypes = types[depth:]

    if(depth == len(types)-1):
        return getInfoForNextRecursion(remainingTypes,currentPartitions,assignedIndices,partitionRatios,True,dynamicSpeedup,otherInfo)

    ans = 0
    for mult,newPartitions,newAssignedIndices in getInfoForNextRecursion(remainingTypes,currentPartitions,assignedIndices,partitionRatios,False,dynamicSpeedup,otherInfo):

        otherInfo['totalMult'] += 1
        if(mult != 0):
            otherInfo['nonZeroMult'] += 1
        elif(SKIP_ZEROS and mult == 0):
            continue

        genRecurVal = genRecur(types,newPartitions,newAssignedIndices,partitionRatios,depth+1,dynamicSpeedup,otherInfo)
        ans += mult*genRecurVal

    return ans


def calculateSumForSets(types,currentPartitions,assignedIndices,partitionRatios,dynamicSpeedup,otherInfo):

    # genRecur will go through the tree and sum all the possibilities
    finalAns = genRecur(types,currentPartitions,assignedIndices,partitionRatios,0,dynamicSpeedup,otherInfo)    

    return finalAns










