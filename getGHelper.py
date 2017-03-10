import os
import operator
import itertools
import math
import random
import numpy as np

def generateGForChromosomeProblem(left_string,right_string,child_string):

    #     XX   Xy   yX   xX   Xx   xx   xy   yx
    p1 = '//   />   >/   |/   /|   ||   |>   >|' # X
    p1_= '//   />   >/   |/   /|   ||   |>   >|' # X

    p2 = '//   />   >/   |/   /|   ||   |>   >|' # X
    p2_= '^^   ^.   .^   V^   ^V   VV   V.   .V' # y

    p3 = '^^   ^.   .^   V^   ^V   VV   V.   .V' # y
    p3_= '//   />   >/   |/   /|   ||   |>   >|' # X

    p4 = '__   _D   D_   x_   _x   xx   xD   Dx' # x
    p4_= '//   />   >/   |/   /|   ||   |>   >|' # X

    p5 = '//   />   >/   |/   /|   ||   |>   >|' # X
    p5_= '__   _D   D_   x_   _x   xx   xD   Dx' # x

    p6 = '__   _D   D_   x_   _x   xx   xD   Dx' # x
    p6_= '__   _D   D_   x_   _x   xx   xD   Dx' # x

    p7 = '__   _D   D_   x_   _x   xx   xD   Dx' # x
    p7_= '^^   ^.   .^   V^   ^V   VV   V.   .V' # y

    p8 = '^^   ^.   .^   V^   ^V   VV   V.   .V' # y
    p8_= '__   _D   D_   x_   _x   xx   xD   Dx' # x

    table = p1+'~'+p1_+'~'+p2+'~'+p2_+'~'+p3+'~'+p3_+'~'+p4+'~'+p4_+'~'+p5+'~'+p5_+'~'+p6+'~'+p6_+'~'+p7+'~'+p7_+'~'+p8+'~'+p8_

    #           XX  Xy  yX  xX  Xx  xx  xy  yx
    mappings = ['/','>','^','_','|','x','D','V']

    parsedTable = [[[_x[0],_x[1]] for _x in x.split('   ')] for x in table.split('~')]

    for p in parsedTable:
        print(p)

    lookup = {
        'unknown':[0,1,2,3,4,5,6,7],
        'female':[0,3,4,5],
        'male':[1,2,6,7]
    }

    left = lookup[left_string]
    right = lookup[right_string]
    child = lookup[child_string]

    overall = []
    for i in child:
        m = mappings[i]
        current = [[0 for _i in range(len(right))] for i in range(len(left))]
        for _j,j in enumerate(left):
            row1 = 2*j
            row2 = 2*j+1
            for _k,k in enumerate(right):
                e1 = parsedTable[row1][k][0]
                e2 = parsedTable[row1][k][1]
                e3 = parsedTable[row2][k][0]
                e4 = parsedTable[row2][k][1]
                relevant = len([x for x in [e1,e2,e3,e4] if x == m])
                total = len([x for x in [e1,e2,e3,e4] if x != '.'])
                current[_j][_k] = float(relevant)/float(total)
        overall.append(current)
    
    # print('[')
    # for k,o in enumerate(overall):
    #     print('\t[')
    #     for i,_o in enumerate(o):
    #         toPrint = '\t\t['
    #         for j,__o in enumerate(_o):
    #             if(j == len(_o)-1):
    #                 toPrint += '{0:1f}'.format(__o)
    #             else:
    #                 toPrint += '{0:1f},'.format(__o)

    #         if(i == len(o)-1):
    #             toPrint += ']'
    #         else:
    #             toPrint += '],'
    #         print(toPrint)

    #     if(k == len(overall)-1):
    #         print('\t]')
    #     else:    
    #         print('\t],')
    # print(']')

    return overall

