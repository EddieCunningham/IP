// g++ logProbIPNew.cpp BMIP.cpp helperFunctions.cpp uniformMonteCarloIntegration.cpp pdfSamplingMonteCarloIntegration.cpp cMain.cpp -I/usr/local/include -L/usr/local/lib -lgsl -lgslcblas -O3 -std=c++11

#ifndef BMIP_H
#define BMIP_H

#include "logProbIPNew.h"


using namespace std;

class EMPedigreeOptimizer {
public:

    vector<pedigreeClass2*> _trainingSet;


/*
    _alpha -> [pedigree][person][chromosome]
    _beta -> [pedigree][familyUnit][chromosomeFemaleParent][chromosomeMaleParent]
    _gamma -> [pedigree][person][chromosome]
    _delta -> [pedigree][familyUnit][chromosomeFemaleParent][chromosomeMaleParent]
    _epsilon -> [pedigree][person][chromosome]
    _zeta -> [pedigree][familyUnit][chromosomeFemaleParent][chromosomeMaleParent][childChromosome]
*/

    /* =========================================================================================== */

    // [pedigree][person][chromosome]
    vector<vector<vector<double>>> _alpha;

    // [pedigree][familyUnit][chromosomeFemaleParent][chromosomeMaleParent]
    vector<vector<vector<vector<double>>>> _beta;
    
    // [pedigree][person][chromosome]
    vector<vector<vector<double>>> _gamma;

    // [pedigree][familyUnit][chromosomeFemaleParent][chromosomeMaleParent]
    vector<vector<vector<vector<double>>>> _delta;

    // [pedigree][person][chromosome]
    vector<vector<vector<double>>> _epsilon;

    // [pedigree][familyUnit][chromosomeFemaleParent][chromosomeMaleParent][childNumber][childSex][childChromosome]
    vector<vector<vector<vector<vector<vector<vector<double>>>>>>> _zeta;

    /* =========================================================================================== */

    // person can be ['shaded', 'possiblyShaded', 'unshaded', 'carrier']
    // emission probs is indexed by: [sex][trueChromosomes][shadingObservation]
    vector<vector<vector<double>>> _emissionProbs;
    unordered_map<string,int> _emissionMapping;

    // root probs is indexed by: [pedigree][root][trueChromosomes]
    vector<vector<vector<double>>> _rootProbs;

    // transition probs is indexed by: [childSex][motherChrom][fatherChrom][childChrom]
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

    void _alphaGammaRootCase(pedigreeClass2* pedigree, personClass* person, int N, int d, int pIndex, int sexIndex, int shadingIndex);
    void _alphaGammaNormalCase(pedigreeClass2* pedigree, personClass* person, int N, int d, int pIndex, int sexIndex, int shadingIndex);
    void _updateAlphaGamma();
    void _betaHelper(pedigreeClass2* pedigree, int d, int famNumb);
    void _updateBeta();
    void _updateDelta();
    void _updateEpsilon();
    void _updateZeta();
    void _eStep();

    void _updateRootProbs();
    void _updateEmissionProbs();
    void _updateTransitionProbs();
    void _mStep();
    
    void _EMStep();

};

#endif
