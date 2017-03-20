#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <cassert>
#include <stdlib.h>
#include <math.h>
#include <gmpxx.h>
#include <numeric>
#include <algorithm>

namespace std {

    struct Person {
        Person* parentA;
        Person* parentB;
        bool isRoot;
        double t,probability;
        int m,n;
        vector<double> probs;
        bool updated;
        vector<vector<vector<double>>> g;

        void storeProbAndNormalize();

        void toString() {
            cout << "this: " << this;
            cout << "\n\tparentA: " << this->parentA;
            cout << "\n\tparentB: " << this->parentB;
            cout << "\n\tisRoot: " << this->isRoot;
            cout << "\n\tt: " << this->t;
            cout << "\n\tprobability: " << this->probability;
            cout << "\n\tm: " << this->m;
            cout << "\n\tn: " << this->n;
            cout << "\n\tupdated: " << this->updated;
            cout << "\n\tprobs: ";
            for(int i=0; i<this->probs.size(); ++i) {
                cout << probs[i] << " ";
            }
            cout << endl << endl;
        }
    };

    struct Pedigree {
        vector<Person*> allPeople;
        vector<Person*> roots;

        double getNormVal(Person *p, int index);
        void updateProbs(Person* c);
        mpf_class getProbability();
        void initializeRandomEval();
        mpf_class randomEvaluation();

        double calcIntegral(int numbCalls);
    };



};