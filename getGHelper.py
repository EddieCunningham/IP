import os
import operator
import itertools
import math
import random
import numpy as np

def runThis():

    mappings = ['x','_','|','D','V','/','>','^']

    table = 'xx   x_   _x   xD   Dx   __   _D   D_'+'~~'+\
            'xx   x_   _x   xD   Dx   __   _D   D_'+'~~'+\
            'xx   x_   _x   xD   Dx   __   _D   D_'+'~~'+\
            '||   |/   /|   |>   >|   //   />   >/'+'~~'+\
            '||   |/   /|   |>   >|   //   />   >/'+'~~'+\
            'xx   x_   _x   xD   Dx   __   _D   D_'+'~~'+\
            'xx   x_   _x   xD   Dx   __   _D   D_'+'~~'+\
            'VV   V^   ^V   V.   .V   ^^   ^.   .^'+'~~'+\
            'VV   V^   ^V   V.   .V   ^^   ^.   .^'+'~~'+\
            'xx   x_   _x   xD   Dx   __   _D   D_'+'~~'+\
            '||   |/   /|   |>   >|   //   />   >/'+'~~'+\
            '||   |/   /|   |>   >|   //   />   >/'+'~~'+\
            '||   |/   /|   |>   >|   //   />   >/'+'~~'+\
            'VV   V^   ^V   V.   .V   ^^   ^.   .^'+'~~'+\
            'VV   V^   ^V   V.   .V   ^^   ^.   .^'+'~~'+\
            '||   |/   /|   |>   >|   //   />   >/'

    parsedTable = [[[_x[0],_x[1]] for _x in x.split('   ')] for x in table.split('~~')]

    for p in parsedTable:
        print(p)

    overall = []
    for i,m in enumerate(mappings):
        current = np.zeros((8,8))
        for j in range(len(parsedTable)/2):
            row1 = 2*j
            row2 = 2*j+1
            for k in range(len(parsedTable[0])):
                e1 = parsedTable[row1][k][0]
                print('row1: '+str(row1))
                print('k: '+str(k))
                print('parsedTable[row1]: '+str(parsedTable[row1]))
                print('parsedTable[row1][k]: '+str(parsedTable[row1][k]))
                print('parsedTable[row1][k][1]: '+str(parsedTable[row1][k][1]))
                e2 = parsedTable[row1][k][1]
                e3 = parsedTable[row2][k][0]
                e4 = parsedTable[row2][k][1]
                relevant = len([x for x in [e1,e2,e3,e4] if x == m])
                total = len([x for x in [e1,e2,e3,e4] if x != '.'])
                current[j][k] = float(relevant)/float(total)
        overall.append(current)
    
    for o in overall:
        for _o in o:
            toPrint = ''
            for __o in _o:
                toPrint += '{0:1f} '.format(__o)

            print(toPrint)
        print('\n')





# runThis()
