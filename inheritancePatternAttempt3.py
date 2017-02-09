# PLAN:
# 1) Generate the types
# 2) Generate setInfo
# 3) Make a function that iterates over possible orderings of for setInfo
#       (called setVals)
# 4) Make a function that checks if the current setVal is worth iterating over
#       (this is because some types might always evaluate to 0, or will have
#        a high probability of evaluating to 0)
# 5) Make a function that recurses on the tree to calculate the actual val
# 6) Add in the dynamic programming part after

# Overview of speedups:
#   - Ignore setVals that have a high probability of having a sum of 0 (done in setValsIterator)
#   - Use dynamic programming on setVals at every depth (done in generateSumForSetVal)

import os
import operator
import itertools
import math
import random
from generateTypes import *
from model import *
from bruteForce import *
import time
# from toCheckProbabilityThing import *

# SET RANDOM SEED TO A KNOWN NUMBER SO THAT WE CAN REPLICATE THE RESULTS!!!!!

jsonFolderPath = '/Users/Eddie/kec-bot/app/pedigreeData'

BRUTE_FORCE = False
USE_TEST = False

def cleanRun():
    def shadingAD(person):
        if(len(person.diagnoses) > 0):
            return 'yes'
        else:
            return 'no'

    funcToUse = shadingAD

    allPedigrees = []
    for filename in os.listdir(jsonFolderPath):
        if('.json' in filename):
            if(USE_TEST):
                filename = 'test.json'
            print('The current filename is: '+str(filename))
            with open(os.path.join(jsonFolderPath, filename)) as data_file:
                data = json.loads(json.load(data_file))
                pedigreeAdding = Pedigree(data)
                pedigreeAdding.setAffectedFunctions(funcToUse)
                allPedigrees.append(pedigreeAdding)
                break

    pedigree = allPedigrees[0]
    types,setMappings = getTypes(pedigree)
    print('\ntypes:')
    for t in types:
        print(t)
    print('\n')

    if(BRUTE_FORCE):
        finalAns = bruteForce(types)
    else:
        finalAns = calcSum(types,EPSILON=0.0)


def runThisFunction():
    def shadingAD(person):
        if(len(person.diagnoses) > 0):
            return 'yes'
        else:
            return 'no'

    funcToUse = shadingAD

    allPedigrees = []
    for filename in os.listdir(jsonFolderPath):
        if('.json' in filename):
            if(USE_TEST):
                filename = 'test.json'
            print('The current filename is: '+str(filename))
            with open(os.path.join(jsonFolderPath, filename)) as data_file:
                data = json.loads(json.load(data_file))
                pedigreeAdding = Pedigree(data)
                pedigreeAdding.setAffectedFunctions(funcToUse)
                allPedigrees.append(pedigreeAdding)
                break

    pedigree = allPedigrees[0]

    # get the types for the pedigree
    # types are the terms that we need to sum over
    # a type has a count tuple which describes what 
    # sets it can pull its corresponding indices from
    # which determine what its value will be
    types,setMappings = getTypes(pedigree)

    # print('Final types:')
    # for t in types:
    #     descriptiveString = ''
    #     for _t in t[1]:
    #         for k,v in setMappings.items():
    #             if(v[0] == _t[0]):
    #                 if(_t != t[1][-1]):
    #                     descriptiveString += str(k.split(',')[0])+' '
    #                 else:
    #                     descriptiveString += str(k.split(',')[0])

    #     print(str(t)+' (In terms of person id: ['+str(descriptiveString))+'])'

    print('\ntypes:')
    for t in types:
        print(t)
    print('\n')
    # print('All set mappings:')
    # for k,v in setMappings.items():
    #     print(str(k)+' -> '+str(v))
    
    # calcSum will calculate the sum over all of the possible types
    # types = customTypes()

    finalAns = calcSum(types,EPSILON=0.0)
    # finalAns = bruteForce(types)

    # P.hist(np.array(allRatios), bins = 20)
    # P.show()

    # numbIters = 7
    # _min = 0.0
    # _max = 0.5
    # allAns = []
    # for EPSILON in range(0,numbIters):
    #     EPSILON = float(EPSILON)*(_max-_min)/(numbIters-1)+_min
    #     ans,iterations = calcSum(types,EPSILON)
    #     allAns.append([EPSILON,ans,iterations])

    # for a in allAns:
    #     print a


def customTypes():
    buckets = [
            ['g',[[0,0],[0,1],[1,2]]],
            ['g',[[1,3],[1,4],[2,5]]],
            ['g',[[0,1],[1,4],[2,6]]]
            ]
    return buckets

start = time.time()
# runThisFunction()
cleanRun()

end = time.time()
print('\n\nTotal time: '+str(end - start))

