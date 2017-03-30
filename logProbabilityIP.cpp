// g++ logProbabilityIP.cpp -O3 -std=c++11

#include "logProbabilityIP.h"


#define MY_DEBUG false
#define PRINT_WORK true

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

    int sgn(double val) {
        if(val == 0) {
            return 0;
        }
        else if(val < 0) {
            return -1;
        }
        else {
            return 1;
        }
    }


    double __accumulatePositive(double log_x, double log_y) {
        return log_x + log1p(exp(log_y - log_x));
    }
    
    double __accumulateNegative(double log_x, double log_y) {
        return log_x + log1p(-exp(log_y - log_x));
    }
    
    struct logAddition {
        double log_ans = __DBL_MAX__;
        bool needToInitialize = true;
        
        void _accumulatePositive(double log_x) {
            this->log_ans = __accumulatePositive(this->log_ans, log_x);
        }
        
        void _accumulateNegative(double log_x) {
            this->log_ans = __accumulateNegative(this->log_ans, log_x);
        }
        
        void _addPoint(int sign, double log_x) {
            if(this->needToInitialize) {
                if(sign == 0) {
                    return;
                }
                this->log_ans = log_x;
                this->needToInitialize = false;
            }
            else if(sign == -1) {
                this->_accumulateNegative(log_x);
            }
            else if(sign == 1){
                this->_accumulatePositive(log_x);
            }
            else {
                return;
            }
        }
        
        void addPositiveLogPoint(double log_x) {
            this->_addPoint(1,log_x);
        }
        void addNegativeLogPoint(double log_x) {
            this->_addPoint(-1,log_x);
        }
        void addZeroPoint() {
            return;
        }
        void addPoint(double x) {
            if(x == 0) {
                return;
            }
            this->_addPoint(sgn(x),log(abs(x)));
        }
    };
    
    struct logVariance {
        int sign_avg = 0;
        double log_x_avg = 0.0;
        double log_m = __DBL_MAX__;
        double log_var = __DBL_MAX__;
        int n = 0;
        
        void _avgIsZero(int sign, double log_x) {
            this->sign_avg = sign;
            if(sign != 0) {
                this->log_x_avg = log_x - log(this->n);
            }
        }
        
        void _updateAvg(int sign, double log_x) {
            
            if(this->sign_avg == 0) {
                this->_avgIsZero(sign,log_x);
                return;
            }
            
            double log_p1 = log(1.0-1.0/this->n) + this->log_x_avg;
            double log_p2 = log_x - log(this->n);
            
            if(sign == 0) {
                this->log_x_avg = log_p1;
            }
            else if(sign == this->sign_avg) {
                this->log_x_avg = __accumulatePositive(log_p1,log_p2);
            }
            else {
                if(log_p1 > log_p2) {
                    this->log_x_avg = __accumulateNegative(log_p1,log_p2);
                }
                else if(log_p1 < log_p2) {
                    this->log_x_avg = __accumulateNegative(log_p2,log_p1);
                    this->sign_avg = sign;
                }
                else {
                    this->log_x_avg = __DBL_MAX__;
                    this->sign_avg = 0;
                }
            }
        }
        
        void _updateM(int sign, double log_x, int old_sign_avg, double old_log_x_avg) {
            
            if(this->n == 1) {
                return;
            }
            double log_p1 = sign == 0 ? __DBL_MAX__ : 2*log_x;
            double log_p2 = sign*this->sign_avg == 0 ? __DBL_MAX__ : log_x + this->log_x_avg;
            double log_p3 = sign*old_sign_avg == 0 ? __DBL_MAX__ : log_x + old_log_x_avg;
            double log_p4 = old_sign_avg*this->sign_avg == 0 ? __DBL_MAX__ : this->log_x_avg + old_log_x_avg;
            
            bool log_m_has_val = false;
            
            if(this->n > 2 && this->log_m != __DBL_MAX__) {
                if(sign != 0) {
                    this->log_m = __accumulatePositive(this->log_m,log_p1);
                    log_m_has_val = true;
                }
            }
            else {
                if(sign != 0) {
                    this->log_m = log_p1;
                    log_m_has_val = true;
                }
            }
            
            /* ------------- */
            
            if(log_m_has_val == false) {
                if(this->sign_avg*old_sign_avg != 0) {
                    if(this->log_m != __DBL_MAX__) {
                        this->log_m = __accumulatePositive(this->log_m,log_p4);
                    }
                    else {
                        this->log_m = log_p4;
                    }
                }
                else {
                    return;
                }
            }
            else if(this->sign_avg*old_sign_avg == 1) {
                this->log_m = __accumulatePositive(this->log_m,log_p4);
            }
            else if(this->sign_avg*old_sign_avg == -1) {
                this->log_m = __accumulateNegative(this->log_m,log_p4);
            }
            
            /* ------------- */
            
            if(sign*this->sign_avg == -1) {
                this->log_m = __accumulatePositive(this->log_m,log_p2);
            }
            else if(sign*this->sign_avg == 1) {
                this->log_m = __accumulateNegative(this->log_m,log_p2);
            }
            
            /* ------------- */
            
            if(sign*old_sign_avg == -1) {
                this->log_m = __accumulatePositive(this->log_m,log_p3);
            }
            else if(sign*old_sign_avg == 1) {
                this->log_m = __accumulateNegative(this->log_m,log_p3);
            }
        }
        
        void _addPoint(int sign, double log_x) {
            this->n += 1;
            double old_log_x_avg = this->log_x_avg;
            int old_sign_avg = this->sign_avg;
            this->_updateAvg(sign,log_x);
            this->_updateM(sign,log_x,old_sign_avg,old_log_x_avg);
            if(this->n > 1) {
                this->log_var = this->log_m - log(this->n - 1);
            }
        }
        
        void addPositiveLogPoint(double log_x) {
            this->_addPoint(1,log_x);
        }
        void addNegativeLogPoint(double log_x) {
            this->_addPoint(-1,log_x);
        }
        void addZeroPoint() {
            this->_addPoint(0,__DBL_MAX__);
        }
        void addPoint(double x) {
            if(x == 0) {
                this->_addPoint(0,__DBL_MAX__);
                return;
            }
            this->_addPoint(sgn(x),log(abs(x)));
        }
        
        double getLogStdev() {
            return this->log_var*0.5;
        }
        
    };
    
    
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
                    return __DBL_MAX__;
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
                    return __DBL_MAX__;
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
                return __DBL_MAX__;
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
        if(log_prob == __DBL_MAX__) {
            return __DBL_MAX__;
        }
        return log_prob+log_extraSines+log_normalizingPart;
    }
    
    
    vector<double> pedigreeClass2::naiveMonteCarlo(long numbCalls, bool printIterations, bool printPeople) {
        if(printPeople) {
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
        logVariance variance;
        
        double currentAns = 0.0;
        double currentStdev = 0.0;
        for(long i=0; i<numbCalls; ++i) {
            
            for(int j=0; j<totalDim; ++j) {
                x[j] = rand()/(double)RAND_MAX*(xu[j]-xl[j]);
            }
            double logEval = this->logEvaluation(x);
            if(logEval == __DBL_MAX__) {
                adder.addZeroPoint();
                variance.addZeroPoint();
            }
            else {
                adder.addPositiveLogPoint(logEval);
                variance.addPositiveLogPoint(logEval);
            }
            
            if(printIterations) {
                if(i%5000 == 0 && i>0) {
                    
                    currentAns = log_volume + adder.log_ans - log(i+1);
                     currentStdev = log_volume + variance.getLogStdev() - 0.5*log(i+1);
                    cout << "\n\ni: " << i << endl;
                    cout << "Approximated log integral: " << currentAns << endl;
                    cout << "Current log standard deviation: " << currentStdev << endl;
                    cout << "\nApproximated integral: " << exp(currentAns) << endl;
                    cout << "Current log standard deviation: " << exp(currentStdev) << endl;
                }
            }
        }
        
        currentAns = log_volume + adder.log_ans - log(numbCalls);
        currentStdev = log_volume + variance.getLogStdev() - 0.5*log(numbCalls);
        
        if(printIterations) {
            cout << "\n-----------\nApproximated log integral: " << currentAns << endl;
            cout << "Current log standard deviation: " << currentStdev << endl;
            cout << "Approximated integral: " << exp(currentAns) << endl;
            cout << "Approximated variance: " << exp(currentStdev) << endl;
        }

        double contradictionFlag = 0;
        for(auto p_it=this->allPeople.begin(); p_it!=this->allPeople.end(); ++p_it) {            
            if((*p_it)->dontInclude) {
                if(true) {
                    cout << "Had a contradiction with person " << (*p_it)->_id << endl;
                }
                contradictionFlag = 1;
            }
        }
        
        return vector<double>({contradictionFlag,currentAns,currentStdev});
    }
    
    
};

using namespace std;


struct variance_adder {
    double x_avg = 0.0;
    double m = 0.0;
    double var = 0.0;
    int n = 0;

    void addPoint(double x) {
        n += 1;
        double delta = x - x_avg;
        x_avg += delta/n;
        double delta2 = x - x_avg;
        m += delta*delta2;
        if(n > 1) {
            var = m/(n-1);
        }
    }
};




int main() {

    /*
    vector<double> vals({0,0,0,0,0,0,0,0,0,-1,1});
    
    variance_adder a;
    logVariance b;
    
    for(int i=0; i<vals.size(); ++i) {

        double x = vals.at(i);
        a.addPoint(x);
        b.addPoint(x);
        
        cout << "\n----------------\n";
        cout << "i: " << i << endl;
        cout << endl;
        cout << "a.x_avg: " << a.x_avg << endl;
        cout << "a.m: " << a.m << endl;
        cout << "a.var: " << a.var << endl;
        cout << endl;
        cout << "exp(b.log_x_avg): " << b.sign_avg*exp(b.log_x_avg) << endl;
        cout << "exp(b.log_m): " << exp(b.log_m) << endl;
        cout << "exp(b.log_var): " << exp(b.log_var) << endl;
        cout << endl;
        cout << "b.log_x_avg: " << b.log_x_avg << endl;
        cout << "b.log_m: " << b.log_m << endl;
        cout << "b.log_var: " << b.log_var << endl;
    }
    return 1;
    */
    
    srand(12934867);
    personClass x_1(1,nullptr,nullptr,true,1.000000,0.000000,2,3,vector<double>(3),false,vector<vector<vector<double>>>({
}));
personClass x_2(2,nullptr,nullptr,true,0.000000,0.000000,2,3,vector<double>(3),false,vector<vector<vector<double>>>({
}));
personClass x_3(3,&x_1,&x_2,false,1.000000,0.000000,2,3,vector<double>(3),false,vector<vector<vector<double>>>({
    {
        {1.000000,0.500000,0.000000},
        {0.500000,0.250000,0.000000},
        {0.000000,0.000000,0.000000}
    },
    {
        {0.000000,0.500000,1.000000},
        {0.500000,0.500000,0.500000},
        {1.000000,0.500000,0.000000}
    },
    {
        {0.000000,0.000000,0.000000},
        {0.000000,0.250000,0.500000},
        {0.000000,0.500000,1.000000}
    }
}));

    
    
    pedigreeClass2 pedigree;
    pedigree.allPeople=vector<personClass*>({&x_1,&x_2,&x_3});
    pedigree.roots=vector<personClass*>({&x_1,&x_2});


    pedigree.naiveMonteCarlo(100000,true,true);
    
    cout << "\n\n ============================ \n\n" << endl;
    
    return 1;
}


