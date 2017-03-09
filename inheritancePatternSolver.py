import os
import operator
import itertools
import math
import random
from generateTypes import *
from model import *
from visualizeTreeGeneral import *
from ipTreeGMP import *
# from ipTree import *
import time
import gmpy2


USE_TEST = True
FILENAME = 'test.json'

VISUALIZE = False
CALC_PROB = True


def probandShading(person):
    assert 0
    if(len(person.diagnoses) > 0):
        return 'yes'
    else:
        return 'no'

def autosomeProblemWrong():
    g = [
          [[1. ,0.5 ,0. ],
           [0.5,0.25,0. ],
           [0. ,0.  ,0. ]],
  
          [[0. ,0.5 ,1. ],
           [0.5,0.5 ,0.5],
           [1. ,0.5 ,0. ]],
  
          [[0. ,0.  ,0. ],
           [0. ,0.25,0.5],
           [0. ,0.5 ,1. ]]
        ]
    m = 2
    n = 3
    return n,m,g

def autosomeProblem():
    g = [
          [[1.  ,0.5 ,0.5 ,0. ],
           [0.5 ,0.25,0.25,0. ],
           [0.5 ,0.25,0.25,0. ],
           [0.0 ,0.  ,0.  ,0. ]],
  
          [[0.  ,0.5 ,0.5 ,1. ],
           [0.  ,0.25,0.25,0.5],
           [0.  ,0.25,0.25,0.5],
           [0.  ,0.  ,0.  ,0. ]],
  
          [[0.  ,0.  ,0.  ,0. ],
           [0.5 ,0.25,0.25,0. ],
           [0.5 ,0.25,0.25,0. ],
           [1.  ,0.5 ,0.5 ,0. ]],

          [[0.  ,0.  ,0.  , 0.],
           [0.  ,0.25,0.25,0.5],
           [0.  ,0.25,0.25,0.5],
           [0.  ,0.5 ,0.5 ,1. ]]
        ]
    m = 3
    n = 4
    return n,m,g

def runThisFunction(jsonFolderPath = '/Users/Eddie/kec-bot/app/pedigreeData'):

    shadingFunction = probandShading
    # problemContext = autosomeProblemWrong
    problemContext = autosomeProblem

    allPedigrees = []
    for filename in os.listdir(jsonFolderPath):
        if('.json' in filename):
            if(USE_TEST):
                filename = FILENAME

            completeFileName = os.path.join(jsonFolderPath,filename)

            pedigreeClass = initPedigree(completeFileName,shadingFunction,problemContext,'dominant')

            if(VISUALIZE):
                visualizeComputation(pedigreeClass)

            if(CALC_PROB):
                num_samples = 50000
                checkpoint = 100
                printCheckpoint = 1000
                calcProb(pedigreeClass,num_samples,checkpoint,printCheckpoint,False,filename)

            break

def initADProb(filename,jsonFolderPath='/Users/Eddie/kec-bot/app/pedigreeData'):
    shadingFunction = probandShading
    problemContext = autosomeProblem
    pedigreeClass = initPedigree(os.path.join(jsonFolderPath,filename),shadingFunction,problemContext,'dominant')
    return pedigreeClass

def initARProb(filename,jsonFolderPath='/Users/Eddie/kec-bot/app/pedigreeData'):
    shadingFunction = probandShading
    problemContext = autosomeProblem
    pedigreeClass = initPedigree(os.path.join(jsonFolderPath,filename),shadingFunction,problemContext,'recessive')
    return pedigreeClass

def initPedigree(filename,shadingFunction,problemContext,dominantOrRecessive):
    pedigreeClass = PyPedigree()
    pedigreeClass.parsePedigree(filename,shadingFunction,problemContext,dominantOrRecessive)
    return pedigreeClass

def visualizeComputation(pedigreeClass):
    n = pedigreeClass.get_n()
    m = pedigreeClass.get_m()
    g = pedigreeClass.get_g()
    roots = pedigreeClass.get_roots()
    allTypes = pedigreeClass.get_allTypes()
    filename = pedigreeClass.get_filename()
    pedigree = pedigreeClass.get_pedigree()
    numbRoots = len(pedigree.roots)
    visualize(roots,allTypes,numbRoots,n)

def calcProb(pedigreeClass,num_samples,checkpoint,printCheckpoint,writeToFile,filename):

    data = pedigreeClass.calculateProbability(num_samples,checkpoint,printCheckpoint)

    if(writeToFile):
        data['name'] = 'data_'+filename
        with open('./stochasticData/'+data['name'], 'w') as file:
            json.dump(data,file)


def mainFunction():
    start = time.time()
    runThisFunction()

    end = time.time()
    print('\n\nTotal time: '+str(end - start))

mainFunction()
