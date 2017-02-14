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
        t2 = list([maxVal['val'],0])
        maxVal['val'] += 1
        currentSets[str(person.parents[0].Id)+','+str(originatedFrom.Id)] = t2

    if(len(person.parents[1].parents) == 0):
        t3 = list(currentSets[str(person.parents[1].Id)])
        currentSets[str(person.parents[1].Id)][1] += 1
    else:
        assert str(person.parents[1].Id)+','+str(originatedFrom.Id) not in currentSets, 'This shouldn\'t be here'
        t3 = list([maxVal['val'],0])
        maxVal['val'] += 1
        currentSets[str(person.parents[1].Id)+','+str(originatedFrom.Id)] = t3

    termsToAdd = [['g',[t1,t2,t3]]]
    termsToAdd.extend(goUpPedigree(person.parents[0],originatedFrom,currentSets,maxVal))
    termsToAdd.extend(goUpPedigree(person.parents[1],originatedFrom,currentSets,maxVal))
    return termsToAdd

def getTypes(pedigree):
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
        currentSets[str(r.Id)] = [maxVal['val'],0]
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
            t1 = list([maxVal['val'],0])
            maxVal['val'] += 1
            currentSets[str(p.parents[0].Id)+','+str(p.Id)] = t1

        if(len(p.parents[1].parents) == 0):
            t2 = list(currentSets[str(p.parents[1].Id)])
            currentSets[str(p.parents[1].Id)][1] += 1
        else:
            assert str(p.parents[1].Id)+','+str(p.Id) not in currentSets, 'This shouldn\'t be here'
            t2 = list([maxVal['val'],0])
            maxVal['val'] += 1
            currentSets[str(p.parents[1].Id)+','+str(p.Id)] = t2

        if(p.affected == 'yes'):
            # then add an 's' term
            zetaTerm = ['s',[t1,t2]]
        elif(p.affected == 'no'):
            # then add a 'n' term
            zetaTerm = ['n',[t1,t2]]
        elif(p.affected == 'possibly'):
            # then add a 'p' term
            zetaTerm = ['p',[t1,t2]]
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
        t[1] = [[_t[0],_t[0]*maxUniqueVal+_t[1]] for _t in t[1]]

    # print(maxUniqueVal)
    # for t in types:
    #     print(t)

    # for k,v in currentSets.items():
    #     print(str(k)+' -> '+str(v))

    # assert 0
    return types,currentSets