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

    class personClass {
    public:
                            
        int _id;
        personClass* parentA;
        personClass* parentB;
        bool isRoot;
        double t,probability;
        int m,n;
        vector<double> probs;
        bool updated;
        vector<vector<vector<double>>> g;
        bool dontInclude;

        personClass(int _id_,personClass* parentA_,personClass* parentB_,bool isRoot_,double t_,double probability_,int m_,int n_,vector<double> probs_,bool updated_,vector<vector<vector<double>>> g_)
                    : _id(_id_)
                    ,parentA(parentA_)
                    ,parentB(parentB_)
                    ,isRoot(isRoot_)
                    ,t(t_)
                    ,probability(probability_)
                    ,m(m_)
                    ,n(n_)
                    ,probs(probs_)
                    ,updated(updated_)
                    ,g(g_)
                    ,dontInclude(false)
                    {}


        void storeProbAndNormalize();

        void toString() {
            cout << "id: " << this->_id;
            cout << "\nthis: " << this;
            cout << "\n\tparentA: " << this->parentA;
            cout << "\n\tparentB: " << this->parentB;
            cout << "\n\tisRoot: " << this->isRoot;
            cout << "\n\tt: " << this->t;
            cout << "\n\tprobability: " << this->probability;
            cout << "\n\tm: " << this->m;
            cout << "\n\tn: " << this->n;
            cout << "\n\tupdated: " << this->updated;
            cout << "\n\tdontInclude: " << this->dontInclude;
            cout << "\n\tprobs: ";
            for(int i=0; i<this->probs.size(); ++i) {
                cout << probs[i] << " ";
            }
            cout << endl << endl;
        }
    };

    class pedigreeClass {
    public:
        pedigreeClass(){}

        vector<personClass*> allPeople;
        vector<personClass*> roots;

        double getNormVal(personClass *p, int index);
        void updateProbs(personClass* c);
        mpf_class getProbability();
        void getProbability2(mpf_class *result);
        double getLogProbability();
        void initializeRandomEval();
        double randomEvaluation();

        mpf_class randomEvaluationGMP();

        double calcIntegral(int numbCalls);
        double calcIntegral2(int numbCalls);
        double naiveMonteCarlo(int numbCalls);
    };



};
