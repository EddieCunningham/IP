import os
import operator
import itertools
import math
import random
from model import *
from ipNEW import *
from getGHelper import *
import time
import numpy as np
import gmpy2

# 3 confusion matrices

# human vs known correct
# algorithm vs human
# algorithm vs known correct

# add logging system

# papers with bullet points

FILENAME = 'test_13.json'

NUMB_CALLS = 100000

PRINT_ITERATIONS = False
PRINT_PEOPLE = False

PRINT_INDIVIDUAL_RESULTS = True


def runProblem(filename,problemContext,dominantOrRecessive,problemType):
    pedigreeClass = PyPedigree()
    pedigreeClass.initialization(filename,problemContext,dominantOrRecessive)
    contradiction,log_ans,log_stdev = pedigreeClass.calculateProbability(NUMB_CALLS,PRINT_ITERATIONS,PRINT_PEOPLE)

    if(contradiction == 1.0):
        contradiction = 'yes'
    else:
        contradiction = 'no'

    resultString = '\n'
    resultString += '\n'+str(problemType)+' results:'
    resultString += '\ncontradiction: '+str(contradiction)
    resultString += '\nans: '+str(np.exp(log_ans))
    resultString += '\nstdev: '+str(np.exp(log_stdev))
    return resultString,contradiction,np.exp(log_ans),np.exp(log_stdev)

def runXLRProb(filename):
    problemContext = chromosomeProblem
    dominantOrRecessive = 'recessive'
    return runProblem(filename,problemContext,dominantOrRecessive,'X-Linked Recessive')

def runXLDProb(filename):
    problemContext = chromosomeProblem
    dominantOrRecessive = 'dominant'
    return runProblem(filename,problemContext,dominantOrRecessive,'X-Linked Dominant')

def runARProb(filename):
    problemContext = autosomeProblem
    dominantOrRecessive = 'recessive'
    return runProblem(filename,problemContext,dominantOrRecessive,'Autosomal Recessive')

def runADProb(filename):
    problemContext = autosomeProblem
    dominantOrRecessive = 'dominant'
    return runProblem(filename,problemContext,dominantOrRecessive,'Autosomal Dominant')
    
def runThisFunction(jsonFolderPath = '/Users/Eddie/kec-bot/app/pedigreeData'):

    filename = os.path.join(jsonFolderPath,FILENAME)
    print('Running solver on XLR problem')
    resultXLR,contradictionXLR,ansXLR,stdevXLR = runXLRProb(filename)

    print('\n---------------\nRunning solver on AR problem')
    resultAR,contradictionAR,ansAR,stdevAR = runARProb(filename)

    print('\n---------------\nRunning solver on AD problem')
    resultAD,contradictionAD,ansAD,stdevAD = runADProb(filename)
    
    print('\n---------------\n')

    total = 0

    if(contradictionXLR != 'yes'):
        if(PRINT_INDIVIDUAL_RESULTS):
            print('\n\n'+resultXLR)
        total += ansXLR
    else:
        if(PRINT_INDIVIDUAL_RESULTS):
            print('\n\n'+'Contradiction in XLR!')

    if(contradictionAR != 'yes'):
        if(PRINT_INDIVIDUAL_RESULTS):
            print('\n\n'+resultAR)
        total += ansAR
    else:
        if(PRINT_INDIVIDUAL_RESULTS):
            print('\n\n'+'Contradiction in AR!')

    if(contradictionAD != 'yes'):
        if(PRINT_INDIVIDUAL_RESULTS):
            print('\n\n'+resultAD)
        total += ansAD
    else:
        if(PRINT_INDIVIDUAL_RESULTS):
            print('\n\n'+'Contradiction in AD!')

    print('\n\n-----------------------\nResults for '+FILENAME+'\n-----------------------\n')
    if(contradictionXLR != 'yes'):
        print('Probability of XLR: '+str(ansXLR/float(total)))
    else:
        print('Probability of XLR: 0')
    if(contradictionAR != 'yes'):
        print('Probability of AR: '+str(ansAR/float(total)))
    else:
        print('Probability of AR: 0')
    if(contradictionAD != 'yes'):
        print('Probability of AD: '+str(ansAD/float(total)))
    else:
        print('Probability of AD: 0')



def mainFunction():
    start = time.time()
    runThisFunction()

    end = time.time()
    print('\n\nTotal time: '+str(end - start))

mainFunction()
