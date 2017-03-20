from graphviz import Digraph
from smartWayPlus import *
from colors import *
from ipTree import *

def displaySingleType(f,theType,whichBranch,colorMappingEdges,colorMappingNodes):

    rootName = str(theType.get_name())+'_'+str(theType.get_id())+'_'+str(whichBranch)
    if(theType.is_root()):
        nodeColor = rootName
    else:
        nodeColor = str(theType.get_name())+'_'+str(whichBranch)

    indices = theType.get_indices()
    if(theType.is_root()):
        index0 = indices[0][0]
        index1 = indices[1][0]
    else:
        index0 = indices[1][0]
        index1 = indices[2][0]

    vals = theType.get_vals()[whichBranch]
    g = Digraph()

    g.attr('node', shape='circle', color=colorMappingNodes[nodeColor], style='filled')
    g.node(rootName,label=str(whichBranch))

    edgesUsed = {}

    for left,right,val in vals:

        leftPointName = rootName+'_leftPoint_'+str(left)
        leftCircleName = rootName+'_leftCircle_'+str(left)

        if(leftPointName not in edgesUsed):
            g.attr('node', shape='point', color='black')
            g.node(leftPointName,label='')
            g.edge(rootName,leftPointName,color=colorMappingEdges[index0],label=str(left))

            g.attr('node', shape='circle', color=colorMappingNodes[nodeColor], style='filled')
            g.node(leftCircleName,label='')
            g.edge(leftPointName,leftCircleName,color=colorMappingEdges[index0])

            edgesUsed[leftPointName] = 1

        rightPointName = rootName+'_rightPoint_'+str(left)+'_'+str(right)
        rightCircleName = rootName+'_rightCircle_'+str(left)+'_'+str(right)

        if(rightPointName not in edgesUsed):
            g.attr('node', shape='point', color='black')
            g.node(rightPointName,label='')
            g.edge(leftCircleName,rightPointName,color=colorMappingEdges[index1],label=str(right))

            g.attr('node', shape='circle', color=colorMappingNodes[nodeColor], style='filled')
            g.node(rightCircleName,label=str(val))
            g.edge(rightPointName,rightCircleName,color=colorMappingEdges[index1])

            edgesUsed[rightPointName] = 1

    f.subgraph(g)

def drawHelper(f,currentType,whichBranch,colorMappingEdges,colorMappingNodes,drawnTypes):

    keepGoing,left,right,val = currentType.get_next_val(whichBranch,False)

    edgesUsed = {}

    while(keepGoing):

        if(currentType.left):

            comingFrom = str(currentType.get_name())+'_'+str(currentType.get_id())+'_'+str(whichBranch)+'_leftPoint_'+str(left)
            goingTo = str(currentType.left.get_name())+'_'+str(currentType.left.get_id())+'_'+str(left)

            if(comingFrom not in edgesUsed):
                if(str(goingTo) not in drawnTypes):
                    displaySingleType(f,currentType.left,left,colorMappingEdges,colorMappingNodes)
                    drawnTypes[goingTo] = 1
                if(str(goingTo)+'_'+str(comingFrom) not in drawnTypes):
                    f.edge(comingFrom,goingTo)
                    drawnTypes[str(goingTo)+'_'+str(comingFrom)] = 1
                drawHelper(f,currentType.left,left,colorMappingEdges,colorMappingNodes,drawnTypes)
                edgesUsed[comingFrom] = 1

        if(currentType.right):

            comingFrom = str(currentType.get_name())+'_'+str(currentType.get_id())+'_'+str(whichBranch)+'_leftPoint_'+str(right)
            goingTo = str(currentType.right.get_name())+'_'+str(currentType.right.get_id())+'_'+str(right)

            if(comingFrom not in edgesUsed):
                if(str(goingTo) not in drawnTypes):
                    displaySingleType(f,currentType.right,right,colorMappingEdges,colorMappingNodes)
                    drawnTypes[goingTo] = 1
                if(str(goingTo)+'_'+str(comingFrom) not in drawnTypes):
                    f.edge(comingFrom,goingTo)
                    drawnTypes[str(goingTo)+'_'+str(comingFrom)] = 1
                drawHelper(f,currentType.right,right,colorMappingEdges,colorMappingNodes,drawnTypes)
                edgesUsed[comingFrom] = 1

        keepGoing,left,right,val = currentType.get_next_val(whichBranch,False)


def visualize(roots,allTypes,numbRoots):

    colorMappingEdges = {}
    colorMappingNodes = {}
    for a in allTypes:
        indices = a.get_indices()
        for i in indices:
            if(i[0] not in colorMappingEdges):
                colorMappingEdges[i[0]] = 1
        if(a.is_root()):
            colorMappingNodes[str(a.get_name())+'_'+str(a.get_id())+'_0'] = 1
        else:
            for i in range(8):
                colorMappingNodes[str(a.get_name())+'_'+str(i)] = 2

    colors = getColors(len(colorMappingEdges))
    for i,k in enumerate(colorMappingEdges):
        if(k < numbRoots):
            colorMappingEdges[k] = colors[i]
        else:
            colorMappingEdges[k] = 'black'
        
    colors = getColors(len(colorMappingNodes),reverse=True)
    for i,k in enumerate(colorMappingNodes):
        colorMappingNodes[k] = colors[i]


    f = Digraph(comment='Pedigree Computation')
    drawnTypes = {}
    for r in roots:
        displaySingleType(f,r,0,colorMappingEdges,colorMappingNodes)
        drawHelper(f,r,0,colorMappingEdges,colorMappingNodes,drawnTypes)

    f.view()
