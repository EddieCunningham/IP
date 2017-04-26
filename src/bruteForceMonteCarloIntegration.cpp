#include "logProbIPNew.h"
#include "metropolisHastings.h"

/*
 
 the current bug is that for some reason the algorithm is converging on a slightly different
answer for test_newMethod.  the average values for all of the nodes are correct and 
the average sample value makes sense, but the overall value doesn't make sense for 
some reason...
 
 */

using namespace std;

void pedigreeClass2::_bruteForcePDF() {
    this->log_probRoots = 0.0;
    return;
}

vector<double> pedigreeClass2::_evaluateFromSingleRoot(long numbCalls, bool printIterations, int numbToPrint, unordered_set<personClass*> rootsToUse) {

    // will calculate the expected value of the pedigree assuming only one root can have the disease
    // this means that will integrate over different distribution of root probabilities


    bool printTopVals = false;

    int totalDim = 0;
    for(int i=0; i<this->roots.size(); ++i) {
        totalDim += this->roots.at(i)->n-1;
    }
    
    vector<double> xl(totalDim,-1.0);
    vector<double> xu(totalDim,-1.0);
    int index = 0;
    for(int i=0; i<this->roots.size(); ++i) {
        
        personClass* currentRoot = this->roots.at(i);
        int l = currentRoot->l;
        int m = currentRoot->m;
        int n = currentRoot->n;

        int& startIndex = currentRoot->startIndex;
        int& endIndex = currentRoot->endIndex;

        if(rootsToUse.find(currentRoot) != rootsToUse.end()) {
        // if(currentRoot == rootToUse) {

            if(currentRoot->affected == false) {
                cout << "root should be affected" << endl;
                raise(SIGABRT);
            }
            // integrate over possible affected/carrier probs

            // if dominant, go from 1 to m -> (m-1) parameters
            // if recessive, go from m to n -> (n-m) parameters

            if(this->isDominant) {
                startIndex = 0;
                endIndex = m-1;
            }
            else {
                startIndex = m;
                endIndex = n-1;
            }
        }
        else {
            // integrate over possible unaffected probs

            // if dominant, go from m+1 to n -> (n-m) parameters
            // if recessive, go from 1 to l -> (l-1) parameters

            if(this->isDominant) {
                startIndex = m;
                endIndex = n-1;
            }
            else {
                startIndex = 0;
                endIndex = l-1;
            }
        }
        assert(startIndex>=0);
        assert(endIndex>=0);
        for(int j=0; j<(endIndex-startIndex-1); ++j) {
            xl.at(index+j) = 0;
            xu.at(index+j) = M_PI;
        }
        if(endIndex-startIndex>0) {
            xl.at(index+(endIndex-startIndex-1)) = 0;
            xu.at(index+(endIndex-startIndex-1)) = 2*M_PI;
        }
        index += n-1;
    }
    
    try {   

        sampler theSampler(totalDim,xl,xu,this,true);
        theSampler.initState(false,-1);
        
        logAddition integral_adder;
        logVariance integral_variance;
        
        double currentAns = 0.0;
        double currentStdev = 0.0;

        const int BREAKHERE = 723968;
        const int PRINTMORE = 722700;

        topK tracker(1000);
        bool printFlag = false;

        double avg = 0.0;
    

        for(long i=0; i<numbCalls; ++i) {
            
            if(i == BREAKHERE) {
                int asdfasdf = 0;
            }

            //              x          rootProb
            const pair<vector<double>&,double> val = theSampler.nextSample(false,-1);
            double logEval_integral = this->lastLogEval;


            if(logEval_integral == __DBL_MAX__) {
                raise(SIGABRT);
                integral_adder.addZeroPoint();
                integral_variance.addZeroPoint();
            }
            else {
                integral_adder.addPositiveLogPoint(logEval_integral);
                integral_variance.addPositiveLogPoint(logEval_integral);
            }

            currentAns = integral_adder.log_ans - log(i+1);

            avg += (exp(currentAns)-avg)/(i+1);
            tracker.addPoint(currentAns);
            
            if(printIterations) {
                if(i > PRINTMORE) {
                    printFlag = false;
                }
                if((printFlag&&i%100) || (i%numbToPrint == 0 && i>0)) {

                    currentAns = integral_adder.log_ans - log(i+1);
                    currentStdev = integral_variance.getLogStdev() - 0.5*log(i+1);

                    cout << "\n\ni: " << i << endl;
                    cout << "Approximated log integral: " << currentAns << endl;
                    cout << "Current log standard deviation: " << currentStdev << endl;
                    cout << "\nApproximated integral: " << exp(currentAns) << endl;
                    cout << "Current log standard deviation: " << exp(currentStdev) << endl;
                    cout << "Acceptance rate: " << theSampler.acceptanceRatio << endl;
                }
            }
        }
        
        

        tracker.finalSort();
        if(printTopVals) {
            cout << "---------------------------\nTHE TOP 1000 VALUES---------------------------" << endl;
            for(int i=0; i<tracker.vals.size(); ++i) {
                cout << tracker.vals.at(i) << " ";
            }
            cout << endl << endl << endl;
        }

        currentAns = integral_adder.log_ans - log(numbCalls);
        currentStdev = integral_variance.getLogStdev() - 0.5*log(numbCalls);
        
        if(printIterations) {
            cout << "\n-----------\nApproximated log integral: " << currentAns << endl;
            cout << "Current log standard deviation: " << currentStdev << endl;
            cout << "Approximated integral: " << exp(currentAns) << endl;
            cout << "Approximated variance: " << exp(currentStdev) << endl;
        }

        double contradictionFlag = 0;
        for(auto p_it=this->allPeople.begin(); p_it!=this->allPeople.end(); ++p_it) {            
            if((*p_it)->dontInclude) {
                if(true) {
                    cout << "Had a contradiction with person " << (*p_it)->_id << endl;
                }
                contradictionFlag = 1;
            }
        }

        return vector<double>({contradictionFlag,currentAns,currentStdev});

    }
    catch(int e) {
        return vector<double>({1,0,0});
    }
    
}

struct combinationIterator {
    vector<int> v;
    combinationIterator(){}
    combinationIterator(int n, int nAffected, int nCarriers):
    v(n) {
        fill(v.end()-nAffected,v.end(),1);
        fill(v.end()-nAffected-nCarriers,v.end()-nAffected,2);
    }
    void initialize(int n, int nAffected, int nCarriers) {
        v = vector<int>(n);
        fill(v.end()-nAffected,v.end(),1);
        fill(v.end()-nAffected-nCarriers,v.end()-nAffected,1);
    }
    bool nextCombination() {
        return next_permutation(v.begin(), v.end());
    }
    void print() {
        for(int i=0; i<v.size(); ++i) {
            cout << v.at(i) << " ";
        }
        cout << endl;
    }
};

pair<double,vector<personClass*>> pedigreeClass2::_bruteForceWithNumbAffected(long numbCalls, bool printIterations, int numbToPrint, int numbRoots, int numbToChange) {

    if(numbToChange > this->possiblyAffectedAncestors.size()+numbRoots) {
        // shouldn't get here
        raise(SIGABRT);
    }

    unordered_set<personClass*> changed;

    pair<double,vector<personClass*>> maxVal(-1,vector<personClass*>({nullptr}));
    
    combinationIterator combRoot(this->carrierRoots.at(0).size(),numbRoots,0);
    do {

        unordered_set<personClass*> rootsToUse;

        for(int i=0; i<combRoot.v.size(); ++i) {
            if(combRoot.v.at(i)) {
                personClass* toAdd = this->carrierRoots.at(0).at(i);
                changed.insert(toAdd);
                if(combRoot.v.at(i) == 1) {
                    this->makeAffected(toAdd);
                }
                else {
                    this->makeCarrier(toAdd);
                }
                rootsToUse.insert(toAdd);
            }
        }


        combinationIterator combNonRoot;
        if(this->isDominant) {
            combNonRoot.initialize(this->possiblyAffectedAncestors.size(),numbToChange-numbRoots,0);
        }
        else {
            combNonRoot.initialize(this->possiblyAffectedAncestors.size(),numbToChange-numbRoots,0);
        }
        do {

            for(int i=0; i<combNonRoot.v.size(); ++i) {
                if(combNonRoot.v.at(i)) {
                    personClass* toAdd = this->possiblyAffectedAncestors.at(i);
                    changed.insert(toAdd);
                    if(combNonRoot.v.at(i) == 1) {
                        this->makeAffected(toAdd);
                    }
                    else {
                        this->makeCarrier(toAdd);
                    }
                }
            }

//            cout << "changed: ";
//            for(auto c_it=changed.begin(); c_it!=changed.end(); ++c_it) {
//               cout << (*c_it)->_id << " ";
//            }

            vector<double> lastEval = this->_evaluateFromSingleRoot(numbCalls, printIterations, numbToPrint, rootsToUse);
            
//            cout << endl;
            

            vector<personClass*> allChanged = vector<personClass*>();
            for(auto it=changed.begin(); it!= changed.end();++it) {
                allChanged.push_back(*it);
            }

            if(lastEval.at(0) == 0) {
                // didn't get a contradiction
                if(lastEval.at(1) > maxVal.first || maxVal.second.at(0) == nullptr) {
                    maxVal.first = lastEval.at(1);
                    maxVal.second = allChanged;
                }
            }

            vector<personClass*> toErase;
            for(auto it=changed.begin(); it!= changed.end();++it) {
                if((*it)->parentA) {
                    this->makeUnAffected(*it);
                    toErase.push_back(*it);
                }
            }
            for(auto it=toErase.begin(); it!= toErase.end();++it) {
                changed.erase(*it);
            }


            
        } while(combNonRoot.nextCombination());
        
        for(auto it=changed.begin(); it!= changed.end();++it) {
            this->makeUnAffected(*it);
        }
        changed.clear();

    } while(combRoot.nextCombination());

    return maxVal;
}

vector<pair<double,vector<personClass*>>> pedigreeClass2::_bruteForceWork(long numbCalls, bool printIterations, int numbToPrint, int numbRoots) {

    vector<pair<double,vector<personClass*>>> allAnswers = vector<pair<double,vector<personClass*>>>();

    while(numbRoots > this->carrierRoots.at(0).size()) {
        numbRoots -= 1;
    }

    for(int numbToChange=numbRoots; numbToChange<=this->possiblyAffectedAncestors.size()+numbRoots; ++numbToChange) {
        
        pair<double,vector<personClass*>> ansForNumb = this->_bruteForceWithNumbAffected(numbCalls, printIterations, numbToPrint, numbRoots, numbToChange);
        allAnswers.push_back(ansForNumb);
        
    }
    cout << "\n\n-------------------------\n\n" << endl;
    for(int i=0; i<allAnswers.size(); ++i) {
        if(!(allAnswers.at(i).second.at(0))) {
            continue;
        }
        cout << "nChanged: " << i+1 << " (";
        for(int j=0; j<allAnswers.at(i).second.size(); ++j) {
            cout << allAnswers.at(i).second.at(j)->_id << " ";
        }
        cout << ") -> " << exp(allAnswers.at(i).first) << endl;
    }

    return allAnswers;

}

vector<double> pedigreeClass2::_bruteForce(long numbCalls, bool printIterations, int numbToPrint, int numbRoots) {
 

    vector<pair<double,vector<personClass*>>> allAnswers = this->_bruteForceWork(numbCalls,printIterations,numbToPrint,numbRoots);
    vector<double> ans;
    ans.push_back(this->carrierRoots.at(0).size());
    ans.push_back(this->possiblyAffectedAncestors.size());
    for(int i=0; i<allAnswers.size(); ++i) {
        if(allAnswers.at(i).second.at(0) == nullptr) {
            ans.push_back(-1);
        }
        else {
            ans.push_back(allAnswers.at(i).first);
        }
    }
    return ans;
}








