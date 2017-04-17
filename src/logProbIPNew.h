#ifndef LOG_PROB_H
#define LOG_PROB_H

#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <stdlib.h>
#include <math.h>
#include <numeric>
#include <algorithm>
#include <stdlib.h>
#include <random>
#include <csignal>
#include <exception>

using namespace std;

struct topK {
    vector<double> vals;
    struct cmp {
        bool operator()(double a, double b) {
            return a>b;
        }
    };
    topK(int size);
    void addPoint(double point);
    void finalSort();
};

struct logAddition {
    double log_ans = __DBL_MAX__;
    bool needToInitialize = true;
    void _accumulatePositive(double log_x);
    void _accumulateNegative(double log_x);
    void _addPoint(int sign, double log_x);
    void addPositiveLogPoint(double log_x);
    void addNegativeLogPoint(double log_x);
    void addZeroPoint();
    void addPoint(double x);
};


struct logVariance {
    int sign_avg = 0;
    double log_x_avg = 0.0;
    double log_m = __DBL_MAX__;
    double log_var = __DBL_MAX__;
    int n = 0;
    
    void _avgIsZero(int sign, double log_x);
    void _updateAvg(int sign, double log_x);
    void _updateM(int sign, double log_x, int old_sign_avg, double old_log_x_avg);
    void _addPoint(int sign, double log_x);
    void addPositiveLogPoint(double log_x);
    void addNegativeLogPoint(double log_x);
    void addZeroPoint();
    void addPoint(double x);
    double getLogStdev();
};


class personClass {
public:
    
    int _id;
    personClass* parentA;
    personClass* parentB;
    bool isRoot;
    double t,s,probability,probOfShadingAverage;
    int l,m,n,timesUpdated;
    int startIndex,endIndex;
    vector<double> probs,probsAverage;
    bool updated;
    vector<vector<vector<double>>> g;
    bool affected;
    bool dontInclude;
    vector<personClass*> children;
    
    personClass(int _id_,personClass* parentA_,personClass* parentB_,bool isRoot_,double t_,double s_,double probability_,int l_,int m_,int n_,vector<double> probs_,bool updated_,vector<vector<vector<double>>> g_,bool affected_)
    : _id(_id_)
    ,parentA(parentA_)
    ,parentB(parentB_)
    ,isRoot(isRoot_)
    ,t(t_)
    ,s(s_)
    ,probability(probability_)
    ,probOfShadingAverage(0)
    ,l(l_)
    ,m(m_)
    ,n(n_)
    ,timesUpdated(1)
    ,startIndex(-1)
    ,endIndex(-1)
    ,probs(probs_)
    ,probsAverage(probs_)
    ,updated(updated_)
    ,g(g_)
    ,affected(affected_)
    ,dontInclude(false)
    ,children()
    {}

    void reset() {
        // need to update these:
        // probOfShadingAverage
        // timesUpdated
        // startIndex
        // endIndex
        // probsAverage
        // updated
        // dontInclude

        this->probOfShadingAverage = 0.0;
        this->timesUpdated = 1;
        this->startIndex = -1;
        this->endIndex = -1;        
        for(int i=0; i<this->probsAverage.size(); ++i) {
            this->probsAverage.at(i) = 0;
        }
        this->updated = false;
        this->dontInclude = false;
    }
    
    
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
        str += to_string(this->s)+",";
        str += to_string(this->probability)+",";
        str += to_string(this->l)+",";
        str += to_string(this->m)+",";
        str += to_string(this->n)+",";
        str += "vector<double>("+to_string(this->n)+"),";
        str += "false,";
        str += "vector<vector<vector<double>>>({";
        for(int i=0; i<this->g.size(); ++i) {
            str += "{";
            // str += "\n\t{";
            for(int j=0; j<this->g.at(i).size(); ++j) {
                str += "{";
                // str += "\n\t\t{";
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
                str += "}";
                // str += "\n\t}";
            }
            else {
               str += "},";
               // str += "\n\t},";
            }
        }
        str += "}),";
        // str += "\n}));";

        if(this->affected) {
            str += "true);";
        }
        else {
            str += "false);";
        }

        cout << str << endl;
    }
};

class pedigreeClass2 {
private:

    double lastLogEval;
    
    bool isDominant;

    vector<personClass*> leaves;

    vector<vector<personClass*>> carrierRoots;
    vector<personClass*> possiblyAffectedAncestors;

    void makeAffected(personClass* person);
    void makeUnAffected(personClass* person);
    void makeCarrier(personClass* person);

    double getNormVal(personClass *p, int index);
    void updateProbs(personClass* c);
    double getProbability();
    double getLogProbability();

    void getDominantOrRecessive();
    void updateAllChildrenAndLeaves();
    void determineCarrierRoots(bool useLeak, double leakProb, double leakDecay);

    void _bruteForcePDF();
    void _oneAffectedPDF(double K);
    void updateRootLogPDF(bool useNewDist, double K);
    

    vector<double> _evaluateFromSingleRoot(long numbCalls, bool printIterations, int numbToPrint, unordered_set<personClass*> rootsToUse);
    pair<double,string> _bruteForceWithNumbAffected(long numbCalls, bool printIterations, int numbToPrint, int numbRoots, int numbToChange);
    vector<double> _bruteForce(long numbCalls, bool printIterations, int numbToPrint, bool useNewDist, int numbRoots);
    vector<double> _monteCarloMH(long numbCalls, bool printIterations, int numbToPrint, bool useNewDist, double K, bool useLeak, double leakProb, double leakDecay);
    vector<double> _uniformMonteCarlo(long numbCalls, bool printIterations, int numbToPrint, bool useNewDist, double K, bool useLeak, double leakProb, double leakDecay);

public:

    vector<personClass*> allPeople;
    vector<personClass*> roots;
    double log_probRoots;


    pedigreeClass2(){}

    void resetAll() {
        for(auto it=this->allPeople.begin(); it!=this->allPeople.end(); ++it) {
            (*it)->reset();
        }
    }

    pair<double,double> logEvaluation(const vector<double> & x, bool useNewDist, double K, bool samplingFromPDF);
    vector<double> monteCarlo(long numbCalls, bool printIterations, int numbToPrint, bool printPeople, bool useNewDist, double K, bool useLeak, double leakProb, double leakDecay, bool useMH, bool useBruteForce, int numbRoots);
};


#endif

