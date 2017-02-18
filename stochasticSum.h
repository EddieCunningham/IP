#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>


namespace std {

    class Counter {
    public:
        Counter(vector<pair<int,int>> initialCounter,int maxSamples);
        vector<pair<int,int>> counter;
        bool stochasticChoice();
    private:
        int numSamples,totalSamples;
    };

    unordered_map<int,double> c_bruteForce(vector<pair<string,vector<pair<int,int>>>> types,int checkpoint,int numSamples);

}