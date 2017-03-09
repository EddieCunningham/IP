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

# cdef extern from "gmp.h":
#     ctypedef struct mpf_t:
#         pass

#     ctypedef struct mp_exp_t:
#         pass

#     char* mpf_get_str(char *be_null, mp_exp_t *expptr, int base, size_t n_digits, mpf_t op)
#     double mpf_get_d_2exp(long *exp, mpf_t op)


# cdef extern from "gmpxx.h":

#     cdef cppclass mpf_class:
#         mpf_class() except +
#         mpf_t get_mpf_t()

cdef extern from "generalizedStochasticGMP.h" namespace "std":

    cdef cppclass Type:
        Type() except +
        Type(bool isRoot, vector[vector[vector[double]]] initialVals, pair[string,vector[pair[int,int]]] theType) except +
        Type* left
        Type* right
        string name
        double tVal
        bool isRoot
        int _id
        vector[pair[int,int]] indices;
        vector[vector[branchInfo]] vals;
        vector[vector[double]] termWeights;
        pair[bool,branchInfo] getNextVal(int whichBranch,bool random)

    cdef struct branchInfo:
        int left,right
        double val

    pair[vector[Type_ptr],vector[Type_ptr]] initializeTypes(int m, vector[vector[vector[double]]] g, vector[pair[double,vector[pair[int,int]]]] types) except +

    unordered_map[int,string] stochasticSum(int n, int m, vector[Type_ptr] roots, unordered_map[int,double] pedigreeRoots, int numSamples, int checkpoint, int printCheckpoint) except +

cdef class PyType:
    cdef Type_ptr c_Type
    cdef public PyType left
    cdef public PyType right

    def __cinit__(self):
        left = None
        right = None

    def get_name(self):
        return self.c_Type.name

    def is_root(self):
        return self.c_Type.isRoot

    def t_value(self):
        return self.c_Type.tVal

    cdef addType(self,Type_ptr theType):
        self.c_Type = theType

    def get_next_val(self, int whichBranch, bool random):
        cdef pair[bool,branchInfo] ans
        ans = self.c_Type.getNextVal(whichBranch,random)
        unwrappedBranchInfo = [ans.first,ans.second.left,ans.second.right,ans.second.val]
        return unwrappedBranchInfo

    def get_id(self):
        return self.c_Type._id

    def get_indices(self):
        cdef vector[pair[int,int]] c_indices
        c_indices = self.c_Type.indices
        listForm = [[x.first,x.second] for x in c_indices]
        return listForm

    def get_vals(self):
        cdef vector[vector[branchInfo]] c_vals
        c_vals = self.c_Type.vals
        listForm = [[[_x.left,_x.right,_x.val] for _x in x] for x in c_vals]
        return listForm

    def get_termWeights(self):
        cdef vector[vector[double]] c_termWeights
        c_termWeights = self.c_Type.termWeights
        return c_termWeights


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
    cdef unordered_map[int,double] pedigreeRoots
    cdef vector[Type_ptr] allTypes
    cdef public int n,m
    cdef public vector[vector[vector[double]]] g
    cdef public string filename
    cdef public object py_roots
    cdef public object py_allTypes
    cdef public object pedigree

    def get_n(self):
        return self.n

    def get_m(self):
        return self.m

    def get_g(self):
        return self.g

    def get_roots(self):
        return self.py_roots

    def get_allTypes(self):
        return self.py_allTypes

    def get_filename(self):
        return self.filename

    def get_pedigree(self):
        return self.pedigree


    cdef parsedTypes(self,int m,vector[vector[vector[double]]] g,vector[pair[double,vector[pair[int,int]]]] types):
        cdef pair[vector[Type_ptr],vector[Type_ptr]] ans
        cdef vector[Type_ptr] roots
        cdef vector[Type_ptr] allTypes

        ans = initializeTypes(m,g,types)
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
        
        cdef int m
        cdef vector[vector[vector[double]]] g
        cdef unordered_map[int,double] pedigreeRoots
        cdef vector[pair[double,vector[pair[int,int]]]] types

        funcToUse = shadingFunction

        with open(filename) as data_file:
            data = json.loads(json.load(data_file))
            pedigree = Pedigree(data)
            pedigree.setAffectedFunctions(funcToUse)

        self.pedigree = pedigree

        types,pedigreeRoots = getTypes(pedigree,useT=True,dominantOrRecessive=dominantOrRecessive)
        n,m,g = problemContext()

        self.n = n
        self.m = m
        self.g = g
        self.pedigreeRoots = pedigreeRoots
        self.parsedTypes(m,g,types)

    cpdef calculateProbability(self,numSamples,checkpoint,printCheckpoint):
        cdef unordered_map[int,string] ans

        ans = stochasticSum(self.n,self.m,self.roots,self.pedigreeRoots,numSamples,checkpoint,printCheckpoint)

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







