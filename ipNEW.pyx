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

cdef extern from "ipImplementation.h" namespace "std":

    cdef cppclass personClass:
        personClass(int _id_,personClass* parentA_,personClass* parentB_,bool isRoot_,double t_,double probability_,int m_,int n_,vector[double] probs_,bool updated_,vector[vector[vector[double]]] g_)
        personClass* parentA
        personClass* parentB
        bool isRoot
        double t,probability
        int m,n
        vector[double] probs
        bool updated
        vector[vector[vector[double]]] g
        int _id

    cdef cppclass pedigreeClass:
        pedigreeClass()
        vector[personClass*] allPeople
        vector[personClass*] roots
        double calcIntegral(int numbCalls)

cdef class PyPerson:
    cdef personClass* c_Person
    cdef public PyPerson parentA
    cdef public PyPerson parentB
    cdef public bool isRoot
    cdef public double t,probability
    cdef public int m,n
    cdef public vector[double] probs
    cdef public bool updated
    cdef public vector[vector[vector[double]]] g
    cdef public int _id

    def __cinit__(self,object modelPerson,dominantOrRecessive,int m,int n,vector[vector[vector[double]]] g):
        parentA = None
        parentB = None

        isRoot = (len(modelPerson.parents) == 0)
        if(modelPerson.affected == 'yes'):
            if(dominantOrRecessive == 'dominant'):
                tVal = 1.0
            elif(dominantOrRecessive == 'recessive'):
                tVal = 0.0
            else:
                assert 0
        elif(modelPerson.affected == 'no'):
            if(dominantOrRecessive == 'dominant'):
                tVal = 0.0
            elif(dominantOrRecessive == 'recessive'):
                tVal = 1.0
            else:
                assert 0
        elif(modelPerson.affected == 'possibly'):
            tVal = 0.5
        else:
            assert 0,'Invalid affected value'
        t = tVal
        probability = 0.0
        probs = vector[double]()
        for i in range(n):
            probs.append(0)
        updated = False
        _id = modelPerson.Id

        self.c_Person = new personClass(_id,NULL,NULL,isRoot,t,probability,m,n,probs,updated,g)                

        self.isRoot = isRoot
        self.t = t
        self.probability = probability
        self.m = m
        self.n = n
        self.probs = probs
        self.probs = probs
        self.updated = updated
        self.g = g
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
        print('\tprobability: '+str(self.probability))
        print('\tm: '+str(self.m))
        print('\tn: '+str(self.n))
        print('\tprobs: '+str(self.probs))
        print('\tupdated: '+str(self.updated))
        print('\tg: '+str(self.g))
        print('\t_id: '+str(self._id))

def empty(obj):
    return None

cdef class PyPedigree:
    cdef pedigreeClass c_pedigree

    cdef public object allPeople
    cdef public object roots

    cdef public unordered_map[string,vector[vector[vector[double]]]] allG
    cdef public unordered_map[string,pair[int,int]] allMN
    cdef public object pedigree
    cdef public object filename

    def get_filename(self):
        return self.filename

    def get_pedigree(self):
        return self.pedigree

    cpdef initialization(self,filename,problemContext,dominantOrRecessive):
        
        cdef PyPerson tempPerson

        with open(filename) as data_file:
            data = json.loads(json.load(data_file))
            pedigree = Pedigree(data)
            pedigree.setAffectedFunctions(empty)

        self.pedigree = pedigree

        allMN,allG,problemName = problemContext()
        self.c_pedigree.allPeople = vector[person_ptr]()
        self.c_pedigree.roots = vector[person_ptr]()
        self.allPeople = []
        self.roots = []

        helperStruct = {}

        for p in pedigree.family:

            m,n = allMN[p.sex]
            if(len(p.parents) > 0):
                child = p.sex
                parentA = p.parents[0].sex
                parentB = p.parents[1].sex
                g = allG[parentA+','+parentB+'->'+child]
            else:
                g = vector[vector[vector[double]]]()

            tempPerson = PyPerson(p,dominantOrRecessive,m,n,g)

            if(len(p.parents) == 0):
                self.roots.append(tempPerson)
            self.allPeople.append(tempPerson)

            if(len(p.parents) == 0):
                self.c_pedigree.roots.push_back(tempPerson.c_Person)
            self.c_pedigree.allPeople.push_back(tempPerson.c_Person)

            helperStruct[p.Id] = tempPerson


        for i,p in enumerate(pedigree.family):
            tempPerson = self.allPeople[i]
            if(len(p.parents) > 0):
                tempPerson.setParentA(helperStruct[p.parents[0].Id])
                tempPerson.setParentB(helperStruct[p.parents[1].Id])


        for a in self.allPeople:
            a.toString()

        print('\n\n--------------------------------------\n\n')


    cpdef calculateProbability(self):
        return self.c_pedigree.calcIntegral(1000)







