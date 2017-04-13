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
    int dimension;
    double standardDeviation;
    vector<double> currentState,temp;
    double currentProb;
    gsl_rng *rng;
    gsl_vector *mean;
    gsl_matrix *var;
    gsl_vector *result;
    gsl_matrix *work;

    double (*pdf)(const vector<double> &x);

    sampler(int dimension_, double (*pdf_)(const vector<double> &x)):
    dimension(dimension_),
    pdf(pdf_),
    currentState(dimension_),
    temp(dimension_) {
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

        for(int i=0; i<this->dimension; ++i) {
            this->currentState[i] = gsl_rng_uniform(this->rng);
        }
        this->currentProb = (*(this->pdf))(this->currentState);
    }

    ~sampler() {
        gsl_rng_free(this->rng);
        gsl_vector_free(this->result);
        gsl_vector_free(this->mean);
        gsl_matrix_free(this->var);
        gsl_matrix_free(this->work);
    }

    void rmvnorm(const gsl_rng *r, const int n, const gsl_vector *mean, const gsl_matrix *var, gsl_vector *result) {

        gsl_matrix_memcpy(this->work,this->var);
        gsl_linalg_cholesky_decomp(this->work);
     
        for(int k=0; k<n; k++) {
            gsl_vector_set(result, k, gsl_ran_ugaussian(r));
        }
     
        gsl_blas_dtrmv(CblasLower, CblasNoTrans, CblasNonUnit, work, result);
        gsl_vector_add(result,mean);
    }

    const vector<double>& nextSample() {

        for(int i=0; i<this->dimension; i++) {
            gsl_vector_set(this->mean, i, this->currentState.at(i));
        }

        rmvnorm(this->rng, this->dimension, this->mean, this->var, this->result);

        for(int i=0; i<this->dimension; i++) {
            this->temp[i] = gsl_vector_get(this->result, i);
        }

        double tempProb = (*(this->pdf))(this->temp);
        double randNumb = gsl_rng_uniform(this->rng);
        double accept = tempProb/this->currentProb;
 
        if(randNumb < accept) {
            this->currentState = this->temp;
            this->currentProb = tempProb;
        } 

        return this->currentState;
    }
};