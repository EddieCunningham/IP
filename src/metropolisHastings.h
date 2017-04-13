#ifndef MET_HAST_H
#define MET_HAST_H

#include "logProbIPNew.h"
#include <math.h>
#include <time.h>
#include <vector>
#include <gsl/gsl_sf_gamma.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_blas.h>
#include <gsl/gsl_linalg.h>

using namespace std;

// adapted from https://ysquared2.wordpress.com/2014/03/27/metropolis-hasting-algorithm-an-example-with-cc-and-r/

class sampler {
public:
    int dimension,nAccepted,nSampled;
    double standardDeviation,acceptanceRatio;
    vector<double> currentState,temp,xl,xu;
    double currentProb;
    gsl_rng *rng;
    gsl_vector *mean;
    gsl_matrix *var;
    gsl_vector *result;
    gsl_matrix *work;

    vector<vector<int>> bins;

    pedigreeClass2* pedigree;
    bool initialized;

    sampler(int dimension_, const vector<double>& xl_, const vector<double>& xu_, pedigreeClass2* pedigree_, vector<int> bins_):
    dimension(dimension_),
    nAccepted(0),
    nSampled(0),
    xl(xl_),
    xu(xu_),
    pedigree(pedigree_),
    currentState(dimension_),
    temp(dimension_),
    initialized(false) {

        this->bins = vector<vector<int>>(this->dimension);
        for(int i=0; i<this->bins.size(); ++i) {
            this->bins[i] = vector<int>(bins_.at(i));
        }

        this->standardDeviation = 0.15;

        this->rng = gsl_rng_alloc(gsl_rng_mt19937);
        int seed = 1234;
        gsl_rng_set(this->rng,seed);

        this->mean = gsl_vector_alloc(this->dimension);
        this->var = gsl_matrix_calloc(this->dimension, this->dimension);
        this->result = gsl_vector_alloc(this->dimension);
        
        for(int i=0; i<this->dimension; ++i) {
            gsl_matrix_set(this->var, i, i, pow(this->standardDeviation,2));
        }

        this->work = gsl_matrix_alloc(this->dimension,this->dimension);

        this->initialized = false;  

        gsl_matrix_memcpy(this->work,this->var);
        gsl_linalg_cholesky_decomp(this->work);     

    }

    ~sampler() {
        gsl_rng_free(this->rng);
        gsl_vector_free(this->result);
        gsl_vector_free(this->mean);
        gsl_matrix_free(this->var);
        gsl_matrix_free(this->work);
    }

    void initState(bool useNewDist, double K) {
        for(int i=0; i<this->dimension; ++i) {
            this->currentState[i] = gsl_rng_uniform(this->rng);
        }

        this->currentProb = this->probEval(this->currentState, useNewDist, K);
        this->initialized = true;
    }

    double probEval(const vector<double>& x, bool useNewDist, double K) {
        this->pedigree->logEvaluation(x, useNewDist, K);
        return exp(this->pedigree->log_probRoots);
    }

    void rmvnorm() {
     
        for(int k=0; k<this->dimension; k++) {
            auto randN = gsl_ran_ugaussian(this->rng);
            gsl_vector_set(this->result, k, randN);
        }

        gsl_blas_dtrmv(CblasLower, CblasNoTrans, CblasNonUnit, this->work, this->result);
        gsl_vector_add(this->result,this->mean);
    }

    const pair<vector<double>&,double> _nextSample(bool useNewDist, double K) {
        
        this->nSampled += 1;
        this->acceptanceRatio = (double)this->nAccepted/this->nSampled;

        for(int i=0; i<this->dimension; i++) {
            gsl_vector_set(this->mean, i, this->currentState.at(i));
        }

        rmvnorm();

        for(int i=0; i<this->dimension; i++) {
            this->temp[i] = gsl_vector_get(this->result, i);
            if(this->temp[i] < this->xl[i] or this->temp[i] > this->xu[i]) {
                return pair<vector<double>&,double>(this->currentState,this->currentProb);
            }
        }

        double tempProb = this->probEval(this->temp, useNewDist, K);
        double randNumb = gsl_rng_uniform(this->rng);
        double accept = tempProb/this->currentProb;

        if(randNumb < accept) {
            this->currentState = this->temp;
            this->currentProb = tempProb;
            
            this->nAccepted += 1;
        } 

        return pair<vector<double>&,double>(this->currentState,this->currentProb);
    }

    const pair<vector<double>&,double> nextSample(bool useNewDist, double K) {

        if(!(this->initialized)) {
            cout << "Need to call the initState function" << endl;
            raise(SIGABRT);
        }

        const pair<vector<double>&,double> ans = this->_nextSample(useNewDist,K);
        return ans;
        for(int i=0; i<this->bins.size(); ++i) {

            int minVal = this->xl.at(i);
            int maxVal = this->xu.at(i);
            double x = ans.first.at(i);
            int ngenHistogram = this->bins.at(i).size();

            int binIndex = (int)((x-minVal)*(maxVal-minVal)/(double)ngenHistogram);

            this->bins.at(i)[binIndex] += 1;
        }

        return ans;
    }

    double KLDivergence() {
        // calculate the KL divergence

        for(int i=0; i<this->bins.size(); ++i) {

            double projectionKLDivergence = 0.0;
            for(int j=0; j<this->bins.at(i).size(); ++j) {

                projectionKLDivergence += 0;
            }
        }

        // won't work in high dimensions!
        return 0.0;
    }
};


#endif




/*



    TO EVALUATE THIS, TRY BINNING THE GENERATED VALUES AND 
    THEN CALCULATE THE KL DIVERGENCE 



*/
