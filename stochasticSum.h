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

    void c_bruteForce(vector<pair<string,vector<pair<unsigned,unsigned>>>> types,unsigned checkpoint,unsigned numbSamples);

}