import os
import operator
import itertools
import math
import random
from generateTypes import *
from model import *
import time
import gmpy2
from libcpp.vector cimport vector
from libcpp.pair cimport pair
from libcpp.string cimport string
from libcpp.unordered_map cimport unordered_map
from libcpp cimport bool
from libcpp cimport nullptr
from libc.stdlib cimport malloc, free


ctypedef Type* Type_ptr

ctypedef struct index_struct:
    int setNumb
    int uVal
    string sex

ctypedef struct g_type_type:
    double tVal
    vector[index_struct] indices

ctypedef struct other_type_type:
    double tVal
    vector[index_struct] indices
    string sex

ctypedef union type_union:
    g_type_type g_type
    other_type_type other_type 


cdef extern from "generalizedStochasticGMPExtended.h" namespace "std":

    cdef cppclass Type:
        Type() except +
        Type(bool isRoot, vector[vector[vector[double]]] initialVals, type_union theType) except +
        Type* left
        Type* right
        string name
        string sex
        double tVal
        bool isRoot
        int _id
        vector[vector[index_struct]] indices;
        vector[vector[branchInfo]] vals;
        vector[vector[double]] termWeights;
        pair[bool,branchInfo] getNextVal(int whichBranch,bool random)

    cdef struct branchInfo:
        int left,right
        double val

    pair[vector[Type_ptr],vector[Type_ptr]] initializeTypes(unordered_map[string,pair[int,int]] allMN, unordered_map[string,vector[vector[vector[double]]]] allG, vector[type_union] types) except +

    unordered_map[int,string] stochasticSum(unordered_map[string,pair[int,int]] allMN, vector[Type_ptr] roots, unordered_map[int,pair[string,double]] pedigreeRoots, int numSamples, int checkpoint, int printCheckpoint) except +

cdef class PyType:
    cdef Type_ptr c_Type
    cdef public PyType left
    cdef public PyType right

    def __cinit__(self):
        left = None
        right = None

    cdef addType(self,Type_ptr theType):
        self.c_Type = theType

cdef buildHelper(PyType currentPyType, allPyTypes):
    if(currentPyType.c_Type.left):
        py_left = PyType()
        py_left.addType(currentPyType.c_Type.left)
        currentPyType.left = py_left
        allPyTypes.append(py_left)
        buildHelper(py_left,allPyTypes)
    if(currentPyType.c_Type.right):
        py_right = PyType()
        py_right.addType(currentPyType.c_Type.right)
        currentPyType.right = py_right
        allPyTypes.append(py_right)
        buildHelper(py_right,allPyTypes)


cdef class PyPedigree:
    cdef vector[Type_ptr] roots
    cdef unordered_map[int,pair[string,double]] pedigreeRoots
    cdef vector[Type_ptr] allTypes

    cdef public unordered_map[string,vector[vector[vector[double]]]] allG
    cdef public unordered_map[string,pair[int,int]] allMN
    cdef public string filename
    cdef public object py_roots
    cdef public object py_allTypes
    cdef public object pedigree

    def get_roots(self):
        return self.py_roots

    def get_allTypes(self):
        return self.py_allTypes

    def get_filename(self):
        return self.filename

    def get_pedigree(self):
        return self.pedigree


    cdef parsedTypes(self,unordered_map[string,pair[int,int]] allMN, unordered_map[string,vector[vector[vector[double]]]] allG, vector[type_union] types):
        cdef pair[vector[Type_ptr],vector[Type_ptr]] ans
        cdef vector[Type_ptr] roots
        cdef vector[Type_ptr] allTypes

        ans = initializeTypes(allMN,allG,types)
        roots = ans.first
        allTypes = ans.second

        self.roots = roots
        self.allTypes = allTypes

        allPyTypes = []
        rootPyTypes = []
        for r in roots:
            py_r = PyType()
            py_r.addType(r)
            rootPyTypes.append(py_r)
            allPyTypes.append(py_r)
            buildHelper(py_r,allPyTypes)

        self.py_roots = rootPyTypes
        self.py_allTypes = allPyTypes


    cpdef parsePedigree(self,filename,shadingFunction,problemContext,dominantOrRecessive):
        
        cdef unordered_map[string,vector[vector[vector[double]]]] allG
        cdef unordered_map[string,pair[int,int]] allMN
        cdef unordered_map[int,pair[string,double]] pedigreeRoots
        cdef vector[type_union] types

        funcToUse = shadingFunction

        with open(filename) as data_file:
            data = json.loads(json.load(data_file))
            pedigree = Pedigree(data)
            pedigree.setAffectedFunctions(funcToUse)

        self.pedigree = pedigree

        allMN,allG,autoOrChromosome = problemContext()
        self.allMN = allMN
        self.allG = allG

        types,pedigreeRoots = getTypes(pedigree,dominantOrRecessive=dominantOrRecessive,autoOrChromosome=autoOrChromosome)

        self.pedigreeRoots = pedigreeRoots
        self.parsedTypes(allMN,allG,types)

    cpdef calculateProbability(self,numSamples,checkpoint,printCheckpoint):
        cdef unordered_map[int,string] ans

        ans = stochasticSum(self.allMN,self.roots,self.pedigreeRoots,numSamples,checkpoint,printCheckpoint)

        pythonAns = {}       
        for val in ans:
            digits = val.second.split(':')[0]
            exponent = int(val.second.split(':')[1])
            
            adding = ''
            if(exponent <= 0):
                adding += '.'
                while(exponent < 0):
                    adding += '0'
                    exponent += 1
                adding += digits
            else:
                adding = digits[0:exponent]+'.'+digits[exponent:]

            pythonAns[val.first] = str(gmpy2.mpfr(adding))

        return pythonAns







