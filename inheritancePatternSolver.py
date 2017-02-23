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


USE_TEST = True




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
    problemContext = autosomeProblem

    allPedigrees = []
    for filename in os.listdir(jsonFolderPath):
        if('.json' in filename):
            if(USE_TEST):
                filename = 'test_9.json'

            completeFileName = os.path.join(jsonFolderPath,filename)
            allPedigrees.append(parsePedigree(completeFileName,shadingFunction,problemContext))
            break

    n,m,g = problemContext()
    pedigree,totalNonZeroTerms,roots,allTypes = allPedigrees[0]
    numbRoots = len(pedigree.roots)

    visualize(roots,allTypes,numbRoots,n)

    


start = time.time()
runThisFunction()

end = time.time()
print('\n\nTotal time: '+str(end - start))

