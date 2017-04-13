// g++ logProbIPNew.cpp -I/usr/local/include -L/usr/local/lib -lgsl -lgslcblas -O3 -std=c++11

#include "logProbIPNew.h"


#define MY_DEBUG false

/*
 
 #1 naive monte carlo with primitive numbers
 #2 naive monte carlo with big number library
 #3 naive monte carlo with log trick and primitive numbers
 #4 naive monte carlo with log trick with big number library
 #5 vegas with log trick and primitive numbers
 #6 vegas with big number library
 #7 vegas with log trick with big number
 
 */

using namespace std;

void personClass::storeProbAndNormalize() {
    
    if(MY_DEBUG) {
        cout << "LINE: " << __LINE__ << endl;
        this->toString();
    }
    double t = this->t;
    double s = this->s;
    double l = this->l;
    double m = this->m;
    double n = this->n;

    double probability = 0.0;
    for(int i=0; i<m; ++i) {

        if(i < l) {
            probability += this->probs[i]*(1-s);
        }
        else {
            probability += this->probs[i]*s;
        }
        if(!(this->probs[i] >= 0 and this->probs[i] <= 1.0+pow(10,15))) {
            raise(SIGABRT);
        }
    }
    this->probability = probability;
    
    double sumOther = 0.0;
    for(int i=m; i<n; ++i) {
        sumOther += this->probs[i];
    }
    
    
    // FIGURE OUT BETTER WAY TO DEAL WITH CONTRADICTIONS
    if((this->probability < pow(10,-15) or this->probability > 1.0+pow(10,15)) and t == 1.0) {
        this->dontInclude = true;
        return;
    }
    if(abs(sumOther) < pow(10,-15) and t == 0.0) {
        this->dontInclude = true;
        return;
    }
    
    
    for(int i=0; i<m; ++i) {
        if(abs(this->probability) < pow(10,-15)) {
            this->probs[i] = 0.0;
        }
        else {
            if(i < l) {
                this->probs[i] *= t*(1-s)/this->probability;
            }
            else {
                this->probs[i] *= t*s/this->probability;
            }
        }
    }
    for(int i=m; i<n; ++i) {
        if(abs(sumOther) < pow(10,-15)) {
            this->probs[i] = 0.0;
        }
        else {
            this->probs[i] *= (1.0-t)/sumOther;
        }
    }
    /////////////////////////////////////////////////////
    
    double totalSum = 0.0;
    for(int i=0; i<this->probs.size(); ++i) {
        totalSum += this->probs.at(i);
    }
    if(abs(totalSum-1.0) > pow(10,-15)) {
        // cout << "Total sum wasn't 1!  It was " << totalSum << endl;
        //             string a;
        //             cin >> a;
        for(int i=0; i<this->probs.size(); ++i) {
            this->probs[i] /= totalSum;
        }
    }
}


double pedigreeClass2::getNormVal(personClass *p, int index) {
    
    if(p->updated) {
        return p->probs.at(index);
    }
    
    updateProbs(p);
    return p->probs.at(index);
}

// will place the normalized val in the
void pedigreeClass2::updateProbs(personClass* c) {
    
    if(MY_DEBUG) {
        cout << "LINE: " << __LINE__ << endl;
        c->toString();
    }
    
    if(c->updated) {
        return;
    }
    
    vector<vector<vector<double>>>& g = c->g;
    personClass* p = c->parentA;
    personClass* q = c->parentB;
    
    for(int i=0; i<g.size(); ++i) {
        
        c->probs[i] = 0.0;
        for(int j=0; j<g.at(i).size(); ++j) {
            
            double pProb = this->getNormVal(p,j);
            for(int k=0; k<g.at(i).at(j).size(); ++k) {
                
                double qProb = this->getNormVal(q,k);
                c->probs[i] += g.at(i).at(j).at(k)*pProb*qProb;
            }
        }
    }
    c->storeProbAndNormalize();
    c->updated = true;
    
    if(MY_DEBUG) {
        cout << "LINE: " << __LINE__ << endl;
        c->toString();
    }
}

double pedigreeClass2::getProbability() {
    double totalAns = 1.0;
    
    for(auto p_it=this->allPeople.begin(); p_it!=this->allPeople.end(); ++p_it) {
        updateProbs(*p_it);
        if((*p_it)->dontInclude) {
            if((*p_it)->isRoot) {
                return __DBL_MAX__;
            }
            // cout << "skipping this dude:\n";
            // (*p_it)->toString();
            continue;
        }

        double t = (*p_it)->t;
        double prob = (*p_it)->probability;
        double probOfShading = t*prob + (1-t)*(1-prob);
        totalAns *= probOfShading;
    }
    
    return totalAns;
}

double pedigreeClass2::getLogProbability() {
    double totalAns = 0.0;
    
    for(auto p_it=this->allPeople.begin(); p_it!=this->allPeople.end(); ++p_it) {
        updateProbs(*p_it);
        if((*p_it)->dontInclude) {
            if((*p_it)->isRoot) {
                return __DBL_MAX__;
            }
            continue;
        }

        double t = (*p_it)->t;
        // s term is already included in prob
        double prob = (*p_it)->probability;
        double probOfShading = t*prob + (1-t)*(1-prob);
        totalAns += log(probOfShading);
    }
    return totalAns;
}

void pedigreeClass2::_oneAffectedPDF(bool useNewDist, double K) {

    if(!useNewDist) {
        this->log_probRoots = 1.0;
    }

    personClass* itMax = nullptr;
    double maxVal = -1.0;

    this->log_probRoots = 0.0;

    for(auto c_it=this->carrierRoots.at(0).begin(); c_it!=this->carrierRoots.at(0).end(); ++c_it) {
        double val = (*c_it)->probability;
        if(val > maxVal) {
            itMax = *c_it;
            maxVal = val;
        }            
    }

    for(auto r_it=this->roots.begin(); r_it!=this->roots.end(); ++r_it) {
        if((*r_it)==itMax) {
            this->log_probRoots += -K*(1.0-(*r_it)->probability);
        }
        else {
            this->log_probRoots += -K*(*r_it)->probability;
        }
    }
}

void pedigreeClass2::updateRootLogPDF(bool useNewDist, double K) {
    this->_oneAffectedPDF(useNewDist,K);
}


pair<double,double> pedigreeClass2::logEvaluation(const vector<double> & x, bool useNewDist, double K) {
    
    for(auto p_it=this->allPeople.begin(); p_it!=this->allPeople.end(); ++p_it) {
        (*p_it)->updated = false;
        (*p_it)->dontInclude = false;
    }
    
    // still need to integrate using spherical coordinates!!
    int index = 0;
    double log_extraSines = 0.0;
    double log_rootProb = 0.0;

    
    if(MY_DEBUG) {
        cout << "\n\n\n~~~~~~~~~~~~~~ NEW EVAL ~~~~~~~~~~~~~~" << endl;
    }
    
    vector<double> sphericalParameters(x.size());
    
    for(auto r_it=this->roots.begin(); r_it!=this->roots.end(); ++r_it) {
        
        // get the spherical parameters from x
        int n = (*r_it)->n;
        for(int i=0; i<n-1; ++i) {
            sphericalParameters[i] = x[index+i];
        }
        index += n-1;
        
        vector<double>& probs = (*r_it)->probs;
        double total = 0.0;
        for(int i=0; i<probs.size(); ++i) {
            
            double value = 1.0;
            if(i < n-1) {
                value *= cos(sphericalParameters.at(i));
            }
            for(int j=0; j<i; ++j) {
                value *= sin(sphericalParameters.at(j));
            }
            probs[i] = pow(value,2);
            if(!(probs[i] <= 1.0 && probs[i] >= 0)) {
                raise(SIGABRT);
            }
            total += pow(value,2);
            
            if(i < n-2) {
                log_extraSines += (n-2-i)*log(sin(sphericalParameters.at(i)));
            }
        }

        if(abs(total-1.0) >= pow(10,-15)) {
            cout << "The total was: " << total << endl;
            if(!(0)) {
                raise(SIGABRT);
            }
        }
        
        (*r_it)->storeProbAndNormalize();
        if((*r_it)->dontInclude) {
            return pair<double,double>(__DBL_MAX__,__DBL_MAX__);
        }
        if(!((*r_it)->probability <= 1.0+pow(10,15) and (*r_it)->probability >= 0.0)) {
            raise(SIGABRT);
        }
        (*r_it)->updated = true;
    }
    
    if(MY_DEBUG) {
        cout << "\n========================================" << endl;
        for(auto p_it=this->allPeople.begin(); p_it!=this->allPeople.end(); ++p_it) {
            
            cout << "LINE: " << __LINE__ << endl;
            (*p_it)->toString();
        }
        cout << "----------------------------------------" << endl;
    }
    double log_prob = this->getLogProbability();
    if(log_prob == __DBL_MAX__) {
        return pair<double,double>(__DBL_MAX__,__DBL_MAX__);
    }

    // calculate the probaility of this root configuration
    this->updateRootLogPDF(useNewDist,K);
    this->lastLogEval = log_prob+log_extraSines+this->log_probRoots;

    // first part is the answer, the second part is the part of the volume
    return pair<double,double>(this->lastLogEval,log_extraSines+this->log_probRoots);
}

void pedigreeClass2::updateAllChildrenAndLeaves() {

    for(auto p_it=this->allPeople.begin(); p_it!=this->allPeople.end(); ++p_it) {
        if((*p_it)->parentA == nullptr && (*p_it)->parentB == nullptr) {
            continue;
        }
        (*p_it)->parentA->children.push_back(*p_it);
        (*p_it)->parentB->children.push_back(*p_it);
    }

    for(auto p_it=this->allPeople.begin(); p_it!=this->allPeople.end(); ++p_it) {
        if((*p_it)->children.size() == 0) {
            this->leaves.push_back(*p_it);
        }
    }
}

bool autosomalContradiction(personClass* person) {

    // THINK ABOUT HOW TO REDO THIS (MAYBE HAVE S ALSO)

    if(person->t == 1.0) {
        if((person->parentA && person->parentB) && person->parentA->t == 0.0 && person->parentB->t == 0.0) {
            return true;
        }
    }
    else if(person->t == 0.0) {
        if((person->parentA && person->parentB) && person->parentA->t == 1.0 && person->parentB->t == 1.0) {
            return true;
        }
    }
    return false;
}

void goUp(personClass* person, bool found, unordered_set<personClass*>* relevantRoots, unordered_set<personClass*>* hasContradiction, bool useLeak, double leakProb, double leakDecay) {

/*
    GOAL IS TO MAKE PEOPLE WHO HAVE A PROB OF BEING 0 SOMETHING HIGHER LIKE 0.2
    TO DO THIS, MARK ONLY THE ANCESTORS OF AFFECTED PEOPLE TO THAT HIGHER VALUE.
    THEN THOSE PEOPLE WHO ARE BOTH MAKED BY THIS AND REVERSE ANCESTORS OF 
    THE CARRIER ROOTS
*/

    if(useLeak && found && person->affected == false) {

        // cout << "changing person: " << endl;
        // person->toString();
        // cout << endl;

        // THINK ABOUT IF LEAK PROBABILITY CAN CHANGE S
        if(person->t == 1.0) {
            person->t -= leakProb;
        }
        else if(person->t == 0.0) {
            person->t += leakProb;
        }
        else {
            // then we already changed this person
        }
        leakProb *= leakDecay;
    }

    if(hasContradiction->find(person) != hasContradiction->end()) {
        found = true;
    }

    if(person->parentA == nullptr && person->parentB == nullptr) {

        if(found || person->affected) {
            relevantRoots->insert(person);
        }
    }
    else {
        goUp(person->parentA,found,relevantRoots,hasContradiction,useLeak,leakProb,leakDecay);
        goUp(person->parentB,found,relevantRoots,hasContradiction,useLeak,leakProb,leakDecay);
    }
}

void pedigreeClass2::determineCarrierRoots(bool useLeak, double leakProb, double leakDecay) {
    // this function will go up the family tree and identify roots that could
    // possibly carry the affected allele.  Every time a child is affected, each 
    // parent's side of the family tree is recursed upon.

    // find all of the autosomal contradictions
    unordered_set<personClass*> hasContradiction;
    for(auto p_it=this->allPeople.begin(); p_it!=this->allPeople.end(); ++p_it) {
        if(autosomalContradiction(*p_it)) {
            hasContradiction.insert(*p_it);
        }
    }

    unordered_set<personClass*> relevantRoots;
    for(auto l_it=this->leaves.begin(); l_it!=this->leaves.end(); ++l_it) {
        goUp(*l_it,false,&relevantRoots,&hasContradiction,useLeak,leakProb,leakDecay);
    }

    this->carrierRoots = vector<vector<personClass*>>(1,vector<personClass*>(relevantRoots.begin(),relevantRoots.end()));
}



vector<double> pedigreeClass2::monteCarlo(long numbCalls, bool printIterations, int numbToPrint, bool printPeople, bool useNewDist, double K, bool useLeak, double leakProb, double leakDecay, bool useMH) {
    srand(1234);

    this->updateAllChildrenAndLeaves();
    this->determineCarrierRoots(useLeak,leakProb,leakDecay);


    if(printPeople) {
        for(int i=0; i<this->allPeople.size(); ++i) {
            this->allPeople[i]->toString();
        }
    }
    
    if(useMH) {
        return this->_monteCarloMH(numbCalls, printIterations, numbToPrint, useNewDist, K, useLeak, leakProb, leakDecay);
    }
    else {
        return this->_uniformMonteCarlo(numbCalls, printIterations, numbToPrint, useNewDist, K, useLeak, leakProb, leakDecay);
    }
}
