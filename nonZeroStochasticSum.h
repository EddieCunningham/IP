#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>


namespace std {

    class Type {
    public:
        string name;
        int setNumb;
        Type* parent1;
        Type* parent2;
        vector<vector<double>> possibleVals;
        double takenVal;
    }

    void computeSum(vector<pair<string,vector<pair<int,int>>>> types,int checkpoint,int numSamples);

}