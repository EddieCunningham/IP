import os
import operator
import itertools
import math
import random
from generateSum import *


def goUpPedigree(person,originatedFrom,currentSets,maxVal):
    # figure out what g terms to add

    if(len(person.parents) == 0):
        # then we are at a root, so nothing to add
        return []

    # these are going to be the indices of g
    # t1 is self, t2 is parent 0, t3 is parent 1
    t1 = list(currentSets[str(person.Id)+','+str(originatedFrom.Id)])
    t2 = -1
    t3 = -1

    # check to see if the parents are roots
    if(len(person.parents[0].parents) == 0):
        t2 = list(currentSets[str(person.parents[0].Id)])
        currentSets[str(person.parents[0].Id)][1] += 1
    else:
        assert str(person.parents[0].Id)+','+str(originatedFrom.Id) not in currentSets, 'This shouldn\'t be here'
        t2 = list([maxVal['val'],0,person.parents[0].sex])
        maxVal['val'] += 1
        currentSets[str(person.parents[0].Id)+','+str(originatedFrom.Id)] = t2

    if(len(person.parents[1].parents) == 0):
        t3 = list(currentSets[str(person.parents[1].Id)])
        currentSets[str(person.parents[1].Id)][1] += 1
    else:
        assert str(person.parents[1].Id)+','+str(originatedFrom.Id) not in currentSets, 'This shouldn\'t be here'
        t3 = list([maxVal['val'],0,person.parents[1].sex])
        maxVal['val'] += 1
        currentSets[str(person.parents[1].Id)+','+str(originatedFrom.Id)] = t3

    # add a g term
    termsToAdd = [[-1.0,[t1,t2,t3]]]

    termsToAdd.extend(goUpPedigree(person.parents[0],originatedFrom,currentSets,maxVal))
    termsToAdd.extend(goUpPedigree(person.parents[1],originatedFrom,currentSets,maxVal))
    return termsToAdd

def getTypes(pedigree,dominantOrRecessive='dominant',autoOrChromosome='autosome'):

    # each type is in the format: [tVal,[[parentID,uniqueID,parentSex],[[parentID,uniqueID,parentSex]]],sex]

    # goal is to recreate the types thing
    # there are going to be a ton of sets,
    # some are only going to have a single 0,1,2
    # which will represent indices not found 
    # inside an integral
    # then the rest will have the sets that we want which
    # represent the indices inside the integrals
    # and we will have <number of roots> of them
    types = []
    maxVal = {'val':0}
    currentSets = {}

    # add all the roots to the currentSets dict
    for r in pedigree.roots:
        assert str(r.Id) not in currentSets, 'This shouldn\'t be here'

        # check for the t value
        if(r.affected == 'yes'):
            if(dominantOrRecessive == 'dominant'):
                tVal = 1.0
            elif(dominantOrRecessive == 'recessive'):
                tVal = 0.0
            else:
                assert 0
        elif(r.affected == 'no'):
            if(dominantOrRecessive == 'dominant'):
                tVal = 0.0
            elif(dominantOrRecessive == 'recessive'):
                tVal = 1.0
            else:
                assert 0
        elif(r.affected == 'possibly'):
            tVal = 0.5
        else:
            assert 0,'Invalid affected value'

        currentSets[str(r.Id)] = [maxVal['val'],0,r.sex,tVal]
        maxVal['val'] += 1

    for p in pedigree.family:

        # if a person is a root, then we don't need to add anything
        if(len(p.parents) == 0):
            continue

        # figure out the set values for each person
        if(len(p.parents[0].parents) == 0):
            t1 = list(currentSets[str(p.parents[0].Id)])
            currentSets[str(p.parents[0].Id)][1] += 1
        else:
            assert str(p.parents[0].Id)+','+str(p.Id) not in currentSets, 'This shouldn\'t be here'
            t1 = list([maxVal['val'],0,p.parents[0].sex])
            maxVal['val'] += 1
            currentSets[str(p.parents[0].Id)+','+str(p.Id)] = t1

        if(len(p.parents[1].parents) == 0):
            t2 = list(currentSets[str(p.parents[1].Id)])
            currentSets[str(p.parents[1].Id)][1] += 1
        else:
            assert str(p.parents[1].Id)+','+str(p.Id) not in currentSets, 'This shouldn\'t be here'
            t2 = list([maxVal['val'],0,p.parents[1].sex])
            maxVal['val'] += 1
            currentSets[str(p.parents[1].Id)+','+str(p.Id)] = t2

        if(p.affected == 'yes'):
            # then add an 's' term
            if(dominantOrRecessive == 'dominant'):
                zetaTerm = [1.0,[t1,t2],p.sex]
            elif(dominantOrRecessive == 'recessive'):
                zetaTerm = [0.0,[t1,t2],p.sex]
            else:
                assert 0

        elif(p.affected == 'no'):
            # then add a 'n' term
            if(dominantOrRecessive == 'dominant'):
                zetaTerm = [0.0,[t1,t2],p.sex]
            elif(dominantOrRecessive == 'recessive'):
                zetaTerm = [1.0,[t1,t2],p.sex]
            else:
                assert 0

        elif(p.affected == 'possibly'):
            # then add a 'p' term
            zetaTerm = [0.5,[t1,t2],p.sex]

        else:
            assert 0,'Invalid affected outcome'

        # now branch up the tree to all of the roots and accumulate
        # the new terms to add to types
        parent0Branch = goUpPedigree(p.parents[0],p,currentSets,maxVal)
        parent1Branch = goUpPedigree(p.parents[1],p,currentSets,maxVal)

        types.extend([zetaTerm])
        types.extend(parent0Branch)
        types.extend(parent1Branch)

    maxUniqueVal = -1
    for t in types:
        maxUniqueVal = max(maxUniqueVal,max([_t[1] for _t in t[1]]))

    maxUniqueVal += 1

    for t in types:
        t[1] = [[_t[0],_t[0]*maxUniqueVal+_t[1],_t[2]] for _t in t[1]]

    # the roots have the form {id:[sex,tVal]}
    pedigreeRoots = dict([[v[0],[v[2],v[3]]] for k,v in currentSets.items() if len(v) == 4])

    print('\n-----------------\n')
    print('Final types:')
    for t in types:
        print('\n\t'+str(t))
    
    print('Current sets:')
    for k,v in currentSets.items():
        print('\n\t'+str(k)+' -> '+str(v))

    print('Pedigree roots:')
    for k,v in pedigreeRoots.items():
        print('\n\t'+str(k)+' -> '+str(v))
    print('\n-----------------\n')

    return types,pedigreeRoots



