import os
import operator
import itertools
import math
import random
from model import *
import time
import gmpy2
from libcpp.vector cimport vector
from libcpp.pair cimport pair
from libcpp.string cimport string
from libcpp.unordered_map cimport unordered_map
from libcpp cimport bool
from libc.stdint cimport uintptr_t
from cython.operator cimport dereference as deref, preincrement as inc

ctypedef personClass* person_ptr
ctypedef pedigreeClass2* pedigree_ptr

cdef extern from "logProbIPNew.h":

    cdef cppclass personClass:
        personClass(int _id_,personClass* parentA_,personClass* parentB_,bool isRoot_,double t_,double s_,double probability_,int l_,int m_,int n_,vector[double] probs_,bool updated_,vector[vector[vector[double]]] g_,bool affected_,string typeOfShading_,string sex_)
        personClass* parentA
        personClass* parentB
        vector[pair[person_ptr,vector[person_ptr]]] mateKids
        bool isRoot
        double t,s,probability
        int m,n
        vector[double] probs
        bool updated
        vector[vector[vector[double]]] g
        bool affected
        int _id

    cdef cppclass pedigreeClass2:
        pedigreeClass2()
        bool sexDependent
        vector[vector[person_ptr]] families
        vector[personClass*] allPeople
        vector[personClass*] roots
        vector[personClass*] leaves
        unordered_map[person_ptr,int] mapToIndexRoots
        unordered_map[person_ptr,int] mapToIndexAllPeople

        vector[double] monteCarlo(long numbCalls, bool printIterations, int numbToPrint, bool printPeople, bool useNewDist, double K, bool useLeak, double leakProb, double leakDecay, bool useMH, bool useBruteForce, int numbRoots, bool useHybrid) except *

cdef extern from "BMIP.h":
    
    cdef cppclass EMPedigreeOptimizer:
        EMPedigreeOptimizer()
        void initialize(const vector[pedigreeClass2*]& trainingSet_, bool printPeople)
        vector[pedigreeClass2] trainingSet
        vector[vector[vector[double]]] emissionProbs
        vector[vector[vector[double]]] rootProbs
        vector[vector[vector[vector[double]]]] transitionProbs

cdef class PyPerson:
    cdef personClass* c_Person
    cdef public PyPerson parentA
    cdef public PyPerson parentB
    cdef public bool isRoot
    cdef public double t,s,probability
    cdef public int l,m,n
    cdef public vector[double] probs
    cdef public bool updated
    cdef public vector[vector[vector[double]]] g
    cdef public bool affected
    cdef public int _id
    cdef public string typeOfShading,sex

    def __cinit__(self,object modelPerson,dominantOrRecessive,int l, int m,int n,vector[vector[vector[double]]] g):
        parentA = None
        parentB = None

        # ADD SPOT FOR S VAL HERE
        isRoot = (len(modelPerson.parents) == 0)
        if(modelPerson.affected == 'yes'):
            typeOfShading = 'shaded'
            if(dominantOrRecessive == 'dominant'):
                tVal = 1.0
                sVal = 0.5
            elif(dominantOrRecessive == 'recessive'):
                tVal = 0.0
                sVal = 0.5
            else:
                assert 0
        elif(modelPerson.affected == 'no'):
            typeOfShading = 'unshaded'
            if(dominantOrRecessive == 'dominant'):
                # can't have carrier in the dominant case
                tVal = 0.0
                sVal = 0.5
            elif(dominantOrRecessive == 'recessive'):
                if(modelPerson.carrier):
                    typeOfShading = 'carrier'
                    tVal = 1.0
                    sVal = 1.0
                else:
                    tVal = 1.0
                    sVal = 0.5
            else:
                assert 0
        elif(modelPerson.affected == 'possibly'):
            typeOfShading = 'possiblyShaded'
            tVal = 0.5
            sVal = 0.5
        else:
            assert 0,'Invalid affected value'
        t = tVal
        s = sVal
        probability = 0.0
        probs = vector[double]()
        for i in range(n):
            probs.append(0)
        updated = False
        _id = modelPerson.Id
        sex = modelPerson.sex

        affected = modelPerson.affected!='no'

        self.c_Person = new personClass(_id,NULL,NULL,isRoot,t,s,probability,l,m,n,probs,updated,g,affected,typeOfShading,sex)                

        self.isRoot = isRoot
        self.t = t
        self.s = s
        self.probability = probability
        self.l = l
        self.m = m
        self.n = n
        self.probs = probs
        self.probs = probs
        self.updated = updated
        self.g = g
        self.affected = affected
        self._id = _id
        self.typeOfShading = typeOfShading
        self.sex = sex

    def __dealloc__(self):
        del self.c_Person

    cdef setParentA(self,PyPerson parentA):
        self.parentA = parentA
        self.c_Person.parentA = parentA.c_Person

    cdef setParentB(self,PyPerson parentB):
        self.parentB = parentB
        self.c_Person.parentB = parentB.c_Person

    def toString(self):
        print('self: '+str(self))
        print('\tparentA: '+str(self.parentA))
        print('\tparentB: '+str(self.parentB))
        print('\tisRoot: '+str(self.isRoot))
        print('\tt: '+str(self.t))
        print('\ts: '+str(self.s))
        print('\tprobability: '+str(self.probability))
        print('\tl: '+str(self.l))
        print('\tm: '+str(self.m))
        print('\tn: '+str(self.n))
        print('\tprobs: '+str(self.probs))
        print('\tupdated: '+str(self.updated))
        print('\tg: '+str(self.g))
        print('\t_id: '+str(self._id))
        print('\ttypeOfShading: '+str(self.typeOfShading))
        print('\tsex: '+str(self.sex))

    # def toString(self):
    #     print('personClass x_'+str(self._id)+'('+str(self._id)+','),
    #     if(not self.parentA):
    #         print('nullptr,'),
    #         print('nullptr,'),
    #         print('true,'),
    #     else:
    #         print('&x_'+str(self.parentA.c_Person._id)+','),
    #         print('&x_'+str(self.parentB.c_Person._id)+','),
    #         print('false,'),
    #     print(str(self.t)+','),
    #     print('0.0,2,3,vector<double>(3),false,g);\n')

def empty(obj):
    return None

cdef class PyPedigree:
    cdef pedigreeClass2 c_pedigree
    cdef pedigree_ptr c_pedigree_ptr

    cdef public object allPeople
    cdef public object roots
    cdef public object families

    cdef public unordered_map[string,vector[vector[vector[double]]]] allG
    cdef public unordered_map[string,pair[int,int]] allMN
    cdef public object pedigree
    cdef public object filename

    cdef public string trueIP

    def get_filename(self):
        return self.filename

    def get_pedigree(self):
        return self.pedigree

    def __cinit__(self):
        self.c_pedigree = pedigreeClass2()
        self.c_pedigree_ptr = &(self.c_pedigree)
        self.c_pedigree.allPeople = vector[person_ptr]()
        self.c_pedigree.roots = vector[person_ptr]()
        self.c_pedigree.families = vector[vector[person_ptr]]()


    cpdef initialization(self,filename,problemContext,dominantOrRecessive):
        
        cdef vector[personClass*].iterator it
        cdef vector[pair[person_ptr,vector[person_ptr]]].iterator it2
        cdef PyPerson tempPerson
        cdef vector[personClass*] familyToAdd
        cdef person_ptr parentA
        cdef person_ptr parentB
        cdef person_ptr child
        cdef pair[person_ptr,vector[person_ptr]] tempPair

        with open(filename) as data_file:
            
            data = json.loads(json.load(data_file))
            pedigree = Pedigree(data)
            pedigree.setAffectedFunctions(empty)

        self.pedigree = pedigree
        self.trueIP = pedigree.inheritancePattern

        allLMN,allG,problemName = problemContext()
        self.allPeople = []
        self.roots = []
        self.families = []

        familyHelper = {}

        if(problemName == 'autosome'):
            self.c_pedigree.sexDependent = False
        else:
            self.c_pedigree.sexDependent = True

        helperStruct = {}

        for p in pedigree.family:

            if(len(p.adoptiveParents) > 0):
                print('Skipping person: '+p.toString())
                continue

            l,m,n = allLMN[p.sex]
            if(len(p.parents) > 0):
                childSex = p.sex
                parentASex = p.parents[0].sex
                parentBSex = p.parents[1].sex
                g = allG[parentASex+','+parentBSex+'->'+childSex]
            else:
                g = vector[vector[vector[double]]]()

            tempPerson = PyPerson(p,dominantOrRecessive,l,m,n,g)

            if(len(p.parents) == 0):
                self.roots.append(tempPerson)
                self.c_pedigree.mapToIndexRoots[tempPerson.c_Person] = len(self.roots)-1
                self.c_pedigree.roots.push_back(tempPerson.c_Person)
            else:
                key = sorted([p.parents[0].Id,p.parents[1].Id])
                if(str(key) not in familyHelper):
                    if(p.parents[0].sex == 'female'):
                        familyHelper[str(key)] = [p.parents[0].Id,p.parents[1].Id,p.Id]
                    else:
                        familyHelper[str(key)] = [p.parents[1].Id,p.parents[0].Id,p.Id]
                else:
                    familyHelper[str(key)].append(p.Id)

            self.allPeople.append(tempPerson)
            self.c_pedigree.allPeople.push_back(tempPerson.c_Person)

            self.c_pedigree.mapToIndexAllPeople[tempPerson.c_Person] = len(self.allPeople)-1

            helperStruct[p.Id] = tempPerson


        # update the families
        for key,fam in familyHelper.items():
            familyToAdd = vector[person_ptr]()

            assert (<PyPerson>(helperStruct[fam[0]])).sex == 'female','Found that the sex of this person ('+str((<PyPerson>(helperStruct[fam[0]]))._id)+') is '+str((<PyPerson>(helperStruct[fam[0]])).sex)
            parentA = (<PyPerson>(helperStruct[fam[0]])).c_Person
            parentB = (<PyPerson>(helperStruct[fam[1]])).c_Person

            # update the mateKids vector for each parent
            # parentA[0].mateKids.push_back(pair[person_ptr,vector[person_ptr]](<person_ptr>parentB,vector[person_ptr]()))
            # parentB[0].mateKids.push_back(pair[person_ptr,vector[person_ptr]](<person_ptr>parentA,vector[person_ptr]()))

            tempPair = pair[person_ptr,vector[person_ptr]]()
            tempPair.first = <person_ptr>parentB
            tempPair.second = vector[person_ptr]()
            parentA[0].mateKids.push_back(tempPair)

            tempPair = pair[person_ptr,vector[person_ptr]]()
            tempPair.first = <person_ptr>parentA
            tempPair.second = vector[person_ptr]()
            parentB[0].mateKids.push_back(tempPair)

            for p in fam[2:]:
                child = (<PyPerson>(helperStruct[p])).c_Person
                parentA[0].mateKids.back().second.push_back(<person_ptr>child)
                parentB[0].mateKids.back().second.push_back(<person_ptr>child)

            # update the family structure for the pedigree
            for p in fam:
                familyToAdd.push_back((<PyPerson>(helperStruct[p])).c_Person)
                # (<PyPerson>(helperStruct[p])).c_Person[0].famNumb = len(self.families)

            self.c_pedigree.families.push_back(familyToAdd)
            self.families.append(fam)

        # update the leaves
        it = self.c_pedigree.allPeople.begin()
        while it != self.c_pedigree.allPeople.end():
            if((<person_ptr>(it[0])).mateKids.size() == 0):
                self.c_pedigree.leaves.push_back(<person_ptr>(it[0]))
            else:
                noKids = True
                it2 = (<person_ptr>(it[0])).mateKids.begin()
                while it2 != (<person_ptr>(it[0])).mateKids.end():
                    if((<pair[person_ptr,vector[person_ptr]]>(it2[0])).second.size() > 0):
                        noKids = False
                        break
                    inc(it2)

                if(noKids):
                    self.c_pedigree.leaves.push_back(<person_ptr>(it[0]))
            inc(it)

        offset = 0
        for i,p in enumerate(pedigree.family):
            if(len(p.adoptiveParents) > 0):
                offset += 1
                continue
            tempPerson = self.allPeople[i-offset]
            if(len(p.parents) > 0):
                tempPerson.setParentA(<PyPerson>(helperStruct[p.parents[0].Id]))
                tempPerson.setParentB(<PyPerson>(helperStruct[p.parents[1].Id]))


        # for a in self.allPeople:
        #     a.toString()

        # print('\n\n--------------------------------------\n\n')


    cpdef calculateProbability(self,numbCalls,printIterations,numbToPrint,printPeople,useNewDist,K,useLeak,leakProb,leakDecay,useMH,bruteForce,numbRoots,useHybrid):
        ans = self.c_pedigree.monteCarlo(numbCalls,printIterations,numbToPrint,printPeople,useNewDist,K,useLeak,leakProb,leakDecay,useMH,bruteForce,numbRoots,useHybrid)
        return ans



cdef class PyEMOptimizer:
    cdef EMPedigreeOptimizer c_EMPedigreeOptimizer
    cdef object allPedigrees

    def __init__(self):
        self.allPedigrees = []

    def addPedigree(self,filename,problemContext,dominantOrRecessive):
        toAdd = PyPedigree()
        toAdd.initialization(filename,problemContext,dominantOrRecessive)
        self.allPedigrees.append(toAdd)

    cpdef lockIn(self,printPeople):
        cdef vector[pedigree_ptr] trainingSet
        cdef pedigree_ptr adding

        for i in range(len(self.allPedigrees)):
            adding = (<PyPedigree>(self.allPedigrees[i])).c_pedigree_ptr
            trainingSet.push_back(adding)

        self.c_EMPedigreeOptimizer.initialize(trainingSet,printPeople)















