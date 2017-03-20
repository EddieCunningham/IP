// g++ -I /usr/local/include -L/usr/local/lib generalizedStochasticGMP.cpp -lgmpxx -lgmp -std=c++11

#include "generalizedStochasticGMP.h"

namespace std {

    int Type::globalId = 0;

    long double findAnsHelper(Type* currentType, int whichBranch, vector<pair<double,vector<int>>>* setVals, const int n, const int m) {

        pair<bool,branchInfo> nextVal = currentType->getNextVal(whichBranch, true);
        double left = nextVal.second.left;
        double right = nextVal.second.right;
        double val = nextVal.second.val;

        // INCREMENTAL INTEGRAL PART
        int leftSetVal = -1;
        int rightSetVal = -1;
        int j=0;
        for(auto i=currentType->indices.rbegin(); i!=currentType->indices.rend(); ++i) {
            if(j == 0) {
                rightSetVal = i->first;
            }
            else if(j == 1) {
                leftSetVal = i->first;
            }
            else {
                break;
            }
            ++j;
        }
        if(leftSetVal != -1 and leftSetVal < setVals->size()) {
            val *= currentType->incrementalIntegralPart(left, n, m, (*setVals)[leftSetVal]);
        }
        if(rightSetVal != -1 and rightSetVal < setVals->size()) {
            val *= currentType->incrementalIntegralPart(right, n, m, (*setVals)[rightSetVal]);
        }

        // UPDATE SET VALS
        j=0;
        for(auto i=currentType->indices.rbegin(); i!=currentType->indices.rend(); ++i) {
            int setNumb = i->first;

            if(setNumb < setVals->size()) {
                if(j == 0) {
                    (*setVals)[setNumb].second[right] += 1;
                }
                else if(j == 1) {
                    (*setVals)[setNumb].second[left] += 1;
                }
                else {
                    assert(0);
                }
            }
            ++j;
        }

        long double leftBranch = 1.0;
        long double rightBranch = 1.0;

        if(currentType->left) {
            leftBranch = findAnsHelper(currentType->left, left, setVals, n, m);
        }
        if(currentType->right) {
            rightBranch = findAnsHelper(currentType->right, right, setVals, n, m);
        }

        return val*leftBranch*rightBranch;
    }

    void printTree(Type* r, int depth) {

        string tabs = "";
        for(int i=0; i<depth; ++i) {
            tabs += "\t";
        }
        string indexString = "";
        for(auto i=r->indices.begin(); i!=r->indices.end(); ++i) {
            indexString += "("+to_string(i->first)+","+to_string(i->second)+") ";
        }
        cout << tabs << r->name << ": " << indexString << endl;
        if(r->left) {
            printTree(r->left,depth+1);
        }
        if(r->right) {
            printTree(r->right,depth+1);
        }

    }

    int updateTermWeightings(Type *r, int whichBranch, bool actuallyUpdateWeights) {

        int ans = 0;

        pair<bool,branchInfo> nextVal = r->getNextVal(whichBranch,false);
        bool keepGoing = nextVal.first;
        double left = nextVal.second.left;
        double right = nextVal.second.right;

        int i=0;
        while(keepGoing) {
            
            int leftBranch = 1;
            int rightBranch = 1;

            if(r->left) {
                leftBranch = updateTermWeightings(r->left,left,actuallyUpdateWeights);
            }
            if(r->right) {
                rightBranch = updateTermWeightings(r->right,right,actuallyUpdateWeights);
            }

            int termsForThisVal = leftBranch*rightBranch;

            if(actuallyUpdateWeights) {
                r->termWeights[whichBranch][i] = termsForThisVal;
            }

            ans += termsForThisVal;

            nextVal = r->getNextVal(whichBranch, false);
            keepGoing = nextVal.first;
            left = nextVal.second.left;
            right = nextVal.second.right;

            ++i;

        }

        if(actuallyUpdateWeights) {
            r->accumulateWeights(whichBranch);
        }
        r->counter = 0;

        return ans;
    }

    vector<Type*> generateAllTypesAndSets(int m, const vector<vector<vector<double>>> & g, const vector<pair<double,vector<pair<int,int>>>> & types) {
        vector<Type*> allTypes = vector<Type*>();
        for(auto t=types.begin(); t!=types.end(); ++t) {
            double tProb = t->first;
            if(tProb == -1) {
                pair<string,vector<pair<int,int>>> theType("g",t->second);
                allTypes.push_back(new Type(false,tProb,g,theType));
            }
            else {
                // g should be a cube
                vector<vector<vector<double>>> newVals = vector<vector<vector<double>>>(1,vector<vector<double>>(g.size(),vector<double>(g.size(),0)));
                for(int i=0; i<g.size(); ++i) {
                    for(int j=0; j<g[0].size(); ++j) {
                        for(int k=0; k<g[0][0].size(); ++k) {
                            double toAdd = g[i][j][k];
                            if(i < m) {
                                toAdd *= tProb;
                            }
                            else {
                                toAdd *= (1.0 - tProb);
                            }
                            newVals[0][j][k] += toAdd;
                        }
                    }
                }
                pair<string,vector<pair<int,int>>> theType("t="+to_string(tProb),t->second);
                allTypes.push_back(new Type(true,tProb,newVals,theType));
            }
        }


        for(auto a=allTypes.begin(); a!=allTypes.end(); ++a) {

            vector<int> uVals = vector<int>();

            for(auto i=(*a)->indices.begin(); i!=(*a)->indices.end(); ++i) {

                int setNumber = i->first;
                int uniqueId = i->second;

                uVals.push_back(uniqueId);
            }

            for(auto _a=allTypes.begin(); _a!=allTypes.end(); ++_a) {
                if((*a)->_id == (*_a)->_id) {
                    continue;
                }
                int valToWorryAbout = (*_a)->indices[0].second;
                int i=0;
                for(auto u=uVals.begin(); u!=uVals.end(); ++u) {
                    if((*u) == valToWorryAbout) {

                        if((*a)->name == "g") {
                            if(i == 0) {                                
                                continue;
                            }
                            else if(i == 1) {
                                (*a)->left = *_a;
                            }
                            else if(i == 2) {
                                (*a)->right = *_a;
                            }
                        }
                        else {
                            if(i == 0) {
                                (*a)->left = *_a;
                            }
                            else if(i == 1) {
                                (*a)->right = *_a;
                            }
                        }
                    }
                    ++i;
                }
            }
        }
        return allTypes;
    }

    mpz_class getTotalTerms(vector<Type*> roots) {

        // this number will be very big!
        mpz_class totalTerms = 1;

        for(auto r=roots.begin(); r!=roots.end(); ++r) {
            int currentTerms = updateTermWeightings(*r,0,false);
            totalTerms *= currentTerms;
        }
        return totalTerms;
    }

    pair<vector<Type*>,vector<Type*>> initializeTypes(int m, const vector<vector<vector<double>>> & g, const vector<pair<double,vector<pair<int,int>>>> & types) {
        // m is the number of dims that go into t
        // n is the total number of dims
        vector<Type*> allTypes = generateAllTypesAndSets(m,g,types);

        vector<Type*> roots = vector<Type*>();

        // this number will be very big!
        mpz_class totalTerms = 1;

        unordered_map<int,int> numbUniqueTerms = unordered_map<int,int>();

        for(auto a=allTypes.begin(); a!=allTypes.end(); ++a) {
            if((*a)->isRoot) {
                roots.push_back(*a);
                printTree(*a,0);
                int currentTerms = updateTermWeightings(*a,0,true);
                cout << "This branch had " << currentTerms << " terms" << endl << endl;
                totalTerms *= currentTerms;
            }

            for(auto i=(*a)->indices.begin(); i!=(*a)->indices.end(); ++i) {
                int uVal = i->second;
                if(numbUniqueTerms.find(uVal) == numbUniqueTerms.end()) {
                    numbUniqueTerms.insert({uVal,1});
                }
            }
        }

        cout << "The total number of non-zero terms is: " << totalTerms << endl;
        cout << "The total number of terms is: " << pow(g[0].size(),numbUniqueTerms.size()) << endl << endl;
        cout << "The total number of types is: " << allTypes.size() << endl;
        pair<vector<Type*>,vector<Type*>> ans = pair<vector<Type*>,vector<Type*>>(roots,allTypes);
        return ans;
    }


    void forSanity(Type* r) {
        r->sanityCheck();
        if(r->left) {
            forSanity(r->left);
        }
        if(r->right) {
            forSanity(r->right);
        }
    }


    unordered_map<int,string> stochasticSum(int n, int m, vector<Type*> roots, unordered_map<int,double> pedigreeRoots, int numSamples, int checkpoint, int printCheckpoint) {

        // cout << "n: " << n << endl;
        // cout << "m: " << m << endl;
        // cout << "totalTerms: " << totalTerms << endl;
        // cout << "numSamples: " << numSamples << endl;
        // cout << "checkpoint: " << checkpoint << endl << endl;;

        // for(int i=0; i<roots.size(); ++i) {
        //     forSanity(roots[i]);
        // }



        
        vector<pair<double,vector<int>>> setVals = vector<pair<double,vector<int>>>(pedigreeRoots.size());
        for(auto i=pedigreeRoots.begin(); i!=pedigreeRoots.end(); ++i) {
            double t = i->second;
            setVals[i->first] = pair<double,vector<int>>(t,vector<int>(n,0));
        }
        // THIS PART IS WRONG! THIS IS USING THE COMPUTATION GRAPH ROOTS (2ND GENERATION)
        // AND SHOULD BE USING THE PEDIGREE ROOTS (1ST GENERATION)!!!!!!!!!

        // vector<pair<double,vector<int>>> setVals = vector<pair<double,vector<int>>>();
        // for(int i=0; i<roots.size(); ++i) {
        //     double t = roots[i]->tVal;
        //     assert(t>=0);
        //     setVals.push_back(pair<double,vector<int>>(t,vector<int>(n,0)));
        // }


        // handles the base case of the incremental integral
        mpf_class base(1.0);
        for(int i=0; i<setVals.size(); ++i) {
            double t = setVals[i].first;
            base *= tgamma(n/2.0)/pow(M_PI,n/2.0)*pow(tgamma(0.5),n)/tgamma(n/2.0 + 1.0) * ((2*m - n)/2.0*t + (n - m)/2.0);
        }

        unordered_map<int,string> toReturn = unordered_map<int,string>();
        mpz_class totalTerms = getTotalTerms(roots);
        mpf_class totalAns = 0.0;

        mp_exp_t *expptr = new mp_exp_t;

        for(int i=0; i<numSamples; ++i) {

            mpf_class ans(base);

            for(auto r=roots.begin(); r!=roots.end(); ++r) {
                double _ans = findAnsHelper(*r, 0, &setVals, n, m);
                assert(_ans > 0.0);
                ans *= _ans;
            }

            totalAns += ans;
            assert(totalAns > 0);

            for(auto s=setVals.begin(); s!=setVals.end(); ++s) {
                fill(s->second.begin(), s->second.end(), 0);
            }


            if(i != 0 and (i%checkpoint == 0 or i%printCheckpoint == 0)) {
                mpf_class averageAnswer = totalAns/i;
                mpf_class projectedAnswer = totalAns/i*totalTerms;

                string digits(mpf_get_str(NULL, expptr, 10, 15, projectedAnswer.get_mpf_t()));
                string toWrite = digits+":"+to_string(*expptr);
                
                if(i%printCheckpoint == 0) {
                    cout << "i: " << i << " \n\ttotalAns: " << totalAns << " \n\tprojected answer: " << projectedAnswer << " \n\taverage answer: " << averageAnswer << endl;
                    // cout << "\n\ttoWrite: " << toWrite << endl;
                }
                if(i%checkpoint == 0) {

                    toReturn.insert({i,toWrite});
                }
            }
        }
        delete expptr;
        return toReturn;
    }


    unordered_map<int,string> calcProbability(int numbRoots,
                                                        int n,
                                                        int m,
                                                        const vector<vector<vector<double>>> & g,
                                                        const vector<pair<double,vector<pair<int,int>>>> & types,
                                                        int numSamples,
                                                        int checkpoint,
                                                        int printCheckpoint) {

        pair<vector<Type*>,vector<Type*>> initializedTypes = initializeTypes(m,g,types);

        vector<Type*> roots = initializedTypes.first;
        vector<Type*> allTypes = initializedTypes.second;

        assert(0);

        // unordered_map<int,string> toReturn = stochasticSum(n, m, roots, pedigreeRoots, numSamples, checkpoint, printCheckpoint);
        

        for(auto a=allTypes.begin(); a!=allTypes.end(); ++a) {
            delete *a;
        }

        // return toReturn;
        return unordered_map<int,string>();
    }

};

using namespace std;

int main() {

    vector<vector<vector<double>>> g = {
          {{1.  ,0.5 ,0.5 ,0. },
           {0.5 ,0.25,0.25,0. },
           {0.5 ,0.25,0.25,0. },
           {0.0 ,0.  ,0.  ,0. }},
  
          {{0.  ,0.5 ,0.5 ,1. },
           {0.  ,0.25,0.25,0.5},
           {0.  ,0.25,0.25,0.5},
           {0.  ,0.  ,0.  ,0. }},
  
          {{0.  ,0.  ,0.  ,0. },
           {0.5 ,0.25,0.25,0. },
           {0.5 ,0.25,0.25,0. },
           {1.  ,0.5 ,0.5 ,0. }},

          {{0.  ,0.  ,0.  , 0.},
           {0.  ,0.25,0.25,0.5},
           {0.  ,0.25,0.25,0.5},
           {0.  ,0.5 ,0.5 ,1. }}
        };

    // vector<pair<double,vector<pair<int,int>>>> types({
    //     pair<double,vector<pair<int,int>>>(0.0,vector<pair<int,int>>({pair<int,int>(0, 0), pair<int,int>(1, 2)})),
    //     pair<double,vector<pair<int,int>>>(0.0,vector<pair<int,int>>({pair<int,int>(3, 6), pair<int,int>(2, 4)})),
    //     pair<double,vector<pair<int,int>>>(-1.0,vector<pair<int,int>>({pair<int,int>(3, 6), pair<int,int>(0, 1), pair<int,int>(1, 3)}))
    //     });
    // 3 roots

                                        vector<pair<double,vector<pair<int,int>>>> types({
        pair<double,vector<pair<int,int>>>(0.0,vector<pair<int,int>>({pair<int,int>(0, 0),pair<int,int>(1, 3)})),
        pair<double,vector<pair<int,int>>>(0.0,vector<pair<int,int>>({pair<int,int>(4, 12),pair<int,int>(2, 6)})),
        pair<double,vector<pair<int,int>>>(-1.0,vector<pair<int,int>>({pair<int,int>(4, 12),pair<int,int>(0, 1),pair<int,int>(1, 4)})),
        pair<double,vector<pair<int,int>>>(0.0,vector<pair<int,int>>({pair<int,int>(5, 15),pair<int,int>(3, 9)})),
        pair<double,vector<pair<int,int>>>(-1.0,vector<pair<int,int>>({pair<int,int>(5, 15),pair<int,int>(6, 18),pair<int,int>(2, 7)})),
        pair<double,vector<pair<int,int>>>(-1.0,vector<pair<int,int>>({pair<int,int>(6, 18),pair<int,int>(0, 2),pair<int,int>(1, 5)}))
        });
    // 4 roots

    int numbRoots = 4;
    int n = 4;
    int m = 3;
    int numSamples = 10000;
    int checkpoint = numSamples*0.1;
    int printCheckpoint = 1000;
    calcProbability(numbRoots,n,m,g,types,numSamples,checkpoint,printCheckpoint);
}