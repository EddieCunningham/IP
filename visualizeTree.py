from graphviz import Digraph
from smartWayPlus import *

def drawN(f,theType):
    name = theType._id
    index0Set = theType.indices[0][0]
    index1Set = theType.indices[1][0]

    f.attr('node', shape='circle')
    f.node(name+'_A',label='')
    f.node(name+'_B',label='')
    f.node(name+'_C',label='')
    f.node(name+'_D',label='1/4')
    f.node(name+'_E',label='1/2')
    f.node(name+'_F',label='1/2')
    f.node(name+'_G',label='1')

    f.attr('node', shape='point')
    f.node(name+'_1*',label='')
    f.node(name+'_2*',label='')
    f.node(name+'_11',label='')
    f.node(name+'_12',label='')
    f.node(name+'_21',label='')
    f.node(name+'_22',label='')


    f.edge(name+'_A',name+'_1*',label='1,D-'+str(index0Set))
    f.edge(name+'_1*',name+'_B')

    f.edge(name+'_A',name+'_2*',label='2,D-'+str(index0Set))
    f.edge(name+'_2*',name+'_C')

    f.edge(name+'_B',name+'_11',label='1,D-'+str(index1Set))
    f.edge(name+'_11',name+'_D')
    f.edge(name+'_B',name+'_12',label='2,D-'+str(index1Set))
    f.edge(name+'_12',name+'_E')

    f.edge(name+'_C',name+'_21',label='1,D-'+str(index1Set))
    f.edge(name+'_21',name+'_F')
    f.edge(name+'_C',name+'_22',label='2,D-'+str(index1Set))
    f.edge(name+'_22',name+'_G')

def drawS(f,theType):
    name = theType._id
    index0Set = theType.indices[0][0]
    index1Set = theType.indices[1][0]

    f.attr('node', shape='circle')
    f.node(name+'_A',label='')
    f.node(name+'_B',label='')
    f.node(name+'_C',label='')
    f.node(name+'_D',label='')
    f.node(name+'_E',label='1')
    f.node(name+'_F',label='1')
    f.node(name+'_G',label='1')
    f.node(name+'_H',label='1')
    f.node(name+'_I',label='3/4')
    f.node(name+'_J',label='1/2')
    f.node(name+'_K',label='1')
    f.node(name+'_L',label='1/2')

    f.attr('node', shape='point')
    f.node(name+'_0*',label='')
    f.node(name+'_1*',label='')
    f.node(name+'_2*',label='')
    f.node(name+'_00',label='')
    f.node(name+'_01',label='')
    f.node(name+'_02',label='')
    f.node(name+'_10',label='')
    f.node(name+'_11',label='')
    f.node(name+'_12',label='')
    f.node(name+'_20',label='')
    f.node(name+'_21',label='')

    f.edge(name+'_A',name+'_0*',label='0,D-'+str(index0Set))
    f.edge(name+'_0*',name+'_B')
    f.edge(name+'_A',name+'_1*',label='1,D-'+str(index0Set))
    f.edge(name+'_1*',name+'_C')
    f.edge(name+'_A',name+'_2*',label='2,D-'+str(index0Set))
    f.edge(name+'_2*',name+'_D')


    f.edge(name+'_B',name+'_00',label='0,D-'+str(index1Set))
    f.edge(name+'_00',name+'_E')
    f.edge(name+'_B',name+'_01',label='1,D-'+str(index1Set))
    f.edge(name+'_01',name+'_F')
    f.edge(name+'_B',name+'_02',label='2,D-'+str(index1Set))
    f.edge(name+'_02',name+'_G')


    f.edge(name+'_C',name+'_10',label='0,D-'+str(index1Set))
    f.edge(name+'_10',name+'_H')
    f.edge(name+'_C',name+'_11',label='1,D-'+str(index1Set))
    f.edge(name+'_11',name+'_I')
    f.edge(name+'_C',name+'_12',label='2,D-'+str(index1Set))
    f.edge(name+'_12',name+'_J')


    f.edge(name+'_D',name+'_20',label='0,D-'+str(index1Set))
    f.edge(name+'_20',name+'_K')
    f.edge(name+'_D',name+'_21',label='1,D-'+str(index1Set))
    f.edge(name+'_21',name+'_L')

def drawP(f,theType):
    name = theType._id
    index0Set = theType.indices[0][0]
    index1Set = theType.indices[1][0]

    f.attr('node', shape='circle')
    f.node(name+'_A',label='')
    f.node(name+'_B',label='')
    f.node(name+'_C',label='')
    f.node(name+'_D',label='')
    f.node(name+'_E',label='1/2')
    f.node(name+'_F',label='1/2')
    f.node(name+'_G',label='1/2')
    f.node(name+'_H',label='1/2')
    f.node(name+'_I',label='1/2')
    f.node(name+'_J',label='1/4')
    f.node(name+'_K',label='1/2')
    f.node(name+'_L',label='1/4')
    f.node(name+'_M',label='1/2')

    f.attr('node', shape='point')
    f.node(name+'_0*',label='')
    f.node(name+'_1*',label='')
    f.node(name+'_2*',label='')
    f.node(name+'_00',label='')
    f.node(name+'_01',label='')
    f.node(name+'_02',label='')
    f.node(name+'_10',label='')
    f.node(name+'_11',label='')
    f.node(name+'_12',label='')
    f.node(name+'_20',label='')
    f.node(name+'_21',label='')

    f.edge(name+'_A',name+'_0*',label='0,D-'+str(index0Set))
    f.edge(name+'_0*',name+'_B')
    f.edge(name+'_A',name+'_1*',label='1,D-'+str(index0Set))
    f.edge(name+'_1*',name+'_C')
    f.edge(name+'_A',name+'_2*',label='2,D-'+str(index0Set))
    f.edge(name+'_2*',name+'_D')


    f.edge(name+'_B',name+'_00',label='0,D-'+str(index1Set))
    f.edge(name+'_00',name+'_E')
    f.edge(name+'_B',name+'_01',label='1,D-'+str(index1Set))
    f.edge(name+'_01',name+'_F')
    f.edge(name+'_B',name+'_02',label='2,D-'+str(index1Set))
    f.edge(name+'_02',name+'_G')


    f.edge(name+'_C',name+'_10',label='0,D-'+str(index1Set))
    f.edge(name+'_10',name+'_H')
    f.edge(name+'_C',name+'_11',label='1,D-'+str(index1Set))
    f.edge(name+'_11',name+'_I')
    f.edge(name+'_C',name+'_12',label='2,D-'+str(index1Set))
    f.edge(name+'_12',name+'_J')


    f.edge(name+'_D',name+'_20',label='0,D-'+str(index1Set))
    f.edge(name+'_20',name+'_K')
    f.edge(name+'_D',name+'_21',label='1,D-'+str(index1Set))
    f.edge(name+'_21',name+'_L')
    f.edge(name+'_D',name+'_22',label='2,D-'+str(index1Set))
    f.edge(name+'_22',name+'_M')

def drawG_0(f,theType):
    name = theType._id
    index1Set = theType.indices[1][0]
    index2Set = theType.indices[2][0]

    f.attr('node', shape='circle')
    f.node(name+'_0_A',label='')
    f.node(name+'_0_B',label='')
    f.node(name+'_0_C',label='')
    f.node(name+'_0_D',label='1')
    f.node(name+'_0_E',label='1/2')
    f.node(name+'_0_F',label='1/2')
    f.node(name+'_0_G',label='1/4')

    f.attr('node', shape='point')
    f.node(name+'_0_0*',label='')
    f.node(name+'_0_1*',label='')
    f.node(name+'_0_00',label='')
    f.node(name+'_0_01',label='')
    f.node(name+'_0_10',label='')
    f.node(name+'_0_11',label='')

    f.edge(name+'_0_A',name+'_0_0*',label='0,D-'+str(index1Set))
    f.edge(name+'_0_0*',name+'_0_B')
    f.edge(name+'_0_A',name+'_0_1*',label='1,D-'+str(index1Set))
    f.edge(name+'_0_1*',name+'_0_C')


    f.edge(name+'_0_B',name+'_0_00',label='0,D-'+str(index2Set))
    f.edge(name+'_0_00',name+'_0_D')
    f.edge(name+'_0_B',name+'_0_01',label='1,D-'+str(index2Set))
    f.edge(name+'_0_01',name+'_0_E')


    f.edge(name+'_0_C',name+'_0_10',label='0,D-'+str(index2Set))
    f.edge(name+'_0_10',name+'_0_F')
    f.edge(name+'_0_C',name+'_0_11',label='1,D-'+str(index2Set))
    f.edge(name+'_0_11',name+'_0_G')

def drawG_1(f,theType):
    name = theType._id
    index1Set = theType.indices[1][0]
    index2Set = theType.indices[2][0]

    f.attr('node', shape='circle')
    f.node(name+'_1_A',label='')
    f.node(name+'_1_B',label='')
    f.node(name+'_1_C',label='')
    f.node(name+'_1_D',label='')
    f.node(name+'_1_E',label='1/2')
    f.node(name+'_1_F',label='1')
    f.node(name+'_1_G',label='1/2')
    f.node(name+'_1_H',label='1/2')
    f.node(name+'_1_I',label='1/2')
    f.node(name+'_1_J',label='1')
    f.node(name+'_1_K',label='1/2')

    f.attr('node', shape='point')
    f.node(name+'_1_0*',label='')
    f.node(name+'_1_1*',label='')
    f.node(name+'_1_2*',label='')
    f.node(name+'_1_01',label='')
    f.node(name+'_1_02',label='')
    f.node(name+'_1_10',label='')
    f.node(name+'_1_11',label='')
    f.node(name+'_1_12',label='')
    f.node(name+'_1_20',label='')
    f.node(name+'_1_21',label='')

    f.edge(name+'_1_A',name+'_1_0*',label='0,D-'+str(index1Set))
    f.edge(name+'_1_0*',name+'_1_B')
    f.edge(name+'_1_A',name+'_1_1*',label='1,D-'+str(index1Set))
    f.edge(name+'_1_1*',name+'_1_C')
    f.edge(name+'_1_A',name+'_1_2*',label='2,D-'+str(index1Set))
    f.edge(name+'_1_2*',name+'_1_D')


    f.edge(name+'_B',name+'_01',label='1,D-'+str(index2Set))
    f.edge(name+'_01',name+'_E')
    f.edge(name+'_B',name+'_02',label='2,D-'+str(index2Set))
    f.edge(name+'_02',name+'_F')


    f.edge(name+'_C',name+'_10',label='0,D-'+str(index2Set))
    f.edge(name+'_10',name+'_G')
    f.edge(name+'_C',name+'_11',label='1,D-'+str(index2Set))
    f.edge(name+'_11',name+'_H')
    f.edge(name+'_C',name+'_12',label='2,D-'+str(index2Set))
    f.edge(name+'_12',name+'_I')


    f.edge(name+'_D',name+'_20',label='0,D-'+str(index2Set))
    f.edge(name+'_20',name+'_J')
    f.edge(name+'_D',name+'_21',label='1,D-'+str(index2Set))
    f.edge(name+'_21',name+'_K')

def drawG_2(f,theType):
    name = theType._id
    index1Set = theType.indices[1][0]
    index2Set = theType.indices[2][0]

    f.attr('node', shape='circle')
    f.node(name+'_2_A',label='')
    f.node(name+'_2_B',label='')
    f.node(name+'_2_C',label='')
    f.node(name+'_2_D',label='1/4')
    f.node(name+'_2_E',label='1/2')
    f.node(name+'_2_F',label='1/2')
    f.node(name+'_2_G',label='1')

    f.attr('node', shape='point')
    f.node(name+'_2_1*',label='')
    f.node(name+'_2_2*',label='')
    f.node(name+'_2_11',label='')
    f.node(name+'_2_12',label='')
    f.node(name+'_2_21',label='')
    f.node(name+'_2_22',label='')

    f.edge(name+'_2_A',name+'_2_1*',label='1,D-'+str(index1Set))
    f.edge(name+'_2_1*',name+'_2_B')

    f.edge(name+'_2_A',name+'_2_2*',label='2,D-'+str(index1Set))
    f.edge(name+'_2_2*',name+'_2_C')

    f.edge(name+'_2_B',name+'_2_11',label='1,D-'+str(index2Set))
    f.edge(name+'_2_11',name+'_2_D')

    f.edge(name+'_2_B',name+'_2_12',label='2,D-'+str(index2Set))
    f.edge(name+'_2_12',name+'_2_E')

    f.edge(name+'_2_C',name+'_2_21',label='1,D-'+str(index2Set))
    f.edge(name+'_2_21',name+'_2_F')

    f.edge(name+'_2_C',name+'_2_22',label='2,D-'+str(index2Set))
    f.edge(name+'_2_22',name+'_2_G')

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

def connectTypes(f,first,second):
    firstName = first._id
    secondName = second._id
    
    info = first.nextVal()
    while(info):
        left,right,val = info

        left = ['zero','one','two'].index(left)
        f.edge(firstName+'_'+left+'*',secondName+'_'+str(left)+'_A')

        right = ['zero','one','two'].index(right)
        for t in second.bottomIndices if t[1] == right:
            pass


        info = first.nextVal()

def visualize(types):
    allTypes,allSets = generateAllTypesAndSets(types)

    f = Digraph(comment='This pedigree')

    # drawSingleType(f,allTypes[0])
    drawSingleType(f,allTypes[2],branch=2)

    f.view()
    assert 0
