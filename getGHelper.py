import os
import operator
import itertools
import math
import random
import numpy as np


PRINT = False


def generatePunnetSquare(inputString,validAlleles,orderMatters,illegal,affectedAllele,sexOfChild,leftParentSex,rightParentSex,chromoOrAuto):

    # each g is indexed by [child][left][right]

    # make sure that we have valid alleles
    for x in inputString:
        assert(x[0] in validAlleles and x[1] in validAlleles)

    # if need order to matter
    if(orderMatters):
        newInputString = []
        for i in inputString:
            if(i[0] != i[1]):
                newInputString.append(i[1]+i[0])
            newInputString.append(i)
        inputString = newInputString

    # sort the inputString so that affected people are first
    inputString = sorted(inputString,key=lambda x: len([_x for _x in x if _x == affectedAllele]),reverse=True)

    # remove illegal pairs
    inputString = [x for x in inputString if x not in illegal]

    # get the sex mappings
    if(chromoOrAuto == 'chromosome'):
        sexMappings = {
            'unknown':list(range(len(inputString))),
            'male':[i for i,x in enumerate(inputString) if 'y' in x],
            'female':[i for i,x in enumerate(inputString) if 'y' not in x]
        }
    else:
        sexMappings = {
            'unknown':list(range(len(inputString))),
            'male':list(range(len(inputString))),
            'female':list(range(len(inputString)))
        }

    left = [inputString[x] for x in sexMappings[leftParentSex]]
    right = [inputString[x] for x in sexMappings[rightParentSex]]
    child = [inputString[x] for x in sexMappings[sexOfChild]]

   
    # get all MN for the sexes

    allLMN = []
    for k,v in sexMappings.items():
        for i,x in enumerate(v):
            pair = inputString[x]
            if(len([x for x in [_x for _x in pair if _x != 'y'] if x == affectedAllele]) !=  len([_x for _x in pair if _x != 'y'])):
                break
        L = i
        M = len([x for x in v if affectedAllele in inputString[x]])
        N = len(v)

        allLMN.append([k,[L,M,N]])
    allLMN = dict(allLMN)


     # make sure that the first index of each represents a person with 2 affected alleles
    for L in range(allLMN[leftParentSex][0]):
        assert len([x for x in [_x for _x in left[L] if _x != 'y'] if x == affectedAllele]) ==  len([_x for _x in left[L] if _x != 'y'])
    
    for L in range(allLMN[rightParentSex][0]):
        assert len([x for x in [_x for _x in right[L] if _x != 'y'] if x == affectedAllele]) ==  len([_x for _x in right[L] if _x != 'y'])
    
    for L in range(allLMN[sexOfChild][0]):
        assert len([x for x in [_x for _x in child[L] if _x != 'y'] if x == affectedAllele]) ==  len([_x for _x in child[L] if _x != 'y'])


    if(PRINT):
        print('\n\n---------------- PUNNET SQUARE ----------------\n')

        print('Child possibilities: '+str(child)+'\n\n')

        print('    '),
        for i,r in enumerate(right):
            if(i+1 == len(right)):
                print(str(r)+'\n')
            else:
                print(str(r)+'  '),
        for l in left:
            print(str(l)+'\n')

        print('\n-----------------------------------------------\n\n')

    punnetSquare = []

    for i,c in enumerate(child):

        currentMatrix = []
        for j,l in enumerate(left):

            currentRow = []
            for k,r in enumerate(right):

                multiplier = 1.0
                if((chromoOrAuto == 'chromosome') and (len([x for x in [l,r] if x[0] == 'y' or x[1] == 'y']) != 1)):
                    # makes sure that same sex doesn't reproduce
                    currentRow.append(0)
                    continue

                allCombos = [l[0]+r[0],l[0]+r[1],l[1]+r[0],l[1]+r[1]]
                if(chromoOrAuto == 'chromosome'):
                    if(sexOfChild == 'male'):
                        total = len([x for x in allCombos if (x not in illegal and 'y' in x)])
                    elif(sexOfChild == 'female'):
                        total = len([x for x in allCombos if (x not in illegal and 'y' not in x)])
                    else:
                        total = len([x for x in allCombos if x not in illegal])
                else:
                    total = len([x for x in allCombos if x not in illegal])
                if(orderMatters):
                    relevant = len([x for x in allCombos if x == c])
                else:
                    relevant = len([x for x in allCombos if (x == c or x[1]+x[0] == c)])
                val = multiplier*float(relevant)/float(total)

                currentRow.append(val)

            currentMatrix.append(currentRow)

        punnetSquare.append(currentMatrix)

    # pretty print
    if(PRINT):
        print('{')
        for k,o in enumerate(punnetSquare):
            print('\t{')
            for i,_o in enumerate(o):
                toPrint = '\t\t{'
                for j,__o in enumerate(_o):
                    if(j == len(_o)-1):
                        toPrint += '{0:1f}'.format(__o)
                    else:
                        toPrint += '{0:1f},'.format(__o)

                if(i == len(o)-1):
                    toPrint += '}'
                else:
                    toPrint += '},'
                print(toPrint)

            if(k == len(punnetSquare)-1):
                print('\t}')
            else:
                print('\t},')
        print('}')

    # check to see that the punnet square makes sense
    for i in range(len(punnetSquare[0])):
        for j in range(len(punnetSquare[0][0])):
            theSum = 0
            for k in range(len(punnetSquare)):
                theSum += punnetSquare[k][i][j]
            assert(theSum == 1 or theSum == 0)

    return punnetSquare,allLMN


def allGHelper(inputString,validAlleles,orderMatters,illegal,affectedAllele,autoOrChromo):
    allG = {}
    for x in itertools.product(['unknown','male','female'],repeat=3):
        leftParentSex,rightParentSex,sexOfChild = x
        if((leftParentSex == 'male' and rightParentSex == 'male') or (leftParentSex == 'female' and rightParentSex == 'female') or (leftParentSex == 'unknown' and rightParentSex != 'unknown') or (leftParentSex != 'unknown' and rightParentSex == 'unknown')):
            continue
        key = leftParentSex+','+rightParentSex+'->'+sexOfChild
        allG[key],allLMN = generatePunnetSquare(inputString,validAlleles,orderMatters,illegal,affectedAllele,sexOfChild,leftParentSex,rightParentSex,autoOrChromo)

    return allG,allLMN

def autosomeProblem():

    inputString = ['AA','Aa','aa']
    validAlleles = 'Aa'
    orderMatters = True
    illegal = []
    affectedAllele = 'A'
    autoOrChromo = 'autosome'

    allG,allLMN = allGHelper(inputString,validAlleles,orderMatters,illegal,affectedAllele,autoOrChromo)

    return allLMN,allG,'autosome'

def chromosomeProblem():

    inputString = ['XX','Xy','Xx','xx','xy']
    validAlleles = 'Xxy'
    orderMatters = True
    illegal = ['yy']
    affectedAllele = 'X'
    autoOrChromo = 'chromosome'

    allG,allLMN = allGHelper(inputString,validAlleles,orderMatters,illegal,affectedAllele,autoOrChromo)

    maleMN = allLMN['male']
    femaleMN = allLMN['female']
    g = allG['male,female->male']


    return allLMN,allG,'chromosome'

# allLMN,allG,autoOrChromo = autosomeProblem()
# print(allLMN)
# print('\n\n\n')
# print(allG)

# allLMN,allG,autoOrChromo = chromosomeProblem()
# print(allLMN)
# print('\n\n\n')
# print(allG)

