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
    vector<double> currentState,temp,xl,xu,averageState;
    double currentProb;
    gsl_rng *rng;
    gsl_vector *mean;
    gsl_matrix *var;
    gsl_vector *result;
    gsl_matrix *work;


    pedigreeClass2* pedigree;
    bool initialized,uniform;

    sampler(int dimension_, const vector<double>& xl_, const vector<double>& xu_, pedigreeClass2* pedigree_, bool uniform_):
    dimension(dimension_),
    nAccepted(0),
    nSampled(0),
    xl(xl_),
    xu(xu_),
    averageState(vector<double>(dimension_,0.0)),
    pedigree(pedigree_),
    currentState(dimension_),
    temp(dimension_),
    initialized(false),
    uniform(uniform_) {

        if(uniform_) {
            return;
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
        if(this->uniform) {
            return;
        }
        gsl_rng_free(this->rng);
        gsl_vector_free(this->result);
        gsl_vector_free(this->mean);
        gsl_matrix_free(this->var);
        gsl_matrix_free(this->work);
    }

    void initState(bool useNewDist, double K) {
        for(int i=0; i<this->dimension; ++i) {
            if(this->uniform) {
                if(this->xu[i] == -1 || this->xl[i] == -1) {
                    this->currentState[i] = -1.0;
                }
                else {
                    this->currentState[i] = rand()/(double)RAND_MAX;
                }
            }
            else {
                this->currentState[i] = gsl_rng_uniform(this->rng);
            }
        }

        this->currentProb = this->probEval(this->currentState, useNewDist, K);
        this->initialized = true;
    }

    double probEval(const vector<double>& x, bool useNewDist, double K) {
        this->pedigree->logEvaluation(x, useNewDist, K, this->uniform);
        return this->pedigree->log_probRoots;
    }

    void rmvnorm() {
     
        for(int k=0; k<this->dimension; k++) {
            auto randN = gsl_ran_ugaussian(this->rng);
            gsl_vector_set(this->result, k, randN);
        }

        gsl_blas_dtrmv(CblasLower, CblasNoTrans, CblasNonUnit, this->work, this->result);
        gsl_vector_add(this->result,this->mean);
    }

    const pair<vector<double>&,double> _uniformSample() {

        for(int i=0; i<this->dimension; ++i) {
            if(this->xu[i] == -1 || this->xl[i] == -1) {
                this->currentState[i] = -1.0;
            }
            else {
                this->currentState[i] = rand()/(double)RAND_MAX*(this->xu[i]-this->xl[i]);
            }
        }
        this->probEval(this->currentState, false, -1);
        return pair<vector<double>&,double>(this->currentState,-1);
    }

    const pair<vector<double>&,double> _nextSample(bool useNewDist, double K) {
        
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

        if(this->nSampled > 0) {
            // update the last average
            for(int i=0; i<this->averageState.size(); ++i) {
                this->averageState.at(i) += (this->currentState.at(i)-this->averageState.at(i))/(double)this->nSampled;
            }
        }

        this->nSampled += 1;

        if(!(this->initialized)) {
            cout << "Need to call the initState function" << endl;
            raise(SIGABRT);
        }

        if(this->uniform) {
            return _uniformSample();
        }
        else {
            return this->_nextSample(useNewDist,K);
        }
    }
};


#endif




/*



    TO EVALUATE THIS, TRY BINNING THE GENERATED VALUES AND 
    THEN CALCULATE THE KL DIVERGENCE 



*/
