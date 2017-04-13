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

ctypedef personClass* person_ptr

cdef extern from "logProbIPNew.h" namespace "std":

    cdef cppclass personClass:
        personClass(int _id_,personClass* parentA_,personClass* parentB_,bool isRoot_,double t_,double s_,double probability_,int l_,int m_,int n_,vector[double] probs_,bool updated_,vector[vector[vector[double]]] g_,bool affected_)
        personClass* parentA
        personClass* parentB
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
        vector[personClass*] allPeople
        vector[personClass*] roots
        vector[double] naiveMonteCarlo(long numbCalls, bool printIterations, int numbToPrint, bool printPeople, bool useNewDist, double K, bool useLeak, double leakProb, double leakDecay, bool useMH) except *

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

    def __cinit__(self,object modelPerson,dominantOrRecessive,int l, int m,int n,vector[vector[vector[double]]] g):
        parentA = None
        parentB = None


        # ADD SPOT FOR S VAL HERE
        isRoot = (len(modelPerson.parents) == 0)
        if(modelPerson.affected == 'yes'):
            if(dominantOrRecessive == 'dominant'):
                tVal = 1.0
                sVal = 0.5
            elif(dominantOrRecessive == 'recessive'):
                tVal = 0.0
                sVal = 0.5
            else:
                assert 0
        elif(modelPerson.affected == 'no'):
            if(dominantOrRecessive == 'dominant'):
                # can't have carrier in the dominant case
                tVal = 0.0
                sVal = 0.5
            elif(dominantOrRecessive == 'recessive'):
                if(modelPerson.carrier):
                    tVal = 1.0
                    sVal = 1.0
                else:
                    tVal = 1.0
                    sVal = 0.5
            else:
                assert 0
        elif(modelPerson.affected == 'possibly'):
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

        affected = modelPerson.affected!='no'

        self.c_Person = new personClass(_id,NULL,NULL,isRoot,t,s,probability,l,m,n,probs,updated,g,affected)                

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

    cdef public object allPeople
    cdef public object roots

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
        self.c_pedigree.allPeople = vector[person_ptr]()
        self.c_pedigree.roots = vector[person_ptr]()


    cpdef initialization(self,filename,problemContext,dominantOrRecessive):
        
        cdef PyPerson tempPerson

        with open(filename) as data_file:
            
            data = json.loads(json.load(data_file))
            pedigree = Pedigree(data)
            pedigree.setAffectedFunctions(empty)

        self.pedigree = pedigree
        self.trueIP = pedigree.inheritancePattern

        allLMN,allG,problemName = problemContext()
        self.allPeople = []
        self.roots = []

        helperStruct = {}

        for p in pedigree.family:

            if(len(p.adoptiveParents) > 0):
                print('Skipping person: '+p.toString())
                continue

            l,m,n = allLMN[p.sex]
            if(len(p.parents) > 0):
                child = p.sex
                parentA = p.parents[0].sex
                parentB = p.parents[1].sex
                g = allG[parentA+','+parentB+'->'+child]
            else:
                g = vector[vector[vector[double]]]()

            tempPerson = PyPerson(p,dominantOrRecessive,l,m,n,g)

            if(len(p.parents) == 0):
                self.roots.append(tempPerson)
            self.allPeople.append(tempPerson)

            if(len(p.parents) == 0):
                self.c_pedigree.roots.push_back(tempPerson.c_Person)
            self.c_pedigree.allPeople.push_back(tempPerson.c_Person)

            helperStruct[p.Id] = tempPerson


        offset = 0
        for i,p in enumerate(pedigree.family):
            if(len(p.adoptiveParents) > 0):
                offset += 1
                continue
            tempPerson = self.allPeople[i-offset]
            if(len(p.parents) > 0):
                tempPerson.setParentA(helperStruct[p.parents[0].Id])
                tempPerson.setParentB(helperStruct[p.parents[1].Id])


        # for a in self.allPeople:
        #     a.toString()

        # print('\n\n--------------------------------------\n\n')


    cpdef calculateProbability(self,numbCalls,printIterations,numbToPrint,printPeople,useNewDist,K,useLeak,leakProb,leakDecay,useMH):
        ans = self.c_pedigree.naiveMonteCarlo(numbCalls,printIterations,numbToPrint,printPeople,useNewDist,K,useLeak,leakProb,leakDecay,useMH)
        return ans







