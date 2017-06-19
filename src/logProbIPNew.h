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
#include <queue>

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
    queue<double> _lastAddedPoints;
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

    vector<double> log_viterbiProbs;
    double viterbiConfidence = -1;
    int mostLikelyState = -1;

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
    vector<pair<personClass*,vector<personClass*>>> mateKids;
    string typeOfShading;
    string sex;
    
    personClass(int _id_,personClass* parentA_,personClass* parentB_,bool isRoot_,double t_,double s_,double probability_,int l_,int m_,int n_,vector<double> probs_,bool updated_,vector<vector<vector<double>>> g_,bool affected_,string typeOfShading_,string sex_)
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
    ,mateKids()
    ,typeOfShading(typeOfShading_)
    ,sex(sex_)
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
    
    void toString(string numb) {
        string str = "personClass x_"+numb;
        if(this->_id < 0) {
            str += "_"+to_string(abs(this->_id));
        }
        else {
            str += to_string(this->_id);
        }
        str += "("+to_string(this->_id)+",";
        if(this->parentA) {
            if(this->parentA->_id < 0) {
                str += "&x_"+numb+"_"+to_string(abs(this->parentA->_id))+",";
            }
            else {
                str += "&x_"+numb+to_string(this->parentA->_id)+",";
            }
        }
        else {
            str += "nullptr,";
        }
        if(this->parentB) {
            if(this->parentB->_id < 0) {
                str += "&x_"+numb+"_"+to_string(abs(this->parentB->_id))+",";
            }
            else {
                str += "&x_"+numb+to_string(this->parentB->_id)+",";
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
            str += "true,";
        }
        else {
            str += "false,";
        }

        str += "\""+this->typeOfShading+"\""+",";
        str += "\""+this->sex+"\"";
        str += ");\n";

        cout << str << endl;
    }

    void mateKidsString(string numb) {
        // update the mateKids
        string str = "x_"+numb;
        if(this->_id < 0) {
            str += "_";
        }
        str += to_string(abs(this->_id))+".mateKids = vector<pair<personClass*,vector<personClass*>>>({";
        for(int i=0; i<this->mateKids.size(); ++i) {

            pair<personClass*,vector<personClass*>> current = this->mateKids.at(i);
            personClass* mate = current.first;
            vector<personClass*> kids = current.second;

            string mateString = "&x_"+numb;
            if(mate->_id < 0) {
                mateString += "_";
            }
            mateString += to_string(abs(mate->_id));

            string pairString = "pair<personClass*,vector<personClass*>>("+mateString+",vector<personClass*>({";
            for(int j=0; j<kids.size(); ++j) {

                personClass* child = kids.at(j);

                string childString = "&x_"+numb;
                if(child->_id < 0) {
                    childString += "_";
                }
                childString += to_string(abs(child->_id));
                pairString += childString;
                if(j != kids.size()-1) {
                    pairString += ",";
                }
            }
            pairString += "}))";

            str += pairString;
            if(i != mateKids.size()-1) {
                str += ",";
            }
        }
        str += "});\n";

        cout << str << endl;
    }
};

class pedigreeClass2 {
private:

    double lastLogEval;

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

    int _getFamNumb(personClass* mateA, personClass* mateB) {
        
        personClass* femaleParent = nullptr;
        personClass* maleParent = nullptr;
            if(mateA->sex == "female") {
            femaleParent = mateA;
            maleParent = mateB;
        }
        else {
            maleParent = mateA;
            femaleParent = mateB;
        }
        
        int ans = 0;
        for(auto fam_it=families.begin(); fam_it!=families.end(); ++fam_it) {
            
            if(femaleParent == fam_it->at(0) && maleParent == fam_it->at(1)) {
                return ans;
            }
            ++ans;
        }
        cout << "Couldn't find a family with these two mates!" << endl;
        raise(SIGABRT);
        return -1;
    }


    /*
    void _bruteForcePDF();
    void _oneAffectedPDF(double K);
    void updateRootLogPDF(bool useNewDist, double K);
    

    vector<double> _evaluateFromSingleRoot(long numbCalls, bool printIterations, int numbToPrint, unordered_set<personClass*> rootsToUse);
    pair<double,vector<personClass*>> _bruteForceWithNumbAffected(long numbCalls, bool printIterations, int numbToPrint, int numbRoots, int numbToChange);
    vector<pair<double,vector<personClass*>>> _bruteForceWork(long numbCalls, bool printIterations, int numbToPrint, int numbRoots);
    vector<double> _bruteForce(long numbCalls, bool printIterations, int numbToPrint, int numbRoots);
    vector<double> _monteCarloMH(long numbCalls, bool printIterations, int numbToPrint, bool useNewDist, double K, bool useLeak, double leakProb, double leakDecay);
    vector<double> _uniformMonteCarlo(long numbCalls, bool printIterations, int numbToPrint, bool useNewDist, double K, bool useLeak, double leakProb, double leakDecay);
    vector<double> _hybridMonteCarlo(long numbCalls, bool printIterations, int numbToPrint, double K);
     */
public:

    string filename;

    double log_probRoots;
    
    double mostLikelyStateProb;


    vector<vector<personClass*>> families;
    vector<personClass*> allPeople;
    vector<personClass*> roots;
    vector<personClass*> leaves;
    vector<personClass*> bredthFirstList;
    bool isDominant;
    bool sexDependent;

    unordered_map<personClass*,int> mapToIndexAllPeople;
    unordered_map<personClass*,int> mapToIndexRoots;

    pedigreeClass2() {}

    void makeBFL();

    void resetAll() {
        for(auto it=this->allPeople.begin(); it!=this->allPeople.end(); ++it) {
            (*it)->reset();
        }
    }

    void printAllPeople(string numb);

    pair<double,double> logEvaluation(const vector<double> & x, bool useNewDist, double K, bool samplingFromPDF);
    // vector<double> monteCarlo(long numbCalls, bool printIterations, int numbToPrint, bool printPeople, bool useNewDist, double K, bool useLeak, double leakProb, double leakDecay, bool useMH, bool useBruteForce, int numbRoots, bool useHybrid);
};



#endif

