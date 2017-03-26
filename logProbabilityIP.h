#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <cassert>
#include <stdlib.h>
#include <math.h>
#include <numeric>
#include <algorithm>
#include <stdlib.h>
#include <random>
#include <csignal>
// #include "ipImplementation.h"

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

    class pedigreeClass2 {
    public:
        pedigreeClass2(){}
        
        vector<personClass*> allPeople;
        vector<personClass*> roots;
        
        double getNormVal(personClass *p, int index);
        void updateProbs(personClass* c);
        double getProbability();
        double getLogProbability();
        
        double logEvaluation(const vector<double> & x);
        double naiveMonteCarlo(long numbCalls);
    };
    
    struct logAddition {
        bool initialized = false;
        double lastF = 0.0;
        double last_log_x = -1;
        
        
        bool initValue(double firstTerm) {
            if(firstTerm <= 0) {
                return false;
            }
            this->last_log_x = log(firstTerm);
            this->initialized = true;
            return true;
        }
        
        bool initLogValue(double log_firstTerm) {
            if(log_firstTerm == -1) {
                return false;
            }
            this->last_log_x = log_firstTerm;
            this->initialized = true;
            return true;
        }
        
        double _accumulate(double log_x1, double log_x2, double lastValue) {
            return log1p(exp(log_x1-log_x2+lastValue));
        }
        
        void _addTerm(double log_term) {
            this->lastF = this->_accumulate(this->last_log_x, log_term, this->lastF);
            this->last_log_x = log_term;
        }
        
        void addTerm(double term) {
            assert(this->initialized);
            if(term <= 0) {
                return;
            }
            double log_term = log(term);
            this->_addTerm(log_term);
        }
        
        void addLogTerm(double log_term) {
            assert(this->initialized);
            if(log_term == -1) {
                return;
            }
            this->_addTerm(log_term);
        }
        
        double getSum() {
            return this->last_log_x + this->lastF;
        }
    };
    
    
    
};
