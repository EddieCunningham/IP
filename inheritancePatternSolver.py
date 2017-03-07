import os
import operator
import itertools
import math
import random
from generateTypes import *
from model import *
from visualizeTreeGeneral import *
from ipTree import *
import time


USE_TEST = False
FILENAME = 'test_9.json'

VISUALIZE = True
CALC_PROB = True


def shadingAD(person):
    if(len(person.diagnoses) > 0):
        return 'yes'
    else:
        return 'no'

def autosomeProblemWrong():
    g = [
          [[1. ,0.5 ,0. ],
           [0.5,0.25,0. ],
           [0. ,0.  ,0. ]],
  
          [[0. ,0.5 ,1. ],
           [0.5,0.5 ,0.5],
           [1. ,0.5 ,0. ]],
  
          [[0. ,0.  ,0. ],
           [0. ,0.25,0.5],
           [0. ,0.5 ,1. ]]
        ]
    m = 2
    n = 3
    return n,m,g

def autosomeProblem():
    g = [
          [[1.  ,0.5 ,0.5 ,0. ],
           [0.5 ,0.25,0.25,0. ],
           [0.5 ,0.25,0.25,0. ],
           [0.0 ,0.  ,0.  ,0. ]],
  
          [[0.  ,0.5 ,0.5 ,1. ],
           [0.  ,0.25,0.25,0.5],
           [0.  ,0.25,0.25,0.5],
           [0.  ,0.  ,0.  ,0. ]],
  
          [[0.  ,0.  ,0.  ,0. ],
           [0.5 ,0.25,0.25,0. ],
           [0.5 ,0.25,0.25,0. ],
           [1.  ,0.5 ,0.5 ,0. ]],

          [[0.  ,0.  ,0.  , 0.],
           [0.  ,0.25,0.25,0.5],
           [0.  ,0.25,0.25,0.5],
           [0.  ,0.5 ,0.5 ,1. ]]
        ]
    m = 3
    n = 4
    return n,m,g

def runThisFunction(jsonFolderPath = '/Users/Eddie/kec-bot/app/pedigreeData'):

    shadingFunction = shadingAD
    problemContext = autosomeProblemWrong
    # problemContext = autosomeProblem

    allPedigrees = []
    for filename in os.listdir(jsonFolderPath):
        if('.json' in filename):
            if(USE_TEST):
                filename = FILENAME

            completeFileName = os.path.join(jsonFolderPath,filename)

            p = PyPedigree()
            p.parsePedigree(completeFileName,shadingFunction,problemContext)

            allPedigrees.append(p)
            break

    pedigreeClass = allPedigrees[0]

    n = pedigreeClass.get_n()
    m = pedigreeClass.get_m()
    g = pedigreeClass.get_g()
    totalNonZeroTerms = pedigreeClass.get_totalNonZeroTerms()
    roots = pedigreeClass.get_roots()
    allTypes = pedigreeClass.get_allTypes()
    filename = pedigreeClass.get_filename()
    pedigree = pedigreeClass.get_pedigree()

    numbRoots = len(pedigree.roots)

    if(VISUALIZE):
        visualize(roots,allTypes,numbRoots,n)

    if(CALC_PROB):
        num_samples = 1000000
        checkpoint = 100000
        # checkpoint = num_samples*0.004
        ans = pedigreeClass.calculateProbability(num_samples,checkpoint)

    


start = time.time()
runThisFunction()

end = time.time()
print('\n\nTotal time: '+str(end - start))

