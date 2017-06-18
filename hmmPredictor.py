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

        self.ADOpt = PyEMOptimizer('AD',self.dominantString,self.autosomeContext)
        self.AROpt = PyEMOptimizer('AR',self.recessiveString,self.autosomeContext)
        self.XLROpt = PyEMOptimizer('XLR',self.recessiveString,self.chromosomeContext)

        self.attempts = 1

    def train(self,ADfilenames,ARfilenames,XLRfilenames,rootProbUpdate,emissionProbUpdate,transitionProbUpdate,printPeople):
        # for f in ADfilenames:
        #     self.ADOpt.addPedigree(f,self.autosomeContext,self.dominantString)
        # for f in ARfilenames:
        #     self.AROpt.addPedigree(f,self.autosomeContext,self.recessiveString)
        for f in XLRfilenames:
            self.XLROpt.addPedigree(f,self.chromosomeContext,self.recessiveString)

        # self.ADfilenames = ADfilenames
        # self.ARfilenames = ARfilenames
        self.XLRfilenames = XLRfilenames

        # self.ADOpt.train('AD',printPeople,rootProbUpdate,emissionProbUpdate,transitionProbUpdate)
        # self.AROpt.train('AR',printPeople,rootProbUpdate,emissionProbUpdate,transitionProbUpdate)
        self.XLROpt.train('XLR',printPeople,rootProbUpdate,emissionProbUpdate,transitionProbUpdate)

    def predictExpectedProbability(self,opt,f,printPeople):

        maxProb = -1
        for i in range(self.attempts):
            prob = opt.predictExpectedProbability(f,printPeople)
            if(prob > maxProb):
                maxProb = prob
        return maxProb

    def predictMostLikelyProbability(self,opt,f,printPeople):

        maxProb = -1
        for i in range(self.attempts):
            prob = opt.predictMostLikelyProbability(f,printPeople)
            if(prob > maxProb):
                maxProb = prob
        return maxProb

    def testExpected(self,filenames,printPeople):
        predictions = []
        for f in filenames:
            ADExpectedProb = self.predictExpectedProbability(self.ADOpt,f,printPeople)
            ARExpectedProb = self.predictExpectedProbability(self.AROpt,f,printPeople)
            XLRExpectedProb = self.predictExpectedProbability(self.XLROpt,f,printPeople)

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

    def testMostLikely(self,filenames,printPeople):
        predictions = []
        for f in filenames:

            print('\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Now working on '+str(f)+' ~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n')

            ADMostLikelyProb = self.predictMostLikelyProbability(self.ADOpt,f,printPeople)
            ARMostLikelyProb = self.predictMostLikelyProbability(self.AROpt,f,printPeople)
            # XLRMostLikelyProb = self.XLROpt.predictMostLikelyProbability(f,printPeople)

            print('\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n')
            print('Results for: '+str(f))
            print('\n-----------------------\n')
            print('AD most likely prob: '+str(ADMostLikelyProb))
            print('AR most likely prob: '+str(ARMostLikelyProb))
            # print('XLR most likely prob: '+str(XLRMostLikelyProb))
            prediction = np.argmax([ADMostLikelyProb,ARMostLikelyProb])
            # prediction = np.argmax([ADMostLikelyProb,ARMostLikelyProb,XLRMostLikelyProb])
            predictions.append(prediction)
        print(predictions)
        return predictions

    def testAll(self,filenames,printPeople):
        predictionsMostLikely = []
        predictionsExpected = []
        for f in filenames:

            print('\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Now working on '+str(f)+' ~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n')

            print('\n\n ===== Expected Work ===== \n\n')
            # ADExpectedProb = self.predictExpectedProbability(self.ADOpt,f,printPeople)
            # ARExpectedProb = self.predictExpectedProbability(self.AROpt,f,printPeople)
            XLRExpectedProb = self.predictExpectedProbability(self.XLROpt,f,True)

            print('\n\n ===== Most Likely Work ===== \n\n')
            ADMostLikelyProb = self.predictMostLikelyProbability(self.ADOpt,f,printPeople)
            # ARMostLikelyProb = self.predictMostLikelyProbability(self.AROpt,f,printPeople)
            # XLRMostLikelyProb = self.predictMostLikelyProbability(self.XLROpt,f,printPeople)

            # print('\n')

            print('\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n')
            print('Results for: '+str(f))
            print('\n-----------------------\n')
            print('AD expected: '+str(ADExpectedProb)+' and most likely prob: '+str(ADMostLikelyProb))
            # print('AR expected: '+str(ARExpectedProb)+' and most likely prob: '+str(ARMostLikelyProb))
            # print('XLR expected: '+str(XLRExpectedProb)+' and most likely prob: '+str(XLRMostLikelyProb))

            assert 0

            predictionsMostLikely.append(np.argmax([ADMostLikelyProb,ARMostLikelyProb,XLRMostLikelyProb]))
            predictionsExpected.append(np.argmax([ADExpectedProb,ARExpectedProb,XLRExpectedProb]))

        print('Most likely predictions: '+str(predictionsMostLikely))
        print('Expected predictions: '+str(predictionsExpected))
        return [predictionsMostLikely,predictionsExpected]


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


# def mainFunction(jsonFolderPath = '/Users/Eddie/kec-bot/app/pedigreeDataOLDBUTWORKS'):

#     ADtrainingSet = ['test_hmm_hard.json','test.json','test_XL.json']
#     ADtrainingSet = [os.path.join(jsonFolderPath,f) for f in ADtrainingSet]

#     ARtrainingSet = ['test_hmm_hard.json','test.json','test_XL.json']
#     ARtrainingSet = [os.path.join(jsonFolderPath,f) for f in ARtrainingSet]

#     XLRtrainingSet = ['test_hmm_hard.json','test.json','test_XL.json']
#     XLRtrainingSet = [os.path.join(jsonFolderPath,f) for f in XLRtrainingSet]
    
#     testSet = ['test_XL.json']
#     testSet = [os.path.join(jsonFolderPath,f) for f in testSet]


#     classifier = PedigreeClassifier()
#     classifier.train(ADtrainingSet,ARtrainingSet,XLRtrainingSet,rootProbUpdate,emissionProbUpdate,transitionProbUpdate)
#     classifier.test(testSet)


# def cycleTest(jsonFolderPath = '/Users/Eddie/kec-bot/app/pedigreeDataOLDBUTWORKS'):
    
#     filename = '5713BS.json'
#     # filename = '1084LN.json'
#     filename = os.path.join(jsonFolderPath,filename)


#     pedigreeClass = PyPedigree()
#     # problem context and dominant or recessive are dummy values here.  only need inheritance pattern
#     pedigreeClass.initialization(filename,autosomeProblem,'dominant')
#     trueIP = pedigreeClass.trueIP

#     hasCycleVal = hasCycle(pedigreeClass)

#     print(hasCycleVal)


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
    classifier.train(ADTrain,ARTrain,XLRTrain,rootProbUpdate,emissionProbUpdate,transitionProbUpdate,printPeople)
    # assert 0
    # classifier.test(['/Users/Eddie/kec-bot/app/pedigreeDataOLDBUTWORKS/1084LN.json'])

    print('\n==========================================\nAD TESTS\n==========================================\n')
    resultMostLikely,resultExpected = classifier.testAll(ADTest,printPeople)
    accuracyADMostLikely = len([x for x in resultMostLikely if x == 0])/float(len(resultMostLikely))
    accuracyADExpected = len([x for x in resultExpected if x == 0])/float(len(resultExpected))
    print('Accuracy for AD - Most likely: '+str(accuracyADMostLikely)+' Expected: '+str(accuracyADExpected))

    # print('\n==========================================\nAR TESTS\n==========================================\n')
    # resultMostLikely,resultExpected = classifier.testAll(ARTest,printPeople)
    # accuracyARMostLikely = len([x for x in resultMostLikely if x == 1])/float(len(resultMostLikely))
    # accuracyARExpected = len([x for x in resultExpected if x == 1])/float(len(resultExpected))
    # print('Accuracy for AR - Most likely: '+str(accuracyARMostLikely)+' Expected: '+str(accuracyARExpected))

    # print('\n==========================================\nXLR TESTS\n==========================================\n')
    # resultMostLikely,resultExpected = classifier.testAll(XLRTest,printPeople)
    # accuracyXLRMostLikely = len([x for x in resultMostLikely if x == 1])/float(len(resultMostLikely))
    # accuracyXLRExpected = len([x for x in resultExpected if x == 1])/float(len(resultExpected))
    # print('Accuracy for XLR - Most likely: '+str(accuracyXLRMostLikely)+' Expected: '+str(accuracyXLRExpected))

    print('\n\nFor later analysis:')
    print('accuracyADMostLikely: '+str(accuracyADMostLikely))
    print('accuracyADExpected: '+str(accuracyADExpected))

    print('accuracyARMostLikely: '+str(accuracyARMostLikely))
    print('accuracyARExpected: '+str(accuracyARExpected))

    print('accuracyXLRMostLikely: '+str(accuracyXLRMostLikely))
    print('accuracyXLRExpected: '+str(accuracyXLRExpected))




# def leaveOneOutTesting(jsonFolderPath = '/Users/Eddie/kec-bot/app/pedigreeDataOLDBUTWORKS'):
#     ADData,ARData,XLRData = allFiles()

#     for f in ADData:
#         print(f)

#     print('\n')

#     for f in ARData:
#         print(f)

#     print('\n')

#     for f in XLRData:
#         print(f)

#     print('\n')

#     print('There are '+str(len(ADData))+' AD data points, '+str(len(ARData))+' AR data points, '+str(len(XLRData))+' XLR data points')

#     totalNumber = len(ADData) + len(ARData) + len(XLRData)

#     correct = 0

#     for i in range(totalNumber):

#         if(i < len(ADData)):
#             ADTrain = ADData[:i]+ADData[i+1:]
#             ARTrain = ARData
#             XLRTrain = XLRData
#             testPoint = ADData[i]
#             trueIP = 0
#         elif(i < len(ADData)+len(ARData)):
#             ADTrain = ADData
#             ARTrain = ARData[:(i-len(ADData))]+ARData[(i-len(ADData))+1:]
#             XLRTrain = XLRData
#             testPoint = ARData[i]
#             trueIP = 1
#         else:
#             ADTrain = ADData
#             ARTrain = ARData
#             XLRTrain = XLRData[:i(len(ADData)-ARData)]+XLRData[i(len(ADData)-ARData)+1:]
#             testPoint = XLRData[i]
#             trueIP = 2


#         classifier = PedigreeClassifier()
#         classifier.train(ADTrain,ARTrain,XLRTrain,rootProbUpdate,emissionProbUpdate,transitionProbUpdate)

#         result = classifier.test([testPoint])

#         if(result[0] == trueIP):
#             correct += 1

#         print('\n\n/=======================================/\nRun # '+str(i)+' Accuracy: '+str(float(correct)/(i+1))+'\n\n/=======================================/\n')

#     print('Final accuracy: '+str(float(correct)/totalNumber))


# print(allFiles())
# cycleTest()

# There are 35 AD data points, 41 AR data points, 21 XLR data points

runOnData()

# leaveOneOutTesting()


def mytest(jsonFolderPath = '/Users/Eddie/kec-bot/app/pedigreeDataOLDBUTWORKS'):


    rootProbUpdate = True
    emissionProbUpdate = False
    transitionProbUpdate = False
    
    # ADTrain = ['test_hmm_AD.json']
    # ADTrain = [os.path.join(jsonFolderPath,filename) for filename in ADTrain]
    # ARTrain = ['test_hmm_AR.json']
    # ARTrain = [os.path.join(jsonFolderPath,filename) for filename in ARTrain]
    # XLRTrain = []

    printPeople = False

    classifier = PedigreeClassifier()
    # classifier.train(ADTrain,ARTrain,XLRTrain,rootProbUpdate,emissionProbUpdate,transitionProbUpdate,printPeople)

    test = ['6457RB.json']
    test = [os.path.join(jsonFolderPath,filename) for filename in test]


    classifier.testMostLikely(test,printPeople)

# mytest()