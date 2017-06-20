import os
import csv
import math
from model import *
from ipNEW import *
from getGHelper import *
import numpy as np

class PedigreeClassifier:

    def __init__(self):
        

        self.dominantString = 'dominant'
        self.recessiveString = 'recessive'
        self.autosomeContext = autosomeProblem
        self.chromosomeContext = chromosomeProblem

        self.ADOpt = PyEMOptimizer(self.dominantString,self.autosomeContext)
        self.AROpt = PyEMOptimizer(self.recessiveString,self.autosomeContext)
        self.XLROpt = PyEMOptimizer(self.recessiveString,self.chromosomeContext)

        self.attempts = 1

    def printModelParams(self):
        adName = "empoAD"
        self.ADOpt.printModelParameters(adName)

        arName = "empoAR"
        self.AROpt.printModelParameters(arName)

        xlrName = "empoXLR"
        self.XLROpt.printModelParameters(xlrName)

    def printForDebug(self):

        adName = "empoAD"
        self.ADOpt.printInitializer(adName)
        self.ADOpt.printModelParameters(adName)

        arName = "empoAR"
        self.AROpt.printInitializer(arName)
        self.AROpt.printModelParameters(arName)

        xlrName = "empoXLR"
        self.XLROpt.printInitializer(xlrName)
        self.XLROpt.printModelParameters(xlrName)

    def train(self,ADfilenames,ARfilenames,XLRfilenames,rootProbUpdate,emissionProbUpdate,transitionProbUpdate,printPeople,printWork):
        for f in ADfilenames:
            self.ADOpt.addPedigree(f,self.autosomeContext,self.dominantString)
        for f in ARfilenames:
            self.AROpt.addPedigree(f,self.autosomeContext,self.recessiveString)
        for f in XLRfilenames:
            self.XLROpt.addPedigree(f,self.chromosomeContext,self.recessiveString)

        self.ADfilenames = ADfilenames
        self.ARfilenames = ARfilenames
        self.XLRfilenames = XLRfilenames

        self.ADOpt.train(printPeople,printWork,rootProbUpdate,emissionProbUpdate,transitionProbUpdate)
        self.AROpt.train(printPeople,printWork,rootProbUpdate,emissionProbUpdate,transitionProbUpdate)
        self.XLROpt.train(printPeople,printWork,rootProbUpdate,emissionProbUpdate,transitionProbUpdate)


    def predictExpectedProbability(self,opt,f,printPeople,printWork):

        maxProb = -1
        for i in range(self.attempts):
            prob = opt.predictExpectedProbability(f,printPeople,printWork)
            if(prob > maxProb):
                maxProb = prob
        return maxProb

    def predictMostLikelyProbability(self,opt,f,printPeople,printWork):

        maxProb = -1
        for i in range(self.attempts):
            prob = opt.predictMostLikelyProbability(f,printPeople,printWork)
            if(prob > maxProb):
                maxProb = prob
        return maxProb

    def testExpected(self,filenames,printPeople,printWork):
        predictions = []
        for f in filenames:
            ADExpectedProb = self.predictExpectedProbability(self.ADOpt,f,printPeople,printWork)
            ARExpectedProb = self.predictExpectedProbability(self.AROpt,f,printPeople,printWork)
            XLRExpectedProb = self.predictExpectedProbability(self.XLROpt,f,printPeople,printWork)

            print('\n')
            print(f)
            print('-----------------------')
            print('AD expected: '+str(ADExpectedProb))
            print('AR expected: '+str(ARExpectedProb))
            print('XLR expected: '+str(XLRExpectedProb))
            prediction = np.argmax([ADExpectedProb,ARExpectedProb,XLRExpectedProb])
            predictions.append(prediction)
        print(predictions)
        return predictions

    def testMostLikely(self,filenames,printPeople,printWork):
        predictions = []
        for f in filenames:

            print('\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Now working on '+str(f)+' ~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n')

            ADMostLikelyProb = self.predictMostLikelyProbability(self.ADOpt,f,printPeople,printWork)
            ARMostLikelyProb = self.predictMostLikelyProbability(self.AROpt,f,printPeople,printWork)
            XLRMostLikelyProb = self.XLROpt.predictMostLikelyProbability(f,printPeople,printWork)

            print('\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n')
            print('Results for: '+str(f))
            print('\n-----------------------\n')
            print('AD most likely prob: '+str(ADMostLikelyProb))
            print('AR most likely prob: '+str(ARMostLikelyProb))
            print('XLR most likely prob: '+str(XLRMostLikelyProb))
            prediction = np.argmax([ADMostLikelyProb,ARMostLikelyProb])
            prediction = np.argmax([ADMostLikelyProb,ARMostLikelyProb,XLRMostLikelyProb])
            predictions.append(prediction)
        print(predictions)
        return predictions

    def testAll(self,filenames,printPeople,printWork):
        predictionsMostLikely = []
        predictionsExpected = []
        allPredictions = []
        for f in filenames:

            print('\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Now working on '+str(f)+' ~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n')

            print('\n\n ===== Expected Work ===== \n\n')
            print('\n ---- About to work on Expected Work AD ---- \n')
            ADExpectedProb = self.predictExpectedProbability(self.ADOpt,f,printPeople,printWork)
            print('\n ---- About to work on Expected Work AR ---- \n')
            ARExpectedProb = self.predictExpectedProbability(self.AROpt,f,printPeople,printWork)
            print('\n ---- About to work on Expected Work XLR ---- \n')
            XLRExpectedProb = self.predictExpectedProbability(self.XLROpt,f,printPeople,printWork)

            print('\n\n ===== Most Likely Work ===== \n\n')
            print('\n ---- About to work on Most Likely Work AD ---- \n')
            ADMostLikelyProb = self.predictMostLikelyProbability(self.ADOpt,f,printPeople,printWork)
            print('\n ---- About to work on Most Likely Work AR ---- \n')
            ARMostLikelyProb = self.predictMostLikelyProbability(self.AROpt,f,printPeople,printWork)
            print('\n ---- About to work on Most Likely Work XLR ---- \n')
            XLRMostLikelyProb = self.predictMostLikelyProbability(self.XLROpt,f,printPeople,printWork)

            print('\n')

            print('\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n')
            print('Results for: '+str(f))
            print('\n-----------------------\n')
            print('AD expected: '+str(ADExpectedProb)+' and most likely prob: '+str(ADMostLikelyProb))
            print('AR expected: '+str(ARExpectedProb)+' and most likely prob: '+str(ARMostLikelyProb))
            print('XLR expected: '+str(XLRExpectedProb)+' and most likely prob: '+str(XLRMostLikelyProb))

            predictionsMostLikely.append(np.argmax([ADMostLikelyProb,ARMostLikelyProb,XLRMostLikelyProb]))
            predictionsExpected.append(np.argmax([ADExpectedProb,ARExpectedProb,XLRExpectedProb]))
            allPredictions.append([[ADMostLikelyProb,ADExpectedProb],[ARMostLikelyProb,ARExpectedProb],[XLRMostLikelyProb,XLRExpectedProb]])

        print('Most likely predictions: '+str(predictionsMostLikely))
        print('Expected predictions: '+str(predictionsExpected))
        return [predictionsMostLikely,predictionsExpected,allPredictions]


def hasCycle(pedigree):

    # print('working on pedigree: '+str(pedigree.filename))


    # for p in pedigree.allPeople:
    #     if(p._id == 3):
    #         print('person: '+str(p._id)+' -> '+str([x[0]._id for x in p.mateKids]))
    #         print(p.mateKids)
    #         return

    currentSet = pedigree.roots

    famCount = 0
    for c in currentSet:
        c.path = []


    usedMates = []

    count=0
    while(len(currentSet) > 0):
        count+=1
        if(count == 15):
            return


        nextSet = []
        for p in currentSet:

            # print('person: '+str(p._id)+' -> '+str([x[0]._id for x in p.mateKids]))

            # add the children
            for mk in p.mateKids:
                mate = mk[0]
                children = mk[1]

                if(str(sorted([p._id,mate._id])) in usedMates):
                    continue

                if(mate not in currentSet):

                    nextSet.append(p)

                else:

                    if(len([x for x in p.path if x in mate.path]) > 0):
                        return True

                    for c in children:
                        
                        c.path = p.path+mate.path+[famCount]

                        if(c not in nextSet):
                            nextSet.append(c)
                    famCount += 1

                    usedMates.append(str(sorted([p._id,mate._id])))

        currentSet = nextSet

    return False


def allFiles(jsonFolderPath = '/Users/Eddie/kec-bot/app/pedigreeDataOLDBUTWORKS'):

    ADFiles = []
    ARFiles = []
    XLRFiles = []

    for root, dirs, filenames in os.walk(jsonFolderPath):
        for f in filenames:
            if('.json' not in f):
                continue

            if('test' in f):
                continue

            if(f == '6481MR.json'):
                goodFlag = True
                break

            if(f == '5777AH.json' or f == '6158AT.json'):
                continue # don't want to deal with adoption bs

            if(f == '5713BS.json'):
                # not sure whats going on here
                continue

            pedigreeClass = PyPedigree()
            # problem context and dominant or recessive are dummy values here.  only need inheritance pattern
            # print(f)
            filename = os.path.join(jsonFolderPath,f)
            pedigreeClass.initialization(filename,autosomeProblem,'dominant')
            trueIP = pedigreeClass.trueIP

            # skip cycles for the moment
            if(hasCycle(pedigreeClass)):
                continue

            if(trueIP == 'AD'):
                ADFiles.append(filename)
            elif(trueIP == 'AR'):
                ARFiles.append(filename)
            elif(trueIP == 'XL'):
                XLRFiles.append(filename)
        break


    return [ADFiles,ARFiles,XLRFiles]


def runOnData(jsonFolderPath = '/Users/Eddie/kec-bot/app/pedigreeDataOLDBUTWORKS'):

    ADData,ARData,XLRData = allFiles()

    for f in ADData:
        print(f)

    print('\n')

    for f in ARData:
        print(f)

    print('\n')

    for f in XLRData:
        print(f)

    print('\n')

    print('There are '+str(len(ADData))+' AD data points, '+str(len(ARData))+' AR data points, '+str(len(XLRData))+' XLR data points')

    printPeople = False
    printWork = False

    rootProbUpdate = True
    emissionProbUpdate = True
    transitionProbUpdate = True

    ADTrain = ADData
    ARTrain = ARData
    XLRTrain = XLRData

    ADTest = ADData
    ARTest = ARData
    XLRTest = XLRData

    classifier = PedigreeClassifier()


    # classifier.train([],[],['/Users/Eddie/kec-bot/app/pedigreeDataOLDBUTWORKS/test_XL.json'],rootProbUpdate,emissionProbUpdate,transitionProbUpdate,True,printWork)
    # assert 0

    # classifier.printForDebug()
    classifier.train(ADTrain,ARTrain,XLRTrain,rootProbUpdate,emissionProbUpdate,transitionProbUpdate,printPeople,printWork)

    print('\n==========================================\nAD TESTS\n==========================================\n')
    resultMostLikely,resultExpected,allPredictionsAD = classifier.testAll(ADTest,printPeople,printWork)
    accuracyADMostLikely = len([x for x in resultMostLikely if x == 0])/float(len(resultMostLikely))
    accuracyADExpected = len([x for x in resultExpected if x == 0])/float(len(resultExpected))
    print('Accuracy for AD - Most likely: '+str(accuracyADMostLikely)+' Expected: '+str(accuracyADExpected))
    allPredictionsAD = [0,allPredictionsAD]

    print('\n==========================================\nAR TESTS\n==========================================\n')
    resultMostLikely,resultExpected,allPredictionsAR = classifier.testAll(ARTest,printPeople,printWork)
    accuracyARMostLikely = len([x for x in resultMostLikely if x == 1])/float(len(resultMostLikely))
    accuracyARExpected = len([x for x in resultExpected if x == 1])/float(len(resultExpected))
    print('Accuracy for AR - Most likely: '+str(accuracyARMostLikely)+' Expected: '+str(accuracyARExpected))
    allPredictionsAR = [1,allPredictionsAR]

    print('\n==========================================\nXLR TESTS\n==========================================\n')
    resultMostLikely,resultExpected,allPredictionsXLR = classifier.testAll(XLRTest,printPeople,printWork)
    accuracyXLRMostLikely = len([x for x in resultMostLikely if x == 2])/float(len(resultMostLikely))
    accuracyXLRExpected = len([x for x in resultExpected if x == 2])/float(len(resultExpected))
    print('Accuracy for XLR - Most likely: '+str(accuracyXLRMostLikely)+' Expected: '+str(accuracyXLRExpected))
    allPredictionsXLR = [2,allPredictionsXLR]

    print('\n\nFor later analysis:')
    print('accuracyADMostLikely: '+str(accuracyADMostLikely))
    print('accuracyADExpected: '+str(accuracyADExpected))

    print('accuracyARMostLikely: '+str(accuracyARMostLikely))
    print('accuracyARExpected: '+str(accuracyARExpected))

    print('accuracyXLRMostLikely: '+str(accuracyXLRMostLikely))
    print('accuracyXLRExpected: '+str(accuracyXLRExpected))

    classifier.printModelParams()

    print('\n\nallPredictionsAD\n')
    print(allPredictionsAD)
    print('\n\nallPredictionsAR\n')
    print(allPredictionsAR)
    print('\n\nallPredictionsXLR\n')
    print(allPredictionsXLR)

def loocv(jsonFolderPath = '/Users/Eddie/kec-bot/app/pedigreeDataOLDBUTWORKS'):

    ADData,ARData,XLRData = allFiles()

    ADData = ADData 
    ARData = ARData 
    XLRData = XLRData

    for f in ADData:
        print(f)
    print('\n')
    for f in ARData:
        print(f)
    print('\n')
    for f in XLRData:
        print(f)
    print('\n')
    print('There are '+str(len(ADData))+' AD data points, '+str(len(ARData))+' AR data points, '+str(len(XLRData))+' XLR data points')

    printPeople = False
    printWork = False

    rootProbUpdate = True
    emissionProbUpdate = True
    transitionProbUpdate = True

    allResults = []

    adAccuracy = [0,0]
    for testPoint in ADData:
        ADTrain = [x for x in ADData if x != testPoint]
        ARTrain = ARData
        XLRTrain = XLRData

        classifier = PedigreeClassifier()
        classifier.train(ADTrain,ARTrain,XLRTrain,rootProbUpdate,emissionProbUpdate,transitionProbUpdate,printPeople,printWork)

        resultMostLikely,resultExpected,allPredictions = classifier.testAll([testPoint],printPeople,printWork)
        if(resultMostLikely[0] == 0):
            adAccuracy[0] += 1
        if(resultExpected[0] == 0):
            adAccuracy[1] += 1
        allResults.append([0,allPredictions])

    arAccuracy = [0,0]
    for testPoint in ARData:
        ADTrain = ADData
        ARTrain = [x for x in ARData if x != testPoint]
        XLRTrain = XLRData

        classifier = PedigreeClassifier()
        classifier.train(ADTrain,ARTrain,XLRTrain,rootProbUpdate,emissionProbUpdate,transitionProbUpdate,printPeople,printWork)

        resultMostLikely,resultExpected,allPredictions = classifier.testAll([testPoint],printPeople,printWork)
        if(resultMostLikely[0] == 0):
            arAccuracy[0] += 1
        if(resultExpected[0] == 0):
            arAccuracy[1] += 1
        allResults.append([1,allPredictions])

    xlrAccuracy = [0,0]
    for testPoint in XLRData:
        ADTrain = ADData
        ARTrain = ARData
        XLRTrain = [x for x in XLRData if x != testPoint]

        classifier = PedigreeClassifier()
        classifier.train(ADTrain,ARTrain,XLRTrain,rootProbUpdate,emissionProbUpdate,transitionProbUpdate,printPeople,printWork)

        resultMostLikely,resultExpected,allPredictions = classifier.testAll([testPoint],printPeople,printWork)
        if(resultMostLikely[0] == 0):
            xlrAccuracy[0] += 1
        if(resultExpected[0] == 0):
            xlrAccuracy[1] += 1
        allResults.append([2,allPredictions])

    print('\n\nadAccuracy ('+str(len(ADData))+' total): ['+str(adAccuracy[0]/float(len(ADData)))+','+str(adAccuracy[1]/float(len(ADData)))+']')
    print('arAccuracy ('+str(len(ARData))+' total): ['+str(arAccuracy[0]/float(len(ARData)))+','+str(arAccuracy[1]/float(len(ARData)))+']')
    print('xlrAccuracy ('+str(len(XLRData))+' total): ['+str(xlrAccuracy[0]/float(len(XLRData)))+','+str(xlrAccuracy[1]/float(len(XLRData)))+']')
    print(allResults)

# There are 35 AD data points, 41 AR data points, 21 XLR data points

# runOnData()
loocv()
