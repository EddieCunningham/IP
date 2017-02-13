#include "counter.h"
#include <stdlib.h>
#include <unordered_map>
#include <cassert>


namespace std {
    
    // srand(1);

    unordered_map<unsigned,double> valsG({{0,1.0},{1,0.5},{2,0.0},{3,0.5},{4,0.25},{5,0.0},{6,0.0},{7,0.0},{8,0.0},{9,0.0},{10,0.5},{11,1.0},{12,0.5},{13,0.5},{14,0.5},{15,1.0},{16,0.5},{17,0.0},{18,0.0},{19,0.0},{20,0.0},{21,0.0},{22,0.25},{23,0.5},{24,0.0},{25,0.5},{26,1.0}});
    unordered_map<unsigned,double> valsS({{0,1.0},{1,1.0},{2,1.0},{3,1.0},{4,0.75},{5,0.5},{6,1.0},{7,0.5},{8,0.0}});
    unordered_map<unsigned,double> valsN({{0,0.0},{1,0.0},{2,0.0},{3,0.0},{4,0.25},{5,0.5},{6,0.0},{7,0.5},{8,1.0}});
    unordered_map<unsigned,double> valsP({{0,0.5},{1,0.5},{2,0.5},{3,0.5},{4,0.5},{5,0.25},{6,0.5},{7,0.25},{8,0.5}});

    Counter::Counter(vector<pair<unsigned,unsigned>> initialCounter,unsigned maxSamples) {
        this->counter = initialCounter;
        this->numbSamples = 0;
        this->totalSamples = maxSamples;
    }

    bool Counter::stochasticChoice() {
        for(auto it=this->counter.begin(); it!=this->counter.end(); ++it) {
            unsigned maxVal = it->second;
            it->first = rand()%maxVal;
        }
        this->numbSamples += 1;
        return this->numbSamples < this->totalSamples;
    }

    double getVal(string name, const vector<unsigned> & indices) {

        unsigned value = 0;
        unsigned i=0;
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

    void c_bruteForce(vector<pair<string,vector<pair<unsigned,unsigned>>>> types,unsigned checkpoint,unsigned numbSamples) {
        unsigned numbUniqueIndices = 0;
        unordered_map<unsigned,unsigned> uniqueMapping;
        
        for(auto it=types.begin(); it!=types.end(); ++it) {
            vector<pair<unsigned,unsigned>> indices = it->second;
            
            for(auto it2=indices.begin(); it2!=indices.end(); ++it2) {
                
                if(uniqueMapping.find(it2->second) == uniqueMapping.end()) {
                    uniqueMapping.insert({it2->second,numbUniqueIndices});
                    numbUniqueIndices += 1;
                }
            }
        }

        Counter counter(vector<pair<unsigned,unsigned>>(numbUniqueIndices,pair<unsigned,unsigned>(0,3)),numbSamples);

        double ans = 0;
        double projectedAns = 0;

        unsigned iters = 1;
        while(counter.stochasticChoice()) {

            double val = 1;
            
            for(auto it=types.begin(); it!=types.end(); ++it) {
                vector<unsigned> indices(it->second.size(),0);
                
                unsigned i=0;
                for(auto it2=it->second.begin(); it2!=it->second.end(); ++it2) {
                    unsigned index = uniqueMapping[it2->second];
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

            if(iters%100000 == 0) {
                cout << iters << endl;
                cout << ans << endl;
                projectedAns = ans*pow(3,numbUniqueIndices)/iters;
                cout << projectedAns << endl;
            }

        }
        cout << iters << endl;
        cout << ans << endl;
        projectedAns = ans*pow(3,numbUniqueIndices)/iters;
        cout << projectedAns << endl;

    }



    // ['n', [[0, 0], [1, 3]]]
    // ['n', [[2, 6], [3, 9]]]
    // ['n', [[4, 12], [5, 15]]]
    // ['g', [[4, 12], [0, 1], [1, 4]]]
    // ['g', [[5, 15], [2, 7], [3, 10]]]
    // ['n', [[6, 18], [7, 21]]]
    // ['g', [[6, 18], [0, 2], [1, 5]]]
    // ['g', [[7, 21], [2, 8], [3, 11]]]

    // c_bruteForce(vector<pair<string,vector<pair<unsigned,unsigned>>>> types,unsigned checkpoint,unsigned numbSamples) {


};

using namespace std;

int main() {

    vector<pair<string,vector<pair<unsigned,unsigned>>>> types({
        pair<string,vector<pair<unsigned,unsigned>>>("n",vector<pair<unsigned,unsigned>>({pair<unsigned,unsigned>(0,0),pair<unsigned,unsigned>(1,3)})),
        pair<string,vector<pair<unsigned,unsigned>>>("n",vector<pair<unsigned,unsigned>>({pair<unsigned,unsigned>(2,6),pair<unsigned,unsigned>(3,9)})),
        pair<string,vector<pair<unsigned,unsigned>>>("n",vector<pair<unsigned,unsigned>>({pair<unsigned,unsigned>(4,12),pair<unsigned,unsigned>(5,15)})),
        pair<string,vector<pair<unsigned,unsigned>>>("g",vector<pair<unsigned,unsigned>>({pair<unsigned,unsigned>(4,12),pair<unsigned,unsigned>(0,1),pair<unsigned,unsigned>(1,4)})),
        pair<string,vector<pair<unsigned,unsigned>>>("g",vector<pair<unsigned,unsigned>>({pair<unsigned,unsigned>(5,15),pair<unsigned,unsigned>(2,7),pair<unsigned,unsigned>(3,10)})),
        pair<string,vector<pair<unsigned,unsigned>>>("n",vector<pair<unsigned,unsigned>>({pair<unsigned,unsigned>(6,18),pair<unsigned,unsigned>(7,21)})),
        pair<string,vector<pair<unsigned,unsigned>>>("g",vector<pair<unsigned,unsigned>>({pair<unsigned,unsigned>(6,18),pair<unsigned,unsigned>(0,2),pair<unsigned,unsigned>(1,5)})),
        pair<string,vector<pair<unsigned,unsigned>>>("g",vector<pair<unsigned,unsigned>>({pair<unsigned,unsigned>(7,21),pair<unsigned,unsigned>(2,8),pair<unsigned,unsigned>(3,11)}))
    });

    unsigned checkpoint = 2;
    unsigned numbSamples = 5000000;
    c_bruteForce(types,checkpoint,numbSamples);
}















