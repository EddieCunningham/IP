#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <cassert>
#include <stdlib.h>
#include <math.h>
#include <gmpxx.h>


namespace std {

    struct index_struct {
        int setNumb;
        int uVal;
        string sex;
    };

    struct type_struct {
        double tVal;
        string name;
        vector<index_struct> indices;
        string sex;
    };

    struct branchInfo {
        int left,right;
        double val;
    };

    class Type {
        static int globalId;
    public:
        int _id,counter;
        string name;
        string sex;
        string leftParentSex;
        string rightParentSex;
        vector<index_struct> indices;
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

        Type(bool isRoot, const vector<vector<vector<double>>> & initialVals, const type_struct & theType) : Type() {
            this->isRoot = isRoot;
            this->tVal = theType.tVal;
            this->name = theType.name;
            this->indices = theType.indices;

            if(this->isRoot) {
                this->sex = theType.sex;
                this->leftParentSex = this->indices[0].sex;
                this->rightParentSex = this->indices[1].sex;
                this->name = "_";
            }
            else {
                this->sex = this->indices[0].sex;
                this->leftParentSex = this->indices[1].sex;
                this->rightParentSex = this->indices[2].sex;
                this->name = "g";
            }

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
                    for(int j=0; j<initialVals.at(i).size(); ++j) {
                        for(int k=0; k<initialVals.at(i).at(j).size(); ++k) {

                            // cout << "\ni: " << i << " j: " << j << " k: " << k << endl;
                            // cout << "dims: " << "(" << initialVals.size() << "," << initialVals.at(i).size() << "," << initialVals.at(i).at(j).size() << ")" << endl;
                            double val = initialVals.at(i).at(j).at(k);
                            // cout << "val: " << val << endl;
                            if(val != 0) {
                                branchInfo adding;
                                adding.left = j;
                                adding.right = k;
                                adding.val = val;
                                inThisBranch.push_back(adding);
                            }
                            // cout << "here" << endl;
                        }
                    }
                    this->vals.push_back(inThisBranch);
                }
            }
            else {
                assert(initialVals.size() == 1);
                vector<branchInfo> inThisBranch = vector<branchInfo>();
                for(int i=0; i<initialVals.at(0).size(); ++i) {
                    for(int j=0; j<initialVals.at(0).at(i).size(); ++j) {
                        double val = initialVals.at(0).at(i).at(j);
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

        long double incrementalIntegralPart(int indexChosen, const unordered_map<string,pair<int,int>> & allMN, const pair<pair<string,double>,vector<int>> & setValsAndT) {

            string sex = setValsAndT.first.first;
            double t = setValsAndT.first.second;
            int m = allMN.at(sex).first;
            int n = allMN.at(sex).second;
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
            double constantPart = (2*m - n)/2.0*t + (n - m)/2.0;

            double numerator;
            if(indexChosen < m) {
                numerator = t*(sumToM+1.0) + (1.0 - t)*sumFromM + constantPart;
            }
            else {
                numerator = t*sumToM + (1.0 - t)*(sumFromM + 1.0) + constantPart;
            }
            double denominator = t*sumToM + (1.0 - t)*sumFromM + constantPart;

            long double ans = (lastK + 0.5)/(sumSetVals + n/2.0 + 1.0)*numerator/denominator;

            return ans;
        }
    };

    mpz_class getTotalTerms(vector<Type*> roots);

    unordered_map<int,string> stochasticSum(const unordered_map<string,pair<int,int>> & allMN, vector<Type*> roots, unordered_map<int,pair<string,double>> pedigreeRoots, int numSamples, int checkpoint, int printCheckpoint);

    pair<vector<Type*>,vector<Type*>> initializeTypes(unordered_map<string,pair<int,int>> allMN, const unordered_map<string,vector<vector<vector<double>>>> & allG, const vector<type_struct> & types);


}