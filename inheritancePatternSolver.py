import os
import operator
import itertools
import math
import random
from generateTypes import *
from model import *
from visualizeTreeGeneral import *
from ipTreeGMPExtended import *
from getGHelper import *
import time
import gmpy2

# 3 confusion matrices

# human vs known correct
# algorithm vs human
# algorithm vs known correct

# add logging system

# papers with bullet points

USE_TEST = True
FILENAME = 'test.json'

VISUALIZE = False
CALC_PROB = True

PROBLEM = 'autosome'
DOMINANT = 'dominant'


def probandShading(person):
    assert 0
    if(len(person.diagnoses) > 0):
        return 'yes'
    else:
        return 'no'

def autosomeProblem():


    # AA, Aa, aA, aa
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

    allG = {}

    for x in itertools.product(['unknown','male','female'],repeat=3):
        left,right,child = x
        if((left == 'male' and right == 'male') or (left == 'female' and right == 'female')):
            continue
        key = left+','+right+'->'+child
        allG[key] = g

    allMN = {
        'unknown':[3,4],
        'female':[3,4],
        'male':[3,4]
    }

    return allMN,allG,'autosome'

def chromosomeProblem():

    # XX, XX_, X_X, XY, YX, X_X_, X_Y, YX_

    allG = {}

    for x in itertools.product(['unknown','male','female'],repeat=3):
        left,right,child = x
        if((left == 'male' and right == 'male') or (left == 'female' and right == 'female')):
            continue
        key = left+','+right+'->'+child
        val = generateGForChromosomeProblem(left,right,child)
        allG[key] = val

    allMN = {
        'unknown':[5,8],
        'female':[3,4],
        'male':[2,4]
    }

    return allMN,allG,'chromosome'

def runThisFunction(jsonFolderPath = '/Users/Eddie/kec-bot/app/pedigreeData'):

    shadingFunction = probandShading
    if(PROBLEM == 'autosome'):
        problemContext = autosomeProblem
    else:
        problemContext = chromosomeProblem
    if(DOMINANT == 'dominant'):
        dominantOrRecessive = 'dominant'
    else:
        dominantOrRecessive = 'recessive'

    allPedigrees = []
    for filename in os.listdir(jsonFolderPath):
        if('.json' in filename):
            if(USE_TEST):
                filename = FILENAME

            completeFileName = os.path.join(jsonFolderPath,filename)

            pedigreeClass = initPedigree(completeFileName,shadingFunction,problemContext,dominantOrRecessive)

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
    roots = pedigreeClass.get_roots()
    allTypes = pedigreeClass.get_allTypes()
    filename = pedigreeClass.get_filename()
    pedigree = pedigreeClass.get_pedigree()
    numbRoots = len(pedigree.roots)
    visualize(roots,allTypes,numbRoots)

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
