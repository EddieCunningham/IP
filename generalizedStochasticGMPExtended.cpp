// g++ -I /usr/local/include -L/usr/local/lib generalizedStochasticGMPExtended.cpp -lgmpxx -lgmp -std=c++11

#include "generalizedStochasticGMPExtended.h"

namespace std {

    int Type::globalId = 0;

    void printTree(Type* r, int depth) {

        string tabs = "";
        for(int i=0; i<depth; ++i) {
            tabs += "\t";
        }
        string indexString = "";
        for(auto i=r->indices.begin(); i!=r->indices.end(); ++i) {
            indexString += "("+to_string(i->setNumb)+","+to_string(i->uVal)+","+i->sex+") ";
        }
        cout << tabs << r->name << ": " << indexString << endl;
        if(r->left) {
            printTree(r->left,depth+1);
        }
        if(r->right) {
            printTree(r->right,depth+1);
        }

    }

    int updateTermWeightings(Type *r, int whichBranch, bool actuallyUpdateWeights) {

        int ans = 0;

        pair<bool,branchInfo> nextVal = r->getNextVal(whichBranch,false);
        bool keepGoing = nextVal.first;
        double left = nextVal.second.left;
        double right = nextVal.second.right;

        int i=0;
        while(keepGoing) {
            
            int leftBranch = 1;
            int rightBranch = 1;

            if(r->left) {
                leftBranch = updateTermWeightings(r->left,left,actuallyUpdateWeights);
            }
            if(r->right) {
                rightBranch = updateTermWeightings(r->right,right,actuallyUpdateWeights);
            }

            int termsForThisVal = leftBranch*rightBranch;

            if(actuallyUpdateWeights) {
                r->termWeights[whichBranch][i] = termsForThisVal;
            }

            ans += termsForThisVal;

            nextVal = r->getNextVal(whichBranch, false);
            keepGoing = nextVal.first;
            left = nextVal.second.left;
            right = nextVal.second.right;

            ++i;

        }

        if(actuallyUpdateWeights) {
            r->accumulateWeights(whichBranch);
        }
        r->counter = 0;

        return ans;
    }

    void printType(const type_struct & t) {
        double tVal = t.tVal;
        string name = t.name;
        vector<index_struct> indices = t.indices;
        string sex = t.sex;

        cout << "-----------" << endl;
        cout << "tVal: " << tVal << endl;
        cout << "name: " << name << endl;
        cout << "indices: ";
        for(int i=0; i<indices.size(); ++i) {
            cout << "[" << indices[i].setNumb << "," << indices[i].uVal << "," << indices[i].sex << "] ";
        }
        cout << endl;
        if(tVal != -1) {
            cout << "sex: " << sex << endl;
        }
        cout << "-----------" << endl;
    }

    vector<Type*> generateAllTypesAndSets(unordered_map<string,pair<int,int>> allMN, const unordered_map<string,vector<vector<vector<double>>>> & allG, const vector<type_struct> & types) {
        vector<Type*> allTypes = vector<Type*>();

        for(auto t_it=types.begin(); t_it!=types.end(); ++t_it) {

            // printType(*t_it);

            double tProb = t_it->tVal;

            if(tProb == -1) {
                // choose the correct g term based on the things in the type
                string child = t_it->indices.at(0).sex;
                string left = t_it->indices.at(1).sex;
                string right = t_it->indices.at(2).sex;

                string key = left+","+right+"->"+child;
                vector<vector<vector<double>>> gTensor = allG.at(key);

                allTypes.push_back(new Type(false,gTensor,(*t_it)));
            }
            else {
                string child = t_it->sex;
                string left = t_it->indices.at(0).sex;
                string right = t_it->indices.at(1).sex;

                string key = left+","+right+"->"+child;
                vector<vector<vector<double>>> gTensor = allG.at(key);

                // cout << "g:" << endl;
                // for(int i=0; i<gTensor.size(); ++i) {
                //     for(int j=0; j<gTensor.at(i).size(); ++j) {
                //         for(int k=0; k<gTensor.at(i).at(j).size(); ++k) {
                //             cout << " " << gTensor.at(i).at(j).at(k);
                //         }
                //         cout << endl;
                //     }
                //     cout << endl;
                // }


                vector<vector<vector<double>>> newVals = vector<vector<vector<double>>>(1,vector<vector<double>>(gTensor.at(0).size(),vector<double>(gTensor.at(0).at(0).size(),0)));
                for(int i=0; i<gTensor.size(); ++i) {
                    for(int j=0; j<gTensor.at(i).size(); ++j) {
                        for(int k=0; k<gTensor.at(i).at(j).size(); ++k) {
                            double toAdd = gTensor.at(i).at(j).at(k);
                            if(i < allMN.at(child).first) {
                                toAdd *= tProb;
                            }
                            else {
                                toAdd *= (1.0 - tProb);
                            }
                            newVals[0][j][k] += toAdd;
                        }
                    }
                }
                allTypes.push_back(new Type(true,newVals,(*t_it)));
            }
        }

        for(auto a=allTypes.begin(); a!=allTypes.end(); ++a) {

            vector<int> uVals = vector<int>();

            for(auto i=(*a)->indices.begin(); i!=(*a)->indices.end(); ++i) {

                int setNumber = i->setNumb;
                int uniqueId = i->uVal;
                string sex = i->sex;

                uVals.push_back(uniqueId);
            }

            for(auto _a=allTypes.begin(); _a!=allTypes.end(); ++_a) {
                if((*a)->_id == (*_a)->_id) {
                    continue;
                }
                int valToWorryAbout = (*_a)->indices.at(0).uVal;
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

    mpz_class getTotalTerms(vector<Type*> roots) {

        // this number will be very big!
        mpz_class totalTerms = 1;

        for(auto r=roots.begin(); r!=roots.end(); ++r) {
            int currentTerms = updateTermWeightings(*r,0,false);
            totalTerms *= currentTerms;
        }
        return totalTerms;
    }

    pair<vector<Type*>,vector<Type*>> initializeTypes(unordered_map<string,pair<int,int>> allMN, const unordered_map<string,vector<vector<vector<double>>>> & allG, const vector<type_struct> & types) {
        // m is the number of dims that go into t
        // n is the total number of dims
        vector<Type*> allTypes = generateAllTypesAndSets(allMN,allG,types);

        vector<Type*> roots = vector<Type*>();

        // this number will be very big!
        mpz_class totalTerms = 1;

        unordered_map<int,int> numbUniqueTerms = unordered_map<int,int>();

        for(auto a=allTypes.begin(); a!=allTypes.end(); ++a) {
            if((*a)->isRoot) {
                roots.push_back(*a);
                printTree(*a,0);
                int currentTerms = updateTermWeightings(*a,0,true);
                cout << "This branch had " << currentTerms << " terms" << endl << endl;
                totalTerms *= currentTerms;
            }

            for(auto i=(*a)->indices.begin(); i!=(*a)->indices.end(); ++i) {
                int uVal = i->uVal;
                if(numbUniqueTerms.find(uVal) == numbUniqueTerms.end()) {
                    numbUniqueTerms.insert({uVal,1});
                }
            }
        }

        cout << "The total number of non-zero terms is: " << totalTerms << endl;
        // cout << "The total number of terms is: " << pow(g.at(0).size(),numbUniqueTerms.size()) << endl << endl;
        cout << "The total number of types is: " << allTypes.size() << endl;
        pair<vector<Type*>,vector<Type*>> ans = pair<vector<Type*>,vector<Type*>>(roots,allTypes);
        return ans;
    }

    long double findAnsHelper(Type* currentType, int whichBranch, vector<pair<pair<string,double>,vector<int>>>* setVals, const unordered_map<string,pair<int,int>> & allMN) {

        pair<bool,branchInfo> nextVal = currentType->getNextVal(whichBranch, true);
        double left = nextVal.second.left;
        double right = nextVal.second.right;
        double val = nextVal.second.val;

        // INCREMENTAL INTEGRAL PART
        int leftSetVal = -1;
        int rightSetVal = -1;
        int j=0;
        for(auto i=currentType->indices.rbegin(); i!=currentType->indices.rend(); ++i) {
            if(j == 0) {
                rightSetVal = i->setNumb;
            }
            else if(j == 1) {
                leftSetVal = i->setNumb;
            }
            else {
                break;
            }
            ++j;
        }
        if(leftSetVal != -1 and leftSetVal < setVals->size()) {
            val *= currentType->incrementalIntegralPart(left, allMN, (*setVals).at(leftSetVal));
        }
        if(rightSetVal != -1 and rightSetVal < setVals->size()) {
            val *= currentType->incrementalIntegralPart(right, allMN, (*setVals).at(rightSetVal));
        }

        // UPDATE SET VALS
        j=0;
        for(auto i=currentType->indices.rbegin(); i!=currentType->indices.rend(); ++i) {
            int setNumb = i->setNumb;

            if(setNumb < setVals->size()) {
                if(j == 0) {
                    (*setVals)[setNumb].second[right] += 1;
                }
                else if(j == 1) {
                    (*setVals)[setNumb].second[left] += 1;
                }
                else {
                    assert(0);
                }
            }
            ++j;
        }

        long double leftBranch = 1.0;
        long double rightBranch = 1.0;

        if(currentType->left) {
            leftBranch = findAnsHelper(currentType->left, left, setVals, allMN);
        }
        if(currentType->right) {
            rightBranch = findAnsHelper(currentType->right, right, setVals, allMN);
        }

        return val*leftBranch*rightBranch;
    }


    unordered_map<int,string> stochasticSum(const unordered_map<string,pair<int,int>> & allMN, vector<Type*> roots, unordered_map<int,pair<string,double>> pedigreeRoots, int numSamples, int checkpoint, int printCheckpoint) {

        vector<pair<pair<string,double>,vector<int>>> setVals = vector<pair<pair<string,double>,vector<int>>>(pedigreeRoots.size());
        for(auto i=pedigreeRoots.begin(); i!=pedigreeRoots.end(); ++i) {
            string sex = i->second.first;
            double t = i->second.second;
            int n = allMN.at(sex).second;
            setVals[i->first] = pair<pair<string,double>,vector<int>>(pair<string,double>(sex,t),vector<int>(n,0));
        }

        // handles the base case of the incremental integral
        mpf_class base(1.0);
        for(int i=0; i<setVals.size(); ++i) {
            double t = setVals.at(i).first.second;
            string sex = setVals.at(i).first.first;
            int m = allMN.at(sex).first;
            int n = allMN.at(sex).second;

            base *= tgamma(n/2.0)/pow(M_PI,n/2.0)*pow(tgamma(0.5),n)/tgamma(n/2.0 + 1.0) * ((2*m - n)/2.0*t + (n - m)/2.0);
        }

        unordered_map<int,string> toReturn = unordered_map<int,string>();
        mpz_class totalTerms = getTotalTerms(roots);
        mpf_class totalAns = 0.0;

        mp_exp_t *expptr = new mp_exp_t;

        for(int i=0; i<numSamples; ++i) {

            mpf_class ans(base);

            for(auto r=roots.begin(); r!=roots.end(); ++r) {
                double _ans = findAnsHelper(*r, 0, &setVals, allMN);
                assert(_ans > 0.0);
                ans *= _ans;
            }

            totalAns += ans;
            assert(totalAns > 0);

            for(auto s=setVals.begin(); s!=setVals.end(); ++s) {
                fill(s->second.begin(), s->second.end(), 0);
            }


            if(i != 0 and (i%checkpoint == 0 or i%printCheckpoint == 0)) {
                mpf_class averageAnswer = totalAns/i;
                mpf_class projectedAnswer = totalAns/i*totalTerms;

                string digits(mpf_get_str(NULL, expptr, 10, 15, projectedAnswer.get_mpf_t()));
                string toWrite = digits+":"+to_string(*expptr);
                
                if(i%printCheckpoint == 0) {
                    cout << "i: " << i << " \n\ttotalAns: " << totalAns << " \n\tprojected answer: " << projectedAnswer << " \n\taverage answer: " << averageAnswer << endl;
                    // cout << "\n\ttoWrite: " << toWrite << endl;
                }
                if(i%checkpoint == 0) {

                    toReturn.insert({i,toWrite});
                }
            }
        }
        delete expptr;
        return toReturn;
    }


    unordered_map<int,string> calcProbability(const unordered_map<string,pair<int,int>> & allMN,
                                              const unordered_map<string,vector<vector<vector<double>>>> & allG,
                                              const vector<type_struct> & types,
                                              const unordered_map<int,pair<string,double>> & pedigreeRoots,
                                              int numSamples,
                                              int checkpoint,
                                              int printCheckpoint) {

        pair<vector<Type*>,vector<Type*>> initializedTypes = initializeTypes(allMN, allG, types);
        vector<Type*> roots = initializedTypes.first;
        vector<Type*> allTypes = initializedTypes.second;        

        unordered_map<int,string> toReturn = stochasticSum(allMN, roots, pedigreeRoots, numSamples, checkpoint, printCheckpoint);

        for(auto a=allTypes.begin(); a!=allTypes.end(); ++a) {
            delete *a;
        }

        // return toReturn;
        return unordered_map<int,string>();
    }

};

using namespace std;

vector<string> split(const string& s, const string& delim, const bool keep_empty = true) {
    vector<string> result;
    if (delim.empty()) {
        result.push_back(s);
        return result;
    }
    string::const_iterator substart = s.begin(), subend;
    while (true) {
        subend = search(substart, s.end(), delim.begin(), delim.end());
        string temp(substart, subend);
        if (keep_empty || !temp.empty()) {
            result.push_back(temp);
        }
        if (subend == s.end()) {
            break;
        }
        substart = subend + delim.size();
    }
    return result;
}


vector<vector<vector<double>>> chromosomeProblemHelper(string left_string, string right_string, string child_string) {

    vector<string> mappings = {"/",">","^","_","|","x","D","V"};

    string p1 = "//   />   >/   |/   /|   ||   |>   >|";
    string p1_= "//   />   >/   |/   /|   ||   |>   >|";

    string p2 = "//   />   >/   |/   /|   ||   |>   >|";
    string p2_= "^^   ^.   .^   V^   ^V   VV   V.   .V";

    string p3 = "^^   ^.   .^   V^   ^V   VV   V.   .V";
    string p3_= "//   />   >/   |/   /|   ||   |>   >|";

    string p4 = "__   _D   D_   x_   _x   xx   xD   Dx";
    string p4_= "//   />   >/   |/   /|   ||   |>   >|";

    string p5 = "//   />   >/   |/   /|   ||   |>   >|";
    string p5_= "__   _D   D_   x_   _x   xx   xD   Dx";

    string p6 = "__   _D   D_   x_   _x   xx   xD   Dx";
    string p6_= "__   _D   D_   x_   _x   xx   xD   Dx";

    string p7 = "__   _D   D_   x_   _x   xx   xD   Dx";
    string p7_= "^^   ^.   .^   V^   ^V   VV   V.   .V";

    string p8 = "^^   ^.   .^   V^   ^V   VV   V.   .V";
    string p8_= "__   _D   D_   x_   _x   xx   xD   Dx";

    string table = p1+"~"+p1_+"~"+p2+"~"+p2_+"~"+p3+"~"+p3_+"~"+p4+"~"+p4_+"~"+p5+"~"+p5_+"~"+p6+"~"+p6_+"~"+p7+"~"+p7_+"~"+p8+"~"+p8_;

    vector<string> splitUp = split(table,"~");
    vector<vector<pair<string,string>>> parsedTable(splitUp.size());

    for(int i=0; i<splitUp.size(); ++i) {

        vector<string> row = split(splitUp[i],"   ");
        vector<pair<string,string>> rowWithPairs(row.size());

        for(int j=0; j<row.size(); ++j) {

            rowWithPairs[j] = pair<string,string>(row[j].substr(0,1),row[j].substr(1,1));
        }
        parsedTable[i] = rowWithPairs;
    }

    // cout << "parsedTable: " << endl;
    // for(int i=0; i<parsedTable.size(); ++i) {
    //     for(int j=0; j<parsedTable[i].size(); ++j) {
    //         cout << parsedTable[i][j].first << " " << parsedTable[i][j].second << " ";
    //     }
    //     cout << endl;
    // }




    unordered_map<string,vector<int>> lookup{
        {"unknown",vector<int>({0,1,2,3,4,5,6,7})},
        {"female",vector<int>({0,3,4,5})},
        {"male",vector<int>({1,2,6,7})}
    };

    vector<int> left = lookup.at(left_string);
    vector<int> right = lookup.at(right_string);
    vector<int> child = lookup.at(child_string);

    vector<vector<vector<double>>> overall = vector<vector<vector<double>>>(child.size());
    for(int i=0; i<child.size(); ++i) {
        string m = mappings[child[i]];

        vector<vector<double>> current = vector<vector<double>>(left.size());
        for(int j=0; j<current.size(); ++j) {
            vector<double> adding = vector<double>(right.size(),0);
            current[j] = adding;
        }

        for(int j=0; j<current.size(); ++j) {
            int row1 = 2*left.at(j);
            int row2 = 2*left.at(j)+1;            

            for(int k=0; k<right.size(); ++k) {
                int col = right.at(k);
                string e1 = parsedTable.at(row1).at(col).first;
                string e2 = parsedTable.at(row1).at(col).second;
                string e3 = parsedTable.at(row2).at(col).first;
                string e4 = parsedTable.at(row2).at(col).second;

                int relevant = 0;
                int total = 0;
                if(e1 == m) {
                    relevant += 1;
                }
                if(e1 != ".") {
                    total += 1;
                }
                if(e2 == m) {
                    relevant += 1;
                }
                if(e2 != ".") {
                    total += 1;
                }
                if(e3 == m) {
                    relevant += 1;
                }
                if(e3 != ".") {
                    total += 1;
                }
                if(e4 == m) {
                    relevant += 1;
                }
                if(e4 != ".") {
                    total += 1;
                }
                current[j][k] = (double)relevant/(double)total;
            }
        }
        overall[i] = current;        
    }
    return overall;
}

unordered_map<string,vector<vector<vector<double>>>> chromosomeProblem() {

    unordered_map<string,vector<vector<vector<double>>>> allG = unordered_map<string,vector<vector<vector<double>>>>();

    vector<string> sexes = {"unknown","male","female"};
    for(int i=0; i<27; ++i) {
        int i1 = i%3;
        int i2 = (i/3)%3;
        int i3 = (i/9)%3;

        string left = sexes.at(i1);
        string right = sexes.at(i2);
        string child = sexes.at(i3);

        if(left == "male" and right == "male") {
            continue;
        }

        string key = left+","+right+"->"+child;
        allG[key] = chromosomeProblemHelper(left, right, child);
    }


    return allG;
}





int main() {

    unordered_map<string,vector<vector<vector<double>>>> allG = chromosomeProblem();
    unordered_map<string,pair<int,int>> allMN{
            {"unknown",pair<int,int>(5,8)},
            {"female",pair<int,int>(3,4)},
            {"male",pair<int,int>(2,4)}
            };

    /*  ------------------------------------------------------------------- */

    // vector<vector<vector<double>>> g = {
    //       {{1.  ,0.5 ,0.5 ,0. },
    //        {0.5 ,0.25,0.25,0. },
    //        {0.5 ,0.25,0.25,0. },
    //        {0.0 ,0.  ,0.  ,0. }},
  
    //       {{0.  ,0.5 ,0.5 ,1. },
    //        {0.  ,0.25,0.25,0.5},
    //        {0.  ,0.25,0.25,0.5},
    //        {0.  ,0.  ,0.  ,0. }},
  
    //       {{0.  ,0.  ,0.  ,0. },
    //        {0.5 ,0.25,0.25,0. },
    //        {0.5 ,0.25,0.25,0. },
    //        {1.  ,0.5 ,0.5 ,0. }},

    //       {{0.  ,0.  ,0.  , 0.},
    //        {0.  ,0.25,0.25,0.5},
    //        {0.  ,0.25,0.25,0.5},
    //        {0.  ,0.5 ,0.5 ,1. }}
    //     };

    // unordered_map<string,pair<int,int>> allMN{
    //         {"unknown",pair<int,int>(3,4)},
    //         {"male",pair<int,int>(3,4)},
    //         {"female",pair<int,int>(3,4)}
    //         };

    // unordered_map<string,vector<vector<vector<double>>>> allG = unordered_map<string,vector<vector<vector<double>>>>();


    // vector<string> sexes = {"unknown","male","female"};
    // for(int i=0; i<27; ++i) {
    //     int i1 = i%3;
    //     int i2 = (i/3)%3;
    //     int i3 = (i/9)%3;
    //     string key = sexes.at(i1)+","+sexes.at(i2)+"->"+sexes.at(i3);
    //     allG[key] = g;
    // }

    /*  ------------------------------------------------------------------- */

    // type_struct p1;
    // index_struct is_1_1,is_1_2;
    // is_1_1.setNumb = 0;is_1_1.uVal = 0;is_1_1.sex = "male";
    // is_1_2.setNumb = 1;is_1_2.uVal = 2;is_1_2.sex = "female";
    // p1.indices = vector<index_struct>({is_1_1,is_1_2});
    // p1.sex = "female";
    // p1.tVal = 0.0;

    // type_struct p2;
    // index_struct is_2_1,is_2_2;
    // is_2_1.setNumb = 3;is_2_1.uVal = 6;is_2_1.sex = "female";
    // is_2_2.setNumb = 2;is_2_2.uVal = 4;is_2_2.sex = "male";
    // p2.indices = vector<index_struct>({is_2_1,is_2_2});
    // p2.sex = "unknown";
    // p2.tVal = 0.0;

    // type_struct p3;
    // index_struct is_3_1,is_3_2,is_3_3;
    // is_3_1.setNumb = 3;is_3_1.uVal = 6;is_3_1.sex = "female";
    // is_3_2.setNumb = 0;is_3_2.uVal = 1;is_3_2.sex = "male";
    // is_3_3.setNumb = 1;is_3_3.uVal = 3;is_3_3.sex = "female";
    // p3.indices = vector<index_struct>({is_3_1,is_3_2,is_3_3});
    // p3.tVal = -1.0;

    // vector<type_struct> types({p1,p2,p3});

    // unordered_map<int,pair<string,double>> pedigreeRoots{
    //     {0,pair<string,double>("female",0.0)},
    //     {1,pair<string,double>("male",0.0)},
    //     {2,pair<string,double>("female",0.0)}
    // };

    /*  ------------------------------------------------------------------- */

    type_struct p1;
    index_struct is_1_1,is_1_2;
    is_1_1.setNumb = 0;is_1_1.uVal = 0;is_1_1.sex = "male";
    is_1_2.setNumb = 1;is_1_2.uVal = 3;is_1_2.sex = "female";
    p1.indices = vector<index_struct>({is_1_1,is_1_2});
    p1.sex = "unknown";
    p1.tVal = 0.0;

    type_struct p2;
    index_struct is_2_1,is_2_2;
    is_2_1.setNumb = 4;is_2_1.uVal = 12;is_2_1.sex = "unknown";
    is_2_2.setNumb = 2;is_2_2.uVal = 6;is_2_2.sex = "unknown";
    p2.indices = vector<index_struct>({is_2_1,is_2_2});
    p2.sex = "female";
    p2.tVal = 0.0;

    type_struct p3;
    index_struct is_3_1,is_3_2,is_3_3;
    is_3_1.setNumb = 4;is_3_1.uVal = 12;is_3_1.sex = "unknown";
    is_3_2.setNumb = 0;is_3_2.uVal = 1;is_3_2.sex = "male";
    is_3_3.setNumb = 1;is_3_3.uVal = 4;is_3_3.sex = "female";
    p3.indices = vector<index_struct>({is_3_1,is_3_2,is_3_3});
    p3.tVal = -1.0;

    type_struct p4;
    index_struct is_4_1,is_4_2;
    is_4_1.setNumb = 5;is_4_1.uVal = 15;is_4_1.sex = "female";
    is_4_2.setNumb = 3;is_4_2.uVal = 9;is_4_2.sex = "male";
    p4.indices = vector<index_struct>({is_4_1,is_4_2});
    p4.sex = "male";
    p4.tVal = 0.0;


    type_struct p5;
    index_struct is_5_1,is_5_2,is_5_3;
    is_5_1.setNumb = 5;is_5_1.uVal = 15;is_5_1.sex = "female";
    is_5_2.setNumb = 6;is_5_2.uVal = 18;is_5_2.sex = "unknown";
    is_5_3.setNumb = 2;is_5_3.uVal = 7;is_5_3.sex = "unknown";
    p5.indices = vector<index_struct>({is_5_1,is_5_2,is_5_3});
    p5.tVal = -1.0;


    type_struct p6;
    index_struct is_6_1,is_6_2,is_6_3;
    is_6_1.setNumb = 6;is_6_1.uVal = 18;is_6_1.sex = "unknown";
    is_6_2.setNumb = 0;is_6_2.uVal = 2;is_6_2.sex = "male";
    is_6_3.setNumb = 1;is_6_3.uVal = 5;is_6_3.sex = "female";
    p6.indices = vector<index_struct>({is_6_1,is_6_2,is_6_3});
    p6.tVal = -1.0;


    vector<type_struct> types({p1,p2,p3,p4,p5,p6});

    unordered_map<int,pair<string,double>> pedigreeRoots{
        {0,pair<string,double>("male",0.0)},
        {1,pair<string,double>("female",0.0)},
        {2,pair<string,double>("unknown",0.0)},
        {3,pair<string,double>("male",0.0)}
    };

    /*  ------------------------------------------------------------------- */


    int numSamples = 10000;
    int checkpoint = numSamples*0.1;
    int printCheckpoint = 1000;

    calcProbability(allMN,allG,types,pedigreeRoots,numSamples,checkpoint,printCheckpoint);

}
