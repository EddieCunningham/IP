#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <stdlib.h>
#include <math.h>
#include <numeric>
#include <algorithm>
#include <stdlib.h>
#include <random>
#include <csignal>

using namespace std;


struct point {
    vector<double> *L;
    vector<double> *s;
    vector<double> val;
    point* left;
    point* right;
}

class hybridMC {
public:

    double minimum, maximum;
    vector<double> points;
    
    hybridMC(double minimum_, double maximum_):
    minimum(minimum_),
    maximum(maximum_),
    points()
    {}

    void addPoint() {

    }

    double samplePoint() {


        return 0.0;
    }    
};


int main() {
    return 1;

}