import os
import math
from model import *
from ipNEW import *
from getGHelper import *
import numpy as np

# 3 confusion matrices

# human vs known correct
# algorithm vs human
# algorithm vs known correct

# add logging system

# papers with bullet points

FILENAME = 'test.json'

NUMB_CALLS = 100000

PRINT_ITERATIONS = False
PRINT_PEOPLE = False

PRINT_INDIVIDUAL_RESULTS = True


def runProblem(filename,problemContext,dominantOrRecessive,problemType):
    pedigreeClass = PyPedigree()
    pedigreeClass.initialization(filename,problemContext,dominantOrRecessive)
    contradiction,log_ans,log_stdev = pedigreeClass.calculateProbability(NUMB_CALLS,PRINT_ITERATIONS,PRINT_PEOPLE)

    trueIP = pedigreeClass.trueIP

    if(contradiction == 1.0):
        contradiction = 'yes'
    else:
        contradiction = 'no'

    resultString = '\n'
    resultString += '\n'+str(problemType)+' results:'
    resultString += '\ncontradiction: '+str(contradiction)
    resultString += '\nans: '+str(np.exp(log_ans))
    resultString += '\nstdev: '+str(np.exp(log_stdev))
    return resultString,contradiction,np.exp(log_ans),np.exp(log_stdev),trueIP

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
    
def evaluateIP(jsonFileName,jsonFolderPath = '/Users/Eddie/kec-bot/app/pedigreeData'):

    filename = os.path.join(jsonFolderPath,jsonFileName)
    print('Running solver on XLR problem')
    resultXLR,contradictionXLR,ansXLR,stdevXLR,trueIP = runXLRProb(filename)

    print('\n---------------\nRunning solver on AR problem')
    resultAR,contradictionAR,ansAR,stdevAR,trueIP = runARProb(filename)

    print('\n---------------\nRunning solver on AD problem')
    resultAD,contradictionAD,ansAD,stdevAD,trueIP = runADProb(filename)
    
    print('\n---------------\n')

    total = 0

    if(contradictionXLR != 'yes'):
        if(PRINT_INDIVIDUAL_RESULTS):
            print('\n\n'+resultXLR)
        total += ansXLR
    else:
        if(PRINT_INDIVIDUAL_RESULTS):
            print('\n\n'+'Contradiction in XLR!  Would have gotten:\n')
            print(resultXLR)

    if(contradictionAR != 'yes'):
        if(PRINT_INDIVIDUAL_RESULTS):
            print('\n\n'+resultAR)
        total += ansAR
    else:
        if(PRINT_INDIVIDUAL_RESULTS):
            print('\n\n'+'Contradiction in AR! Would have gotten:\n')
            print(resultAR)

    if(contradictionAD != 'yes'):
        if(PRINT_INDIVIDUAL_RESULTS):
            print('\n\n'+resultAD)
        total += ansAD
    else:
        if(PRINT_INDIVIDUAL_RESULTS):
            print('\n\n'+'Contradiction in AD! Would have gotten:\n')
            print(resultAD)

    print('\n\n-----------------------\nResults for '+jsonFileName+' (True inheritance pattern is: '+str(trueIP)+')\n-----------------------\n')
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


def evaluateAllPedigrees(jsonFolderPath = '/Users/Eddie/kec-bot/app/pedigreeData'):

    goodFlag = True

    for root, dirs, filenames in os.walk(jsonFolderPath):
        for f in filenames:
            if(f == '6481MR.json'):
                goodFlag = True

            if(f == '5777AH.json' or f == '6158AT.json'):
                continue # don't want to deal with adoption bs
            
            if(goodFlag and '.json' in f):
                print('\n\n\n============================ SOLVING FOR '+str(f)+' ============================\n\n\n')
                evaluateIP(f,jsonFolderPath)
                print('\n\n\n================================================================================\n\n\n')


def mainFunction():
    evaluateIP(FILENAME)


evaluateAllPedigrees()
# mainFunction()
