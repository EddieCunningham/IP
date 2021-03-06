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
    unordered_map[int,double] c_bruteForce(int,vector[pair[string,vector[pair[int,int]]]],int,int)


cdef class PyStochasticSum:
    cdef vector[pair[string,vector[pair[int,int]]]] types
    cdef int checkpoint,numSamples,numbRoots
    cdef unordered_map[int,double] returnDict

    def __cinit__(self,numbRoots_,types_,int checkpoint_,int numSamples_):
        self.numbRoots = numbRoots_
        self.checkpoint = checkpoint_
        self.numSamples = numSamples_
        self.types = types_

    def run(self):
        self.returnDict = c_bruteForce(self.numbRoots,self.types,self.checkpoint,self.numSamples)

    def getOutput(self):
        return dict(self.returnDict)

def shadingAD(person):
    if(len(person.diagnoses) > 0):
        return 'yes'
    else:
        return 'no'

def getSumForFile(filename,checkpoint,numSamples):

    funcToUse = shadingAD

    with open(os.path.join(jsonFolderPath, filename)) as data_file:
        data = json.loads(json.load(data_file))
        pedigree = Pedigree(data)
        pedigree.setAffectedFunctions(funcToUse)

    types,setMappings = getTypes(pedigree)
    getApproxSum(len(pedigree.roots),types,checkpoint,numSamples,filename)

def getApproxSum(numbRoots,types,checkpoint,numSamples,filename):

    theSumFunc = PyStochasticSum(numbRoots,types,checkpoint,numSamples)
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

