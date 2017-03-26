// g++ logProbabilityIP.cpp -O3 -std=c++11

#include "logProbabilityIP.h"


#define MY_DEBUG false


/*
 
 #1 naive monte carlo with primitive numbers
 #2 naive monte carlo with big number library
 #3 naive monte carlo with log trick and primitive numbers
 #4 naive monte carlo with log trick with big number library
 #5 vegas with log trick and primitive numbers
 #6 vegas with big number library
 #7 vegas with log trick with big number
 
 */


namespace std {
    
    
    void personClass::storeProbAndNormalize() {
        
        if(MY_DEBUG) {
            cout << "LINE: " << __LINE__ << endl;
            this->toString();
        }
               double t = this->t;
        double m = this->m;
        double n = this->n;
        
        double probability = 0.0;
        for(int i=0; i<m; ++i) {
            probability += this->probs[i];
            if(!(this->probs[i] >= 0 and this->probs[i] <= 1.0)) {
                raise(SIGABRT);
            }
        }
        this->probability = probability;
        
        double sumOther = 0.0;
        for(int i=m; i<n; ++i) {
            sumOther += this->probs[i];
        }
        
        
        if((this->probability < pow(10,-15) or this->probability > 1.0) and t == 1.0) {
            // cout << "LINE: " << __LINE__ << endl;
            // this->toString();
            // if(this->parentA) {
            //     cout << "ParentA:" << endl;
            //     this->parentA->toString();
            // }
            // if(this->parentB) {
            //     cout << "ParentB:" << endl;
            //     this->parentB->toString();
            // }
            
            // cout << "CONTRADICTION!  probability was: " << this->probability << endl;
            this->dontInclude = true;
            return;
            // throw 20;
        }
        if(abs(sumOther) < pow(10,-15) and t == 0.0) {
            // cout << "LINE: " << __LINE__ << endl;
            // this->toString();
            // if(this->parentA) {
            //     cout << "ParentA:" << endl;
            //     this->parentA->toString();
            // }
            // if(this->parentB) {
            //     cout << "ParentB:" << endl;
            //     this->parentB->toString();
            // }
            
            // cout << "CONTRADICTION!  sumOther was: " << sumOther << endl;
            this->dontInclude = true;
            return;
            // throw 20;
        }
        
        
        for(int i=0; i<m; ++i) {
            if(abs(this->probability) < pow(10,-15)) {
                this->probs[i] = 0.0;
            }
            else {
                this->probs[i] *= t/this->probability;
            }
        }
        for(int i=m; i<n; ++i) {
            if(abs(sumOther) < pow(10,-15)) {
                this->probs[i] = 0.0;
            }
            else {
                this->probs[i] *= (1.0-t)/sumOther;
            }
        }
        
        double totalSum = 0.0;
        for(int i=0; i<this->probs.size(); ++i) {
            totalSum += this->probs.at(i);
        }
        if(abs(totalSum-1.0) > pow(10,-15)) {
            // cout << "Total sum wasn't 1!  It was " << totalSum << endl;
            //             string a;
            //             cin >> a;
            for(int i=0; i<this->probs.size(); ++i) {
                this->probs[i] /= totalSum;
            }
        }
    }
    
    
    double pedigreeClass2::getNormVal(personClass *p, int index) {
        
        if(p->updated) {
            return p->probs.at(index);
        }
        
        updateProbs(p);
        return p->probs.at(index);
    }
    
    // will place the normalized val in the
    void pedigreeClass2::updateProbs(personClass* c) {
        
        if(MY_DEBUG) {
            cout << "LINE: " << __LINE__ << endl;
            c->toString();
        }
        
        if(c->updated) {
            return;
        }
        
        vector<vector<vector<double>>>& g = c->g;
        personClass* p = c->parentA;
        personClass* q = c->parentB;
        
        for(int i=0; i<g.size(); ++i) {
            
            c->probs[i] = 0.0;
            for(int j=0; j<g.at(i).size(); ++j) {
                
                double pProb = this->getNormVal(p,j);
                for(int k=0; k<g.at(i).at(j).size(); ++k) {
                    
                    double qProb = this->getNormVal(q,k);
                    c->probs[i] += g.at(i).at(j).at(k)*pProb*qProb;
                }
            }
        }
        c->storeProbAndNormalize();
        c->updated = true;
        
        if(MY_DEBUG) {
            cout << "LINE: " << __LINE__ << endl;
            c->toString();
        }
    }
    
    double pedigreeClass2::getProbability() {
        double totalAns = 1.0;
        
        for(auto p_it=this->allPeople.begin(); p_it!=this->allPeople.end(); ++p_it) {
            if((*p_it)->dontInclude) {
                if((*p_it)->isRoot) {
                    return 0;
                }
                // cout << "skipping this dude:\n";
                // (*p_it)->toString();
                continue;
            }
            updateProbs(*p_it);
            double t = (*p_it)->t;
            double prob = (*p_it)->probability;
            double probOfShading = t*prob + (1-t)*(1-prob);
            totalAns *= probOfShading;
        }
        
        return totalAns;
    }
    
    double pedigreeClass2::getLogProbability() {
        double totalAns = 0.0;
        
        for(auto p_it=this->allPeople.begin(); p_it!=this->allPeople.end(); ++p_it) {
            
            updateProbs(*p_it);
            
            if((*p_it)->dontInclude) {
                if((*p_it)->isRoot) {
                    return -1;
                }
                continue;
            }
            
            double t = (*p_it)->t;
            double prob = (*p_it)->probability;
            double probOfShading = t*prob + (1-t)*(1-prob);
            totalAns += log(probOfShading);
        }
        return totalAns;
    }

    
    double pedigreeClass2::logEvaluation(const vector<double> & x) {
        
        for(auto p_it=this->allPeople.begin(); p_it!=this->allPeople.end(); ++p_it) {
            (*p_it)->updated = false;
            (*p_it)->dontInclude = false;
        }
        
        // still need to integrate using spherical coordinates!!
        int index = 0;
        double log_extraSines = 0.0;
        double log_normalizingPart = 0.0;
        
        string ess = "";
        
        if(MY_DEBUG) {
            cout << "\n\n\n~~~~~~~~~~~~~~ NEW EVAL ~~~~~~~~~~~~~~" << endl;
        }
        
        vector<double> sphericalParameters(x.size());
        
        for(auto r_it=this->roots.begin(); r_it!=this->roots.end(); ++r_it) {
            
            // get the spherical parameters from x
            int n = (*r_it)->n;
            for(int i=0; i<n-1; ++i) {
                sphericalParameters[i] = x[index+i];
            }
            index += n-1;
            
            vector<double>& probs = (*r_it)->probs;
            double total = 0.0;
            for(int i=0; i<probs.size(); ++i) {
                
                double value = 1.0;
                if(i < n-1) {
                    value *= cos(sphericalParameters.at(i));
                }
                for(int j=0; j<i; ++j) {
                    value *= sin(sphericalParameters.at(j));
                }
                probs[i] = pow(value,2);
                if(!(probs[i] <= 1.0 && probs[i] >= 0)) {
                    raise(SIGABRT);
                }
                total += pow(value,2);
                
                if(i < n-2) {
                    log_extraSines += (n-2-i)*log(sin(sphericalParameters.at(i)));
                    // extraSines *= pow(sin(sphericalParameters.at(i)),n-2-i);
                }
            }
            
            log_normalizingPart += log(tgamma(n/2.0))-log(2.0)-(n/2.0)*log(M_PI);
            // normalizingPart *= tgamma(n/2.0)/pow(M_PI,n/2.0)/2.0;
            
            if(abs(total-1.0) >= pow(10,-15)) {
                cout << "The total was: " << total << endl;
                if(!(0)) {
                    raise(SIGABRT);
                }
            }
            
            (*r_it)->storeProbAndNormalize();
            if((*r_it)->dontInclude) {
                return -1;
            }
            if(!((*r_it)->probability <= 1.0 and (*r_it)->probability >= 0.0)) {
                raise(SIGABRT);
            }
            (*r_it)->updated = true;
        }
        
        if(MY_DEBUG) {
            cout << "\n========================================" << endl;
            for(auto p_it=this->allPeople.begin(); p_it!=this->allPeople.end(); ++p_it) {
                
                cout << "LINE: " << __LINE__ << endl;
                (*p_it)->toString();
            }
            cout << "----------------------------------------" << endl;
        }
        double log_prob = this->getLogProbability();
        if(log_prob == -1) {
            return -1;
        }
        return log_prob+log_extraSines+log_normalizingPart;
    }
    
    
    double pedigreeClass2::naiveMonteCarlo(long numbCalls) {
        if(MY_DEBUG) {
            for(int i=0; i<this->allPeople.size(); ++i) {
                this->allPeople[i]->toString();
            }
        }
        
        int totalDim = 0;
        for(int i=0; i<this->roots.size(); ++i) {
            totalDim += this->roots[i]->n-1;
        }
        
        double xl[totalDim];
        double xu[totalDim];
        int index = 0;
        double log_volume = 0.0;
        for(int i=0; i<this->roots.size(); ++i) {
            
            int n = this->roots[i]->n;
            
            for(int j=0; j<n-2; ++j) {
                xl[index+j] = 0;
                xu[index+j] = M_PI;
                log_volume += log(M_PI);
            }
            xl[index+n-2] = 0;
            xu[index+n-2] = 2*M_PI;
            log_volume += log(2)+log(M_PI);
            index += n-1;
        }
        
        vector<double> x(totalDim);
        
        logAddition adder;
        
        while(!(adder.initialized)) {
            for(int j=0; j<totalDim; ++j) {
                x[j] = rand()/(double)RAND_MAX*(xu[j]-xl[j]);
            }
            double logEval = this->logEvaluation(x);
            adder.initLogValue(logEval);
        }
        
        double currentAns = 0.0;
        for(long i=0; i<numbCalls; ++i) {
            
            for(int j=0; j<totalDim; ++j) {
                x[j] = rand()/(double)RAND_MAX*(xu[j]-xl[j]);
            }
            
            double logEval = this->logEvaluation(x);
            adder.addLogTerm(logEval);
            
            
            if(i%5000 == 0) {
                currentAns = log_volume + adder.getSum() - log(i+1);
                cout << "\ni: " << i << endl;
                cout << "Adder sum is: " << adder.getSum() << endl;
                cout << "Approximated log integral: " << currentAns << endl;
                cout << "Approximated integral: " << exp(currentAns) << endl;
            }
        }
        
        currentAns = log_volume + adder.getSum() - log(numbCalls);
        double variance = -1.0;
        
        cout << "\n-----------\nApproximated log integral: " << currentAns << endl;
        cout << "Approximated integral: " << exp(currentAns) << endl;
        cout << "Approximated variance: " << variance << endl;

        for(auto p_it=this->allPeople.begin(); p_it!=this->allPeople.end(); ++p_it) {            
            if((*p_it)->dontInclude) {
                cout << "Had a contradiction with person " << (*p_it)->_id << endl;
            }
        }
        
        
        
        return 0.0;
    }
    
    
};

using namespace std;

int main() {
    
    
    srand(12934867);
    
    vector<vector<vector<double>>> g = {
        {
            {1.0,0.5,0.0},
            {0.5,0.25,0.0},
            {0.0,0.0,0.0}
        },
        {
            {0.0,0.5,1.0},
            {0.5,0.5,0.5},
            {1.0,0.5,0.0}
        },
        {
            {0.0,0.0,0.0},
            {0.0,0.25,0.5},
            {0.0,0.5,1.0}
        }
    };
    
    
    // personClass a(0,                  // id
    //               nullptr,            // parentA
    //               nullptr,            // parentB
    //               true,               // isRoot
    //               0.0,                // t
    //               0.0,                // probability
    //               2,                  // m
    //               3,                  // n
    //               vector<double>(3),  // probs
    //               false,              // updated
    //               g);                 // g
    
    // personClass b(1,                  // id
    //               nullptr,            // parentA
    //               nullptr,            // parentB
    //               true,               // isRoot
    //               1.0,                // t
    //               0.0,                // probability
    //               2,                  // m
    //               3,                  // n
    //               vector<double>(3),  // probs
    //               false,              // updated
    //               g);                 // g
    
    // personClass c(2,                  // id
    //               &a,                 // parentA
    //               &b,                 // parentB
    //               false,              // isRoot
    //               1.0,                // t
    //               0.0,                // probability
    //               2,                  // m
    //               3,                  // n
    //               vector<double>(3),  // probs
    //               false,              // updated
    //               g);                 // g
    
    // personClass d(3,                  // id
    //               nullptr,            // parentA
    //               nullptr,            // parentB
    //               true,               // isRoot
    //               0.0,                // t
    //               0.0,                // probability
    //               2,                  // m
    //               3,                  // n
    //               vector<double>(3),  // probs
    //               false,              // updated
    //               g);                 // g
    
    // personClass e(4,                  // id
    //               &c,                 // parentA
    //               &d,                 // parentB
    //               false,              // isRoot
    //               0.0,                // t
    //               0.0,                // probability
    //               2,                  // m
    //               3,                  // n
    //               vector<double>(3),  // probs
    //               false,              // updated
    //               g);                 // g



    personClass x_1(1, nullptr, nullptr, true, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x_2(2, nullptr, nullptr, true, 1.0, 0.0,2,3,vector<double>(3),false,g);
personClass x_21(21, nullptr, nullptr, true, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x_22(22, nullptr, nullptr, true, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x__1(-1, nullptr, nullptr, true, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x__4(-4, nullptr, nullptr, true, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x__10(-10, nullptr, nullptr, true, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x__13(-13, nullptr, nullptr, true, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x__16(-16, nullptr, nullptr, true, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x__19(-19, nullptr, nullptr, true, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x__23(-23, nullptr, nullptr, true, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x__27(-27, nullptr, nullptr, true, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x__31(-31, nullptr, nullptr, true, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x__34(-34, nullptr, nullptr, true, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x__37(-37, nullptr, nullptr, true, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x__40(-40, nullptr, nullptr, true, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x__7(-7, nullptr, nullptr, true, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x__43(-43, nullptr, nullptr, true, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x__46(-46, nullptr, nullptr, true, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x__49(-49, nullptr, nullptr, true, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x__53(-53, nullptr, nullptr, true, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x__74(-74, nullptr, nullptr, true, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x_3(3, &x_1, &x_2, false, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x_4(4, &x_1, &x_2, false, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x_5(5, &x_1, &x_2, false, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x_6(6, &x_1, &x_2, false, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x_7(7, &x_1, &x_2, false, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x_8(8, &x_1, &x_2, false, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x_9(9, &x_1, &x_2, false, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x_10(10, &x_1, &x_2, false, 1.0, 0.0,2,3,vector<double>(3),false,g);
personClass x_11(11, &x_1, &x_2, false, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x_12(12, &x_1, &x_2, false, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x_13(13, &x_1, &x_2, false, 1.0, 0.0,2,3,vector<double>(3),false,g);
personClass x_14(14, &x_22, &x_21, false, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x_15(15, &x_22, &x_21, false, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x_16(16, &x_22, &x_21, false, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x_17(17, &x_22, &x_21, false, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x_18(18, &x_22, &x_21, false, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x_19(19, &x_22, &x_21, false, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x_20(20, &x_22, &x_21, false, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x_32(32, &x_1, &x_2, false, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x_33(33, &x_3, &x__1, false, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x_34(34, &x_4, &x__4, false, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x_35(35, &x_32, &x__7, false, 1.0, 0.0,2,3,vector<double>(3),false,g);
personClass x_36(36, &x_5, &x__10, false, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x_37(37, &x_6, &x__13, false, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x_38(38, &x_7, &x__16, false, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x_39(39, &x_9, &x__19, false, 1.0, 0.0,2,3,vector<double>(3),false,g);
personClass x_40(40, &x_12, &x__23, false, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x_41(41, &x_13, &x_14, false, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x_42(42, &x_13, &x_14, false, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x_43(43, &x_13, &x_14, false, 1.0, 0.0,2,3,vector<double>(3),false,g);
personClass x_44(44, &x_13, &x_14, false, 1.0, 0.0,2,3,vector<double>(3),false,g);
personClass x_45(45, &x_13, &x_14, false, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x_46(46, &x_16, &x__27, false, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x_47(47, &x_17, &x__31, false, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x_48(48, &x_18, &x__34, false, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x_49(49, &x_19, &x__37, false, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x_50(50, &x_20, &x__40, false, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x_51(51, &x_41, &x__43, false, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x_52(52, &x_42, &x__46, false, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x_53(53, &x_43, &x__49, false, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x_54(54, &x_43, &x__49, false, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x_55(55, &x_43, &x__49, false, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x_56(56, &x_43, &x__49, false, 1.0, 0.0,2,3,vector<double>(3),false,g);
personClass x_57(57, &x_44, &x__53, false, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x_58(58, &x_44, &x__53, false, 0.0, 0.0,2,3,vector<double>(3),false,g);
personClass x_602(602, &x_56, &x__74, false, 0.0, 0.0,2,3,vector<double>(3),false,g);

    
    
    pedigreeClass2 pedigree;
    // pedigree.allPeople=vector<personClass*>({&a,&b,&c,&d,&e});
    // pedigree.roots=vector<personClass*>({&a,&b,&d});

    pedigree.allPeople=vector<personClass*>({&x_1,&x_2,&x_21,&x_22,&x__1,&x__4,&x__10,&x__13,&x__16,&x__19,&x__23,&x__27,&x__31,&x__34,
&x__37,&x__40,&x__7,&x__43,&x__46,&x__49,&x__53,&x__74,&x_3,&x_4,&x_5,&x_6,&x_7,&x_8,&x_9,&x_10,&x_11,&x_12,&x_13,&x_14,&x_15,&x_16,
&x_17,&x_18,&x_19,&x_20,&x_32,&x_33,&x_34,&x_35,&x_36,&x_37,&x_38,&x_39,&x_40,&x_41,&x_42,&x_43,&x_44,&x_45,&x_46,&x_47,&x_48,&x_49,
&x_50,&x_51,&x_52,&x_53,&x_54,&x_55,&x_56,&x_57,&x_58,&x_602});

pedigree.roots=vector<personClass*>({&x_1,&x_2,&x_21,&x_22,&x__1,&x__4,&x__10,&x__13,&x__16,&x__19,&x__23,&x__27,&x__31,&x__34,&x__37,
&x__40,&x__7,&x__43,&x__46,&x__49,&x__53,&x__74});


    pedigree.naiveMonteCarlo(1000000);
    
    cout << "\n\n ============================ \n\n" << endl;
    
    // pedigreeClass pedigree_non_log;
    // pedigree_non_log.allPeople=vector<personClass*>({&a,&b,&c,&d,&e});
    // pedigree_non_log.roots=vector<personClass*>({&a,&b,&d});
    // pedigree_non_log.calcIntegral(100000);
    return 1;
}


