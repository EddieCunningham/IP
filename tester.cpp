#include "logProbabilityIP.cpp"

using namespace std;

double pedigreeClass2::differentPDF(const vector<double> & x) {
    
    for(auto p_it=this->allPeople.begin(); p_it!=this->allPeople.end(); ++p_it) {
        (*p_it)->updated = false;
        (*p_it)->dontInclude = false;
    }
    
    // still need to integrate using spherical coordinates!!
    int index = 0;
    double log_extraSines = 0.0;
    
    string ess = "";
    
    if(MY_DEBUG) {
        cout << "\n\n\n~~~~~~~~~~~~~~ NEW EVAL ~~~~~~~~~~~~~~" << endl;
    }
    
    vector<double> sphericalParameters(x.size());

    vector<double> rootProbabilities = vector<double>();
    
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


        // calculate the integral part
        rootProbabilities.push_back((*r_it)->probability);
    }
    
    if(MY_DEBUG) {
        cout << "\n========================================" << endl;
        for(auto p_it=this->allPeople.begin(); p_it!=this->allPeople.end(); ++p_it) {
            
            cout << "LINE: " << __LINE__ << endl;
            (*p_it)->toString();
        }
        cout << "----------------------------------------" << endl;
    }


    int indexMax = -1;
    double maxVal = -1.0;
    for(int i=0; i<rootProbabilities.size(); ++i) {

        double val = rootProbabilities.at(i);
        if(val > maxVal) {
            indexMax = i;
            maxVal = val;
        }
    }

    double K = 3.0;

    double log_integralPart = 0.0;
    for(int i=0; i<this->roots.size(); ++i) {

        if(i == indexMax) {
            log_integralPart += -K*(1.0-this->roots.at(i)->probability);
        }
        else {
            log_integralPart += -K*this->roots.at(i)->probability;
        }
    }

    return log_integralPart+log_extraSines;
}


vector<double> pedigreeClass2::testerMonteCarlo(long numbCalls, bool printIterations, bool printPeople) {
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
        double logEval = this->differentPDF(x);
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
