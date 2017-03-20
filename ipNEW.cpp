// g++ -I /usr/local/include -L/usr/local/lib ipNEW.cpp -lgmpxx -lgmp -lgsl -std=c++11

#include "ipNEW.h"
#include <stdlib.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_monte.h>
#include <gsl/gsl_monte_plain.h>
#include <gsl/gsl_monte_miser.h>
#include <gsl/gsl_monte_vegas.h>

namespace std {

    void Person::storeProbAndNormalize() {

        // cout << "LINE: " << __LINE__ << endl;
        // this->toString();


        double t = this->t;
        double m = this->m;
        double n = this->n;

        double probability = 0.0;
        for(int i=0; i<m; ++i) {
            probability += this->probs[i];
        }
        this->probability = probability;

        double sumOther = 0.0;
        for(int i=m; i<n; ++i) {
            sumOther += this->probs[i];
        }

        // cout << "THE PROBABILITY IS: " << probability << endl;
        // cout << "sumOther IS: " << sumOther << endl;


        if(abs(this->probability) < pow(10,-10) and t == 1.0) {
            cout << "LINE: " << __LINE__ << endl;
            this->toString();
            cout << "CONTRADICTION!  probability was: " << this->probability << endl;
            assert(0);
        }
        if(abs(sumOther) < pow(10,-10) and t == 0.0) {
            cout << "LINE: " << __LINE__ << endl;
            this->toString();
            cout << "CONTRADICTION!  sumOther was: " << sumOther << endl;
            assert(0);
        }


        for(int i=0; i<m; ++i) {
            if(abs(this->probability) < pow(10,-10)) {
                this->probs[i] = 0.0;
            }
            else {
                this->probs[i] *= t/this->probability;
            }
        }
        for(int i=m; i<n; ++i) {
            if(abs(sumOther) < pow(10,-10)) {
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
        if(abs(totalSum-1.0) > pow(10,-10)) {
            cout << "Total sum wasn't 1!  It was " << totalSum << endl;
            string a;
            cin >> a;
            for(int i=0; i<this->probs.size(); ++i) {
                this->probs[i] /= totalSum;
            }
        }
    }

    double Pedigree::getNormVal(Person *p, int index) {

        if(p->updated) {
            return p->probs.at(index);
        }

        updateProbs(p);
        return p->probs.at(index);
    }

    // will place the normalized val in the
    void Pedigree::updateProbs(Person* c) {

        if(c->updated) {
            return;
        }

        double t = c->t;
        double m = c->m;
        double n = c->n;
        vector<vector<vector<double>>>& g = c->g;
        Person* p = c->parentA;
        Person* q = c->parentB;

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

        cout << "LINE: " << __LINE__ << endl;
        c->toString();
    }

    mpf_class Pedigree::getProbability() {
        mpf_class totalAns = 1.0;

        for(auto p_it=this->allPeople.begin(); p_it!=this->allPeople.end(); ++p_it) {
            updateProbs(*p_it);
            double t = (*p_it)->t;
            double prob = (*p_it)->probability;
            double probOfShading = t*prob + (1-t)*(1-prob);
            totalAns *= probOfShading;
        }

        return totalAns;
    }

    void Pedigree::initializeRandomEval() {
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

        for(auto p_it=this->allPeople.begin(); p_it!=this->allPeople.end(); ++p_it) {

            cout << "LINE: " << __LINE__ << endl;
            (*p_it)->toString();
        }
        cout << "----------------------------------------" << endl;

    }

    mpf_class Pedigree::randomEvaluation() {
        this->initializeRandomEval();
        return this->getProbability();
    }

    double Pedigree::evaluate(double x[], size_t dim, void* p) {

        // need to make the update values for the roots 1 and non roots 0
        for(auto p_it=this->allPeople.begin(); p_it!=this->allPeople.end(); ++p_it) {
            (*p_it)->updated = false;
        }

        // still need to integrate using spherical coordinates!!
        int index = 0;
        for(auto r_it=this->roots.begin(); r_it!=this->roots.end(); ++r_it) {

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
                for(int j=0; j<i; ++j) {
                    double phi = sphericalParameters.at(i);
                    value *= cos()
                }


                double randomChoice = x[index++];
                probs[i] = randomChoice;
                total += randomChoice;
            }

            for(int i=0; i<probs.size(); ++i) {

                probs[i] /= total;
            }

            (*r_it)->storeProbAndNormalize();
            (*r_it)->updated = true;
        }
    }

    double Pedigree::calcIntegral() {

        struct my_f_params params = {};

        int totalDim = 0;
        for(int i=0; i<this->roots.size(); ++i) {
            totalDim += this->roots[i].n;
        }

        gsl_monte_function F {
            .f = &this->evaluate,
            .dim = totalDim,
            .params = &params
        };

        double xl[3] = { 0, 0, 0 };
        double xu[3] = { M_PI, M_PI, M_PI };

        const gsl_rng_type *T;
        gsl_rng *r;

        size_t calls = 500000;

        gsl_rng_env_setup ();

    }

};

using namespace std;

int main() {

    srand(12433);

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

    Person a = {
                .parentA=nullptr,
                .parentB=nullptr,
                .isRoot=true,
                .t=0.0,
                .m=2,
                .n=3,
                .probs=vector<double>(3),
                .updated=false,
                .g=g
                };

    Person b = {
                .parentA=nullptr,
                .parentB=nullptr,
                .isRoot=true,
                .t=1.0,
                .m=2,
                .n=3,
                .probs=vector<double>(3),
                .updated=false,
                .g=g
                };

    Person c = {
                .parentA=&a,
                .parentB=&b,
                .isRoot=false,
                .t=1.0,
                .m=2,
                .n=3,
                .probs=vector<double>(3),
                .updated=false,
                .g=g
                };

    Pedigree pedigree = {
        .allPeople=vector<Person*>({&a,&b,&c}),
        .roots=vector<Person*>({&a,&b})
    };

    cout << pedigree.randomEvaluation() << endl;

    return 1;
}


