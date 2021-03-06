// g++ -I /usr/local/include -L/usr/local/lib ipImplementation.cpp VEGAS.cpp -lgmpxx -lgmp -lgsl -std=c++11

#include "ipImplementation.h"
#include "VEGAS.h"
#include <stdlib.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_monte.h>
#include <gsl/gsl_monte_plain.h>
#include <gsl/gsl_monte_miser.h>
#include <gsl/gsl_monte_vegas.h>
#include <random>

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

    pedigreeClass* globalPedigree;

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
            assert(this->probs[i] >= 0 and this->probs[i] <= 1.0);
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

    double pedigreeClass::getNormVal(personClass *p, int index) {

        if(p->updated) {
            return p->probs.at(index);
        }

        updateProbs(p);
        return p->probs.at(index);
    }

    // will place the normalized val in the
    void pedigreeClass::updateProbs(personClass* c) {

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

    mpf_class pedigreeClass::getProbability() {
        mpf_class totalAns = 1.0;

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
    
    void pedigreeClass::getProbability2(mpf_class *result) {
        
        for(auto p_it=this->allPeople.begin(); p_it!=this->allPeople.end(); ++p_it) {
            if((*p_it)->dontInclude) {
                if((*p_it)->isRoot) {
                    *result = 0.0;
                    return;
                }
                // cout << "skipping this dude:\n";
                // (*p_it)->toString();
                continue;
            }
            updateProbs(*p_it);
            double t = (*p_it)->t;
            double prob = (*p_it)->probability;
            double probOfShading = t*prob + (1-t)*(1-prob);
            (*result) = (*result)*probOfShading;
        }
    }
    
    double pedigreeClass::getLogProbability() {
        
        double ans = 0.0;
        
        for(auto p_it=this->allPeople.begin(); p_it!=this->allPeople.end(); ++p_it) {
            if((*p_it)->dontInclude) {
                if((*p_it)->isRoot) {
                    return 0.0;
                }
                // cout << "skipping this dude:\n";
                // (*p_it)->toString();
                continue;
            }
            updateProbs(*p_it);
            double t = (*p_it)->t;
            double prob = (*p_it)->probability;
            double probOfShading = t*prob + (1-t)*(1-prob);
            ans += log(probOfShading);
        }
        return ans;
    }

    void pedigreeClass::initializeRandomEval() {
        // need to make the update values for the roots 1 and non roots 0
        for(auto p_it=this->allPeople.begin(); p_it!=this->allPeople.end(); ++p_it) {
            (*p_it)->updated = false;
        }

        for(auto r_it=this->roots.begin(); r_it!=this->roots.end(); ++r_it) {

            // MAKE SURE THAT THIS IS A TRULY RANDOM WAY TO ASSIGN THE ROOT PROBS!!!!!!!!!!
            vector<double>& probs = (*r_it)->probs;
            double total = 0.0;
            for(int i=0; i<probs.size(); ++i) {
                double randomChoice = rand()/(double)RAND_MAX;
                probs[i] = randomChoice;
                total += randomChoice;
            }
            for(int i=0; i<probs.size(); ++i) {
                probs[i] /= total;
            }

            (*r_it)->storeProbAndNormalize();
            (*r_it)->updated = true;
        }

        // for(auto p_it=this->allPeople.begin(); p_it!=this->allPeople.end(); ++p_it) {

        //     cout << "LINE: " << __LINE__ << endl;
        //     (*p_it)->toString();
        // }
        // cout << "----------------------------------------" << endl;
    }

    mpf_class pedigreeClass::randomEvaluationGMP() {
        this->initializeRandomEval();
        return this->getProbability();
    }

    double pedigreeClass::randomEvaluation() {
        this->initializeRandomEval();
        double ans = mpf_get_d(this->getProbability().get_mpf_t());
        // for(auto p_it=this->allPeople.begin(); p_it!=this->allPeople.end(); ++p_it) {

        //     cout << "LINE: " << __LINE__ << endl;
        //     (*p_it)->toString();
        // }
        // cout << "----------------------------------------" << endl;

        return ans;
    }



    double evaluate(double x[], size_t dim, void* p) {

        (void)(dim);
        (void)(p);

        // each root has n-1 parameters in x
        // integration terms are {[0,pi],[0,pi],.....,[0,2*pi]} for each root

        // need to make the update values for the roots 1 and non roots 0
        for(auto p_it=globalPedigree->allPeople.begin(); p_it!=globalPedigree->allPeople.end(); ++p_it) {
            (*p_it)->updated = false;
        }

        // still need to integrate using spherical coordinates!!
        int index = 0;
        double extraSines = 1.0;
        double normalizingPart = 1.0;

        string ess = "";

        if(MY_DEBUG) {
            cout << "\n\n\n~~~~~~~~~~~~~~ NEW EVAL ~~~~~~~~~~~~~~" << endl;
        }

        for(auto r_it=globalPedigree->roots.begin(); r_it!=globalPedigree->roots.end(); ++r_it) {

            // get the spherical parameters from x
            int n = (*r_it)->n;
            vector<double> sphericalParameters(n-1);
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
                total += pow(value,2);

                if(i < n-2) {
                    extraSines *= pow(sin(sphericalParameters.at(i)),n-2-i);
                }
            }

            normalizingPart *= tgamma(n/2.0)/pow(M_PI,n/2.0)/2.0;

            if(abs(total-1.0) >= pow(10,-15)) {
                cout << "The total was: " << total << endl;
                assert(0);
            }

            (*r_it)->storeProbAndNormalize();
            (*r_it)->updated = true;
        }

        if(MY_DEBUG) {
            cout << "\n========================================" << endl;
            for(auto p_it=globalPedigree->allPeople.begin(); p_it!=globalPedigree->allPeople.end(); ++p_it) {

                cout << "LINE: " << __LINE__ << endl;
                (*p_it)->toString();
            }
            cout << "----------------------------------------" << endl;
        }

        return mpf_get_d(globalPedigree->getProbability().get_mpf_t())*extraSines*normalizingPart;
    }

    double pedigreeClass::calcIntegral(int numbCalls) {

        if(MY_DEBUG) {
            for(int i=0; i<this->allPeople.size(); ++i) {
                this->allPeople[i]->toString();
            }
        }

        int totalDim = 0;
        for(int i=0; i<this->roots.size(); ++i) {
            totalDim += this->roots[i]->n-1;
        }

        globalPedigree = this;

        gsl_monte_function F {
            .f = &(evaluate),
            .dim = (size_t)totalDim,
            .params = 0
        };

        double res, err;
        double xl[totalDim];
        double xu[totalDim];
        int index = 0;
        for(int i=0; i<this->roots.size(); ++i) {

            int n = this->roots[i]->n;

            for(int j=0; j<n-2; ++j) {
                xl[index+j] = 0;
                xu[index+j] = M_PI;
            }
            xl[index+n-2] = 0;
            xu[index+n-2] = 2*M_PI;
            index += n-1;
        }

        const gsl_rng_type *T;
        gsl_rng *r;
        size_t callsPerIteration = numbCalls;
        gsl_rng_env_setup();
        T = gsl_rng_default;
        r = gsl_rng_alloc(T);

        gsl_monte_vegas_state *s = gsl_monte_vegas_alloc(totalDim);
        gsl_monte_vegas_integrate(&F, xl, xu, totalDim, 5000, r, s, &res, &err);
        do {
            gsl_monte_vegas_integrate(&F, xl, xu, totalDim, callsPerIteration, r, s, &res, &err);
            printf("result = % .6f sigma = % .6f chisq/dof = %.1f\n", res, err, gsl_monte_vegas_chisq(s));
        }
        while(fabs(gsl_monte_vegas_chisq(s)-1.0) > 0.5);
        gsl_monte_vegas_free(s);

        return res;
    }

    float evaluate2(const vector<float> & x, float wgt) {

        // cout << "THE PARAMETERS ARE:" << endl;
        // for(int i=0; i<6; ++i) {
        //     cout << "x[" << i << "]: " << x[i] << endl;
        // }

        (void)wgt;

        // each root has n-1 parameters in x
        // integration terms are {[0,pi],[0,pi],.....,[0,2*pi]} for each root

        // need to make the update values for the roots 1 and non roots 0
        for(auto p_it=globalPedigree->allPeople.begin(); p_it!=globalPedigree->allPeople.end(); ++p_it) {
            (*p_it)->updated = false;
        }

        // still need to integrate using spherical coordinates!!
        int index = 0;
        double extraSines = 1.0;
        double normalizingPart = 1.0;

        string ess = "";

        if(MY_DEBUG) {
            cout << "\n\n\n~~~~~~~~~~~~~~ NEW EVAL ~~~~~~~~~~~~~~" << endl;
        }

        for(auto r_it=globalPedigree->roots.begin(); r_it!=globalPedigree->roots.end(); ++r_it) {

            // get the spherical parameters from x
            int n = (*r_it)->n;
            vector<double> sphericalParameters(n-1);
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
                assert(probs[i] <= 1.0 && probs[i] >= 0);
                total += pow(value,2);

                if(i < n-2) {
                    extraSines *= pow(sin(sphericalParameters.at(i)),n-2-i);
                }
            }

            normalizingPart *= tgamma(n/2.0)/pow(M_PI,n/2.0)/2.0;

            if(abs(total-1.0) >= pow(10,-15)) {
                cout << "The total was: " << total << endl;
                assert(0);
            }
            
            (*r_it)->storeProbAndNormalize();
            if((*r_it)->dontInclude) {
                return 0.0;
            }
            assert((*r_it)->probability <= 1.0 and (*r_it)->probability >= 0.0);
            (*r_it)->updated = true;
        }

        if(MY_DEBUG) {
            cout << "\n========================================" << endl;
            for(auto p_it=globalPedigree->allPeople.begin(); p_it!=globalPedigree->allPeople.end(); ++p_it) {

                cout << "LINE: " << __LINE__ << endl;
                (*p_it)->toString();
            }
            cout << "----------------------------------------" << endl;
        }

        return mpf_get_d(globalPedigree->getProbability().get_mpf_t())*extraSines*normalizingPart;
    }


    double pedigreeClass::calcIntegral2(int numbCalls) {

        if(MY_DEBUG) {
            for(int i=0; i<this->allPeople.size(); ++i) {
                this->allPeople[i]->toString();
            }
        }

        int ndim = 0;
        for(int i=0; i<this->roots.size(); ++i) {
            ndim += this->roots[i]->n-1;
        }

        globalPedigree = this;

        float regn[ndim*2];
        int index = 0;
        for(int i=0; i<this->roots.size(); ++i) {

            int n = this->roots[i]->n;

            for(int j=0; j<n-2; ++j) {
                regn[index+j] = 0;
                regn[ndim + index+j] = M_PI;
            }
            regn[index+n-2] = 0;
            regn[ndim + index+n-2] = 2*M_PI;
            index += n-1;
        }

        int init = 0;
        unsigned long ncall = 1000;
        int itmx = 10;
        int nprn = 0;
        float tgral;
        float sd;
        float chi2a;

        vegas(regn,ndim,&evaluate2,init,ncall,itmx,nprn,&tgral,&sd,&chi2a);

        return tgral;
    }

    void evaluate3(const vector<double> & x, mpf_class *result) {

        // cout << "THE PARAMETERS ARE:" << endl;
        // for(int i=0; i<6; ++i) {
        //     cout << "x[" << i << "]: " << x[i] << endl;
        // }

        // each root has n-1 parameters in x
        // integration terms are {[0,pi],[0,pi],.....,[0,2*pi]} for each root

        // need to make the update values for the roots 1 and non roots 0
        for(auto p_it=globalPedigree->allPeople.begin(); p_it!=globalPedigree->allPeople.end(); ++p_it) {
            (*p_it)->updated = false;
        }

        // still need to integrate using spherical coordinates!!
        int index = 0;
        double extraSines = 1.0;
        double normalizingPart = 1.0;

        string ess = "";

        if(MY_DEBUG) {
            cout << "\n\n\n~~~~~~~~~~~~~~ NEW EVAL ~~~~~~~~~~~~~~" << endl;
        }
        
        vector<double> sphericalParameters(x.size());

        for(auto r_it=globalPedigree->roots.begin(); r_it!=globalPedigree->roots.end(); ++r_it) {

            // get the spherical parameters from x
            int n = (*r_it)->n;
//            vector<double> sphericalParameters(n-1);
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
                assert(probs[i] <= 1.0 && probs[i] >= 0);
                total += pow(value,2);

                if(i < n-2) {
                    extraSines *= pow(sin(sphericalParameters.at(i)),n-2-i);
                }
            }

            normalizingPart *= tgamma(n/2.0)/pow(M_PI,n/2.0)/2.0;

            if(abs(total-1.0) >= pow(10,-15)) {
                cout << "The total was: " << total << endl;
                assert(0);
            }
            
            (*r_it)->storeProbAndNormalize();
            if((*r_it)->dontInclude) {
                return;
            }
            assert((*r_it)->probability <= 1.0 and (*r_it)->probability >= 0.0);
            (*r_it)->updated = true;
        }

        if(MY_DEBUG) {
            cout << "\n========================================" << endl;
            for(auto p_it=globalPedigree->allPeople.begin(); p_it!=globalPedigree->allPeople.end(); ++p_it) {

                cout << "LINE: " << __LINE__ << endl;
                (*p_it)->toString();
            }
            cout << "----------------------------------------" << endl;
        }
        globalPedigree->getProbability2(result);
        (*result) = (*result) * (double)(extraSines*normalizingPart);
    }
    
    
    double pedigreeClass::naiveMonteCarlo(int numbCalls) {
        if(MY_DEBUG) {
            for(int i=0; i<this->allPeople.size(); ++i) {
                this->allPeople[i]->toString();
            }
        }
        
        int totalDim = 0;
        for(int i=0; i<this->roots.size(); ++i) {
            totalDim += this->roots[i]->n-1;
        }
        
        globalPedigree = this;
        
        double xl[totalDim];
        double xu[totalDim];
        int index = 0;
        mpf_class volume = 1.0;
        for(int i=0; i<this->roots.size(); ++i) {
            
            int n = this->roots[i]->n;
            
            for(int j=0; j<n-2; ++j) {
                xl[index+j] = 0;
                xu[index+j] = M_PI;
                volume *= M_PI;
            }
            xl[index+n-2] = 0;
            xu[index+n-2] = 2*M_PI;
            volume *= 2*M_PI;
            index += n-1;
        }

        vector<double> x(totalDim);

        mpf_class sum = 0.0;
        mpf_class sumSquares = 0.0;
        
        mpf_class result = 1.0;
        long int result_precision = result.get_prec();

        for(int i=0; i<numbCalls; ++i) {

            for(int j=0; j<totalDim; ++j) {
                x[i] = rand()/(double)RAND_MAX*(xu[j]-xl[j]);
            }
            
            result = 1.0;
            
            evaluate3(x,&result);
            
            sum = sum + result;
            sumSquares = sumSquares + mpf_class(result*result);
            
            result.set_prec(result_precision);
            
        }

        mpf_class ans = volume*sum/numbCalls;
        mpf_class s2 = volume*volume/numbCalls*sumSquares;
        mpf_class variance = (s2 - ans*ans)/numbCalls;

        cout << "Approximated integral: " << ans << endl;
        cout << "Approximated variance: " << variance << endl;
        
        
        
        return 0.0;
    }


};

using namespace std;

double logAccumulator(double log_x1, double log_x2, double lastValue) {
    return log1p(exp(log_x1-log_x2+lastValue));
}

struct logAddition {
    bool initialized = false;
    double lastF = 0.0;
    double last_log_x = -1;
    
    bool initValue(double firstTerm) {
        if(firstTerm <= 0) {
            return false;
        }
        this->last_log_x = log(firstTerm);
        this->initialized = true;
        return true;
    }
    
    void _addTerm(double log_term) {
        this->lastF = logAccumulator(this->last_log_x, log_term, this->lastF);
        this->last_log_x = log_term;
    }
    
    void addTerm(double term) {
        assert(this->initialized);
        if(term <= 0) {
            return;
        }
        double log_term = log(term);
        this->_addTerm(log_term);
    }
    
    void addLogTerm(double log_term) {
        assert(this->initialized);
        this->_addTerm(log_term);
    }
    
    double getSum() {
        return this->last_log_x + this->lastF;
    }
};
/*
int main() {
    
    
    vector<double> randomNumbers = vector<double>(10000000);
    double trueAns = 0.0;
    for(int i=0; i<randomNumbers.size(); ++i) {
        double randomNumb = pow(rand()/(double)RAND_MAX,20);
        randomNumbers[i] = randomNumb;
        trueAns += randomNumbers.at(i);
    }
    trueAns = log(trueAns);
    
    logAddition adder;
    int i=0;
    while(!(adder.initValue(randomNumbers.at(i++)))){}
    for(;i<randomNumbers.size(); ++i) {
        adder.addTerm(randomNumbers.at(i));
    }
    
    cout << "True ans: " << trueAns << endl;
    cout << "Adder ans: " << adder.getSum() << endl;
    return 1;

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


    personClass a(0,                  // id
                  nullptr,            // parentA
                  nullptr,            // parentB
                  true,               // isRoot
                  0.0,                // t
                  0.0,                // probability
                  2,                  // m
                  3,                  // n
                  vector<double>(3),  // probs
                  false,              // updated
                  g);                 // g

    personClass b(1,                  // id
                  nullptr,            // parentA
                  nullptr,            // parentB
                  true,               // isRoot
                  1.0,                // t
                  0.0,                // probability
                  2,                  // m
                  3,                  // n
                  vector<double>(3),  // probs
                  false,              // updated
                  g);                 // g

    personClass c(2,                  // id
                  &a,                 // parentA
                  &b,                 // parentB
                  false,              // isRoot
                  1.0,                // t
                  0.0,                // probability
                  2,                  // m
                  3,                  // n
                  vector<double>(3),  // probs
                  false,              // updated
                  g);                 // g

    personClass d(3,                  // id
                  nullptr,            // parentA
                  nullptr,            // parentB
                  true,               // isRoot
                  0.0,                // t
                  0.0,                // probability
                  2,                  // m
                  3,                  // n
                  vector<double>(3),  // probs
                  false,              // updated
                  g);                 // g

    personClass e(4,                  // id
                  &c,                 // parentA
                  &d,                 // parentB
                  false,              // isRoot
                  0.0,                // t
                  0.0,                // probability
                  2,                  // m
                  3,                  // n
                  vector<double>(3),  // probs
                  false,              // updated
                  g);                 // g


    pedigreeClass pedigree;
    pedigree.allPeople=vector<personClass*>({&a,&b,&c,&d,&e});
    pedigree.roots=vector<personClass*>({&a,&b,&d});

    // cout << pedigree.randomEvaluation() << endl;


    int totalDim = 0;
    for(int i=0; i<pedigree.roots.size(); ++i) {
        totalDim += pedigree.roots[i]->n;
    }
    double x[totalDim];
    for(int i=0; i<totalDim; ++i) {
        x[i] = 0.5;
    }

    // globalPedigree = &pedigree;
    // cout << pedigree.evaluate(x, totalDim, nullptr) << endl;

    // cout << pedigree.calcIntegral2(10000) << endl;
    pedigree.naiveMonteCarlo(10000);
    return 1;
}


*/
