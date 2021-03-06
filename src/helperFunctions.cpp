#include "logProbIPNew.h"
#include "BMIP.h"

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


using namespace std;


/* ------------------------------------------------------------------------------------------- */

string EMPedigreeOptimizer::_getTransitionProbString() {
    string transProbString = "vector<vector<vector<vector<double>>>>({";
    for(int i=0; i<_transitionProbs.size(); ++i) {
        transProbString += "\n\t{";
        for(int j=0; j<_transitionProbs.at(i).size(); ++j) {
            transProbString += "\n\t\t{";
            for(int k=0; k<_transitionProbs.at(i).at(j).size(); ++k) {
                transProbString += "\n\t\t\t{";
                for(int l=0; l<_transitionProbs.at(i).at(j).at(k).size(); ++l) {

                    double val = _transitionProbs.at(i).at(j).at(k).at(l);
                    if(l < _transitionProbs.at(i).at(j).at(k).size()-1) {
                        transProbString += to_string(val)+",";
                    }
                    else {
                        transProbString += to_string(val);
                    }
                }
                if(k < _transitionProbs.at(i).at(j).size()-1) {
                    transProbString += "\n\t\t\t},";
                }
                else {
                    transProbString += "\n\t\t\t}";
                }
            }
            if(j < _transitionProbs.at(i).size()-1) {
                transProbString += "\n\t\t},";
            }
            else {
                transProbString += "\n\t\t}";
            }
        }
        if(i < _transitionProbs.size()-1) {
            transProbString += "\n\t},";
        }
        else {
            transProbString += "\n\t}";
        }
    }
    transProbString += "\n})";
    return transProbString;
}

string EMPedigreeOptimizer::_getEmissionProbString() {

    string emissProbString = "vector<vector<vector<double>>>({";
    for(int i=0; i<_emissionProbs.size(); ++i) {
        emissProbString += "\n\t{";
        for(int j=0; j<_emissionProbs.at(i).size(); ++j) {
            emissProbString += "\n\t\t{";
            for(int k=0; k<_emissionProbs.at(i).at(j).size(); ++k) {
                
                double val = _emissionProbs.at(i).at(j).at(k);
                if(k < _emissionProbs.at(i).at(j).size()-1) {
                    emissProbString += to_string(val)+",";
                }
                else {
                    emissProbString += to_string(val);
                }                    
            }
            if(j < _emissionProbs.at(i).size()-1) {
                emissProbString += "\n\t\t},";
            }
            else {
                emissProbString += "\n\t\t}";
            }
        }
        if(i < _emissionProbs.size()-1) {
            emissProbString += "\n\t},";
        }
        else {
            emissProbString += "\n\t}";
        }
    }
    emissProbString += "\n})";
    return emissProbString;
}

string EMPedigreeOptimizer::_getEmissionMappingString() {
    string ans = "unordered_map<string,int>({";
    int counter = 0;
    for(auto keyVal: _emissionMapping) {
        string sex = keyVal.first;
        int index = keyVal.second;
        ans += "{\""+sex+"\","+to_string(index)+"}";
        if(counter < _emissionMapping.size()-1) {
            ans += ",";
        }
        ++counter;
    }
    ans += "})";
    return ans;
}

string EMPedigreeOptimizer::_getAllLMNString() {

    string ans = "unordered_map<string,vector<int>>({";
    int counter = 0;
    for(auto keyVal: _allLMN) {
        string sex = keyVal.first;
        vector<int> lmn = keyVal.second;
        ans += "{\""+sex+"\",vector<int>({";

        for(int i=0; i<lmn.size(); ++i) {
            int val = lmn.at(i);
            ans += to_string(val);
            if(i < lmn.size()-1) {
                ans += ",";
            }
        }
        ans += "})}";

        if(counter < _allLMN.size()-1) {
            ans += ",";
        }
        ++counter;
    }
    ans += "})";
    return ans;
}

string EMPedigreeOptimizer::_getAllGString() {
    string ans = "unordered_map<string,vector<vector<vector<double>>>>({";
    int counter = 0;
    for(auto keyVal: _allG) {
        string sex = keyVal.first;
        vector<vector<vector<double>>> transitions = keyVal.second;
        ans += "{\""+sex+"\",vector<vector<vector<double>>>({";

        for(int i=0; i<transitions.size(); ++i) {
            ans += "{";
            for(int j=0; j<transitions.at(i).size(); ++j) {
                ans += "{";
                for(int k=0; k<transitions.at(i).at(j).size(); ++k) {

                    double val = transitions.at(i).at(j).at(k);
                    ans += to_string(val);

                    if(k < transitions.at(i).at(j).size()-1) {
                        ans += ",";
                    }
                }
                ans += "}";
                if(j < transitions.at(i).size()-1) {
                    ans += ",";
                }
            }

            ans += "}";
            if(i < transitions.size()-1) {
                ans += ",";
            }
        }
        ans += "})}";

        if(counter < _allG.size()-1) {
            ans += ",";
        }
        ++counter;
    }
    ans += "})";
    return ans;
}


void EMPedigreeOptimizer::_updateMaleLMN() {
    vector<int> lmn = _allLMN.at("male");
    _maleL = lmn.at(0);
    _maleM = lmn.at(1);
    _maleN = lmn.at(2);
}
void EMPedigreeOptimizer::_updateFemaleLMN() {
    vector<int> lmn = _allLMN.at("female");
    _femaleL = lmn.at(0);
    _femaleM = lmn.at(1);
    _femaleN = lmn.at(2);
}
void EMPedigreeOptimizer::_updateUnknownLMN() {
    vector<int> lmn = _allLMN.at("unknown");
    _unknownL = lmn.at(0);
    _unknownM = lmn.at(1);
    _unknownN = lmn.at(2);
}

int EMPedigreeOptimizer::_getL(personClass* person) {
    if(person->sex == "male") {
        if(_maleL == -1) {
            _updateMaleLMN();
        }
        return _maleL;
    }
    else if(person->sex == "female") {
        if(_femaleL == -1) {
            _updateFemaleLMN();
        }
        return _femaleL;
    }
    else if(person->sex == "unknown") {
        if(_unknownL == -1) {
            _updateUnknownLMN();
        }
        return _unknownL;
    }
    else {
        cout << "Invalid sex" << endl;
        raise(SIGABRT);
    }
    return -1;
}

int EMPedigreeOptimizer::_getM(personClass* person) {
    if(person->sex == "male") {
        if(_maleM == -1) {
            _updateMaleLMN();
        }
        return _maleM;
    }
    else if(person->sex == "female") {
        if(_femaleM == -1) {
            _updateFemaleLMN();
        }
        return _femaleM;
    }
    else if(person->sex == "unknown") {
        if(_unknownM == -1) {
            _updateUnknownLMN();
        }
        return _unknownM;
    }
    else {
        cout << "Invalid sex" << endl;
        raise(SIGABRT);
    }
    return -1;
}

int EMPedigreeOptimizer::_getN(personClass* person) {
    if(person->sex == "male") {
        if(_maleN == -1) {
            _updateMaleLMN();
        }
        return _maleN;
    }
    else if(person->sex == "female") {
        if(_femaleN == -1) {
            _updateFemaleLMN();
        }
        return _femaleN;
    }
    else if(person->sex == "unknown") {
        if(_unknownN == -1) {
            _updateUnknownLMN();
        }
        return _unknownN;
    }
    else {
        cout << "Invalid sex" << endl;
        raise(SIGABRT);
    }
    return -1;
}

int EMPedigreeOptimizer::_getL(string sex) {
    if(sex == "male") {
        if(_maleL == -1) {
            _updateMaleLMN();
        }
        return _maleL;
    }
    else if(sex == "female") {
        if(_femaleL == -1) {
            _updateFemaleLMN();
        }
        return _femaleL;
    }
    else if(sex == "unknown") {
        if(_unknownL == -1) {
            _updateUnknownLMN();
        }
        return _unknownL;
    }
    else {
        cout << "Invalid sex" << endl;
        raise(SIGABRT);
    }
    return -1;
}

int EMPedigreeOptimizer::_getM(string sex) {
    if(sex == "male") {
        if(_maleM == -1) {
            _updateMaleLMN();
        }
        return _maleM;
    }
    else if(sex == "female") {
        if(_femaleM == -1) {
            _updateFemaleLMN();
        }
        return _femaleM;
    }
    else if(sex == "unknown") {
        if(_unknownM == -1) {
            _updateUnknownLMN();
        }
        return _unknownM;
    }
    else {
        cout << "Invalid sex" << endl;
        raise(SIGABRT);
    }
    return -1;
}

int EMPedigreeOptimizer::_getN(string sex) {
    if(sex == "male") {
        if(_maleN == -1) {
            _updateMaleLMN();
        }
        return _maleN;
    }
    else if(sex == "female") {
        if(_femaleN == -1) {
            _updateFemaleLMN();
        }
        return _femaleN;
    }
    else if(sex == "unknown") {
        if(_unknownN == -1) {
            _updateUnknownLMN();
        }
        return _unknownN;
    }
    else {
        cout << "Invalid sex" << endl;
        raise(SIGABRT);
    }
    return -1;
}

double EMPedigreeOptimizer::_safeAdd(double lhs, double rhs) {

    if(lhs == UNIQUE_ZERO_ID || rhs == UNIQUE_ZERO_ID) {
        return UNIQUE_ZERO_ID;
    }
    return lhs + rhs;
}

void EMPedigreeOptimizer::_safeAdd(logAddition &lhs, double rhs) {

    if(rhs != UNIQUE_ZERO_ID) {
        lhs.addPositiveLogPoint(rhs);
    }
}

double EMPedigreeOptimizer::_safeExp(double log_val) {
    if(log_val == UNIQUE_ZERO_ID) {
        return 0;
    }
    return exp(log_val);
}

void EMPedigreeOptimizer::_resetPedigrees() {        
    
    for(auto ped_it=_trainingSet.begin(); ped_it!=_trainingSet.end(); ++ped_it) {
        (*ped_it)->resetAll();
    }
}

vector<double> EMPedigreeOptimizer::_leastSquaresDiff(const vector<vector<vector<double>>> & oldRootProbs, const vector<vector<vector<vector<double>>>> & oldTransitionProbs, const vector<vector<vector<double>>> & oldEmissionProbs) {
    
    double rootsDiff = 0.0;
    for(int i1=0; i1<oldRootProbs.size(); ++i1) {
        for(int i2=0; i2<oldRootProbs.at(i1).size(); ++i2) {
            for(int i3=0; i3<oldRootProbs.at(i1).at(i2).size(); ++i3) {
                double oldProb = oldRootProbs.at(i1).at(i2).at(i3);
                double newProb = _rootProbs.at(i1).at(i2).at(i3);
                rootsDiff += pow(oldProb-newProb,2);
            }
        }
    }
    
    double transDiff = 0.0;
    for(int i1=0; i1<oldTransitionProbs.size(); ++i1) {
        for(int i2=0; i2<oldTransitionProbs.at(i1).size(); ++i2) {
            for(int i3=0; i3<oldTransitionProbs.at(i1).at(i2).size(); ++i3) {
                for(int i4=0; i4<oldTransitionProbs.at(i1).at(i2).at(i3).size(); ++i4) {
                    
                    double oldTrans = oldTransitionProbs.at(i1).at(i2).at(i3).at(i4);
                    double newTrans = _transitionProbs.at(i1).at(i2).at(i3).at(i4);
                    transDiff += pow(oldTrans-newTrans,2);
                }
            }
        }
    }
    
    double emissDiff = 0.0;
    for(int i1=0; i1<oldEmissionProbs.size(); ++i1) {
        for(int i2=0; i2<oldEmissionProbs.at(i1).size(); ++i2) {
            for(int i3=0; i3<oldEmissionProbs.at(i1).at(i2).size(); ++i3) {
                double oldProb = oldEmissionProbs.at(i1).at(i2).at(i3);
                double newProb = _emissionProbs.at(i1).at(i2).at(i3);
                emissDiff += pow(oldProb-newProb,2);
            }
        }
    }
    
    return vector<double>({rootsDiff,transDiff,emissDiff});
}

void EMPedigreeOptimizer::_resetDataStructures() {

    for(int i=0; i<_log_u.size(); ++i) {            
        for(int j=0; j<_log_u.at(i).size(); ++j) {                
            for(int k=0; k<_log_u.at(i).at(j).size(); ++k) {                    
                _log_u.at(i).at(j).at(k).first = false;                    
                _log_u.at(i).at(j).at(k).second = -1;                    
            }
        }
    }
    for(int i1=0; i1<_log_w.size(); ++i1) {            
        for(int i2=0; i2<_log_w.at(i1).size(); ++i2) {                
            for(int i3=0; i3<_log_w.at(i1).at(i2).size(); ++i3) {                    
                for(int i4=0; i4<_log_w.at(i1).at(i2).at(i3).size(); ++i4) {                        
                    for(int i5=0; i5<_log_w.at(i1).at(i2).at(i3).at(i4).size(); ++i5) {                            
                        _log_w.at(i1).at(i2).at(i3).at(i4).at(i5).first = false;                            
                        _log_w.at(i1).at(i2).at(i3).at(i4).at(i5).second = -1;                            
                    }
                }
            }
        }
    }
    for(int i1=0; i1<_log_a.size(); ++i1) {            
        for(int i2=0; i2<_log_a.at(i1).size(); ++i2) {                
            for(int i3=0; i3<_log_a.at(i1).at(i2).size(); ++i3) {                    
                for(int i4=0; i4<_log_a.at(i1).at(i2).at(i3).size(); ++i4) {                        
                    _log_a.at(i1).at(i2).at(i3).at(i4).first = false;                        
                    _log_a.at(i1).at(i2).at(i3).at(i4).second = -1;                        
                }
            }
        }
    }
    for(int i1=0; i1<_log_b.size(); ++i1) {            
        for(int i2=0; i2<_log_b.at(i1).size(); ++i2) {                
            for(int i3=0; i3<_log_b.at(i1).at(i2).size(); ++i3) {                    
                for(int i4=0; i4<_log_b.at(i1).at(i2).at(i3).size(); ++i4) {                        
                    for(int i5=0; i5<_log_b.at(i1).at(i2).at(i3).at(i4).size(); ++i5) {                            
                        for(int i6=0; i6<_log_b.at(i1).at(i2).at(i3).at(i4).at(i5).size(); ++i6) {                                
                            _log_b.at(i1).at(i2).at(i3).at(i4).at(i5).at(i6).first = false;                                
                            _log_b.at(i1).at(i2).at(i3).at(i4).at(i5).at(i6).second = -1;                                
                        }
                    }
                }
            }
        }
    }
}

bool EMPedigreeOptimizer::_logCompare(double log_a, double log_b) {
    // makes sure that log_a and log_b are close enough together
    double diff;
    if(log_a > log_b) {
        diff = log_a + log1p(-exp(log_b - log_a));
    }
    else {
        diff = log_b + log1p(-exp(log_a - log_b));
    }
    return diff < -LOG_PRECISION;
}

double EMPedigreeOptimizer::_getEmissionProb(personClass* person, int state) {
    int sexIndex = _getSexIndex(person);
    int shadingIndex = _emissionMapping.at(person->typeOfShading);
    double emissionProb = _emissionProbs.at(sexIndex).at(state).at(shadingIndex);
    return emissionProb;
}

double EMPedigreeOptimizer::_getRootProb(pedigreeClass2* pedigree, personClass* person, int state) {
    int rootIndex = pedigree->mapToIndexRoots.at(person);
    int pedigreeIndex = -1;
    for(int i=0; i<_trainingSet.size(); ++i) {
        if(pedigree == _trainingSet.at(i)) {
            pedigreeIndex = i;
            break;
        }
    }
    double rootProb = _rootProbs.at(pedigreeIndex).at(rootIndex).at(state);
    return rootProb;
}

double EMPedigreeOptimizer::_getTransitionProb(personClass* person, int motherState, int fatherState, int state) {
    int sexIndex = _getSexIndex(person);
    double transProb = _transitionProbs.at(sexIndex).at(motherState).at(fatherState).at(state);
    return transProb;
}

vector<personClass*>& EMPedigreeOptimizer::_getFamily(pedigreeClass2* pedigree, personClass* parentA, personClass* parentB) {
    personClass* mother;
    personClass* father;
    _sortMates(parentA,parentB,mother,father);
    int f = _getFamNumb(pedigree,mother,father);
    return pedigree->families.at(f);
}

personClass* EMPedigreeOptimizer::_getMother(personClass* person) {
    personClass* mother;
    personClass* father;
    _sortMates(person->parentA,person->parentB,mother,father);
    return mother;
}

personClass* EMPedigreeOptimizer::_getFather(personClass* person) {
    personClass* mother;
    personClass* father;
    _sortMates(person->parentA,person->parentB,mother,father);
    return father;
}

double EMPedigreeOptimizer::_safeReturn(logAddition sum) {
    if(sum.needToInitialize) {
        return UNIQUE_ZERO_ID;
    }
    return sum.log_ans;
}

int EMPedigreeOptimizer::_getSexIndex(personClass* person) {
    return _sexIndexMapping.at(person->sex);
}

void EMPedigreeOptimizer::_sortMates(personClass* mateA, personClass* mateB, personClass*& femaleMate, personClass*& maleMate) {
    if(mateA->sex == "female") {
        femaleMate = mateA;
        maleMate = mateB;
    }
    else {
        maleMate = mateA;
        femaleMate = mateB;
    }
}        

int EMPedigreeOptimizer::_getFamNumb(pedigreeClass2* pedigree, personClass* mateA, personClass* mateB) {
    
    personClass* femaleParent = nullptr;
    personClass* maleParent = nullptr;
    _sortMates(mateA,mateB,femaleParent,maleParent);
    
    int ans = 0;
    for(auto fam_it=pedigree->families.begin(); fam_it!=pedigree->families.end(); ++fam_it) {
        
        if(femaleParent == fam_it->at(0) && maleParent == fam_it->at(1)) {
            return ans;
        }
        ++ans;
    }
    cout << "Couldn't find a family with these two mates!" << endl;
    raise(SIGABRT);
    return -1;
}

/* ------------------------------------------------------------------------------------------- */

int sgn(double val) {
    if(val == 0) {
        return 0;
    }
    else if(val < 0) {
        return -1;
    }
    else {
        return 1;
    }
}


topK::topK(int size) {
    vals = vector<double>(size,-999);
    make_heap(vals.begin(),vals.end(),cmp());
}

void topK::addPoint(double point) {
    if(point > vals.front()) {
        pop_heap(vals.begin(), vals.end(), cmp());
        vals.pop_back();
        
        vals.push_back(point);
        push_heap(vals.begin(), vals.end(), cmp());
    }
}

void topK::finalSort() {
    sort_heap(vals.begin(), vals.end(), cmp());
}

/* ------------------------------------------------------------------------------------------- */


double __accumulatePositive(double log_x, double log_y) {
    if(log_x < -500) {
        return log_y;
    }
    if(log_y < -500) {
        return log_x;
    }
    return log_x + log1p(exp(log_y - log_x));
}

double __accumulateNegative(double log_x, double log_y) {
    return log_x + log1p(-exp(log_y - log_x));
}

void logAddition::_accumulatePositive(double log_x) {
    double lastVal = this->log_ans;
    this->log_ans = __accumulatePositive(this->log_ans, log_x);
    if(isinf(this->log_ans)) {
        cout << "Infinite value!" << endl;
        cout << "Last value was: " << lastVal << endl;
        cout << "Added was: " << log_x << endl;
        raise(SIGABRT);
    }
}

void logAddition::_accumulateNegative(double log_x) {
    double lastVal = this->log_ans;
    this->log_ans = __accumulateNegative(this->log_ans, log_x);
    if(isinf(this->log_ans)) {
        cout << "Infinite value!" << endl;
        cout << "Last value was: " << lastVal << endl;
        cout << "Added was: " << log_x << endl;
        raise(SIGABRT);
    }
}

void logAddition::_addPoint(int sign, double log_x) {

    if(_lastAddedPoints.size() > 100) {
        _lastAddedPoints.pop();
    }
    _lastAddedPoints.push(log_x);
    if(this->needToInitialize) {
        if(sign == 0) {
            return;
        }
        this->log_ans = log_x;
        this->needToInitialize = false;
    }
    else if(sign == -1) {
        this->_accumulateNegative(log_x);
    }
    else if(sign == 1){
        this->_accumulatePositive(log_x);
    }
    else {
        return;
    }
}

void logAddition::addPositiveLogPoint(double log_x) {
    this->_addPoint(1,log_x);
}
void logAddition::addNegativeLogPoint(double log_x) {
    this->_addPoint(-1,log_x);
}
void logAddition::addZeroPoint() {
    return;
}
void logAddition::addPoint(double x) {
    if(x == 0) {
        return;
    }
    this->_addPoint(sgn(x),log(abs(x)));
}

/* ------------------------------------------------------------------------------------------- */


void logVariance::_avgIsZero(int sign, double log_x) {
    this->sign_avg = sign;
    if(sign != 0) {
        this->log_x_avg = log_x - log(this->n);
    }
}

void logVariance::_updateAvg(int sign, double log_x) {
    
    if(this->sign_avg == 0) {
        this->_avgIsZero(sign,log_x);
        return;
    }
    
    double log_p1 = log(1.0-1.0/this->n) + this->log_x_avg;
    double log_p2 = log_x - log(this->n);
    
    if(sign == 0) {
        this->log_x_avg = log_p1;
    }
    else if(sign == this->sign_avg) {
        this->log_x_avg = __accumulatePositive(log_p1,log_p2);
    }
    else {
        if(log_p1 > log_p2) {
            this->log_x_avg = __accumulateNegative(log_p1,log_p2);
        }
        else if(log_p1 < log_p2) {
            this->log_x_avg = __accumulateNegative(log_p2,log_p1);
            this->sign_avg = sign;
        }
        else {
            this->log_x_avg = __DBL_MAX__;
            this->sign_avg = 0;
        }
    }
}

void logVariance::_updateM(int sign, double log_x, int old_sign_avg, double old_log_x_avg) {
    
    if(this->n == 1) {
        return;
    }
    double log_p1 = sign == 0 ? __DBL_MAX__ : 2*log_x;
    double log_p2 = sign*this->sign_avg == 0 ? __DBL_MAX__ : log_x + this->log_x_avg;
    double log_p3 = sign*old_sign_avg == 0 ? __DBL_MAX__ : log_x + old_log_x_avg;
    double log_p4 = old_sign_avg*this->sign_avg == 0 ? __DBL_MAX__ : this->log_x_avg + old_log_x_avg;
    
    bool log_m_has_val = false;
    
    if(this->n > 2 && this->log_m != __DBL_MAX__) {
        if(sign != 0) {
            this->log_m = __accumulatePositive(this->log_m,log_p1);
            log_m_has_val = true;
        }
    }
    else {
        if(sign != 0) {
            this->log_m = log_p1;
            log_m_has_val = true;
        }
    }
    
    /* ------------- */
    
    if(log_m_has_val == false) {
        if(this->sign_avg*old_sign_avg != 0) {
            if(this->log_m != __DBL_MAX__) {
                this->log_m = __accumulatePositive(this->log_m,log_p4);
            }
            else {
                this->log_m = log_p4;
            }
        }
        else {
            return;
        }
    }
    else if(this->sign_avg*old_sign_avg == 1) {
        this->log_m = __accumulatePositive(this->log_m,log_p4);
    }
    else if(this->sign_avg*old_sign_avg == -1) {
        this->log_m = __accumulateNegative(this->log_m,log_p4);
    }
    
    /* ------------- */
    
    if(sign*this->sign_avg == -1) {
        this->log_m = __accumulatePositive(this->log_m,log_p2);
    }
    else if(sign*this->sign_avg == 1) {
        this->log_m = __accumulateNegative(this->log_m,log_p2);
    }
    
    /* ------------- */
    
    if(sign*old_sign_avg == -1) {
        this->log_m = __accumulatePositive(this->log_m,log_p3);
    }
    else if(sign*old_sign_avg == 1) {
        this->log_m = __accumulateNegative(this->log_m,log_p3);
    }
}

void logVariance::_addPoint(int sign, double log_x) {
    this->n += 1;
    double old_log_x_avg = this->log_x_avg;
    int old_sign_avg = this->sign_avg;
    this->_updateAvg(sign,log_x);
    this->_updateM(sign,log_x,old_sign_avg,old_log_x_avg);
    if(this->n > 1) {
        this->log_var = this->log_m - log(this->n - 1);
    }
}

void logVariance::addPositiveLogPoint(double log_x) {
    this->_addPoint(1,log_x);
}
void logVariance::addNegativeLogPoint(double log_x) {
    this->_addPoint(-1,log_x);
}
void logVariance::addZeroPoint() {
    this->_addPoint(0,__DBL_MAX__);
}
void logVariance::addPoint(double x) {
    if(x == 0) {
        this->_addPoint(0,__DBL_MAX__);
        return;
    }
    this->_addPoint(sgn(x),log(abs(x)));
}

double logVariance::getLogStdev() {
    return this->log_var*0.5;
}

