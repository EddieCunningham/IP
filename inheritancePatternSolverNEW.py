import os
import csv
import math
from model import *
from ipNEW import *
from getGHelper import *
import numpy as np

'''

questions:
    - How to sample from high dimensional pdf
    - Is that the best strategy?
    - Would importance sampling do better?    
    - Any recent algorithms to look into?
    - What techniques are good for evaluating integrals?


'''




'''

 - plot ad and ar for different values of t
 - change t for the parents and not the other ancestors
 - change t with a fade out towards the ancestors 

'''

# 3 confusion matrices

# human vs known correct
# algorithm vs human
# algorithm vs known correct

# add logging system

# papers with bullet points

FILENAME = '3383AT.json'

NUMB_CALLS = 10000
NUMB_TO_PRINT = NUMB_CALLS*0.5

PRINT_ITERATIONS = False
PRINT_PEOPLE = False

PRINT_INDIVIDUAL_RESULTS = True

USE_NEW_DISTRIBUTION = False
K = 10.0

USELEAK = False
LEAKPROB = 0.01
LEAKDECAY = 0.5

USEMH = False
USEBRUTEFORCE = True

NUMB_ROOTS = 3

def runProblem(filename,problemContext,dominantOrRecessive,problemType):

    pedigreeClass = PyPedigree()
    pedigreeClass.initialization(filename,problemContext,dominantOrRecessive)
    trueIP = pedigreeClass.trueIP

    if(USEBRUTEFORCE):
        ans = pedigreeClass.calculateProbability(NUMB_CALLS,PRINT_ITERATIONS,NUMB_TO_PRINT,PRINT_PEOPLE,USE_NEW_DISTRIBUTION,K,USELEAK,LEAKPROB,LEAKDECAY,USEMH,USEBRUTEFORCE,NUMB_ROOTS)
        
        numbAncestralRoots = ans[0]
        numbAncestralNonRoots = ans[1]
        toReturn = [trueIP,numbAncestralRoots,numbAncestralNonRoots]
        toReturn.extend([np.exp(x) if x!=-1 else 0 for i,x in enumerate(ans[2:])])
        return toReturn
    else:
        contradiction,log_ans,log_stdev = pedigreeClass.calculateProbability(NUMB_CALLS,PRINT_ITERATIONS,NUMB_TO_PRINT,PRINT_PEOPLE,USE_NEW_DISTRIBUTION,K,USELEAK,LEAKPROB,LEAKDECAY,USEMH,USEBRUTEFORCE,NUMB_ROOTS)
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
    if(USEBRUTEFORCE):
        ansXLR = runXLRProb(filename)
        trueIP = ansXLR[0]
        ansXLR = ansXLR[1:]
    else:
        resultXLR,contradictionXLR,ansXLR,stdevXLR,trueIP = runXLRProb(filename)

    print('\n------------------------------------------------------------------------------------------------------\nRunning solver on AR problem')
    if(USEBRUTEFORCE):
        ansAR = runARProb(filename)
        trueIP = ansAR[0]
        ansAR = ansAR[1:]
    else:
        resultAR,contradictionAR,ansAR,stdevAR,trueIP = runARProb(filename)

    print('\n------------------------------------------------------------------------------------------------------\nRunning solver on AD problem')
    if(USEBRUTEFORCE):
        ansAD = runADProb(filename)
        trueIP = ansAD[0]
        ansAD = ansAD[1:]
    else:
        resultAD,contradictionAD,ansAD,stdevAD,trueIP = runADProb(filename)
    
    print('\n------------------------------------------------------------------------------------------------------\n')

    if(USEBRUTEFORCE):
        return trueIP,ansXLR,ansAR,ansAD
    else:
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

        return resultXLR,contradictionXLR,ansXLR,stdevXLR,resultAR,contradictionAR,ansAR,stdevAR,resultAD,contradictionAD,ansAD,stdevAD,trueIP


def evaluateAllPedigrees(jsonFolderPath = '/Users/Eddie/kec-bot/app/pedigreeData',writeToCSV=True):

    goodFlag = True

    with open('pedigreeResultsBruteForce3.csv', 'w') as csvfile:
        if(USEBRUTEFORCE):
            fieldnames = ['PedigreeId','Correct_IP','ResultsXLR','ResultsAR','ResultsAD']
        else:
            fieldnames = ['PedigreeId','Correct_IP','contradictionXLR','ansXLR','stdevXLR','contradictionAR','ansAR','stdevAR','contradictionAD','ansAD','stdevAD']
        writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
        writer.writeheader()

        for root, dirs, filenames in os.walk(jsonFolderPath):
            for f in filenames:
                if(f == '6481MR.json'):
                    goodFlag = True

                if(f == '5777AH.json' or f == '6158AT.json'):
                    continue # don't want to deal with adoption bs
                
                if(goodFlag and '.json' in f):
                    print('\n\n\n============================ SOLVING FOR '+str(f)+' ============================\n\n\n')
                    ans = evaluateIP(f,jsonFolderPath)
                    
                    if(USEBRUTEFORCE):
                        trueIP,ansXLR,ansAR,ansAD = ans

                        writer.writerow({ \
                                        'PedigreeId': str(f), \
                                        'Correct_IP': str(trueIP), \
                                        'ResultsXLR': str(ansXLR), \
                                        'ResultsAR': str(ansAR), \
                                        'ResultsAD': str(ansAD) \
                                        })
                    else:
                        resultXLR,contradictionXLR,ansXLR,stdevXLR,resultAR,contradictionAR,ansAR,stdevAR,resultAD,contradictionAD,ansAD,stdevAD,trueIP = ans
                        writer.writerow({ \
                                        'PedigreeId': str(f), \
                                        'Correct_IP': str(trueIP), \
                                        'contradictionXLR': str(contradictionXLR), \
                                        'ansXLR': str(ansXLR), \
                                        'stdevXLR': str(stdevXLR), \
                                        'contradictionAR': str(contradictionAR), \
                                        'ansAR': str(ansAR), \
                                        'stdevAR': str(stdevAR), \
                                        'contradictionAD': str(contradictionAD), \
                                        'ansAD': str(ansAD), \
                                        'stdevAD': str(stdevAD) \
                                        })


                    print('\n\n\n================================================================================\n\n\n')



'''
    ######################

    MAKE A PART OF THE PERSONCLASS ABOUT THE CARRIER SO THAT INSTEAD OF CHANGING 
    T TO BATTLE INCOMPLETE PENETRANCE, USE CARRIER PROB

    ######################
'''


def testIncompletePenetrance():
    global LEAKPROB

    answers = []
    MIN = 0.001
    MAX = 1.0
    ITERS = 200
    for i in range(0,ITERS+1):
        LEAKPROB = (MAX-MIN)*i/ITERS + MIN
        _,_,_,_,_,_,ansAR,_,_,_,ansAD,_,_ = evaluateIP(FILENAME)
        answers.append([LEAKPROB,[ansAR,ansAD]])
        print('LEAK PROB: '+str(LEAKPROB)+'\n\n\n')

    for l,a in answers:
        print(str(l)+' -> '+str(a))


def mainFunction():
    evaluateIP(FILENAME)


evaluateAllPedigrees()
# mainFunction()
# testIncompletePenetrance()


