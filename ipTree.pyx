import os
import operator
import itertools
import math
import random
from generateTypes import *
from model import *
import time
from libcpp.vector cimport vector
from libcpp.pair cimport pair
from libcpp.string cimport string
from libcpp.unordered_map cimport unordered_map
from libcpp cimport bool



ctypedef Type* Type_ptr

cdef extern from "generalizedStochastic.h" namespace "std":

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

    pair[long long,pair[vector[Type_ptr],vector[Type_ptr]]] initializeTypes(int m, vector[vector[vector[double]]] g, vector[pair[double,vector[pair[int,int]]]] types)

    unordered_map[int,double] stochasticSum(int n, int m, vector[Type_ptr] roots, long long totalTerms, int numSamples, int checkpoint)

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

cdef parsedTypes(int m,vector[vector[vector[double]]] g,vector[pair[double,vector[pair[int,int]]]] types):
    cdef pair[long long,pair[vector[Type_ptr],vector[Type_ptr]]] ans
    cdef long long totalNonZeroTerms
    cdef vector[Type_ptr] roots
    cdef vector[Type_ptr] allTypes

    ans = initializeTypes(m,g,types)
    totalNonZeroTerms = ans.first
    roots = ans.second.first
    allTypes = ans.second.second

    allPyTypes = []
    rootPyTypes = []
    for r in roots:
        py_r = PyType()
        py_r.addType(r)
        rootPyTypes.append(py_r)
        allPyTypes.append(py_r)
        buildHelper(py_r,allPyTypes)

    return [totalNonZeroTerms,rootPyTypes,allPyTypes]


cpdef parsePedigree(filename,shadingFunction,problemContext,solve=False,numSamples=0,checkpoint=0):
    
    cdef int m
    cdef vector[vector[vector[double]]] g
    cdef vector[pair[double,vector[pair[int,int]]]] types
    cdef unordered_map[int,double] returnPoints

    funcToUse = shadingFunction

    with open(filename) as data_file:
        data = json.loads(json.load(data_file))
        pedigree = Pedigree(data)
        pedigree.setAffectedFunctions(funcToUse)

    types,setMappings = getTypes(pedigree,useT=True)
    n,m,g = problemContext()


    totalNonZeroTerms,roots,allTypes = parsedTypes(m,g,types)
    if(solve):
        returnPoints = stochasticSum(n,m,roots,totalNonZeroTerms,numSamples,checkpoint)

    return [pedigree,totalNonZeroTerms,roots,allTypes,returnPoints]










