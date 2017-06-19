// g++ logProbIPNew.cpp BMIP.cpp helperFunctions.cpp uniformMonteCarloIntegration.cpp pdfSamplingMonteCarloIntegration.cpp cMain.cpp -I/usr/local/include -L/usr/local/lib -lgsl -lgslcblas -O3 -std=c++11

#ifndef BMIP_H
#define BMIP_H

#include <unordered_set>
#include <iomanip>
#include "logProbIPNew.h"

#define PRECISION pow(10,-8)
#define LOG_PRECISION log(pow(10,-8))
#define UNIQUE_ZERO_ID 1234.5678


using namespace std;

class EMPedigreeOptimizer {

    int _nTabs = 0;

    bool _firstUpdate = false;

    bool _sexDependent;
    int _femaleN;
    int _maleN;
    int _unknownN;
    vector<pedigreeClass2*> _trainingSet;

    /* =========================================================================================== */

    vector<vector<vector<pair<int,double>>>> _log_u;
    vector<vector<vector<vector<vector<pair<int,double>>>>>> _log_w;
    vector<vector<vector<vector<pair<int,double>>>>> _log_a;
    vector<vector<vector<vector<vector<vector<pair<int,double>>>>>>> _log_b;


    vector<vector<vector<double>>> _log_c;
    vector<vector<vector<vector<double>>>> _log_d;
    vector<vector<vector<vector<vector<vector<vector<double>>>>>>> _log_e;

    /* =========================================================================================== */

    // root probs is indexed by: [pedigree][root][trueChromosomes]
    // transition probs is indexed by: [childSexIndex][motherChrom][fatherChrom][childChrom]
    // person can be ['shaded', 'possiblyShaded', 'unshaded', 'carrier'] or ['shaded', 'unshaded']
    // emission probs is indexed by: [sex][trueChromosomes][shadingObservation]
    vector<vector<vector<double>>> _rootProbs;
    vector<vector<vector<vector<double>>>> _transitionProbs;
    vector<vector<vector<double>>> _emissionProbs;
    unordered_map<string,int> _emissionMapping;
    
    /* =========================================================================================== */

    /* fuck this shit tho */
    void _transitionProbHack();

    /* implemented in helperFunctions.cpp */
    double _safeAdd(double lhs, double rhs);
    void _safeAdd(logAddition &lhs, double rhs);
    double _safeExp(double log_val);
    bool _logCompare(double log_a, double log_b);
    double _getEmissionProb(pedigreeClass2* pedigree, personClass* person, int state);
    double _getRootProb(pedigreeClass2* pedigree, personClass* person, int state);
    double _getTransitionProb(pedigreeClass2* pedigree, personClass* person, int motherState, int fatherState, int state);
    vector<personClass*>& _getFamily(pedigreeClass2* pedigree, personClass* parentA, personClass* parentB);
    personClass* _getMother(personClass* person);
    personClass* _getFather(personClass* person);
    double _safeReturn(logAddition sum);
    int _getSexIndex(pedigreeClass2* pedigree, personClass* person);
    void _sortMates(personClass* mateA, personClass* mateB, personClass*& femaleMate, personClass*& maleMate);
    int _getFamNumb(pedigreeClass2* pedigree, personClass* mateA, personClass* mateB);
    void _resetDataStructures();
    vector<double> _leastSquaresDiff(const vector<vector<vector<double>>> & oldRootProbs, const vector<vector<vector<vector<double>>>> & oldTransitionProbs, const vector<vector<vector<double>>> & oldEmissionProbs);
    void _resetPedigrees();

    /* implemented in BMIP_eStep.cpp */
    double _getLogUVal(pedigreeClass2* pedigree, int d, personClass* child, int k);
    double _getLogWVal(pedigreeClass2* pedigree, int d, int f, int motherIsP, int i, int j);
    double _getLogAVal(pedigreeClass2* pedigree, int d, int f, int motherIsP, int i);
    double _getLogBVal(pedigreeClass2* pedigree, int d, int f, int i, int j, personClass* child, int c);
    void _computeLogAVal(pedigreeClass2* pedigree, int d, int f, int motherIsP, int i);
    void _computeLogBVal(pedigreeClass2* pedigree, int d, int f, int i, int j, personClass* child, int c);
    void _computeLogUVal(pedigreeClass2* pedigree, int d, personClass* child, int k);
    void _computeLogWVal(pedigreeClass2* pedigree, int d, int f, int motherIsP, int i, int j);
    void _log_cUpdate(double& log_PofY);
    void _log_dUpdate(double& log_PofY);
    void _log_eUpdate(double& log_PofY);
    void _log_eStep2(double& log_PofY);

    /* implemented in BMIP_mStep.cpp */
    void _log_updateRootProbs2();   
    void _log_updateEmissionProbs2();  
    void _log_updateTransitionProbs2(); 
    void _log_mStep2(bool rootProbUpdate, bool emissionProbUpdate, bool transitionProbUpdate);

    /* implemented in BMIPLog.cpp */
    void _log_initialize(const vector<pedigreeClass2*> & trainingSet_, string problemType, bool printPeople, bool initializeRoots, bool initializeEmission, bool initializeTransition);
    void _log_EMStep2(bool rootProbUpdate, bool emissionProbUpdate, bool transitionProbUpdate);
    void _train(const vector<pedigreeClass2*> & trainingSet, string problemType, bool printPeople, bool printWork, bool rootProbUpdate, bool emissionProbUpdate, bool transitionProbUpdate, bool initializeRoots, bool initializeEmission, bool initializeTransition);
    void _trainRoots(const vector<pedigreeClass2*> & testSet, string problemType, bool printPeople, bool printWork);
    double _calcProb();
    void _viterbiUpdate(pedigreeClass2* pedigree);
    void _calculateViterbiStates(pedigreeClass2* pedigree, string problemType, bool printPeople, bool printWork);


public:

    void setModelParameters(const vector<vector<vector<vector<double>>>>& transitionProbs, const vector<vector<vector<double>>>& emissionProbs) {
        _transitionProbs = transitionProbs;
        _emissionProbs = emissionProbs;
        _firstUpdate = true;
    }

    void printModelParameters(string name) {

        string transProbString = "vector<vector<vector<vector<double>>>>({";
        for(int i=0; i<_transitionProbs.size(); ++i) {
            transProbString += "\n\t{";
            for(int j=0; j<_transitionProbs.at(i).size(); ++j) {
                transProbString += "\n\t\t{";
                for(int k=0; k<_transitionProbs.at(i).at(j).size(); ++k) {
                    transProbString += "\n\t\t\t{";
                    for(int l=0; l<_transitionProbs.at(i).at(j).at(k).size(); ++l) {

                        double val = _transitionProbs.at(i).at(j).at(k).at(l);
                        if(l < _transitionProbs.at(i).at(j).at(k).size()-1) {
                            transProbString += to_string(val)+",";
                        }
                        else {
                            transProbString += to_string(val);
                        }
                    }
                    if(k < _transitionProbs.at(i).at(j).size()-1) {
                        transProbString += "\n\t\t\t},";
                    }
                    else {
                        transProbString += "\n\t\t\t}";
                    }
                }
                if(j < _transitionProbs.at(i).size()-1) {
                    transProbString += "\n\t\t},";
                }
                else {
                    transProbString += "\n\t\t}";
                }
            }
            if(i < _transitionProbs.size()-1) {
                transProbString += "\n\t},";
            }
            else {
                transProbString += "\n\t}";
            }
        }
        transProbString += "\n})";


        string emissProbString = "vector<vector<vector<double>>>({";
        for(int i=0; i<_emissionProbs.size(); ++i) {
            emissProbString += "\n\t{";
            for(int j=0; j<_emissionProbs.at(i).size(); ++j) {
                emissProbString += "\n\t\t{";
                for(int k=0; k<_emissionProbs.at(i).at(j).size(); ++k) {
                    
                    double val = _emissionProbs.at(i).at(j).at(k);
                    if(k < _emissionProbs.at(i).at(j).size()-1) {
                        emissProbString += to_string(val)+",";
                    }
                    else {
                        emissProbString += to_string(val);
                    }                    
                }
                if(j < _emissionProbs.at(i).size()-1) {
                    emissProbString += "\n\t\t},";
                }
                else {
                    emissProbString += "\n\t\t}";
                }
            }
            if(i < _emissionProbs.size()-1) {
                emissProbString += "\n\t},";
            }
            else {
                emissProbString += "\n\t}";
            }
        }
        emissProbString += "\n})";

        string toPrint = name+".setModelParameters("+transProbString+","+emissProbString+");";
        cout << toPrint << endl;
    }


    EMPedigreeOptimizer():
    _emissionMapping({{"shaded",0},{"unshaded",1}}) {
        _trainingSet = vector<pedigreeClass2*>();
    }

    // EMPedigreeOptimizer():
    // _emissionMapping({{"shaded",0},{"possiblyShaded",1},{"unshaded",2},{"carrier",3}}) {
    //     _trainingSet = vector<pedigreeClass2*>();
    // }

    
    void train(const vector<pedigreeClass2*> & trainingSet, string problemType, bool printPeople, bool printWork, bool rootProbUpdate, bool emissionProbUpdate, bool transitionProbUpdate) {

        bool initializeRoots = true;
        bool initializeEmission = true;
        bool initializeTransition = true;

        _train(trainingSet,problemType,printPeople,printWork,rootProbUpdate,emissionProbUpdate,transitionProbUpdate,initializeRoots,initializeEmission,initializeTransition);
        
        cout << "DONE TRAINING!" << endl;

        cout << "Final emission probabilities: " << endl;
        for(int i=0; i<_emissionProbs.size(); ++i) {
            for(int j=0; j<_emissionProbs.at(i).size(); ++j) {
                for(int k=0; k<_emissionProbs.at(i).at(j).size(); ++k) {
                    cout << setprecision(4) << _emissionProbs.at(i).at(j).at(k) << " ";
                }
                cout << endl;
            }
            cout << endl;
        }

        cout << "Final transition probabilities: " << endl;
        for(int i=0; i<_transitionProbs.size(); ++i) {
            cout << "----------" << endl;
            for(int j=0; j<_transitionProbs.at(i).size(); ++j) {
                for(int k=0; k<_transitionProbs.at(i).at(j).size(); ++k) {
                    for(int l=0; l<_transitionProbs.at(i).at(j).at(k).size(); ++l) {
                        cout << setprecision(4) << _transitionProbs.at(i).at(j).at(k).at(l) << " ";
                    }
                    cout << endl;
                }
                cout << endl;
            }
            cout << "----------" << endl;
            cout << endl;
        }
    }

    double predictExpectedProbability(pedigreeClass2* pedigree, string problemType, bool printPeople, bool printWork) {

        _trainRoots(vector<pedigreeClass2*>({pedigree}),problemType,printPeople,printWork);
        return _calcProb();
    }

    double predictMostLikelyProbability(pedigreeClass2* pedigree, string problemType, bool printPeople, bool printWork) {

        _calculateViterbiStates(pedigree,problemType,printPeople,printWork);
        return pedigree->mostLikelyStateProb;
    }

};

#endif
