#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <cassert>


namespace std {

    struct branchInfo {
        int left,right;
        double val;
    };

    class Type {
        static int globalId;
    public:
        int _id,counter;
        string name;
        vector<pair<int,int>> indices;
        Type* left;
        Type* right;
        vector<vector<branchInfo>> vals;
        double tVal;
        bool isRoot;
        vector<vector<double>> termWeights;
        vector<vector<int>> numberTimesSelected;

        Type() {
            this->_id = Type::globalId++;
            this->left = nullptr;
            this->right = nullptr;
            this->counter = 0;
        }

        Type(bool isRoot, double t_val, const vector<vector<vector<double>>> & initialVals, const pair<string,vector<pair<int,int>>> & theType) : Type() {
            this->isRoot = isRoot;
            this->tVal = t_val;
            this->name = theType.first;
            this->indices = theType.second;

            this->initVals(initialVals);


            this->termWeights = vector<vector<double>>(this->vals.size());
            this->numberTimesSelected = vector<vector<int>>(this->vals.size());
            for(int i=0; i<this->vals.size(); ++i) {
                this->termWeights[i] = vector<double>(this->vals[i].size(),0);
                this->numberTimesSelected[i] = vector<int>(this->vals[i].size(),0);
            }
        }

        void initVals(const vector<vector<vector<double>>> & initialVals) {
            if(!this->isRoot) {
                for(int i=0; i<initialVals.size(); ++i) {
                    vector<branchInfo> inThisBranch = vector<branchInfo>();
                    for(int j=0; j<initialVals[i].size(); ++j) {
                        for(int k=0; k<initialVals[j].size(); ++k) {
                            double val = initialVals[i][j][k];
                            if(val != 0) {
                                branchInfo adding;
                                adding.left = j;
                                adding.right = k;
                                adding.val = val;
                                inThisBranch.push_back(adding);
                            }
                        }
                    }
                    this->vals.push_back(inThisBranch);
                }
            }
            else {
                assert(initialVals.size() == 1);
                vector<branchInfo> inThisBranch = vector<branchInfo>();
                for(int i=0; i<initialVals[0].size(); ++i) {
                    for(int j=0; j<initialVals[0][i].size(); ++j) {
                        double val = initialVals[0][i][j];
                        if(val != 0) {
                            branchInfo adding;
                            adding.left = i;
                            adding.right = j;
                            adding.val = val;
                            inThisBranch.push_back(adding);
                        }
                    }
                }
                this->vals.push_back(inThisBranch);
            }

        }

        void accumulateWeights(int whichBranch) {
            int totalWeight = 0;
            for(auto w=this->termWeights[whichBranch].begin(); w!=this->termWeights[whichBranch].end(); ++w) {
                totalWeight += (*w);
                (*w) = totalWeight;
            }
            if(totalWeight > 0) {
                for(auto w=this->termWeights[whichBranch].begin(); w!=this->termWeights[whichBranch].end(); ++w) {
                    (*w) /= (double)totalWeight;
                }
            }
        }

        void randomChoice(int &counter, int whichBranch) {
            double randomNumb = rand()/double(RAND_MAX);
            int i=0;
            for(auto w=this->termWeights[whichBranch].begin(); w!=this->termWeights[whichBranch].end(); ++w) {
                if((*w) > randomNumb) {
                    counter = i;
                    numberTimesSelected[whichBranch][i] += 1;
                    break;
                }
                ++i;
            }
        }

        pair<bool,branchInfo> getNextVal(int whichBranch, bool random) {

            branchInfo ans;
            bool keepGoing = true;

            if(random) {
                randomChoice(this->counter,whichBranch);
            }
            if(this->counter == this->vals[whichBranch].size()) {
                this->counter = 0;
                keepGoing = false;
            }
            else {
                ans = this->vals[whichBranch][this->counter];
            }

            this->counter += 1;

            return pair<bool,branchInfo>(keepGoing,ans);
        }

        long double incrementalIntegralPart(int indexChosen, int n, int m, const pair<double,vector<int>> & setValsAndT) {
            double t = setValsAndT.first;
            vector<int> setVals = setValsAndT.second;
            int lastK = setVals[indexChosen];
            int sumSetVals = 0.0;
            int sumToM = 0.0;
            int sumFromM = 0.0;
            for(int i=0; i<setVals.size(); ++i) {
                int k = setVals[i];
                if(i < m) {
                    sumToM += k;
                }
                else {
                    sumFromM += k;
                }
                sumSetVals += k;
            }
            double constantPart = (2*m - n)/2.0*t + (m - n)/2.0;

            double firstTerm = 1.0;
            if(sumSetVals == 0) {
                firstTerm = tgamma(n/2.0)/pow(M_PI,n/2.0)*pow(tgamma(0.5),n)/tgamma(n/2.0 + 1.0)*constantPart;
            }


            double numerator;
            if(indexChosen < m) {
                numerator = t*(sumToM+1.0) + (1.0 - t)*sumFromM + constantPart;
            }
            else {
                numerator = t*sumToM + (1.0 - t)*(sumFromM + 1.0) + constantPart;
            }
            double denominator = t*sumToM + (1.0 - t)*sumFromM + constantPart;

            long double ans = firstTerm*(lastK + 0.5)/(sumSetVals + n/2.0 + 1.0)*numerator/denominator;

            // cout << "\n\n";
            // cout << "setVals: ";
            // for(int i=0; i<setVals.size(); ++i) {
            //     cout << setVals[i] << " ";
            // }
            // cout << "\nindexChosen: " << indexChosen << endl;
            // cout << "n: " << n << endl;
            // cout << "m: " << m << endl;
            // cout << "t: " << t << endl;
            // cout << "lastK: " << lastK << endl;
            // cout << "sumSetVals: " << sumSetVals << endl;
            // cout << "sumToM: " << sumToM << endl;
            // cout << "sumFromM: " << sumFromM << endl;
            // cout << "(lastK + 0.5)/(sumSetVals + n/2.0 + 1.0): " << (lastK + 0.5)/(sumSetVals + n/2.0 + 1.0) << endl;
            // cout << "numerator: " << numerator << endl;
            // cout << "denominator: " << denominator << endl;
            // cout << "ans: " << ans << endl;

            return ans;
        }
    };

    unordered_map<int,double> stochasticSum(int n, int m, vector<Type*> roots, long long totalTerms, int numSamples, int checkpoint);

    pair<long long,pair<vector<Type*>,vector<Type*>>> initializeTypes(int m, const vector<vector<vector<double>>> & g, const vector<pair<double,vector<pair<int,int>>>> & types);

    // pass in generalized types which are similar to before but instead of ['n',[[0,2],[1,3]]] or ['g',[[0,2],[0,2],[1,3]]]
    // have the t value included so that different types can be made dynamically. 
    // so input would look like [0.5,[[0,2],[1,3]]]  for non g types and [-1,[[0,2],[0,2],[1,3]]] for g types.

    // also need to pass in all of g so be able to make calculations

    pair<int,unordered_map<int,double>> calcProbability(int numbRoots,
                                                        int n,
                                                        vector<vector<vector<double>>> g,
                                                        vector<pair<double,vector<pair<int,int>>>> types,
                                                        int numSamples,int 
                                                        checkpoint);

}











