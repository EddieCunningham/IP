import os
import operator
import itertools
import math
import random
from generateTypes import *
from model import *
import time
from libcpp.vector cimport vector
from libcpp.pair cimport pair
from libcpp.string cimport string
from libcpp.unordered_map cimport unordered_map


jsonFolderPath = '/Users/Eddie/kec-bot/app/pedigreeData'


cdef extern from "stochasticSum.h" namespace "std":
    unordered_map[int,double] c_bruteForce(vector[pair[string,vector[pair[int,int]]]],int,int)


cdef class PyStochasticSum:
    cdef vector[pair[string,vector[pair[int,int]]]] types
    cdef int checkpoint,numSamples
    cdef unordered_map[int,double] returnDict

    def __cinit__(self,types_,int checkpoint_,int numSamples_):
        self.checkpoint = checkpoint_
        self.numSamples = numSamples_
        self.types = types_

    def run(self):
        self.returnDict = c_bruteForce(self.types,self.checkpoint,self.numSamples)

    def getOutput(self):
        return dict(self.returnDict)

def shadingAD(person):
    if(len(person.diagnoses) > 0):
        return 'yes'
    else:
        return 'no'

# def runThisFunction():

#     funcToUse = shadingAD

#     allPedigrees = []
#     for filename in os.listdir(jsonFolderPath):
#         if('.json' in filename):
#             if(USE_TEST):
#                 filename = 'test_7.json'
#             print('The current filename is: '+str(filename))
#             with open(os.path.join(jsonFolderPath, filename)) as data_file:
#                 data = json.loads(json.load(data_file))
#                 pedigreeAdding = Pedigree(data)
#                 pedigreeAdding.setAffectedFunctions(funcToUse)
#                 allPedigrees.append(pedigreeAdding)
#                 break

#     pedigree = allPedigrees[0]
#     types,setMappings = getTypes(pedigree)
#     getApproxSum(types)

def getSumForFile(filename,checkpoint,numSamples):

    funcToUse = shadingAD

    with open(os.path.join(jsonFolderPath, filename)) as data_file:
        data = json.loads(json.load(data_file))
        pedigree = Pedigree(data)
        pedigree.setAffectedFunctions(funcToUse)

    types,setMappings = getTypes(pedigree)
    getApproxSum(types,checkpoint,numSamples,filename)

def getApproxSum(types,checkpoint,numSamples,filename):

    theSumFunc = PyStochasticSum(types,checkpoint,numSamples)
    theSumFunc.run()
    data = theSumFunc.getOutput()

    numUniqueIndices = 0
    uniqueMapping = {}
    for t in types:
        for _t in t[1]:
            if(_t[1] not in uniqueMapping):
                uniqueMapping[_t[1]] = numUniqueIndices
                numUniqueIndices += 1

    data['name'] = 'data_'+filename
    data['types'] = types
    data['totalNumTerms'] = 3**numUniqueIndices

    with open('./stochasticData/'+data['name'], 'w') as file:
        json.dump(data, file)


# start = time.time()
# runThisFunction()

# end = time.time()
# print('\n\nTotal time: '+str(end - start))

