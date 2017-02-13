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


jsonFolderPath = '/Users/Eddie/kec-bot/app/pedigreeData'

USE_TEST = True

CHECKPOINT = 10000
STOCHASTIC = True
WRITE_RESULTS = True
NUM_SAMPLES = 2000000


       # Counter(vector<pair<unsigned,unsigned>> initialCounter,unsigned maxSamples);
        # vector<pair<unsigned,unsigned>> counter;
        # bool stochasticChoice();


cdef extern from "stochasticSum.h" namespace "std":
    void c_bruteForce(vector[pair[string,vector[pair[unsigned,unsigned]]]],unsigned,unsigned)


# ['n', [[0, 0], [1, 3]]]
# ['n', [[2, 6], [3, 9]]]
# ['n', [[4, 12], [5, 15]]]
# ['g', [[4, 12], [0, 1], [1, 4]]]
# ['g', [[5, 15], [2, 7], [3, 10]]]
# ['n', [[6, 18], [7, 21]]]
# ['g', [[6, 18], [0, 2], [1, 5]]]
# ['g', [[7, 21], [2, 8], [3, 11]]]


cdef class PyStochasticSum:
    cdef vector[pair[string,vector[pair[unsigned,unsigned]]]] *types
    cdef unsigned checkpoint,numSamples

    def __cinit__(self,object types_,unsigned checkpoint_,unsigned numSamples_):
        self.checkpoint = checkpoint_
        self.numSamples = numSamples_

        self.types = new vector[pair[string,vector[pair[unsigned,unsigned]]]]()
        for t in types_:      
            string name = t[0]
            vector[pair[unsigned,unsigned]] indices;
            for _t in t[1]:
                pair[unsigned,unsigned] adding
                adding.first = _t[0]
                adding.second = _t[1]
                indices.push_back(adding)

            pair[string,vector[pair[unsigned,unsigned]]] currentPair
            currentPair.first = name
            currentPair.second = indices
            self.types.push_back(currentPair)

    def __dealloc__(self):
        del self.types

    def run(self):
        c_bruteForce(self.types,self.checkpoint,self.numSamples)


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
                filename = 'test_7.json'
            print('The current filename is: '+str(filename))
            with open(os.path.join(jsonFolderPath, filename)) as data_file:
                data = json.loads(json.load(data_file))
                pedigreeAdding = Pedigree(data)
                pedigreeAdding.setAffectedFunctions(funcToUse)
                allPedigrees.append(pedigreeAdding)
                break

    pedigree = allPedigrees[0]
    types,setMappings = getTypes(pedigree)

    summer = PyStochasticSum(types,CHECKPOINT,NUM_SAMPLES)
    summer.run()

start = time.time()
runThisFunction()

end = time.time()
print('\n\nTotal time: '+str(end - start))

