from graphviz import Digraph
from smartWayPlus import *

def drawN(f,theType):
    name = theType._id
    index0Set = theType.indices[0][0]
    index1Set = theType.indices[1][0]

    g = Digraph('n')
    # g.body.append('style=filled')
    g.body.append('color=lightgrey')
    g.attr('node', shape='circle', color='lightblue', style='filled')
    g.node(name+'_A',label=str(theType._id))
    # g.node(name+'_A',label=str(name)+'_'+str(theType.name)+': '+str(theType.indices))
    g.node(name+'_B',label='')
    g.node(name+'_C',label='')
    g.node(name+'_D',label='1/4')
    g.node(name+'_E',label='1/2')
    g.node(name+'_F',label='1/2')
    g.node(name+'_G',label='1')

    g.attr('node', shape='point', color='black')
    g.node(name+'_1*',label='')
    g.node(name+'_2*',label='')
    g.node(name+'_11',label='')
    g.node(name+'_12',label='')
    g.node(name+'_21',label='')
    g.node(name+'_22',label='')


    g.edge(name+'_A',name+'_1*',label='1,D['+str(index0Set)+']')
    g.edge(name+'_1*',name+'_B')

    g.edge(name+'_A',name+'_2*',label='2,D['+str(index0Set)+']')
    g.edge(name+'_2*',name+'_C')

    g.edge(name+'_B',name+'_11',label='1,D['+str(index1Set)+']')
    g.edge(name+'_11',name+'_D')
    g.edge(name+'_B',name+'_12',label='2,D['+str(index1Set)+']')
    g.edge(name+'_12',name+'_E')

    g.edge(name+'_C',name+'_21',label='1,D['+str(index1Set)+']')
    g.edge(name+'_21',name+'_F')
    g.edge(name+'_C',name+'_22',label='2,D['+str(index1Set)+']')
    g.edge(name+'_22',name+'_G')

    f.subgraph(g)

def drawS(f,theType):
    name = theType._id
    index0Set = theType.indices[0][0]
    index1Set = theType.indices[1][0]

    g = Digraph('n')

    g.attr('node', shape='circle', color='lightred', style='filled')
    g.node(name+'_A',label=str(theType._id))
    # g.node(name+'_A',label=str(name)+'_'+str(theType.name)+': '+str(theType.indices))
    g.node(name+'_B',label='')
    g.node(name+'_C',label='')
    g.node(name+'_D',label='')
    g.node(name+'_E',label='1')
    g.node(name+'_F',label='1')
    g.node(name+'_G',label='1')
    g.node(name+'_H',label='1')
    g.node(name+'_I',label='3/4')
    g.node(name+'_J',label='1/2')
    g.node(name+'_K',label='1')
    g.node(name+'_L',label='1/2')

    g.attr('node', shape='point', color='black')
    g.node(name+'_0*',label='')
    g.node(name+'_1*',label='')
    g.node(name+'_2*',label='')
    g.node(name+'_00',label='')
    g.node(name+'_01',label='')
    g.node(name+'_02',label='')
    g.node(name+'_10',label='')
    g.node(name+'_11',label='')
    g.node(name+'_12',label='')
    g.node(name+'_20',label='')
    g.node(name+'_21',label='')

    g.edge(name+'_A',name+'_0*',label='0,D['+str(index0Set)+']')
    g.edge(name+'_0*',name+'_B')
    g.edge(name+'_A',name+'_1*',label='1,D['+str(index0Set)+']')
    g.edge(name+'_1*',name+'_C')
    g.edge(name+'_A',name+'_2*',label='2,D['+str(index0Set)+']')
    g.edge(name+'_2*',name+'_D')


    g.edge(name+'_B',name+'_00',label='0,D['+str(index1Set)+']')
    g.edge(name+'_00',name+'_E')
    g.edge(name+'_B',name+'_01',label='1,D['+str(index1Set)+']')
    g.edge(name+'_01',name+'_F')
    g.edge(name+'_B',name+'_02',label='2,D['+str(index1Set)+']')
    g.edge(name+'_02',name+'_G')


    g.edge(name+'_C',name+'_10',label='0,D['+str(index1Set)+']')
    g.edge(name+'_10',name+'_H')
    g.edge(name+'_C',name+'_11',label='1,D['+str(index1Set)+']')
    g.edge(name+'_11',name+'_I')
    g.edge(name+'_C',name+'_12',label='2,D['+str(index1Set)+']')
    g.edge(name+'_12',name+'_J')


    g.edge(name+'_D',name+'_20',label='0,D['+str(index1Set)+']')
    g.edge(name+'_20',name+'_K')
    g.edge(name+'_D',name+'_21',label='1,D['+str(index1Set)+']')
    g.edge(name+'_21',name+'_L')

    f.subgraph(g)

def drawP(f,theType):
    name = theType._id
    index0Set = theType.indices[0][0]
    index1Set = theType.indices[1][0]

    g = Digraph('n')
    g.attr('node', shape='circle', color='lightgreen', style='filled')
    g.node(name+'_A',label=str(theType._id))
    # g.node(name+'_A',label=str(name)+'_'+str(theType.name)+': '+str(theType.indices))
    g.node(name+'_B',label='')
    g.node(name+'_C',label='')
    g.node(name+'_D',label='')
    g.node(name+'_E',label='1/2')
    g.node(name+'_F',label='1/2')
    g.node(name+'_G',label='1/2')
    g.node(name+'_H',label='1/2')
    g.node(name+'_I',label='1/2')
    g.node(name+'_J',label='1/4')
    g.node(name+'_K',label='1/2')
    g.node(name+'_L',label='1/4')
    g.node(name+'_M',label='1/2')

    g.attr('node', shape='point', color='black')
    g.node(name+'_0*',label='')
    g.node(name+'_1*',label='')
    g.node(name+'_2*',label='')
    g.node(name+'_00',label='')
    g.node(name+'_01',label='')
    g.node(name+'_02',label='')
    g.node(name+'_10',label='')
    g.node(name+'_11',label='')
    g.node(name+'_12',label='')
    g.node(name+'_20',label='')
    g.node(name+'_21',label='')

    g.edge(name+'_A',name+'_0*',label='0,D['+str(index0Set)+']')
    g.edge(name+'_0*',name+'_B')
    g.edge(name+'_A',name+'_1*',label='1,D['+str(index0Set)+']')
    g.edge(name+'_1*',name+'_C')
    g.edge(name+'_A',name+'_2*',label='2,D['+str(index0Set)+']')
    g.edge(name+'_2*',name+'_D')


    g.edge(name+'_B',name+'_00',label='0,D['+str(index1Set)+']')
    g.edge(name+'_00',name+'_E')
    g.edge(name+'_B',name+'_01',label='1,D['+str(index1Set)+']')
    g.edge(name+'_01',name+'_F')
    g.edge(name+'_B',name+'_02',label='2,D['+str(index1Set)+']')
    g.edge(name+'_02',name+'_G')


    g.edge(name+'_C',name+'_10',label='0,D['+str(index1Set)+']')
    g.edge(name+'_10',name+'_H')
    g.edge(name+'_C',name+'_11',label='1,D['+str(index1Set)+']')
    g.edge(name+'_11',name+'_I')
    g.edge(name+'_C',name+'_12',label='2,D['+str(index1Set)+']')
    g.edge(name+'_12',name+'_J')


    g.edge(name+'_D',name+'_20',label='0,D['+str(index1Set)+']')
    g.edge(name+'_20',name+'_K')
    g.edge(name+'_D',name+'_21',label='1,D['+str(index1Set)+']')
    g.edge(name+'_21',name+'_L')
    g.edge(name+'_D',name+'_22',label='2,D['+str(index1Set)+']')
    g.edge(name+'_22',name+'_M')

    f.subgraph(g)

def drawG_0(f,theType):
    name = theType._id
    index1Set = theType.indices[1][0]
    index2Set = theType.indices[2][0]

    g = Digraph('n')
    g.attr('node', shape='circle', color='greenyellow', style='filled')
    g.node(name+'_0_A',label=str(theType._id))
    # g.node(name+'_0_A',label=str(name)+'_'+str(theType.name)+': '+str(theType.indices))
    g.node(name+'_0_B',label='')
    g.node(name+'_0_C',label='')
    g.node(name+'_0_D',label='1')
    g.node(name+'_0_E',label='1/2')
    g.node(name+'_0_F',label='1/2')
    g.node(name+'_0_G',label='1/4')

    g.attr('node', shape='point', color='black')
    g.node(name+'_0_0*',label='')
    g.node(name+'_0_1*',label='')
    g.node(name+'_0_00',label='')
    g.node(name+'_0_01',label='')
    g.node(name+'_0_10',label='')
    g.node(name+'_0_11',label='')

    g.edge(name+'_0_A',name+'_0_0*',label='0,D['+str(index1Set)+']')
    g.edge(name+'_0_0*',name+'_0_B')
    g.edge(name+'_0_A',name+'_0_1*',label='1,D['+str(index1Set)+']')
    g.edge(name+'_0_1*',name+'_0_C')


    g.edge(name+'_0_B',name+'_0_00',label='0,D['+str(index2Set)+']')
    g.edge(name+'_0_00',name+'_0_D')
    g.edge(name+'_0_B',name+'_0_01',label='1,D['+str(index2Set)+']')
    g.edge(name+'_0_01',name+'_0_E')


    g.edge(name+'_0_C',name+'_0_10',label='0,D['+str(index2Set)+']')
    g.edge(name+'_0_10',name+'_0_F')
    g.edge(name+'_0_C',name+'_0_11',label='1,D['+str(index2Set)+']')
    g.edge(name+'_0_11',name+'_0_G')

    f.subgraph(g)

def drawG_1(f,theType):
    name = theType._id
    index1Set = theType.indices[1][0]
    index2Set = theType.indices[2][0]

    g = Digraph('n')
    g.attr('node', shape='circle', color='orange', style='filled')
    g.node(name+'_1_A',label=str(theType._id))
    # g.node(name+'_1_A',label=str(name)+'_'+str(theType.name)+': '+str(theType.indices))
    g.node(name+'_1_B',label='')
    g.node(name+'_1_C',label='')
    g.node(name+'_1_D',label='')
    g.node(name+'_1_E',label='1/2')
    g.node(name+'_1_F',label='1')
    g.node(name+'_1_G',label='1/2')
    g.node(name+'_1_H',label='1/2')
    g.node(name+'_1_I',label='1/2')
    g.node(name+'_1_J',label='1')
    g.node(name+'_1_K',label='1/2')

    g.attr('node', shape='point', color='black')
    g.node(name+'_1_0*',label='')
    g.node(name+'_1_1*',label='')
    g.node(name+'_1_2*',label='')
    g.node(name+'_1_01',label='')
    g.node(name+'_1_02',label='')
    g.node(name+'_1_10',label='')
    g.node(name+'_1_11',label='')
    g.node(name+'_1_12',label='')
    g.node(name+'_1_20',label='')
    g.node(name+'_1_21',label='')

    g.edge(name+'_1_A',name+'_1_0*',label='0,D['+str(index1Set)+']')
    g.edge(name+'_1_0*',name+'_1_B')
    g.edge(name+'_1_A',name+'_1_1*',label='1,D['+str(index1Set)+']')
    g.edge(name+'_1_1*',name+'_1_C')
    g.edge(name+'_1_A',name+'_1_2*',label='2,D['+str(index1Set)+']')
    g.edge(name+'_1_2*',name+'_1_D')


    g.edge(name+'_1_B',name+'_1_01',label='1,D['+str(index2Set)+']')
    g.edge(name+'_1_01',name+'_1_E')
    g.edge(name+'_1_B',name+'_1_02',label='2,D['+str(index2Set)+']')
    g.edge(name+'_1_02',name+'_1_F')


    g.edge(name+'_1_C',name+'_1_10',label='0,D['+str(index2Set)+']')
    g.edge(name+'_1_10',name+'_1_G')
    g.edge(name+'_1_C',name+'_1_11',label='1,D['+str(index2Set)+']')
    g.edge(name+'_1_11',name+'_1_H')
    g.edge(name+'_1_C',name+'_1_12',label='2,D['+str(index2Set)+']')
    g.edge(name+'_1_12',name+'_1_I')


    g.edge(name+'_1_D',name+'_1_20',label='0,D['+str(index2Set)+']')
    g.edge(name+'_1_20',name+'_1_J')
    g.edge(name+'_1_D',name+'_1_21',label='1,D['+str(index2Set)+']')
    g.edge(name+'_1_21',name+'_1_K')

    f.subgraph(g)

def drawG_2(f,theType):
    name = theType._id
    index1Set = theType.indices[1][0]
    index2Set = theType.indices[2][0]

    g = Digraph('n')
    g.attr('node', shape='circle', color='lightyellow', style='filled')
    g.node(name+'_2_A',label=str(theType._id))
    # g.node(name+'_2_A',label=str(name)+'_'+str(theType.name)+': '+str(theType.indices))
    g.node(name+'_2_B',label='')
    g.node(name+'_2_C',label='')
    g.node(name+'_2_D',label='1/4')
    g.node(name+'_2_E',label='1/2')
    g.node(name+'_2_F',label='1/2')
    g.node(name+'_2_G',label='1')

    g.attr('node', shape='point', color='black')
    g.node(name+'_2_1*',label='')
    g.node(name+'_2_2*',label='')
    g.node(name+'_2_11',label='')
    g.node(name+'_2_12',label='')
    g.node(name+'_2_21',label='')
    g.node(name+'_2_22',label='')

    g.edge(name+'_2_A',name+'_2_1*',label='1,D['+str(index1Set)+']')
    g.edge(name+'_2_1*',name+'_2_B')

    g.edge(name+'_2_A',name+'_2_2*',label='2,D['+str(index1Set)+']')
    g.edge(name+'_2_2*',name+'_2_C')

    g.edge(name+'_2_B',name+'_2_11',label='1,D['+str(index2Set)+']')
    g.edge(name+'_2_11',name+'_2_D')

    g.edge(name+'_2_B',name+'_2_12',label='2,D['+str(index2Set)+']')
    g.edge(name+'_2_12',name+'_2_E')

    g.edge(name+'_2_C',name+'_2_21',label='1,D['+str(index2Set)+']')
    g.edge(name+'_2_21',name+'_2_F')

    g.edge(name+'_2_C',name+'_2_22',label='2,D['+str(index2Set)+']')
    g.edge(name+'_2_22',name+'_2_G')

    f.subgraph(g)

def drawG(f,theType,branch):
    if(branch == 0):
        drawG_0(f,theType)
    elif(branch == 1):
        drawG_1(f,theType)
    elif(branch == 2):
        drawG_2(f,theType)
    else:
        assert 0,'Invalid branch'

def drawSingleType(f,theType,branch=None):
    if(theType.name == 'n'):
        drawN(f,theType)
    elif(theType.name == 's'):
        drawS(f,theType)
    elif(theType.name == 'p'):
        drawP(f,theType)
    elif(theType.name == 'g'):
        drawG(f,theType,branch)
    else:
        assert 0,'Invalid type'

def findAnsHelper(f,currentType,whichBranch,alreadyDrawn):

    if(currentType.left == None and currentType.right == None):
        return

    nextVal = currentType.getNextVal(whichBranch)
    if(whichBranch):
        whichBranchNumb = ['zero','one','two'].index(whichBranch)
    while(nextVal):
        left,right,val = nextVal
        leftNumb = ['zero','one','two'].index(left)
        rightNumb = ['zero','one','two'].index(right)

        if(currentType.left):

            treeStr = str(currentType.left._id)+'_'+str(leftNumb)
            if(treeStr not in alreadyDrawn):
                alreadyDrawn[treeStr] = 1
                drawSingleType(f,currentType.left,branch=leftNumb)

            if(whichBranch):
                toAdd = [currentType._id+'_'+str(whichBranchNumb)+'_'+str(leftNumb)+'*',currentType.left._id+'_'+str(leftNumb)+'_A']
            else:
                toAdd = [currentType._id+'_'+str(leftNumb)+'*',currentType.left._id+'_'+str(leftNumb)+'_A']

            if(str(toAdd) not in alreadyDrawn):
                alreadyDrawn[str(toAdd)] = 1
                f.edge(toAdd[0],toAdd[1])
            
            findAnsHelper(f,currentType.left,left,alreadyDrawn)

        if(currentType.right):
            treeStr = str(currentType.right._id)+'_'+str(rightNumb)
            if(treeStr not in alreadyDrawn):
                alreadyDrawn[treeStr] = 1
                drawSingleType(f,currentType.right,branch=rightNumb)

            if(whichBranch):
                toAdd = [currentType._id+'_'+str(whichBranchNumb)+'_'+str(leftNumb)+str(rightNumb),currentType.right._id+'_'+str(rightNumb)+'_A']
            else:
                toAdd = [currentType._id+'_'+str(leftNumb)+str(rightNumb),currentType.right._id+'_'+str(rightNumb)+'_A']

            if(str(toAdd) not in alreadyDrawn):
                alreadyDrawn[str(toAdd)] = 1
                f.edge(toAdd[0],toAdd[1])

            findAnsHelper(f,currentType.right,right,alreadyDrawn)

        nextVal = currentType.getNextVal(whichBranch)
    
def printTree(r,depth):
    tabs = ''
    for t in range(depth):
        tabs += '\t'
    print(tabs+' '+r.name+': '+str(r.indices))
    if(r.left):
        printTree(r.left,depth+1)
    if(r.right):
        printTree(r.right,depth+1)


def visualize(types):
    allTypes,allSets = generateAllTypesAndSets(types)

    f = Digraph(comment='Pedigree Computation')

    roots = [a for a in allTypes if a.isRoot]

    alreadyDrawn = {}
    for r in roots:
        print('\n')
        printTree(r,0)
        drawSingleType(f,r)
        alreadyDrawn[r._id] = 1
        findAnsHelper(f,r,False,alreadyDrawn)

    f.view()
