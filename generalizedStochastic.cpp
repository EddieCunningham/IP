#include "generalizedStochastic.h"
#include <stdlib.h>
#include <cassert>
#include <math.h>

bool INTEGRAL = true;
bool INCREMENTAL_INTEGRAL = true;

namespace std {

    int Type::globalId = 0;

    long double individualIntegral(double t, int n, int m, const vector<int> & indexCounts) {
        long double ans = 1.0;
        long double denominator = n/2.0 + 1.0;
        long double sumToM = 0.0;
        long double sumFromM = 0.0;
        for(int i=0; i<indexCounts.size(); ++i) {
            int currentVal = indexCounts[i];

            ans *= tgamma(currentVal+0.5);
            denominator += currentVal;
            if(i < m) {
                sumToM += currentVal;
            }
            else {
                sumFromM += currentVal;
            }
        }
        ans /= tgamma(denominator);
        ans *= (t*sumToM + (1.0 - t)*sumFromM + t*(2*m - n)/2.0 + (m - n)/2.0);

        ans *= tgamma(n/2.0)/pow(M_PI,n/2.0);

        return ans;
    }

    // add in t parts later
    long double integralPart(int n, int m, vector<pair<double,vector<int>>> *setVals) {
        long double ans = 1.0;
        for(auto it=setVals->begin(); it!=setVals->end(); ++it) {
            double t = it->first;
            long double integral = individualIntegral(t,n,m,it->second);
            ans *= integral;
        }
        return ans;
    }

    long double findAnsHelper(Type* currentType, int whichBranch, vector<pair<double,vector<int>>>* setVals, const int n, const int m) {

        pair<bool,branchInfo> nextVal = currentType->getNextVal(whichBranch, true);
        double left = nextVal.second.left;
        double right = nextVal.second.right;
        double val = nextVal.second.val;

        if(INCREMENTAL_INTEGRAL) {
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
            if(leftSetVal < setVals->size()) {
                val *= currentType->incrementalIntegralPart(left, n, m, (*setVals)[leftSetVal]);
            }
            if(rightSetVal < setVals->size()) {
                val *= currentType->incrementalIntegralPart(right, n, m, (*setVals)[rightSetVal]);
            }
        }

        int j=0;
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

        if(currentType->left == nullptr and currentType->right == nullptr) {
            assert(val != 0);
            return val;
        }

        long double leftBranch = 1.0;
        long double rightBranch = 1.0;

        if(currentType->left) {
            leftBranch = findAnsHelper(currentType->left, left, setVals, n, m);
        }
        if(currentType->right) {
            rightBranch = findAnsHelper(currentType->right, right, setVals, n, m);
        }

        assert(val != 0);
        assert(leftBranch != 0);
        assert(rightBranch != 0);
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

    int updateTermWeightings(Type *r, int whichBranch) {

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
                leftBranch = updateTermWeightings(r->left,left);
            }
            if(r->right) {
                rightBranch = updateTermWeightings(r->right,right);
            }

            int termsForThisVal = leftBranch*rightBranch;
            r->termWeights[whichBranch][i] = termsForThisVal;

            ans += termsForThisVal;

            nextVal = r->getNextVal(whichBranch, false);
            keepGoing = nextVal.first;
            left = nextVal.second.left;
            right = nextVal.second.right;

            ++i;

        }

        r->accumulateWeights(whichBranch);
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

    pair<long long,pair<vector<Type*>,vector<Type*>>> initializeTypes(int m, const vector<vector<vector<double>>> & g, const vector<pair<double,vector<pair<int,int>>>> & types) {
        // m is the number of dims that go into t
        // n is the total number of dims
        vector<Type*> allTypes = generateAllTypesAndSets(m,g,types);

        vector<Type*> roots = vector<Type*>();
        long long totalTerms = 1;
        unordered_map<int,int> numbUniqueTerms = unordered_map<int,int>();

        for(auto a=allTypes.begin(); a!=allTypes.end(); ++a) {
            if((*a)->isRoot) {
                roots.push_back(*a);
                printTree(*a,0);
                int currentTerms = updateTermWeightings(*a,0);
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
        cout << "The total number of terms is: " << pow(3,numbUniqueTerms.size()) << endl << endl;

        pair<long long,pair<vector<Type*>,vector<Type*>>> ans = pair<long long,pair<vector<Type*>,vector<Type*>>>(totalTerms,pair<vector<Type*>,vector<Type*>>(roots,allTypes));
        return ans;
    }

    unordered_map<int,double> stochasticSum(int n, int m, vector<Type*> roots, long long totalTerms, int numSamples, int checkpoint) {

        unordered_map<int,double> toReturn = unordered_map<int,double>();

        long double totalAns = 0.0;

        vector<pair<double,vector<int>>> setVals = vector<pair<double,vector<int>>>();
        for(int i=0; i<roots.size(); ++i) {
            double t = roots[i]->tVal;
            setVals.push_back(pair<double,vector<int>>(t,vector<int>(n,0)));
        }


        for(long long i=0; i<numSamples; ++i) {

            long double ans = 1.0;
            for(auto r=roots.begin(); r!=roots.end(); ++r) {
                ans *= findAnsHelper(*r, 0, &setVals, n, m);
            }

            if(INTEGRAL and !INCREMENTAL_INTEGRAL) {
                ans *= integralPart(n,m,&setVals);
            }

            totalAns += ans;

            for(auto s=setVals.begin(); s!=setVals.end(); ++s) {
                fill(s->second.begin(), s->second.end(), 0);
            }

            if(i != 0 and i%checkpoint == 0) {
                long double averageAnswer = totalAns/i;
                long double projectedAnswer = totalAns/i*totalTerms;
                cout << "i: " << i << " \n\ttotalAns: " << totalAns << " \n\tprojected answer: " << projectedAnswer << " \n\taverage answer: " << averageAnswer << endl;
                toReturn.insert({i,totalAns});
            }
        }

        return toReturn;

    }


    pair<int,unordered_map<int,double>> calcProbability(int numbRoots,
                                                        int n,
                                                        int m,
                                                        const vector<vector<vector<double>>> & g,
                                                        const vector<pair<double,vector<pair<int,int>>>> & types,
                                                        int numSamples,
                                                        int checkpoint) {

        pair<long long,pair<vector<Type*>,vector<Type*>>> initializedTypes = initializeTypes(m,g,types);

        long long totalTerms = initializedTypes.first;
        vector<Type*> roots = initializedTypes.second.first;
        vector<Type*> allTypes = initializedTypes.second.second;

        unordered_map<int,double> toReturn = stochasticSum(n, m, roots, totalTerms, numSamples, checkpoint);
        

        for(auto a=allTypes.begin(); a!=allTypes.end(); ++a) {
            delete *a;
        }

        return pair<int,unordered_map<int,double>>(totalTerms,toReturn);
    }

};

using namespace std;

int main() {

    vector<vector<vector<double>>> g = {
                                        {
                                            {1.0,0.5,0.0},
                                            {0.5,0.25,0.0},
                                            {0.0,0.0,0.0}
                                        },
                                        {
                                            {0.0,0.5,1.0},
                                            {0.5,0.5,0.5},
                                            {1.0,0.5,0.0}
                                        },
                                        {
                                            {0.0,0.0,0.0},
                                            {0.0,0.25,0.5},
                                            {0.0,0.5,1.0}
                                        }
                                    };

    vector<pair<double,vector<pair<int,int>>>> types({
        pair<double,vector<pair<int,int>>>(0.0,vector<pair<int,int>>({pair<int,int>(0, 0), pair<int,int>(1, 2)})),
        pair<double,vector<pair<int,int>>>(0.0,vector<pair<int,int>>({pair<int,int>(3, 6), pair<int,int>(2, 4)})),
        pair<double,vector<pair<int,int>>>(-1.0,vector<pair<int,int>>({pair<int,int>(3, 6), pair<int,int>(0, 1), pair<int,int>(1, 3)}))
        });
    // 3 roots

        //                                 vector<pair<double,vector<pair<int,int>>>> types({
        // pair<double,vector<pair<int,int>>>(0.0,vector<pair<int,int>>({pair<int,int>(0, 0),pair<int,int>(1, 3)})),
        // pair<double,vector<pair<int,int>>>(0.0,vector<pair<int,int>>({pair<int,int>(4, 12),pair<int,int>(2, 6)})),
        // pair<double,vector<pair<int,int>>>(-1.0,vector<pair<int,int>>({pair<int,int>(4, 12),pair<int,int>(0, 1),pair<int,int>(1, 4)})),
        // pair<double,vector<pair<int,int>>>(0.0,vector<pair<int,int>>({pair<int,int>(5, 15),pair<int,int>(3, 9)})),
        // pair<double,vector<pair<int,int>>>(-1.0,vector<pair<int,int>>({pair<int,int>(5, 15),pair<int,int>(6, 18),pair<int,int>(2, 7)})),
        // pair<double,vector<pair<int,int>>>(-1.0,vector<pair<int,int>>({pair<int,int>(6, 18),pair<int,int>(0, 2),pair<int,int>(1, 5)}))
        // });

    int numbRoots = 3;
    int n = 3;
    int m = 2;
    int numSamples = 1000000;
    int checkpoint = numSamples*0.1;
    calcProbability(numbRoots,n,m,g,types,numSamples,checkpoint);
}
