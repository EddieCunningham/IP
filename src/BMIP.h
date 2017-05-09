// g++ logProbIPNew.cpp BMIP.cpp helperFunctions.cpp uniformMonteCarloIntegration.cpp pdfSamplingMonteCarloIntegration.cpp cMain.cpp -I/usr/local/include -L/usr/local/lib -lgsl -lgslcblas -O3 -std=c++11

#ifndef BMIP_H
#define BMIP_H

#include "logProbIPNew.h"


using namespace std;

class EMPedigreeOptimizer {

    int getSexIndex(pedigreeClass2* pedigree, personClass* person);
    void sortMates(personClass* mateA, personClass* mateB, personClass*& femaleMate, personClass*& maleMate);
    int getFamNumb(pedigreeClass2* pedigree, personClass* mateA, personClass* mateB);

    void _checkC();
    void _checkD();
    void _checkE();

    double _getUVal(pedigreeClass2* pedigree, int d, personClass* child, int k);
    double _getWVal(pedigreeClass2* pedigree, int d, int f, int motherIsP, int i, int j);
    double _getAVal(pedigreeClass2* pedigree, int d, int f, int motherIsP, int i);
    double _getBVal(pedigreeClass2* pedigree, int d, int f, int i, int j, personClass* child, int c);
    void _computeAVal(pedigreeClass2* pedigree, int d, int f, int motherIsP, int i);
    void _computeBVal(pedigreeClass2* pedigree, int d, int f, int i, int j, personClass* child, int c);
    void _computeUVal(pedigreeClass2* pedigree, int d, personClass* child, int k);
    void _computeWVal(pedigreeClass2* pedigree, int d, int f, int motherIsP, int i, int j);

    void _cUpdate();
    void _dUpdate();
    void _eUpdate();
    void _eStep2();


    void _updateRootProbs2();
    void _updateEmissionProbs2();
    void _updateTransitionProbs2();
    void _mStep2();


public:

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
    vector<vector<vector<pair<int,double>>>> _u;
    vector<vector<vector<vector<vector<pair<int,double>>>>>> _w;
    vector<vector<vector<vector<pair<int,double>>>>> _a;
    vector<vector<vector<vector<vector<vector<pair<int,double>>>>>>> _b;


    vector<vector<vector<double>>> _c;
    vector<vector<vector<vector<double>>>> _d;
    vector<vector<vector<vector<vector<vector<vector<double>>>>>>> _e;

    /* =========================================================================================== */

    // person can be ['shaded', 'possiblyShaded', 'unshaded', 'carrier']
    // emission probs is indexed by: [sex][trueChromosomes][shadingObservation]
    vector<vector<vector<double>>> _emissionProbs;
    unordered_map<string,int> _emissionMapping;

    // root probs is indexed by: [pedigree][root][trueChromosomes]
    vector<vector<vector<double>>> _rootProbs;

    // transition probs is indexed by: [childSexIndex][motherChrom][fatherChrom][childChrom]
    vector<vector<vector<vector<double>>>> _transitionProbs;

    EMPedigreeOptimizer():
    _emissionMapping({{"shaded",0},{"possiblyShaded",1},{"unshaded",2},{"carrier",3}}) {
        _trainingSet = vector<pedigreeClass2*>();
    }

    void initialize(const vector<pedigreeClass2*> & trainingSet_, bool printPeople);

    void _resetPedigrees() {
        for(auto ped_it=_trainingSet.begin(); ped_it!=_trainingSet.end(); ++ped_it) {
            (*ped_it)->resetAll();
        }
    }



    // void _EMStep();

    void _EMStep2();

};

#endif
