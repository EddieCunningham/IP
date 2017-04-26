#include "logProbIPNew.h"

using namespace std;

// this method will first use brute force to change who is shaded in the pedigree, and will then run
// the uniform monte carlo integration algorithm with the new distribution to get an answer

vector<double> pedigreeClass2::_hybridMonteCarlo(long numbCalls, bool printIterations, int numbToPrint, double K) {        

    int numbRoots = 2;
    vector<pair<double,vector<personClass*>>> allAnswers = this->_bruteForceWork(numbCalls,printIterations,numbToPrint,numbRoots);

    // first identify the best change
    vector<personClass*> toShade;
    double maxProb = -999999;
    for(auto it=allAnswers.begin(); it!=allAnswers.end(); ++it) {
        if(it->first > maxProb && it->second.at(0)) {
            maxProb = it->first;
            toShade = it->second;
        }
    }

    // now shade the people
    if(maxProb != 999999) {
        for(auto it=toShade.begin(); it!=toShade.end(); ++it) {
            this->makeAffected(*it);
        }
    }

    numbCalls *= 10;
    printIterations = true;
    numbToPrint = numbCalls*0.1;
    bool useNewDist = true;
    bool useLeak = false;
    bool leakProb = -1;
    bool leakDecay = -1;

    auto ans = this->_uniformMonteCarlo(numbCalls, printIterations, numbToPrint, useNewDist, K, useLeak, leakProb, leakDecay);
    return ans;
}
