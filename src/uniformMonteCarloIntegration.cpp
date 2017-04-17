#include "logProbIPNew.h"

using namespace std;

vector<double> pedigreeClass2::_uniformMonteCarlo(long numbCalls, bool printIterations, int numbToPrint, bool useNewDist, double K, bool useLeak, double leakProb, double leakDecay) {        
    
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

        this->roots[i]->startIndex = 0;
        this->roots[i]->endIndex = n-1;
    }
    try {
        vector<double> x(totalDim);
        
        logAddition integral_adder;
        logVariance integral_variance;

        logAddition volume_adder;
        logVariance volume_variance;
        
        double currentAns = 0.0;
        double currentStdev = 0.0;

        double integralVolume;
        double integralStdev;
        double normalizingVolume;
        double normalizingStdev;


        topK tracker(1000);
        bool printFlag = false;

        const int BREAKHERE = 723968;
        const int PRINTMORE = 722700;

        for(long i=0; i<numbCalls; ++i) {
            
            for(int j=0; j<totalDim; ++j) {
                x[j] = rand()/(double)RAND_MAX*(xu[j]-xl[j]);
            }
            
            if(i == BREAKHERE) {
                int asdfasdf = 0;
            }

            pair<double,double> logEvaluation_x_ = this->logEvaluation(x,useNewDist,K,false);
            double logEval_integral = logEvaluation_x_.first;
            double log_volumeEval = logEvaluation_x_.second;

            if(logEval_integral == __DBL_MAX__) {
                integral_adder.addZeroPoint();
                integral_variance.addZeroPoint();

                volume_adder.addZeroPoint();
                volume_variance.addZeroPoint();
            }
            else {
                integral_adder.addPositiveLogPoint(logEval_integral);
                integral_variance.addPositiveLogPoint(logEval_integral);

                volume_adder.addPositiveLogPoint(log_volumeEval);
                volume_variance.addPositiveLogPoint(log_volumeEval);
            }

            integralVolume = log_volume + integral_adder.log_ans - log(i+1);
            normalizingVolume = log_volume + volume_adder.log_ans - log(i+1);
            currentAns = integralVolume - normalizingVolume;

            tracker.addPoint(currentAns);

            
            if(printIterations) {
                if(i > PRINTMORE) {
                    printFlag = false;
                }
                if((printFlag&&i%100) || (i%numbToPrint == 0 && i>0)) {
                    integralVolume = log_volume + integral_adder.log_ans - log(i+1);
                    integralStdev = log_volume + integral_variance.getLogStdev() - 0.5*log(i+1);
                    
                    normalizingVolume = log_volume + volume_adder.log_ans - log(i+1);
                    normalizingStdev = log_volume + volume_variance.getLogStdev() - 0.5*log(i+1);

                    currentAns = integralVolume - normalizingVolume;
                    // currentStdev = log_volume + integral_variance.getLogStdev() - 0.5*log(i+1);

                    cout << "\n\ni: " << i << endl;
                    cout << "Approximated log integral: " << currentAns << endl;
                    // cout << "Current log standard deviation: " << currentStdev << endl;
                    cout << "\nApproximated integral: " << exp(currentAns) << endl;
                    // cout << "Current log standard deviation: " << exp(currentStdev) << endl;
                }
            }
        }

        tracker.finalSort();
        // cout << "---------------------------\nTHE TOP 1000 VALUES---------------------------" << endl;
        // for(int i=0; i<tracker.vals.size(); ++i) {
        //     cout << tracker.vals.at(i) << " ";
        // }
        // cout << endl << endl << endl;

        integralVolume = log_volume + integral_adder.log_ans - log(numbCalls);
        integralStdev = log_volume + integral_variance.getLogStdev() - 0.5*log(numbCalls);
        
        normalizingVolume = log_volume + volume_adder.log_ans - log(numbCalls);
        normalizingStdev = log_volume + volume_variance.getLogStdev() - 0.5*log(numbCalls);
        
        currentAns = integralVolume - normalizingVolume;
        // currentStdev = log_volume + integral_variance.getLogStdev() - 0.5*log(numbCalls);
        
        if(printIterations) {
            cout << "\n-----------\nApproximated log integral: " << currentAns << endl;
            // cout << "Current log standard deviation: " << currentStdev << endl;
            cout << "Approximated integral: " << exp(currentAns) << endl;
            // cout << "Approximated variance: " << exp(currentStdev) << endl;
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
    catch(int e) {
        return vector<double>({1,0,0});
    }
}
