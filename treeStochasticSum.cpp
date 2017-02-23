#include "treeStochasticSum.h"
#include <stdlib.h>
#include <cassert>
#include <math.h>


namespace std {

    int Type::globalId = 0;

    pair<bool,vector<double>> gType::getNextVal(int whichBranch, bool random) {
        int left,right;
        double val;

        if(whichBranch == 0) {

            if(random) {
                randomChoice(this->counterLeft,0);
            }

            if(this->counterLeft == 4) {
                this->resetCounters();
                return pair<bool,vector<double>>(false,vector<double>(3,0));
            }
            left = this->counterLeft/2;
            right = this->counterLeft%2;
            val = this->vals[0][this->counterLeft];
            this->counterLeft += 1;
        }
        else if(whichBranch == 1) {

            if(random) {
                randomChoice(this->counterMiddle,1);
            }

            if(this->counterMiddle == 7) {
                this->resetCounters();
                return pair<bool,vector<double>>(false,vector<double>(3,0));
            }
            if(this->counterMiddle == 0) {
                left = 0;
                right = 1;
            }
            else if(this->counterMiddle == 1) {
                left = 0;
                right = 2;
            }
            else if(this->counterMiddle == 2) {
                left = 1;
                right = 0;
            }
            else if(this->counterMiddle == 3) {
                left = 1;
                right = 1;
            }
            else if(this->counterMiddle == 4) {
                left = 1;
                right = 2;
            }
            else if(this->counterMiddle == 5) {
                left = 2;
                right = 0;
            }
            else if(this->counterMiddle == 6) {
                left = 2;
                right = 1;
            }
            val = this->vals[1][this->counterMiddle];
            this->counterMiddle += 1;
        }
        else if(whichBranch == 2) {

            if(random) {
                randomChoice(this->counterRight,2);
            }

            if(this->counterRight == 4) {
                this->resetCounters();
                return pair<bool,vector<double>>(false,vector<double>(3,0));
            }
            left = this->counterRight/2 + 1;
            right = this->counterRight%2 + 1;
            val = this->vals[2][this->counterRight];
            this->counterRight += 1;
        }
        else {
            assert(0);
        }

        vector<double> ans = {(double)left,(double)right,val};
        return pair<bool,vector<double>>(true,ans);
    }

    pair<bool,vector<double>> nType::getNextVal(int whichBranch, bool random) {
        if(random) {
            randomChoice(this->counterLeft,0);
        }
        if(this->counterLeft == 4) {
            this->resetCounters();
            return pair<bool,vector<double>>(false,vector<double>(3,0));
        }
        int left,right;
        double val;
        left = this->counterLeft/2 + 1;
        right = this->counterLeft%2 + 1;
        val = this->vals[0][this->counterLeft];
        this->counterLeft += 1;

        vector<double> ans = {(double)left,(double)right,val};
        return pair<bool,vector<double>>(true,ans);
    }

    pair<bool,vector<double>> pType::getNextVal(int whichBranch, bool random) {
        if(random) {
            randomChoice(this->counterLeft,0);
        }

        if(this->counterLeft == 8) {
            this->resetCounters();
            return pair<bool,vector<double>>(false,vector<double>(3,0));
        }
        int left,right;
        double val;

        if(this->counterLeft < 6) {
            left = this->counterLeft/3;
            right = this->counterLeft%3;
        }
        else if(this->counterLeft == 6) {
            left = 2;
            right = 0;
        }
        else if(this->counterLeft == 7) {
            left = 2;
            right = 1;
        }

        val = this->vals[0][this->counterLeft];
        this->counterLeft += 1;

        vector<double> ans = {(double)left,(double)right,val};
        return pair<bool,vector<double>>(true,ans);
    }

    pair<bool,vector<double>> sType::getNextVal(int whichBranch, bool random) {

        if(random) {
            randomChoice(this->counterLeft,0);
        }

        if(this->counterLeft == 9) {
            this->resetCounters();
            return pair<bool,vector<double>>(false,vector<double>(3,0));
        }
        int left,right;
        double val;

        left = this->counterLeft/3;
        right = this->counterLeft%3;
        val = this->vals[0][this->counterLeft];
        this->counterLeft += 1;

        vector<double> ans = {(double)left,(double)right,val};
        return pair<bool,vector<double>>(true,ans);
    }

    double individualIntegral(double t, double a, double b, double c) {
        return (2*t*(a+b)+2*c*(1-t)+t+1)*tgamma(a+0.5)*tgamma(b+0.5)*tgamma(c+0.5)/tgamma(a+b+c+2.5);
    }

    double integralPart(vector<vector<int>> *setVals) {
        double ans = 1.0;
        for(auto it=setVals->begin(); it!=setVals->end(); ++it) {
            double t = 1.0;
            double integral = individualIntegral(t,(*it)[0],(*it)[1],(*it)[2]);
            ans *= integral;///(4*M_PI); 
                            //FOR THE SAKE OF NUMERICAL STABILITY KEEP THIS OUT
                            // HOWEVER THIS MEANS THAT PROBABILITY ISNT THE SAME FOR EVERYTHING
                            // MAYBE AT END FACTOR IN THING THAT TAKES INTO ACCOUNT NUBMER OF ROOTS?
        }
        return ans;
    }


    vector<Type*> generateAllTypesAndSets(vector<pair<string,vector<pair<int,int>>>> types, int numbRoots) {
        vector<Type*> allTypes = vector<Type*>();
        for(auto t=types.begin(); t!=types.end(); ++t) {
            string name = t->first;
            if(name == "g") {
                allTypes.push_back(new gType(*t));
            }
            else if(name == "n") {
                allTypes.push_back(new nType(*t));
            }
            else if(name == "p") {
                allTypes.push_back(new pType(*t));
            }
            else if(name == "s") {
                allTypes.push_back(new sType(*t));
            }
        }


        for(auto a=allTypes.begin(); a!=allTypes.end(); ++a) {

            vector<int> uVals = vector<int>();

            for(auto i=(*a)->indices.begin(); i!=(*a)->indices.end(); ++i) {

                int setNumber = i->first;
                int uniqueId = i->second;

                uVals.push_back(uniqueId);
            }

            for(auto _a=allTypes.begin(); _a!=allTypes.end(); ++_a) {
                if((*a)->_id == (*_a)->_id) {
                    continue;
                }
                int valToWorryAbout = (*_a)->indices[0].second;
                int i=0;
                for(auto u=uVals.begin(); u!=uVals.end(); ++u) {
                    if((*u) == valToWorryAbout) {

                        if((*a)->name == "g") {
                            if(i == 0) {                                
                                continue;
                            }
                            else if(i == 1) {
                                (*a)->left = *_a;
                            }
                            else if(i == 2) {
                                (*a)->right = *_a;
                            }
                        }
                        else {
                            if(i == 0) {
                                (*a)->left = *_a;
                            }
                            else if(i == 1) {
                                (*a)->right = *_a;
                            }
                        }
                    }
                    ++i;
                }
            }
        }
        return allTypes;
    }

    long double findAnsHelper(Type* currentType, int whichBranch, vector<vector<int>>* setVals) {

        pair<bool,vector<double>> nextVal = currentType->getNextVal(whichBranch, true);
        double left = nextVal.second[0];
        double right = nextVal.second[1];
        double val = nextVal.second[2];

        // update the setVals
        int j=0;
        for(auto i=currentType->indices.rbegin(); i!=currentType->indices.rend(); ++i) {
            int setNumb = i->first;

            if(setNumb < setVals->size()) {
                if(j == 0) {
                    (*setVals)[setNumb][right] += 1;
                }
                else if(j == 1) {
                    (*setVals)[setNumb][left] += 1;
                }
                else {
                    assert(0);
                }
            }
            ++j;
        }

        if(currentType->left == nullptr and currentType->right == nullptr) {
            return val;
        }

        long double leftBranch = 1.0;
        long double rightBranch = 1.0;

        if(currentType->left) {
            leftBranch = findAnsHelper(currentType->left, left, setVals);
        }
        if(currentType->right) {
            rightBranch = findAnsHelper(currentType->right, right, setVals);
        }

        return val*leftBranch*rightBranch;
    }

    void printTree(Type* r, int depth) {
        string tabs = "";
        for(int i=0; i<depth; ++i) {
            tabs += "\t";
        }
        string indexString = "";
        for(auto i=r->indices.begin(); i!=r->indices.end(); ++i) {
            indexString += "("+to_string(i->first)+","+to_string(i->second)+") ";
        }
        cout << tabs << r->name << ": " << indexString << endl;
        if(r->left) {
            printTree(r->left,depth+1);
        }
        if(r->right) {
            printTree(r->right,depth+1);
        }
    }

    int updateTermWeightings(Type *r, int whichBranch) {

        int ans = 0;

        pair<bool,vector<double>> nextVal = r->getNextVal(whichBranch, false);
        bool keepGoing = nextVal.first;
        double left = nextVal.second[0];
        double right = nextVal.second[1];

        int i=0;
        while(keepGoing) {
            
            int leftBranch = 1;
            int rightBranch = 1;

            if(r->left) {
                leftBranch = updateTermWeightings(r->left,left);
            }
            if(r->right) {
                rightBranch = updateTermWeightings(r->right,right);
            }

            int termsForThisVal = leftBranch*rightBranch;
            r->termWeights[whichBranch][i] = termsForThisVal;

            ans += termsForThisVal;

            nextVal = r->getNextVal(whichBranch, false);
            keepGoing = nextVal.first;
            left = nextVal.second[0];
            right = nextVal.second[1];

            ++i;
        }

        r->accumulateWeights(whichBranch);
        r->resetCounters();

        return ans;

    }

    pair<int,unordered_map<int,double>> getValues(int numbRoots,vector<pair<string,vector<pair<int,int>>>> types, int numSamples, int checkpoint) {

        unordered_map<int,double> toReturn = unordered_map<int,double>();

        vector<Type*> allTypes = generateAllTypesAndSets(types,numbRoots);
        vector<vector<int>> setVals = vector<vector<int>>(numbRoots,vector<int>({0,0,0}));

        vector<Type*> roots = vector<Type*>();
        long long totalTerms = 1;
        unordered_map<int,int> numbUniqueTerms = unordered_map<int,int>();

        for(auto a=allTypes.begin(); a!=allTypes.end(); ++a) {
            if((*a)->isRoot) {
                roots.push_back(*a);
                printTree(*a,0);
                int currentTerms = updateTermWeightings(*a,0);
                cout << "This branch had " << currentTerms << " terms" << endl << endl;
                totalTerms *= currentTerms;
            }

            for(auto i=(*a)->indices.begin(); i!=(*a)->indices.end(); ++i) {
                int uVal = i->second;
                if(numbUniqueTerms.find(uVal) == numbUniqueTerms.end()) {
                    numbUniqueTerms.insert({uVal,1});
                }
            }
        }

        cout << "The total number of non-zero terms is: " << totalTerms << endl;
        cout << "The total number of terms is: " << pow(3,numbUniqueTerms.size()) << endl << endl;

        long double totalAns = 0.0;

        for(long long i=0; i<numSamples; ++i) {

            long double ans = 1.0;
            for(auto r=roots.begin(); r!=roots.end(); ++r) {
                ans *= findAnsHelper(*r, 0, &setVals);
            }

            ans *= integralPart(&setVals);

            totalAns += ans;

            for(auto s=setVals.begin(); s!=setVals.end(); ++s) {
                fill(s->begin(), s->end(), 0);
            }

            if(i != 0 and i%checkpoint == 0) {
                long double averageAnswer = totalAns/i;
                long double projectedAnswer = totalAns/i*totalTerms;
                cout << "i: " << i << " \n\ttotalAns: " << totalAns << " \n\tprojected answer: " << projectedAnswer << " \n\taverage answer: " << averageAnswer << endl;
                toReturn.insert({i,totalAns});
            }
        }

        for(auto a=allTypes.begin(); a!=allTypes.end(); ++a) {
            delete *a;
        }

        return pair<int,unordered_map<int,double>>(totalTerms,toReturn);
    }
};

using namespace std;

int main() {

//     vector<pair<string,vector<pair<int,int>>>> types({
// pair<string,vector<pair<int,int>>>("g", vector<pair<int,int>>({pair<int,int>(22, 748), pair<int,int>(0, 12), pair<int,int>(1, 46)})),
// pair<string,vector<pair<int,int>>>("g", vector<pair<int,int>>({pair<int,int>(23, 782), pair<int,int>(0, 13), pair<int,int>(1, 47)})),
// pair<string,vector<pair<int,int>>>("g", vector<pair<int,int>>({pair<int,int>(24, 816), pair<int,int>(0, 14), pair<int,int>(1, 48)})),
// pair<string,vector<pair<int,int>>>("g", vector<pair<int,int>>({pair<int,int>(25, 850), pair<int,int>(0, 15), pair<int,int>(1, 49)})),
// pair<string,vector<pair<int,int>>>("g", vector<pair<int,int>>({pair<int,int>(26, 884), pair<int,int>(0, 16), pair<int,int>(1, 50)})),
// pair<string,vector<pair<int,int>>>("g", vector<pair<int,int>>({pair<int,int>(27, 918), pair<int,int>(0, 17), pair<int,int>(1, 51)})),
// pair<string,vector<pair<int,int>>>("g", vector<pair<int,int>>({pair<int,int>(28, 952), pair<int,int>(0, 18), pair<int,int>(1, 52)})),
// pair<string,vector<pair<int,int>>>("g", vector<pair<int,int>>({pair<int,int>(29, 986), pair<int,int>(0, 19), pair<int,int>(1, 53)})),
// pair<string,vector<pair<int,int>>>("g", vector<pair<int,int>>({pair<int,int>(30, 1020), pair<int,int>(0, 20), pair<int,int>(1, 54)})),
// pair<string,vector<pair<int,int>>>("g", vector<pair<int,int>>({pair<int,int>(31, 1054), pair<int,int>(3, 109), pair<int,int>(2, 75)})),
// pair<string,vector<pair<int,int>>>("g", vector<pair<int,int>>({pair<int,int>(32, 1088), pair<int,int>(0, 21), pair<int,int>(1, 55)})),
// pair<string,vector<pair<int,int>>>("g", vector<pair<int,int>>({pair<int,int>(33, 1122), pair<int,int>(3, 110), pair<int,int>(2, 76)})),
// pair<string,vector<pair<int,int>>>("g", vector<pair<int,int>>({pair<int,int>(34, 1156), pair<int,int>(0, 22), pair<int,int>(1, 56)})),
// pair<string,vector<pair<int,int>>>("g", vector<pair<int,int>>({pair<int,int>(35, 1190), pair<int,int>(3, 111), pair<int,int>(2, 77)})),
// pair<string,vector<pair<int,int>>>("g", vector<pair<int,int>>({pair<int,int>(36, 1224), pair<int,int>(0, 23), pair<int,int>(1, 57)})),
// pair<string,vector<pair<int,int>>>("g", vector<pair<int,int>>({pair<int,int>(37, 1258), pair<int,int>(3, 112), pair<int,int>(2, 78)})),
// pair<string,vector<pair<int,int>>>("g", vector<pair<int,int>>({pair<int,int>(38, 1292), pair<int,int>(0, 24), pair<int,int>(1, 58)})),
// pair<string,vector<pair<int,int>>>("g", vector<pair<int,int>>({pair<int,int>(39, 1326), pair<int,int>(3, 113), pair<int,int>(2, 79)})),
// pair<string,vector<pair<int,int>>>("g", vector<pair<int,int>>({pair<int,int>(40, 1360), pair<int,int>(3, 114), pair<int,int>(2, 80)})),
// pair<string,vector<pair<int,int>>>("g", vector<pair<int,int>>({pair<int,int>(41, 1394), pair<int,int>(3, 115), pair<int,int>(2, 81)})),
// pair<string,vector<pair<int,int>>>("g", vector<pair<int,int>>({pair<int,int>(42, 1428), pair<int,int>(3, 116), pair<int,int>(2, 82)})),
// pair<string,vector<pair<int,int>>>("g", vector<pair<int,int>>({pair<int,int>(43, 1462), pair<int,int>(3, 117), pair<int,int>(2, 83)})),
// pair<string,vector<pair<int,int>>>("g", vector<pair<int,int>>({pair<int,int>(44, 1496), pair<int,int>(3, 118), pair<int,int>(2, 84)})),
// pair<string,vector<pair<int,int>>>("g", vector<pair<int,int>>({pair<int,int>(45, 1530), pair<int,int>(46, 1564), pair<int,int>(47, 1598)})),
// pair<string,vector<pair<int,int>>>("g", vector<pair<int,int>>({pair<int,int>(46, 1564), pair<int,int>(0, 25), pair<int,int>(1, 59)})),
// pair<string,vector<pair<int,int>>>("g", vector<pair<int,int>>({pair<int,int>(47, 1598), pair<int,int>(3, 119), pair<int,int>(2, 85)})),
// pair<string,vector<pair<int,int>>>("g", vector<pair<int,int>>({pair<int,int>(48, 1632), pair<int,int>(49, 1666), pair<int,int>(50, 1700)})),
// pair<string,vector<pair<int,int>>>("g", vector<pair<int,int>>({pair<int,int>(49, 1666), pair<int,int>(0, 26), pair<int,int>(1, 60)})),
// pair<string,vector<pair<int,int>>>("g", vector<pair<int,int>>({pair<int,int>(50, 1700), pair<int,int>(3, 120), pair<int,int>(2, 86)})),
// pair<string,vector<pair<int,int>>>("g", vector<pair<int,int>>({pair<int,int>(51, 1734), pair<int,int>(52, 1768), pair<int,int>(53, 1802)})),
// pair<string,vector<pair<int,int>>>("g", vector<pair<int,int>>({pair<int,int>(52, 1768), pair<int,int>(0, 27), pair<int,int>(1, 61)})),
// pair<string,vector<pair<int,int>>>("g", vector<pair<int,int>>({pair<int,int>(53, 1802), pair<int,int>(3, 121), pair<int,int>(2, 87)})),
// pair<string,vector<pair<int,int>>>("g", vector<pair<int,int>>({pair<int,int>(54, 1836), pair<int,int>(55, 1870), pair<int,int>(56, 1904)})),
// pair<string,vector<pair<int,int>>>("g", vector<pair<int,int>>({pair<int,int>(55, 1870), pair<int,int>(0, 28), pair<int,int>(1, 62)})),
// pair<string,vector<pair<int,int>>>("g", vector<pair<int,int>>({pair<int,int>(56, 1904), pair<int,int>(3, 122), pair<int,int>(2, 88)})),
// pair<string,vector<pair<int,int>>>("g", vector<pair<int,int>>({pair<int,int>(57, 1938), pair<int,int>(58, 1972), pair<int,int>(59, 2006)})),
// pair<string,vector<pair<int,int>>>("g", vector<pair<int,int>>({pair<int,int>(58, 1972), pair<int,int>(0, 29), pair<int,int>(1, 63)})),
// pair<string,vector<pair<int,int>>>("g", vector<pair<int,int>>({pair<int,int>(59, 2006), pair<int,int>(3, 123), pair<int,int>(2, 89)})),
// pair<string,vector<pair<int,int>>>("g", vector<pair<int,int>>({pair<int,int>(60, 2040), pair<int,int>(61, 2074), pair<int,int>(62, 2108)})),
// pair<string,vector<pair<int,int>>>("g", vector<pair<int,int>>({pair<int,int>(61, 2074), pair<int,int>(0, 30), pair<int,int>(1, 64)})),
// pair<string,vector<pair<int,int>>>("g", vector<pair<int,int>>({pair<int,int>(62, 2108), pair<int,int>(3, 124), pair<int,int>(2, 90)})),
// pair<string,vector<pair<int,int>>>("g", vector<pair<int,int>>({pair<int,int>(63, 2142), pair<int,int>(64, 2176), pair<int,int>(65, 2210)})),
// pair<string,vector<pair<int,int>>>("g", vector<pair<int,int>>({pair<int,int>(64, 2176), pair<int,int>(0, 31), pair<int,int>(1, 65)})),
// pair<string,vector<pair<int,int>>>("g", vector<pair<int,int>>({pair<int,int>(65, 2210), pair<int,int>(3, 125), pair<int,int>(2, 91)})),
// pair<string,vector<pair<int,int>>>("g", vector<pair<int,int>>({pair<int,int>(66, 2244), pair<int,int>(67, 2278), pair<int,int>(68, 2312)})),
// pair<string,vector<pair<int,int>>>("g", vector<pair<int,int>>({pair<int,int>(67, 2278), pair<int,int>(0, 32), pair<int,int>(1, 66)})),
// pair<string,vector<pair<int,int>>>("g", vector<pair<int,int>>({pair<int,int>(68, 2312), pair<int,int>(3, 126), pair<int,int>(2, 92)})),
// pair<string,vector<pair<int,int>>>("g", vector<pair<int,int>>({pair<int,int>(69, 2346), pair<int,int>(70, 2380), pair<int,int>(19, 650)})),
// pair<string,vector<pair<int,int>>>("g", vector<pair<int,int>>({pair<int,int>(70, 2380), pair<int,int>(71, 2414), pair<int,int>(72, 2448)})),
// pair<string,vector<pair<int,int>>>("g", vector<pair<int,int>>({pair<int,int>(71, 2414), pair<int,int>(0, 33), pair<int,int>(1, 67)})),
// pair<string,vector<pair<int,int>>>("g", vector<pair<int,int>>({pair<int,int>(72, 2448), pair<int,int>(3, 127), pair<int,int>(2, 93)})),
// pair<string,vector<pair<int,int>>>("n", vector<pair<int,int>>({pair<int,int>(0, 0), pair<int,int>(1, 34)})),
// pair<string,vector<pair<int,int>>>("n", vector<pair<int,int>>({pair<int,int>(0, 11), pair<int,int>(1, 45)})),
// pair<string,vector<pair<int,int>>>("n", vector<pair<int,int>>({pair<int,int>(0, 1), pair<int,int>(1, 35)})),
// pair<string,vector<pair<int,int>>>("n", vector<pair<int,int>>({pair<int,int>(0, 2), pair<int,int>(1, 36)})),
// pair<string,vector<pair<int,int>>>("n", vector<pair<int,int>>({pair<int,int>(0, 3), pair<int,int>(1, 37)})),
// pair<string,vector<pair<int,int>>>("n", vector<pair<int,int>>({pair<int,int>(0, 4), pair<int,int>(1, 38)})),
// pair<string,vector<pair<int,int>>>("n", vector<pair<int,int>>({pair<int,int>(0, 5), pair<int,int>(1, 39)})),
// pair<string,vector<pair<int,int>>>("n", vector<pair<int,int>>({pair<int,int>(0, 6), pair<int,int>(1, 40)})),
// pair<string,vector<pair<int,int>>>("n", vector<pair<int,int>>({pair<int,int>(0, 8), pair<int,int>(1, 42)})),
// pair<string,vector<pair<int,int>>>("n", vector<pair<int,int>>({pair<int,int>(0, 9), pair<int,int>(1, 43)})),
// pair<string,vector<pair<int,int>>>("n", vector<pair<int,int>>({pair<int,int>(22, 748), pair<int,int>(4, 136)})),
// pair<string,vector<pair<int,int>>>("n", vector<pair<int,int>>({pair<int,int>(23, 782), pair<int,int>(5, 170)})),
// pair<string,vector<pair<int,int>>>("n", vector<pair<int,int>>({pair<int,int>(25, 850), pair<int,int>(6, 204)})),
// pair<string,vector<pair<int,int>>>("n", vector<pair<int,int>>({pair<int,int>(26, 884), pair<int,int>(7, 238)})),
// pair<string,vector<pair<int,int>>>("n", vector<pair<int,int>>({pair<int,int>(27, 918), pair<int,int>(8, 272)})),
// pair<string,vector<pair<int,int>>>("n", vector<pair<int,int>>({pair<int,int>(29, 986), pair<int,int>(10, 340)})),
// pair<string,vector<pair<int,int>>>("n", vector<pair<int,int>>({pair<int,int>(3, 102), pair<int,int>(2, 68)})),
// pair<string,vector<pair<int,int>>>("n", vector<pair<int,int>>({pair<int,int>(3, 103), pair<int,int>(2, 69)})),
// pair<string,vector<pair<int,int>>>("n", vector<pair<int,int>>({pair<int,int>(3, 104), pair<int,int>(2, 70)})),
// pair<string,vector<pair<int,int>>>("n", vector<pair<int,int>>({pair<int,int>(3, 105), pair<int,int>(2, 71)})),
// pair<string,vector<pair<int,int>>>("n", vector<pair<int,int>>({pair<int,int>(3, 106), pair<int,int>(2, 72)})),
// pair<string,vector<pair<int,int>>>("n", vector<pair<int,int>>({pair<int,int>(3, 107), pair<int,int>(2, 73)})),
// pair<string,vector<pair<int,int>>>("n", vector<pair<int,int>>({pair<int,int>(3, 108), pair<int,int>(2, 74)})),
// pair<string,vector<pair<int,int>>>("n", vector<pair<int,int>>({pair<int,int>(30, 1020), pair<int,int>(31, 1054)})),
// pair<string,vector<pair<int,int>>>("n", vector<pair<int,int>>({pair<int,int>(32, 1088), pair<int,int>(33, 1122)})),
// pair<string,vector<pair<int,int>>>("n", vector<pair<int,int>>({pair<int,int>(38, 1292), pair<int,int>(39, 1326)})),
// pair<string,vector<pair<int,int>>>("n", vector<pair<int,int>>({pair<int,int>(40, 1360), pair<int,int>(11, 374)})),
// pair<string,vector<pair<int,int>>>("n", vector<pair<int,int>>({pair<int,int>(41, 1394), pair<int,int>(12, 408)})),
// pair<string,vector<pair<int,int>>>("n", vector<pair<int,int>>({pair<int,int>(42, 1428), pair<int,int>(13, 442)})),
// pair<string,vector<pair<int,int>>>("n", vector<pair<int,int>>({pair<int,int>(43, 1462), pair<int,int>(14, 476)})),
// pair<string,vector<pair<int,int>>>("n", vector<pair<int,int>>({pair<int,int>(44, 1496), pair<int,int>(15, 510)})),
// pair<string,vector<pair<int,int>>>("n", vector<pair<int,int>>({pair<int,int>(45, 1530), pair<int,int>(17, 578)})),
// pair<string,vector<pair<int,int>>>("n", vector<pair<int,int>>({pair<int,int>(48, 1632), pair<int,int>(18, 612)})),
// pair<string,vector<pair<int,int>>>("n", vector<pair<int,int>>({pair<int,int>(51, 1734), pair<int,int>(19, 646)})),
// pair<string,vector<pair<int,int>>>("n", vector<pair<int,int>>({pair<int,int>(54, 1836), pair<int,int>(19, 647)})),
// pair<string,vector<pair<int,int>>>("n", vector<pair<int,int>>({pair<int,int>(57, 1938), pair<int,int>(19, 648)})),
// pair<string,vector<pair<int,int>>>("n", vector<pair<int,int>>({pair<int,int>(63, 2142), pair<int,int>(20, 680)})),
// pair<string,vector<pair<int,int>>>("n", vector<pair<int,int>>({pair<int,int>(66, 2244), pair<int,int>(20, 681)})),
// pair<string,vector<pair<int,int>>>("n", vector<pair<int,int>>({pair<int,int>(69, 2346), pair<int,int>(21, 714)})),
// pair<string,vector<pair<int,int>>>("s", vector<pair<int,int>>({pair<int,int>(0, 10), pair<int,int>(1, 44)})),
// pair<string,vector<pair<int,int>>>("s", vector<pair<int,int>>({pair<int,int>(0, 7), pair<int,int>(1, 41)})),
// pair<string,vector<pair<int,int>>>("s", vector<pair<int,int>>({pair<int,int>(24, 816), pair<int,int>(16, 544)})),
// pair<string,vector<pair<int,int>>>("s", vector<pair<int,int>>({pair<int,int>(28, 952), pair<int,int>(9, 306)})),
// pair<string,vector<pair<int,int>>>("s", vector<pair<int,int>>({pair<int,int>(34, 1156), pair<int,int>(35, 1190)})),
// pair<string,vector<pair<int,int>>>("s", vector<pair<int,int>>({pair<int,int>(36, 1224), pair<int,int>(37, 1258)})),
// pair<string,vector<pair<int,int>>>("s", vector<pair<int,int>>({pair<int,int>(60, 2040), pair<int,int>(19, 649)}))
// });
    // 22 roots

    vector<pair<string,vector<pair<int,int>>>> types({
        pair<string,vector<pair<int,int>>>("n",vector<pair<int,int>>({pair<int,int>(0, 0),pair<int,int>(1, 3)})),
        pair<string,vector<pair<int,int>>>("n",vector<pair<int,int>>({pair<int,int>(4, 12),pair<int,int>(2, 6)})),
        pair<string,vector<pair<int,int>>>("g",vector<pair<int,int>>({pair<int,int>(4, 12),pair<int,int>(0, 1),pair<int,int>(1, 4)})),
        pair<string,vector<pair<int,int>>>("n",vector<pair<int,int>>({pair<int,int>(5, 15),pair<int,int>(3, 9)})),
        pair<string,vector<pair<int,int>>>("g",vector<pair<int,int>>({pair<int,int>(5, 15),pair<int,int>(6, 18),pair<int,int>(2, 7)})),
        pair<string,vector<pair<int,int>>>("g",vector<pair<int,int>>({pair<int,int>(6, 18),pair<int,int>(0, 2),pair<int,int>(1, 5)}))
        });
    // 4 roots

    // vector<pair<string,vector<pair<int,int>>>> types({
    //     pair<string,vector<pair<int,int>>>("n",vector<pair<int,int>>({pair<int,int>(0, 0), pair<int,int>(1, 2)})),
    //     pair<string,vector<pair<int,int>>>("n",vector<pair<int,int>>({pair<int,int>(3, 6), pair<int,int>(2, 4)})),
    //     pair<string,vector<pair<int,int>>>("g",vector<pair<int,int>>({pair<int,int>(3, 6), pair<int,int>(0, 1), pair<int,int>(1, 3)}))
    //     });
    // 3 roots

    int numSamples = 1000000;
    int checkpoint = numSamples*0.05;
    getValues(4,types,numSamples,checkpoint);
}
