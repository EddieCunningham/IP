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
from smartWay import *
from visualizeTree import *
import time


jsonFolderPath = '/Users/Eddie/kec-bot/app/pedigreeData'

SMART_WAY = False

BRUTE_FORCE = True
USE_TEST = True
PRINT_TYPES = True

CHECKPOINT = 0.0
STOCHASTIC = False
WRITE_RESULTS = False
NUM_SAMPLES = 1000000


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
                filename = 'test_10.json'
            print('The current filename is: '+str(filename))
            with open(os.path.join(jsonFolderPath, filename)) as data_file:
                data = json.loads(json.load(data_file))
                pedigreeAdding = Pedigree(data)
                pedigreeAdding.setAffectedFunctions(funcToUse)
                allPedigrees.append(pedigreeAdding)
                break

    pedigree = allPedigrees[0]

    familySize = len(pedigree.family)

    # get the types for the pedigree
    # types are the terms that we need to sum over
    # a type has a count tuple which describes what 
    # sets it can pull its corresponding indices from
    # which determine what its value will be
    types,setMappings = getTypes(pedigree)

    if(PRINT_TYPES):
        print('Final types:')
        for t in types:
            descriptiveString = ''
            for _t in t[1]:
                for k,v in setMappings.items():
                    if(v[0] == _t[0]):
                        if(_t != t[1][-1]):
                            descriptiveString += str(k.split(',')[0])+' '
                        else:
                            descriptiveString += str(k.split(',')[0])

            print(str(t)+' (In terms of person id: ['+str(descriptiveString))+'])'

    print('\ntypes:')
    for t in types:
        print(t)
    print('\n')

    visualize(types)
    return

    # assert 0
    # print('All set mappings:')
    # for k,v in setMappings.items():
    #     print(str(k)+' -> '+str(v))
    
    # calcSum will calculate the sum over all of the possible types
    # types = customTypes()

    writeData = None

    if(SMART_WAY):
        finalAns = findAns(types)
    else:
        if(BRUTE_FORCE):
            writeData = bruteForce(familySize,types,d_checkpoint=CHECKPOINT,stochastic=STOCHASTIC,writeResults=WRITE_RESULTS,numSamples=NUM_SAMPLES,random_seed=RANDOM_SEED)
        else:
            finalAns = calcSum(types,d_checkpoint=CHECKPOINT,EPSILON=0.0,stochastic=STOCHASTIC,writeResults=WRITE_RESULTS,numSamples=NUM_SAMPLES,random_seed=RANDOM_SEED)

    if(writeData):
        writeData['name'] = 'data_'+filename
        writeData['types'] = types

        with open('./stochasticData/'+writeData['name'], 'w') as file:
            json.dump(writeData, file)


start = time.time()
runThisFunction()

end = time.time()
print('\n\nTotal time: '+str(end - start))

