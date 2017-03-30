// g++ -I /usr/local/include -L/usr/local/lib logSumAccuracyTest.cpp -lmpfr -lgmp -std=c++11

#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <cassert>
#include <stdlib.h>
#include <math.h>
#include <numeric>
#include <algorithm>
#include <stdlib.h>
#include <random>
#include <csignal>
#include <mpfr.h>

using namespace std;

int main() {

    mpfr_t actualVal,log1p_exp_x_error,exp_x_error,x_exp__x_error,x__error;
    mpfr_inits2(1024,actualVal,log1p_exp_x_error,exp_x_error,x_exp__x_error,x__error,(mpfr_ptr)0);

    int minimum = -500;
    int maximum = 500;
    int numbPoints = 100;

    for(int i=0; i<numbPoints; ++i) {
        double val = (maximum-minimum)*(double)i/(double)numbPoints + minimum;

        /* --------------------------------------------------------------- */

        mpfr_set_d(actualVal,val,MPFR_RNDD);
        mpfr_exp(actualVal,actualVal,MPFR_RNDD);
        mpfr_log1p(actualVal,actualVal,MPFR_RNDD);

        cout << "\nval: " << val << endl;
        cout << "Actual val is: ";
        mpfr_out_str(stdout,10,10,actualVal,MPFR_RNDD);
        cout << endl;

        /* --------------------------------------------------------------- */

        double log1p_exp_x = log1p(exp(val));
        mpfr_set_d(log1p_exp_x_error,log1p_exp_x,MPFR_RNDD);
        mpfr_sub(log1p_exp_x_error,log1p_exp_x_error,actualVal,MPFR_RNDD);
        mpfr_abs(log1p_exp_x_error,log1p_exp_x_error,MPFR_RNDD);
        mpfr_div(log1p_exp_x_error,log1p_exp_x_error,actualVal,MPFR_RNDD);

        cout << "log1p(exp(val)): " << log1p_exp_x << endl;
        cout << "log1p(exp(val)) error: ";
        mpfr_out_str(stdout,10,10,log1p_exp_x_error,MPFR_RNDD);
        cout << endl;

        /* --------------------------------------------------------------- */

        // double exp_x = exp(val);
        // mpfr_set_d(exp_x_error,exp_x,MPFR_RNDD);
        // mpfr_sub(exp_x_error,exp_x_error,actualVal,MPFR_RNDD);
        // mpfr_abs(exp_x_error,exp_x_error,MPFR_RNDD);
        // mpfr_div(exp_x_error,exp_x_error,actualVal,MPFR_RNDD);

        // cout << "exp(val): " << exp_x << endl;
        // cout << "exp(val) error: ";
        // mpfr_out_str(stdout,10,10,exp_x_error,MPFR_RNDD);
        // cout << endl;

        // /* --------------------------------------------------------------- */

        // double x_exp__x = val + exp(-val);
        // mpfr_set_d(x_exp__x_error,x_exp__x,MPFR_RNDD);
        // mpfr_sub(x_exp__x_error,x_exp__x_error,actualVal,MPFR_RNDD);
        // mpfr_abs(x_exp__x_error,x_exp__x_error,MPFR_RNDD);
        // mpfr_div(x_exp__x_error,x_exp__x_error,actualVal,MPFR_RNDD);

        // cout << "val + exp(-val): " << x_exp__x << endl;
        // cout << "val + exp(-val) error: ";
        // mpfr_out_str(stdout,10,10,x_exp__x_error,MPFR_RNDD);
        // cout << endl;

        // /* --------------------------------------------------------------- */

        // double x_ = val;
        // mpfr_set_d(x__error,x_,MPFR_RNDD);
        // mpfr_sub(x__error,x__error,actualVal,MPFR_RNDD);
        // mpfr_abs(x__error,x__error,MPFR_RNDD);
        // mpfr_div(x__error,x__error,actualVal,MPFR_RNDD);

        // cout << "val: " << x_ << endl;
        // cout << "val error: ";
        // mpfr_out_str(stdout,10,10,x__error,MPFR_RNDD);
        // cout << endl;

    }

    mpfr_clear(actualVal);
    mpfr_clear(log1p_exp_x_error);
    mpfr_clear(exp_x_error);
    mpfr_clear(x_exp__x_error);
    mpfr_clear(x__error);
    mpfr_free_cache();

    cout << "double min: " << __DBL_MIN__ << endl;

    return 1;
}











