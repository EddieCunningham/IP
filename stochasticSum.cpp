#include "stochasticSum.h"
#include <stdlib.h>
#include <cassert>


namespace std {
    // srand(1);

    unordered_map<int,double> valsG({{0,1.0},{1,0.5},{2,0.0},{3,0.5},{4,0.25},{5,0.0},{6,0.0},{7,0.0},{8,0.0},{9,0.0},{10,0.5},{11,1.0},{12,0.5},{13,0.5},{14,0.5},{15,1.0},{16,0.5},{17,0.0},{18,0.0},{19,0.0},{20,0.0},{21,0.0},{22,0.25},{23,0.5},{24,0.0},{25,0.5},{26,1.0}});
    unordered_map<int,double> valsS({{0,1.0},{1,1.0},{2,1.0},{3,1.0},{4,0.75},{5,0.5},{6,1.0},{7,0.5},{8,0.0}});
    unordered_map<int,double> valsN({{0,0.0},{1,0.0},{2,0.0},{3,0.0},{4,0.25},{5,0.5},{6,0.0},{7,0.5},{8,1.0}});
    unordered_map<int,double> valsP({{0,0.5},{1,0.5},{2,0.5},{3,0.5},{4,0.5},{5,0.25},{6,0.5},{7,0.25},{8,0.5}});

    Counter::Counter(vector<pair<int,int>> initialCounter,int maxSamples) {
        this->counter = initialCounter;
        this->numSamples = 0;
        this->totalSamples = maxSamples;
    }

    bool Counter::stochasticChoice() {
        for(auto it=this->counter.begin(); it!=this->counter.end(); ++it) {
            int maxVal = it->second;
            it->first = rand()%maxVal;
        }
        this->numSamples += 1;
        return this->numSamples < this->totalSamples;
    }

    double getVal(string name, const vector<int> & indices) {

        int value = 0;
        int i=0;
        for(auto it=indices.rbegin(); it!=indices.rend(); ++it) {
            value += (*it)*pow(3,i);
            ++i;
        }
        if(name == "g") {
            return valsG[value];
        }
        else if(name == "s") {
            return valsS[value];
        }
        else if(name == "n") {
            return valsN[value];
        }
        else {
            return valsP[value];
        }
    }

    unordered_map<int,double> c_bruteForce(vector<pair<string,vector<pair<int,int>>>> types,int checkpoint,int numSamples) {

        unordered_map<int,double> toReturn;

        int numbUniqueIndices = 0;
        unordered_map<int,int> uniqueMapping;
        
        for(auto it=types.begin(); it!=types.end(); ++it) {
            vector<pair<int,int>> indices = it->second;
            
            for(auto it2=indices.begin(); it2!=indices.end(); ++it2) {
                
                if(uniqueMapping.find(it2->second) == uniqueMapping.end()) {
                    uniqueMapping.insert({it2->second,numbUniqueIndices});
                    numbUniqueIndices += 1;
                }
            }
        }

        Counter counter(vector<pair<int,int>>(numbUniqueIndices,pair<int,int>(0,3)),numSamples);

        double ans = 0;
        // double projectedAns = 0;

        int iters = 1;
        while(counter.stochasticChoice()) {

            double val = 1;
            
            for(auto it=types.begin(); it!=types.end(); ++it) {
                vector<int> indices(it->second.size(),0);
                
                int i=0;
                for(auto it2=it->second.begin(); it2!=it->second.end(); ++it2) {
                    int index = uniqueMapping[it2->second];
                    indices[i] = counter.counter[index].first;
                    ++i;
                }

                double currentVal = getVal(it->first,indices);
                if(currentVal == 0) {
                    val = 0;
                    break;
                }
                val *= currentVal;
            }
            ans += val;
            iters += 1;

            if(iters%checkpoint == 0) {
                // cout << iters << endl;
                // cout << ans << endl;
                // projectedAns = ans*pow(3,numbUniqueIndices)/iters;
                // cout << projectedAns << endl;
                toReturn.insert({iters,ans});
            }
        }
        // cout << iters << endl;
        // cout << ans << endl;
        // projectedAns = ans*pow(3,numbUniqueIndices)/iters;
        // cout << projectedAns << endl;
        // cout << "THE TOTAL NUMBER OF TERMS IS: " << pow(3,numbUniqueIndices) << endl;
        return toReturn;
    }
};

// using namespace std;

// int main() {

//     vector<pair<string,vector<pair<int,int>>>> types({
//         pair<string,vector<pair<int,int>>>("n",vector<pair<int,int>>({pair<int,int>(0,0),pair<int,int>(1,3)})),
//         pair<string,vector<pair<int,int>>>("n",vector<pair<int,int>>({pair<int,int>(2,6),pair<int,int>(3,9)})),
//         pair<string,vector<pair<int,int>>>("n",vector<pair<int,int>>({pair<int,int>(4,12),pair<int,int>(5,15)})),
//         pair<string,vector<pair<int,int>>>("g",vector<pair<int,int>>({pair<int,int>(4,12),pair<int,int>(0,1),pair<int,int>(1,4)})),
//         pair<string,vector<pair<int,int>>>("g",vector<pair<int,int>>({pair<int,int>(5,15),pair<int,int>(2,7),pair<int,int>(3,10)})),
//         pair<string,vector<pair<int,int>>>("n",vector<pair<int,int>>({pair<int,int>(6,18),pair<int,int>(7,21)})),
//         pair<string,vector<pair<int,int>>>("g",vector<pair<int,int>>({pair<int,int>(6,18),pair<int,int>(0,2),pair<int,int>(1,5)})),
//         pair<string,vector<pair<int,int>>>("g",vector<pair<int,int>>({pair<int,int>(7,21),pair<int,int>(2,8),pair<int,int>(3,11)}))
//     });

//     int checkpoint = 2;
//     int numSamples = 5000000;
//     c_bruteForce(types,checkpoint,numSamples);
// }















