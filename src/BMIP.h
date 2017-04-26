#include "logProbIPNew.h"


using namespace std;

class BMPedigree {
    const vector<PedigreeClass2*> trainingSet;

    // person can be ['shaded', 'possiblyShaded', 'unshaded', 'carrier']
    // emmision probs is indexed by: [sex][trueChromosomes][shadingObservation]
    vector<vector<vector<double>>> emissionProbs;

    // root probs is indexed by: [pedigree][root][trueChromosomes]
    vector<vector<vector<double>>> rootProbs;

    // transition probs is indexed by: [parentAChrom][parentBChrom][childChrom]
    vector<vector<vector<double>>> transitionProbs;

    BMPedigree(const vector<PedigreeClass2*> trainingSet_)
    : trainingSet(trainingSet_) {



        // initialize the rootProbs
        for(auto ped_it=trainingSet.begin(); ped_it!=trainingSet.end(); ++ped_it) {

            vector<vector<double>> rootsToAdd;
            for(auto r_it=ped_it->begin(); r_it!=ped_it->end(); ++r_it) {

                int n = (*r_it)->n;
                vector<double> rootToAdd(n);
                // randomly initialize (for the moment)

                for(int i=0; i<n; ++i) {
                    double randomNumb = rand()/(double)RAND_MAX;
                    rootToAdd[i] = randomNumb;
                }
                rootsToAdd.push_back(rootToAdd);
            }
            this->rootProbs.push_back(rootsToAdd);
        }



    }


};