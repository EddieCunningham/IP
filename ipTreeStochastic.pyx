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


cdef extern from "treeStochasticSum.h" namespace "std":
    pair[int,unordered_map[int,double]] getValues(int,vector[pair[string,vector[pair[int,int]]]],int,int)


cdef class PyTreeStochasticSum:
    cdef vector[pair[string,vector[pair[int,int]]]] types
    cdef int checkpoint,numSamples,numbRoots
    cdef pair[int,unordered_map[int,double]] returnDict

    def __cinit__(self,numbRoots_,types_,int checkpoint_,int numSamples_):
        self.numbRoots = numbRoots_
        self.checkpoint = checkpoint_
        self.numSamples = numSamples_
        self.types = types_

    def run(self):
        self.returnDict = getValues(self.numbRoots,self.types,self.numSamples,self.checkpoint)

    def getOutput(self):
        totalNumTerms = self.returnDict.first
        theDict = dict(self.returnDict.second)
        return [totalNumTerms,theDict]

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

    theSumFunc = PyTreeStochasticSum(numbRoots,types,checkpoint,numSamples)
    theSumFunc.run()
    totalNumTerms,data = theSumFunc.getOutput()

    data['name'] = 'data_'+filename
    data['types'] = types
    data['totalNumTerms'] = totalNumTerms

    with open('./stochasticData/'+data['name'], 'w') as file:
        json.dump(data, file)


# start = time.time()
# runThisFunction()

# end = time.time()
# print('\n\nTotal time: '+str(end - start))

