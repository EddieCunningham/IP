#include <stdlib.h>
#include <cassert>
#include "nonZeroStochasticSum.h"

using namespace std {

    void computeSum(vector<pair<string,vector<pair<int,int>>>> types,int checkpoint,int numSamples) {

        // create graph and store roots in data structure

        // each evaluation will involve choosing a path down a type and then updating the parent types 
        // possible graphs and continuing until all the leafs are reached

        // the value of a traversal is the product of all of the values of the types (will never be 0)
    }



}