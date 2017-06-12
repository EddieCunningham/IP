// g++ logProbIPNew.cpp BMIP.cpp helperFunctions.cpp uniformMonteCarloIntegration.cpp pdfSamplingMonteCarloIntegration.cpp cMain.cpp -I/usr/local/include -L/usr/local/lib -lgsl -lgslcblas -O3 -std=c++11

#ifndef BMIP_H
#define BMIP_H

#include "logProbIPNew.h"

#define PRECISION pow(10,-10)
#define LOG_PRECISION log(pow(10,-10))
#define UNIQUE_ZERO_ID 1234.5678

using namespace std;

class EMPedigreeOptimizer {

    int getSexIndex(pedigreeClass2* pedigree, personClass* person) {
        int sexIndex = 0;
        if(pedigree->sexDependent) {
            if(person->sex == "male") {
                sexIndex = 0;
            }
            else if(person->sex == "female") {
                sexIndex = 1;
            }
            else if(person->sex == "unknown") {
                sexIndex = 2;
            }
            else {
                cout << "Invalid sex" << endl;
                raise(SIGABRT);
            }
        }
        return sexIndex;
    }

    void sortMates(personClass* mateA, personClass* mateB, personClass*& femaleMate, personClass*& maleMate) {
        if(mateA->sex == "female") {
            femaleMate = mateA;
            maleMate = mateB;
        }
        else {
            maleMate = mateA;
            femaleMate = mateB;
        }
    }        

    int getFamNumb(pedigreeClass2* pedigree, personClass* mateA, personClass* mateB) {
        
        personClass* femaleParent = nullptr;
        personClass* maleParent = nullptr;
        sortMates(mateA,mateB,femaleParent,maleParent);
        
        int ans = 0;
        for(auto fam_it=pedigree->families.begin(); fam_it!=pedigree->families.end(); ++fam_it) {
            
            if(femaleParent == fam_it->at(0) && maleParent == fam_it->at(1)) {
                return ans;
            }
            ++ans;
        }
        cout << "Couldn't find a family with these two mates!" << endl;
        raise(SIGABRT);
        return -1;
    }

    // void _checkC();
    // void _checkD();
    // void _checkE();

    double _getLogUVal(pedigreeClass2* pedigree, int d, personClass* child, int k);
    double _getLogWVal(pedigreeClass2* pedigree, int d, int f, int motherIsP, int i, int j);
    double _getLogAVal(pedigreeClass2* pedigree, int d, int f, int motherIsP, int i);
    double _getLogBVal(pedigreeClass2* pedigree, int d, int f, int i, int j, personClass* child, int c);
    void _computeLogAVal(pedigreeClass2* pedigree, int d, int f, int motherIsP, int i);
    void _computeLogBVal(pedigreeClass2* pedigree, int d, int f, int i, int j, personClass* child, int c);
    void _computeLogUVal(pedigreeClass2* pedigree, int d, personClass* child, int k);
    void _computeLogWVal(pedigreeClass2* pedigree, int d, int f, int motherIsP, int i, int j);
    void _log_cUpdate();
    void _log_dUpdate();
    void _log_eUpdate();
    void _log_eStep2();

    void _log_updateRootProbs2();   
    void _log_updateEmissionProbs2();   
    void _log_updateTransitionProbs2(); 
    void _log_mStep2();
    





    // double _getUVal(pedigreeClass2* pedigree, int d, personClass* child, int k);
    // double _getWVal(pedigreeClass2* pedigree, int d, int f, int motherIsP, int i, int j);
    // double _getAVal(pedigreeClass2* pedigree, int d, int f, int motherIsP, int i);
    // double _getBVal(pedigreeClass2* pedigree, int d, int f, int i, int j, personClass* child, int c);
    // void _computeAVal(pedigreeClass2* pedigree, int d, int f, int motherIsP, int i);
    // void _computeBVal(pedigreeClass2* pedigree, int d, int f, int i, int j, personClass* child, int c);
    // void _computeUVal(pedigreeClass2* pedigree, int d, personClass* child, int k);
    // void _computeWVal(pedigreeClass2* pedigree, int d, int f, int motherIsP, int i, int j);

    // void _cUpdate();
    // void _dUpdate();
    // void _eUpdate();
    // void _eStep2();


    // void _updateRootProbs2();
    // void _updateEmissionProbs2();
    // void _updateTransitionProbs2();
    // void _mStep2();



    // void _updateAndCompareC();
    // void _updateAndCompareD();
    // void _updateAndCompareE();



    void _resetDataStructures() {

        for(int i=0; i<_log_u.size(); ++i) {
            for(int j=0; j<_log_u.at(i).size(); ++j) {
                for(int k=0; k<_log_u.at(i).at(j).size(); ++k) {
                    _log_u.at(i).at(j).at(k).first = false;
                    _log_u.at(i).at(j).at(k).second = -1;
                }
            }
        }

        for(int i1=0; i1<_log_w.size(); ++i1) {
            for(int i2=0; i2<_log_w.at(i1).size(); ++i2) {
                for(int i3=0; i3<_log_w.at(i1).at(i2).size(); ++i3) {
                    for(int i4=0; i4<_log_w.at(i1).at(i2).at(i3).size(); ++i4) {
                        for(int i5=0; i5<_log_w.at(i1).at(i2).at(i3).at(i4).size(); ++i5) {
                            _log_w.at(i1).at(i2).at(i3).at(i4).at(i5).first = false;
                            _log_w.at(i1).at(i2).at(i3).at(i4).at(i5).second = -1;
                        }
                    }
                }
            }
        }

        for(int i1=0; i1<_log_a.size(); ++i1) {
            for(int i2=0; i2<_log_a.at(i1).size(); ++i2) {
                for(int i3=0; i3<_log_a.at(i1).at(i2).size(); ++i3) {
                    for(int i4=0; i4<_log_a.at(i1).at(i2).at(i3).size(); ++i4) {
                        _log_a.at(i1).at(i2).at(i3).at(i4).first = false;
                        _log_a.at(i1).at(i2).at(i3).at(i4).second = -1;
                    }
                }
            }
        }

        for(int i1=0; i1<_log_b.size(); ++i1) {
            for(int i2=0; i2<_log_b.at(i1).size(); ++i2) {
                for(int i3=0; i3<_log_b.at(i1).at(i2).size(); ++i3) {
                    for(int i4=0; i4<_log_b.at(i1).at(i2).at(i3).size(); ++i4) {
                        for(int i5=0; i5<_log_b.at(i1).at(i2).at(i3).at(i4).size(); ++i5) {
                            for(int i6=0; i6<_log_b.at(i1).at(i2).at(i3).at(i4).at(i5).size(); ++i6) {
                                _log_b.at(i1).at(i2).at(i3).at(i4).at(i5).at(i6).first = false;
                                _log_b.at(i1).at(i2).at(i3).at(i4).at(i5).at(i6).second = -1;
                            }
                        }
                    }
                }
            }
        }
    }


public:
    
    vector<double> _leastSquaresDiff(const vector<vector<vector<double>>> & oldRootProbs, const vector<vector<vector<vector<double>>>> & oldTransitionProbs, const vector<vector<vector<double>>> & oldEmissionProbs) {
        
        double rootsDiff = 0.0;
        for(int i1=0; i1<oldRootProbs.size(); ++i1) {
            for(int i2=0; i2<oldRootProbs.at(i1).size(); ++i2) {
                for(int i3=0; i3<oldRootProbs.at(i1).at(i2).size(); ++i3) {
                    double oldProb = oldRootProbs.at(i1).at(i2).at(i3);
                    double newProb = _rootProbs.at(i1).at(i2).at(i3);
                    rootsDiff += pow(oldProb-newProb,2);
                }
            }
        }
        
        double transDiff = 0.0;
        for(int i1=0; i1<oldTransitionProbs.size(); ++i1) {
            for(int i2=0; i2<oldTransitionProbs.at(i1).size(); ++i2) {
                for(int i3=0; i3<oldTransitionProbs.at(i1).at(i2).size(); ++i3) {
                    for(int i4=0; i4<oldTransitionProbs.at(i1).at(i2).size(); ++i4) {
                        
                        double oldTrans = oldTransitionProbs.at(i1).at(i2).at(i3).at(i4);
                        double newTrans = _transitionProbs.at(i1).at(i2).at(i3).at(i4);
                        transDiff += pow(oldTrans-newTrans,2);
                    }
                }
            }
        }
        
        double emissDiff = 0.0;
        for(int i1=0; i1<oldEmissionProbs.size(); ++i1) {
            for(int i2=0; i2<oldEmissionProbs.at(i1).size(); ++i2) {
                for(int i3=0; i3<oldEmissionProbs.at(i1).at(i2).size(); ++i3) {
                    double oldProb = oldEmissionProbs.at(i1).at(i2).at(i3);
                    double newProb = _emissionProbs.at(i1).at(i2).at(i3);
                    emissDiff += pow(oldProb-newProb,2);
                }
            }
        }
        
        return vector<double>({rootsDiff,transDiff,emissDiff});
    }

    
    void _checkLogMethod();

    bool _sexDependent;
    int _femaleN;
    int _maleN;
    int _unknownN;

    vector<pedigreeClass2*> _trainingSet;

    /* =========================================================================================== */
/*
    _u -> [pedigree (d)][person (c)][chromosome (k)] -> u_k(c)
    _w -> [pedigree (d)][familyUnit (f)][p==mother][parentAChromosome (i)][parentBChromosome (j)] -> w_ij(q|p)
    _a -> [pedigree (d)][familyUnit (f)][p==mother][parentAChromosome (i)] -> a_i(p,q)
    _b -> [pedigree (d)][familyUnit (f)][motherChromosome (i)][fatherChromosome (j)][childNumber (c)][childSexIndex] -> b_ij(c)

    _c -> [pedigree][person][chromosome]
    _d -> [pedigree][familyUnit][chromosomeFemaleParent][chromosomeMaleParent]
    _e -> [pedigree][familyUnit][chromosomeFemaleParent][chromosomeMaleParent][childNumber][childSexIndex][childChromosome]
*/
    //                      status,value
    // vector<vector<vector<pair<int,double>>>> _u;
    // vector<vector<vector<vector<vector<pair<int,double>>>>>> _w;
    // vector<vector<vector<vector<pair<int,double>>>>> _a;
    // vector<vector<vector<vector<vector<vector<pair<int,double>>>>>>> _b;


    // vector<vector<vector<double>>> _c;
    // vector<vector<vector<vector<double>>>> _d;
    // vector<vector<vector<vector<vector<vector<vector<double>>>>>>> _e;







    vector<vector<vector<pair<int,double>>>> _log_u;
    vector<vector<vector<vector<vector<pair<int,double>>>>>> _log_w;
    vector<vector<vector<vector<pair<int,double>>>>> _log_a;
    vector<vector<vector<vector<vector<vector<pair<int,double>>>>>>> _log_b;


    vector<vector<vector<double>>> _log_c;
    vector<vector<vector<vector<double>>>> _log_d;
    vector<vector<vector<vector<vector<vector<vector<double>>>>>>> _log_e;

    /* =========================================================================================== */

    vector<vector<vector<double>>> __rootProbs;
    vector<vector<vector<vector<double>>>> __transitionProbs;
    vector<vector<vector<double>>> __emissionProbs;

    /* =========================================================================================== */

    // root probs is indexed by: [pedigree][root][trueChromosomes]
    vector<vector<vector<double>>> _rootProbs;

    // transition probs is indexed by: [childSexIndex][motherChrom][fatherChrom][childChrom]
    vector<vector<vector<vector<double>>>> _transitionProbs;

    // person can be ['shaded', 'possiblyShaded', 'unshaded', 'carrier']
    // emission probs is indexed by: [sex][trueChromosomes][shadingObservation]
    vector<vector<vector<double>>> _emissionProbs;
    unordered_map<string,int> _emissionMapping;

    EMPedigreeOptimizer():
    _emissionMapping({{"shaded",0},{"possiblyShaded",1},{"unshaded",2},{"carrier",3}}) {
        _trainingSet = vector<pedigreeClass2*>();
    }

    // void initialize(const vector<pedigreeClass2*> & trainingSet_, bool printPeople);
    void log_initialize(const vector<pedigreeClass2*> & trainingSet_, bool printPeople);

    void _resetPedigrees() {        
        
        for(auto ped_it=_trainingSet.begin(); ped_it!=_trainingSet.end(); ++ped_it) {
            (*ped_it)->resetAll();
        }
    }



    // void _EMStep();

    void _EMStep2();
    void _log_EMStep2();
    
    void train() {
        int nLoops = 0;
        while(true) {
            
            vector<vector<vector<double>>> emissionProbsOld = _emissionProbs;
            vector<vector<vector<double>>> rootProbsOld = _rootProbs;
            vector<vector<vector<vector<double>>>> transitionProbsOld = _transitionProbs;

            _log_EMStep2();
            
            vector<double> diffs = _leastSquaresDiff(rootProbsOld, transitionProbsOld, emissionProbsOld);
            double total = diffs.at(0)+diffs.at(1)+diffs.at(2);
            cout << "total: " << total << endl;
            if(total < pow(10,-5)) {
                _emissionProbs = emissionProbsOld;
                _rootProbs = rootProbsOld;
                _transitionProbs = transitionProbsOld;
                break;
            }
            ++nLoops;
        }

        __emissionProbs = _emissionProbs;
        __rootProbs = _rootProbs;
        __transitionProbs = _transitionProbs;

        cout << "DONE!" << endl;

    }

    void _trainRoots() {

        vector<vector<vector<vector<double>>>> transitionProbsDummy = _transitionProbs;
        vector<vector<vector<double>>> emissionProbsDummy = _emissionProbs;
            
        // train new root probabilities
        int nLoops = 0;
        while(true) {

            vector<vector<vector<double>>> rootProbsOld = _rootProbs;

            _resetDataStructures();
            _log_eStep2();
            _log_updateRootProbs2();
            
            vector<double> diffs = _leastSquaresDiff(rootProbsOld, transitionProbsDummy, emissionProbsDummy);
            double total = diffs.at(0);
            cout << "total: " << total << endl;
            if(total < pow(10,-5)) {
                _rootProbs = rootProbsOld;
                break;
            }
            ++nLoops;
        }
    }

    double _calculateProbability(pedigreeClass2* pedigree, vector<vector<vector<double>>> rootProbs);

    double predictProbability(pedigreeClass2* pedigree) {

        log_initialize(vector<pedigreeClass2*>({pedigree}), false);
        _trainRoots();

        // calculate the new value
        double ans = _calculateProbability(pedigree,_rootProbs);
        
        return ans;
    }

};

#endif
