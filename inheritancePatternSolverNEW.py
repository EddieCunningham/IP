import os
import operator
import itertools
import math
import random
from model import *
from ipNEW import *
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

CALC_PROB = True

PROBLEM = 'chromosome'
DOMINANT = 'recessive'


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

            pedigreeClass = PyPedigree()
            pedigreeClass.initialization(completeFileName,problemContext,dominantOrRecessive)

            if(CALC_PROB):
                pedigreeClass.calculateProbability()

            break


def initADProb(filename,jsonFolderPath='/Users/Eddie/kec-bot/app/pedigreeData'):
    problemContext = autosomeProblem
    pedigreeClass = PyPedigree()    
    pedigreeClass.initialization(os.path.join(jsonFolderPath,filename),problemContext,'dominant')
    return pedigreeClass

def initARProb(filename,jsonFolderPath='/Users/Eddie/kec-bot/app/pedigreeData'):
    problemContext = autosomeProblem
    pedigreeClass = PyPedigree()
    pedigreeClass.initialization(os.path.join(jsonFolderPath,filename),problemContext,'recessive')
    return pedigreeClass


def mainFunction():
    start = time.time()
    runThisFunction()

    end = time.time()
    print('\n\nTotal time: '+str(end - start))

mainFunction()
