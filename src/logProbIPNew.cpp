// g++ logProbIPNew.cpp helperFunctions.cpp uniformMonteCarloIntegration.cpp pdfSamplingMonteCarloIntegration.cpp cMain.cpp -I/usr/local/include -L/usr/local/lib -lgsl -lgslcblas -O3 -std=c++11

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
        this->toString("");
    }
    double t = this->t;
    double s = this->s;
    double l = this->l;
    double m = this->m;
    double n = this->n;

    double probability = 0.0;
    double probToL = 0.0;
    double probFromL = 0.0;
    for(int i=0; i<m; ++i) {

        if(i < l) {
            probability += this->probs.at(i);
            probToL += (1-s)*this->probs.at(i);
        }
        else {
            probability += this->probs.at(i);
            probFromL += s*this->probs.at(i);
        }
        if(!(this->probs.at(i) >= 0 and this->probs.at(i) <= 1.0+pow(10,15))) {
            raise(SIGABRT);
        }
        this->probsAverage.at(i) += (this->probs.at(i)-this->probsAverage.at(i))/this->timesUpdated;
    }
    this->probability = probability;
    double probOfShading = this->t*probability + (1-this->t)*(1-probability);

    this->probOfShadingAverage += (probOfShading-this->probOfShadingAverage)/this->timesUpdated;
    
    this->timesUpdated += 1;
    
    double sumOther = 0.0;
    for(int i=m; i<n; ++i) {
        sumOther += this->probs.at(i);
    }
    
    
    if((this->probability < pow(10,-25) or this->probability > 1.0+pow(10,15)) and t == 1.0) {
//        cout << " | contradiction at person " << this->_id;
        this->dontInclude = true;
        throw 20;
        return;
    }
    if(sumOther < pow(10,-25) && t == 0.0) {
//        cout << " | contradiction at person " << this->_id;
        this->dontInclude = true;
        throw 20;
        return;
    }
    if(probFromL < pow(10,-25) && (t == 1.0 && s == 1.0)) {
//        cout << " | contradiction at person " << this->_id;
        this->dontInclude = true;
        throw 20;
        return;
    }
    
    
    for(int i=0; i<m; ++i) {
        if(abs(this->probability) < pow(10,-25)) {
            this->probs.at(i) = 0.0;
        }
        else {
            if(i < l) {
                this->probs.at(i) *= t*(1-s)/(probToL+probFromL);
            }
            else {
                this->probs.at(i) *= t*s/(probToL+probFromL);
            }
        }
    }
    for(int i=m; i<n; ++i) {
        if(abs(sumOther) < pow(10,-25)) {
            this->probs.at(i) = 0.0;
        }
        else {
            this->probs.at(i) *= (1.0-t)/sumOther;
        }
    }
    
    /////////////////////////////////////////////////////
    
    double totalSum = 0.0;
    for(int i=0; i<this->probs.size(); ++i) {
        totalSum += this->probs.at(i);
    }
    if(abs(totalSum-1.0) > pow(10,-25)) {
        // cout << "Total sum wasn't 1!  It was " << totalSum << endl;
        //             string a;
        //             cin >> a;
        for(int i=0; i<this->probs.size(); ++i) {
            this->probs.at(i) /= totalSum;
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
        c->toString("");
    }
    
    if(c->updated) {
        return;
    }
    
    vector<vector<vector<double>>>& g = c->g;
    personClass* p = c->parentA;
    personClass* q = c->parentB;
    
    double pProb,qProb;
    for(int i=0; i<g.size(); ++i) {
        
        c->probs.at(i) = 0.0;
        for(int j=0; j<g.at(i).size(); ++j) {
            
            pProb = this->getNormVal(p,j);
            for(int k=0; k<g.at(i).at(j).size(); ++k) {
                
                qProb = this->getNormVal(q,k);
                c->probs.at(i) += g.at(i).at(j).at(k)*pProb*qProb;
            }
        }
    }
    c->storeProbAndNormalize();
    c->updated = true;
    
    if(MY_DEBUG) {
        cout << "LINE: " << __LINE__ << endl;
        c->toString("");
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
/*
void pedigreeClass2::_oneAffectedPDF(double K) {

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
    if(!useNewDist) {
        this->_bruteForcePDF();
    }
    else {
        this->_oneAffectedPDF(K);
    }
}

pair<double,double> pedigreeClass2::logEvaluation(const vector<double> & x, bool useNewDist, double K, bool samplingFromPDF) {
    
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

        vector<double>& probs = (*r_it)->probs;
        int startIndex = (*r_it)->startIndex;
        int endIndex = (*r_it)->endIndex;
        
        // get the spherical parameters from x
        int n = (*r_it)->n;
        int nonZero = 0;
        for(int i=0; i<n-1; ++i) {
            sphericalParameters.at(i) = x.at(index+i);
            if(sphericalParameters.at(i) > 0) {
                nonZero += 1;
            }
        }
        index += n-1;

        if(endIndex-startIndex>0 && nonZero != endIndex-startIndex) {
            cout << "Was expecting this value to be " << endIndex-startIndex << endl;
            raise(SIGABRT);
        }
        assert(startIndex>=0);

        
        double total = 0.0;
        fill(probs.begin(),probs.end(),0.0);
        if(endIndex-startIndex == 0) {
            probs.at(startIndex) = 1;
            total += 1;
        }
        else {

            string helper = "";

            for(int i=0; i<(endIndex-startIndex+1); ++i) {
            // for(int i=0; i<probs.size(); ++i) {
                
                double value = 1.0;
                helper += "[";
                if(i < endIndex-startIndex) {
                    value *= cos(sphericalParameters.at(i));
                    helper += "cos^2(t"+to_string(i+startIndex)+") ";
                }
                for(int j=0; j<i; ++j) {
                    value *= sin(sphericalParameters.at(j));
                    helper += "sin^2(t"+to_string(j+startIndex)+") ";
                }
                probs.at(i+startIndex) = pow(value,2);
                if(!(probs.at(i+startIndex) <= 1.0 && probs.at(i+startIndex) >= 0)) {
                    raise(SIGABRT);
                }
                total += pow(value,2);
                helper += "] {";
                
                if(i < endIndex-startIndex-1) {
                    log_extraSines += (endIndex-startIndex-1-i)*log(sin(sphericalParameters.at(i)));
                    helper += "sin(t"+to_string(i+startIndex)+")^"+to_string(endIndex-startIndex-1-i)+" ";
                }
                helper += "} ";
            }
            helper += ";";
        }

        if(abs(total-1.0) >= pow(10,-15)) {
            cout << "The total was: " << total << endl;
            raise(SIGABRT);
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
            (*p_it)->toString("");
        }
        cout << "----------------------------------------" << endl;
    }
    double log_prob = this->getLogProbability();
    if(log_prob == __DBL_MAX__) {
        return pair<double,double>(__DBL_MAX__,__DBL_MAX__);
    }
    
    // calculate the probaility of this root configuration
    if(samplingFromPDF) {

        // if we are sampling from the pdf while using monte carlo integration, 
        // we don't need to worry about having a pdf that integrates to 1
        // because the normalization factors cancel out
        this->lastLogEval = log_prob;
    }
    else {
        this->updateRootLogPDF(useNewDist,K);
        this->lastLogEval = log_prob+log_extraSines+this->log_probRoots;
    }

    // first part is the answer, the second part is the part of the volume
    return pair<double,double>(this->lastLogEval,log_extraSines+this->log_probRoots);
}

void pedigreeClass2::updateAllChildrenAndLeaves() {

    // this is handled in cython now


    // for(auto p_it=this->allPeople.begin(); p_it!=this->allPeople.end(); ++p_it) {
    //     if((*p_it)->parentA == nullptr && (*p_it)->parentB == nullptr) {
    //         continue;
    //     }
    //     (*p_it)->parentA->children.push_back(*p_it);
    //     (*p_it)->parentB->children.push_back(*p_it);
    // }

    // for(auto p_it=this->allPeople.begin(); p_it!=this->allPeople.end(); ++p_it) {
    //     if((*p_it)->children.size() == 0) {
    //         this->leaves.push_back(*p_it);
    //     }
    // }
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

void goUp(personClass* person, bool found, unordered_set<personClass*>* relevantRoots, unordered_set<personClass*>* hasContradiction, unordered_set<personClass*>* relevantAncestors, bool useLeak, double leakProb, double leakDecay) {


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

    if(found && (person->affected == false) && person->parentA && person->s != 1.0) {
        // mark all people in the ancestral tree of affected people
        // who might be marked incorrectly.  these people must not be
        // roots and must not be affected
        relevantAncestors->insert(person);
    }

    if(person->parentA == nullptr && person->parentB == nullptr) {

        if(found || person->affected) {
            relevantRoots->insert(person);
        }
    }
    else {
        goUp(person->parentA,found,relevantRoots,hasContradiction,relevantAncestors,useLeak,leakProb,leakDecay);
        goUp(person->parentB,found,relevantRoots,hasContradiction,relevantAncestors,useLeak,leakProb,leakDecay);
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
    unordered_set<personClass*> relevantAncestors;
    for(auto l_it=this->leaves.begin(); l_it!=this->leaves.end(); ++l_it) {
        goUp(*l_it,false,&relevantRoots,&hasContradiction,&relevantAncestors,useLeak,leakProb,leakDecay);
    }

    this->possiblyAffectedAncestors = vector<personClass*>(relevantAncestors.begin(),relevantAncestors.end());
    this->carrierRoots = vector<vector<personClass*>>(1,vector<personClass*>(relevantRoots.begin(),relevantRoots.end()));
}

void pedigreeClass2::makeAffected(personClass* person) {
    if(!(person->affected)) {        
        if(this->isDominant) {
            person->t = 1.0;
            person->s = 0.5;
        }
        else {
            person->t = 0.0;
            person->s = 0.5;
        }
        person->affected = true;
    }
}

void pedigreeClass2::makeUnAffected(personClass* person) {
    if(person->affected) {        
        if(this->isDominant) {
            person->t = 0.0;
            person->s = 0.5;
        }
        else {
            person->t = 1.0;
            person->s = 0.5;
        }
        person->affected = false;
    }
}

void pedigreeClass2::makeCarrier(personClass* person) {
    if(person->affected) {        
        if(this->isDominant) {
            cout << "Can't have carriers in dominant case! " << endl;
            raise(SIGABRT);
        }
        else {
            person->t = 1.0;
            person->s = 1.0;
        }
        person->affected = false;
    }
}

void pedigreeClass2::getDominantOrRecessive() {

    for(auto p_it=this->allPeople.begin(); p_it!=this->allPeople.end(); ++p_it) {
        if((*p_it)->affected) {
            if((*p_it)->t == 1.0 && (*p_it)->s == 0.5) {
                this->isDominant = true;
                return;
            }
            else if((*p_it)->t == 0.0 && (*p_it)->s == 0.5) {
                this->isDominant = false;
                return;
            }
        }
        else {
            if((*p_it)->t == 0.0 && (*p_it)->s == 0.5) {
                this->isDominant = true;
                return;
            }
            else if((*p_it)->t == 1.0 && (*p_it)->s == 1.0) {
                this->isDominant = false;
                return;
            }
            else if((*p_it)->t == 1.0 && (*p_it)->s == 0.5) {
                this->isDominant = false;
                return;
            }
        }
    }
    cout << "should have figured out what type this is" << endl;
    raise(SIGABRT);
}
 
 vector<double> pedigreeClass2::monteCarlo(long numbCalls, bool printIterations, int numbToPrint, bool printPeople, bool useNewDist, double K, bool useLeak, double leakProb, double leakDecay, bool useMH, bool useBruteForce, int numbRoots, bool useHybrid) {
 srand(1234);
 
 this->getDominantOrRecessive();
 this->updateAllChildrenAndLeaves();
 this->determineCarrierRoots(useLeak,leakProb,leakDecay);
 
 if(printPeople) {
 this->printAllPeople("");
 }
 
 if(useMH) {
 return this->_monteCarloMH(numbCalls, printIterations, numbToPrint, useNewDist, K, useLeak, leakProb, leakDecay);
 }
 if(useBruteForce) {
 return this->_bruteForce(numbCalls, printIterations, numbToPrint, numbRoots);
 }
 if(useHybrid) {
 return this->_hybridMonteCarlo(numbCalls, printIterations, numbToPrint, K);
 }
 return this->_uniformMonteCarlo(numbCalls, printIterations, numbToPrint, useNewDist, K, useLeak, leakProb, leakDecay);
 }
 */

bool allReady(const unordered_set<personClass*>& currentSet, personClass* person, unordered_set<personClass*> beingInvestigated) {

    beingInvestigated.insert(person);

    for(auto mk: person->mateKids) {

        personClass* mate = mk.first;
        if(beingInvestigated.find(mate) != beingInvestigated.end()) {
            continue;
        }
        if(currentSet.find(mate) == currentSet.end()) {
            return false;
        }
        bool mateReady = allReady(currentSet,mate,beingInvestigated);
        if(!mateReady) {
            return false;
        }
    }
    return true;
}

void pedigreeClass2::makeBFL() {

    vector<personClass*> ans = roots;

    unordered_set<personClass*> currentSet(roots.begin(),roots.end());

    while(currentSet.size() > 0) {
        unordered_set<personClass*> nextSet;
        for(personClass* person: currentSet) {

            if(!allReady(currentSet,person,unordered_set<personClass*>())) {
                nextSet.insert(person);
                continue;
            }

            for(auto mk: person->mateKids) {

                vector<personClass*> children = mk.second;

                for(personClass* child: children) {
                    nextSet.insert(child);
                    if(find(ans.begin(),ans.end(),child) == ans.end()) {
                        ans.push_back(child);
                    }
                }
            }
        }
        currentSet = nextSet;
    }

    // check that everyone is covered once
    for(personClass* person: allPeople) {

        int totalInstances = 0;
        for(personClass* otherPerson: ans) {
            if(person == otherPerson) {
                totalInstances += 1;
            }
        }
        if(totalInstances != 1) {
            cout << "Should be 1!" << endl;
            raise(SIGABRT);
        }
    }
    bredthFirstList = ans;
}

void pedigreeClass2::printAllPeople(string numb) {

    if(bredthFirstList.size() == 0) {
        makeBFL();
    }
    for(personClass* person: bredthFirstList) {
        person->toString(numb);
    }
    for(personClass* person: bredthFirstList) {
        person->mateKidsString(numb);
    }
    



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    string str = "pedigreeClass2 pedigree"+numb+";\npedigree"+numb+".roots=vector<personClass*>({";
    for(int i=0; i<this->roots.size(); ++i) {
        str += "&x_"+numb;
        // if(this->roots.at(i)->_id < 0) {
        //     str += "_"+to_string(abs(this->roots.at(i)->_id));
        // }
        // else {
        //     str += to_string(this->roots.at(i)->_id);
        // }
        if(this->roots.at(i)->_id < 0) {
            str += "_";
        }
        str += to_string(abs(this->roots.at(i)->_id));

        if(i < this->roots.size()-1) {
            str += ",";
        }            
    }
    str += "});\n";
    str += "pedigree"+numb+".allPeople=vector<personClass*>({";
    for(int i=0; i<this->allPeople.size(); ++i) {
        str += "&x_"+numb;
        // if(this->allPeople.at(i)->_id < 0) {
        //     str += "_"+to_string(abs(this->allPeople.at(i)->_id));
        // }
        // else {
        //     str += to_string(this->allPeople.at(i)->_id);
        // }
        if(this->allPeople.at(i)->_id < 0) {
            str += "_";
        }
        str += to_string(abs(this->allPeople.at(i)->_id));
        if(i < this->allPeople.size()-1) {
            str += ",";
        } 
    }
    str += "});\n";

    // families
    str += "pedigree"+numb+".families=vector<vector<personClass*>>({";
    for(int i=0; i<this->families.size(); ++i) {
        str += "{";
        for(int j=0; j<this->families.at(i).size(); ++j) {
            str += "&x_"+numb;
            if(this->families.at(i).at(j)->_id < 0) {
                str += "_";
            }
            str += to_string(abs(this->families.at(i).at(j)->_id));
            if(j < this->families.at(i).size()-1) {
                str += ",";
            }
        }
        str += "}";
        if(i < this->families.size()-1) {
            str += ",";
        }
    }
    str += "});\n";

    // leaves
    str += "pedigree"+numb+".leaves=vector<personClass*>({";
    for(int i=0; i<this->leaves.size(); ++i) {
        str += "&x_"+numb;
        if(this->leaves.at(i)->_id < 0) {
            str += "_";
        }
        str += to_string(abs(this->leaves.at(i)->_id));
        if(i < this->leaves.size()-1) {
            str += ",";
        } 
    }
    str += "});\n";


    // isDominant
    str += "pedigree"+numb+".isDominant=";
    if(this->isDominant) {
        str += "true;\n";
    }
    else {
        str += "false;\n";
    }

    // sexDependent
    str += "pedigree"+numb+".sexDependent=";
    if(this->sexDependent) {
        str += "true;\n";
    }
    else {
        str += "false;\n";
    }

    // mapToIndexRoots
    str += "pedigree"+numb+".mapToIndexRoots=unordered_map<personClass*,int>({";
    int index = 0;
    for(auto it=this->mapToIndexRoots.begin(); it!=this->mapToIndexRoots.end(); ++it) {
        personClass* current = it->first;
        int val = it->second;
        str += "{";
        str += "&x_"+numb;
        if(current->_id < 0) {
            str += "_";
        }
        str += to_string(abs(current->_id));
        str += ","+to_string(val)+"}";

        if(index < this->mapToIndexRoots.size()-1) {
            str += ",";
        }
        ++index;
    }
    str += "});\n";

    // mapToIndexAllPeople
    str += "pedigree"+numb+".mapToIndexAllPeople=unordered_map<personClass*,int>({";
    index = 0;
    for(auto it=this->mapToIndexAllPeople.begin(); it!=this->mapToIndexAllPeople.end(); ++it) {
        personClass* current = it->first;
        int val = it->second;
        str += "{";
        str += "&x_"+numb;
        if(current->_id < 0) {
            str += "_";
        }
        str += to_string(abs(current->_id));
        str += ","+to_string(val)+"}";

        if(index < this->mapToIndexAllPeople.size()-1) {
            str += ",";
        }
        ++index;
    }
    str += "});\n";

    str += "pedigree"+numb+".filename = \""+this->filename+"\";\n";


    cout << str << endl;
}
