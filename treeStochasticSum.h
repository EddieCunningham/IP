#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>


namespace std {

    class Type {
        static int globalId;
    public:
        int _id,counterLeft,counterMiddle,counterRight;
        string name;
        vector<pair<int,int>> indices;
        Type* left;
        Type* right;
        vector<vector<double>> vals;
        bool isRoot;
        vector<vector<double>> termWeights;

        vector<vector<int>> numberTimesSelected;

        Type(pair<string,vector<pair<int,int>>> theType) {
            this->_id = Type::globalId++;
            this->left = nullptr;
            this->right = nullptr;
            this->counterLeft = 0;
            this->counterMiddle = 0;
            this->counterRight = 0;
            this->name = theType.first;
            this->indices = theType.second;
        } 
        void resetCounters() {
            this->counterLeft = 0;
            this->counterMiddle = 0;
            this->counterRight = 0;
        }

        string toString() {
            return "name: "+this->name+" counterLeft: "+to_string(this->counterLeft)+" counterMiddle: "+to_string(this->counterMiddle)+" counterRight: "+to_string(this->counterRight);
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
            // double randomNumb = rand()%(int)this->termWeights[whichBranch][this->termWeights[whichBranch].size()-1];
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


        virtual ~Type() {}
        virtual pair<bool,vector<double>> getNextVal(int whichBranch, bool random) = 0;
    };

    class gType : public Type {
    public:
        ~gType() {}
        gType(pair<string,vector<pair<int,int>>> theType): Type(theType) {
            this->isRoot = false;
            this->vals = {
                            {1.0,0.5,0.5,0.25},
                            {0.5,1.0,0.5,0.5,0.5,1.0,0.5},
                            {0.25,0.5,0.5,1.0}
                          };
            this->termWeights = vector<vector<double>>(this->vals);
            this->numberTimesSelected = vector<vector<int>>(this->vals.size());
            for(int i=0; i<this->vals.size(); ++i) {
                this->numberTimesSelected[i] = vector<int>(this->vals[i].size(),0);
            }
        }
        pair<bool,vector<double>> getNextVal(int whichBranch, bool random);
    };

    class nType : public Type {
    public:
        ~nType() {}
        nType(pair<string,vector<pair<int,int>>> theType): Type(theType) {
            this->isRoot = true;
            this->vals = {
                            {0.25,0.5,0.5,1.0}
                          };
            this->termWeights = vector<vector<double>>(this->vals);
            this->numberTimesSelected = vector<vector<int>>(this->vals.size());
            for(int i=0; i<this->vals.size(); ++i) {
                this->numberTimesSelected[i] = vector<int>(this->vals[i].size(),0);
            }
        }
        pair<bool,vector<double>> getNextVal(int whichBranch, bool random);
    };

    class pType : public Type {
    public:
        ~pType() {}
        pType(pair<string,vector<pair<int,int>>> theType): Type(theType) {
            this->isRoot = true;
            this->vals = {
                            {1.0,1.0,1.0,1.0,0.75,0.5,1.0,0.5}
                          };
            this->termWeights = vector<vector<double>>(this->vals);
            this->numberTimesSelected = vector<vector<int>>(this->vals.size());
            for(int i=0; i<this->vals.size(); ++i) {
                this->numberTimesSelected[i] = vector<int>(this->vals[i].size(),0);
            }
        }
        pair<bool,vector<double>> getNextVal(int whichBranch, bool random);
    };

    class sType : public Type {
    public:
        ~sType() {}
        sType(pair<string,vector<pair<int,int>>> theType): Type(theType) {
            this->isRoot = true;
            this->vals = {
                            {0.5,0.5,0.5,0.5,0.5,0.25,0.5,0.25,0.5}
                          };
            this->termWeights = vector<vector<double>>(this->vals);
            this->numberTimesSelected = vector<vector<int>>(this->vals.size());
            for(int i=0; i<this->vals.size(); ++i) {
                this->numberTimesSelected[i] = vector<int>(this->vals[i].size(),0);
            }
        }
        pair<bool,vector<double>> getNextVal(int whichBranch, bool random);
    };    

    pair<int,unordered_map<int,double>> getValues(int numbRoots,vector<pair<string,vector<pair<int,int>>>> types,int numSamples,int checkpoint);

}