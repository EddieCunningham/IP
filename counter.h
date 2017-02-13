#include <iostream>
#include <vector>
#include <utility>


namespace std {

    class Counter {
    public:
        Counter(vector<pair<unsigned,unsigned>> initialCounter,unsigned maxSamples);
        vector<pair<unsigned,unsigned>> counter;
        bool stochasticChoice();
    private:
        unsigned numbSamples,totalSamples;
    };

}