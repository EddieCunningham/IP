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
            string str = "personClass x_";
            if(this->_id < 0) {
                str += "_"+to_string(abs(this->_id));
            }
            else {
                str += to_string(this->_id);
            }
            str += "("+to_string(this->_id)+",";
            if(this->parentA) {
                if(this->parentA->_id < 0) {
                    str += "&x__"+to_string(abs(this->parentA->_id))+",";
                }
                else {
                    str += "&x_"+to_string(this->parentA->_id)+",";
                }
            }
            else {
                str += "nullptr,";
            }
            if(this->parentB) {
                if(this->parentB->_id < 0) {
                    str += "&x__"+to_string(abs(this->parentB->_id))+",";
                }
                else {
                    str += "&x_"+to_string(this->parentB->_id)+",";
                }
            }
            else {
                str += "nullptr,";
            }
            if(this->isRoot) {
                str += "true,";
            }
            else {
                str += "false,";
            }
            str += to_string(this->t)+",";
            str += to_string(this->probability)+",";
            str += to_string(this->m)+",";
            str += to_string(this->n)+",";
            str += "vector<double>("+to_string(this->n)+"),";
            str += "false,";
            str += "vector<vector<vector<double>>>({";
            for(int i=0; i<this->g.size(); ++i) {
                str += "\n\t{";
                for(int j=0; j<this->g.at(i).size(); ++j) {
                    str += "\n\t\t{";
                    for(int k=0; k<this->g.at(i).at(j).size(); ++k) {
                        if(k == this->g.at(i).at(j).size()-1) {
                            str += to_string(g.at(i).at(j).at(k));
                        }
                        else {
                            str += to_string(g.at(i).at(j).at(k))+",";
                        }
                    }
                    if(j == this->g.at(i).size()-1) {
                        str += "}";
                    }
                    else {
                       str += "},";
                    }
                }
                if(i == this->g.size()-1) {
                    str += "\n\t}";
                }
                else {
                   str += "\n\t},";
                }
            }
            str += "\n}));";

            cout << str << endl;
        }

        // void toString() {
        //     cout << "id: " << this->_id;
        //     cout << "\nthis: " << this;
        //     cout << "\n\tparentA: " << this->parentA;
        //     cout << "\n\tparentB: " << this->parentB;
        //     cout << "\n\tisRoot: " << this->isRoot;
        //     cout << "\n\tt: " << this->t;
        //     cout << "\n\tprobability: " << this->probability;
        //     cout << "\n\tm: " << this->m;
        //     cout << "\n\tn: " << this->n;
        //     cout << "\n\tupdated: " << this->updated;
        //     cout << "\n\tdontInclude: " << this->dontInclude;
        //     cout << "\n\tprobs: ";
        //     for(int i=0; i<this->probs.size(); ++i) {
        //         cout << probs[i] << " ";
        //     }
        //     cout << endl << endl;
        // }
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
        vector<double> naiveMonteCarlo(long numbCalls, bool printIterations, bool printPeople);
    };
    
};
