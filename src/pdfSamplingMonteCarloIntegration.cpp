#include "logProbIPNew.h"
#include "metropolisHastings.h"

using namespace std;

vector<double> pedigreeClass2::_monteCarloMH(long numbCalls, bool printIterations, int numbToPrint, bool useNewDist, double K, bool useLeak, double leakProb, double leakDecay) {

    // this algorithm will use the Metropolis-Hastings algorithm to sample from the pdf (which should increase the rate of convergence)

    // if we sample from the pdf, then the estimation of the integral becomes 1/N*sum(integral(x_i))

    bool printTopVals = false;


    int totalDim = 0;
    for(int i=0; i<this->roots.size(); ++i) {
        totalDim += this->roots[i]->n-1;
    }
    
    vector<double> xl(totalDim);
    vector<double> xu(totalDim);
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
    
    sampler theSampler(totalDim,xl,xu,this,vector<int>(totalDim,1));
    theSampler.initState(useNewDist,K);
    
    logAddition integral_adder;
    logVariance integral_variance;
    
    double currentAns = 0.0;
    double currentStdev = 0.0;

    const int BREAKHERE = 723968;
    const int PRINTMORE = 722700;

    topK tracker(1000);
    bool printFlag = false;

    for(long i=0; i<numbCalls; ++i) {
        
        if(i == BREAKHERE) {
            int asdfasdf = 0;
        }

        //              x          rootProb
        const pair<vector<double>&,double> val = theSampler.nextSample(useNewDist,K);
        double logEval_integral = this->lastLogEval;


        if(logEval_integral == __DBL_MAX__) {
            integral_adder.addZeroPoint();
            integral_variance.addZeroPoint();
        }
        else {
            integral_adder.addPositiveLogPoint(logEval_integral);
            integral_variance.addPositiveLogPoint(logEval_integral);
        }

        currentAns = integral_adder.log_ans - log(i+1);

        tracker.addPoint(currentAns);
        
        if(printIterations) {
            if(i > PRINTMORE) {
                printFlag = false;
            }
            if((printFlag&&i%100) || (i%numbToPrint == 0 && i>0)) {

                currentAns = integral_adder.log_ans - log(i+1);
                currentStdev = integral_variance.getLogStdev() - 0.5*log(i+1);

                cout << "\n\ni: " << i << endl;
                cout << "Approximated log integral: " << currentAns << endl;
                cout << "Current log standard deviation: " << currentStdev << endl;
                cout << "\nApproximated integral: " << exp(currentAns) << endl;
                cout << "Current log standard deviation: " << exp(currentStdev) << endl;
                cout << "Acceptance rate: " << theSampler.acceptanceRatio << endl;
            }
        }
    }

    tracker.finalSort();
    if(printTopVals) {
        cout << "---------------------------\nTHE TOP 1000 VALUES---------------------------" << endl;
        for(int i=0; i<tracker.vals.size(); ++i) {
            cout << tracker.vals.at(i) << " ";
        }
        cout << endl << endl << endl;
    }

    currentAns = integral_adder.log_ans - log(numbCalls);
    currentStdev = integral_variance.getLogStdev() - 0.5*log(numbCalls);
    
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

