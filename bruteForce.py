import os
import operator
import itertools
import math
import random
from vals import *

def bruteForce(types):
    numUniqueIndices = 0
    uniqueMapping = {}
    for t in types:
        for _t in t[1]:
            if(_t[1] not in uniqueMapping):
                uniqueMapping[_t[1]] = numUniqueIndices
                numUniqueIndices += 1

    total = 3**numUniqueIndices
    print('Total terms: '+str(total))

    count = {'count':0}
    checkpoint = 0.0
    ans = 0
    for i in itertools.product([0,1,2], repeat=numUniqueIndices):
        count['count'] += 1
        if(count['count']/float(total) > checkpoint):
            print(checkpoint)
            checkpoint += 0.0001

        val = 1
        for t in types:
            indices = [i[uniqueMapping[_t[1]]] for _t in t[1]]
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
        ans += val

    print('ans: '+str(ans))
    print('count: '+str(count['count']))