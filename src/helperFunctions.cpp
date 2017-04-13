#include "logProbIPNew.h"

#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <stdlib.h>
#include <math.h>
#include <numeric>
#include <algorithm>
#include <stdlib.h>
#include <random>
#include <csignal>


using namespace std;

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


topK::topK(int size) {
    vals = vector<double>(size,-999);
    make_heap(vals.begin(),vals.end(),cmp());
}

void topK::addPoint(double point) {
    if(point > vals.front()) {
        pop_heap(vals.begin(), vals.end(), cmp());
        vals.pop_back();
        
        vals.push_back(point);
        push_heap(vals.begin(), vals.end(), cmp());
    }
}

void topK::finalSort() {
    sort_heap(vals.begin(), vals.end(), cmp());
}

double __accumulatePositive(double log_x, double log_y) {
    return log_x + log1p(exp(log_y - log_x));
}

double __accumulateNegative(double log_x, double log_y) {
    return log_x + log1p(-exp(log_y - log_x));
}

void logAddition::_accumulatePositive(double log_x) {
    this->log_ans = __accumulatePositive(this->log_ans, log_x);
}

void logAddition::_accumulateNegative(double log_x) {
    this->log_ans = __accumulateNegative(this->log_ans, log_x);
}

void logAddition::_addPoint(int sign, double log_x) {
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

void logAddition::addPositiveLogPoint(double log_x) {
    this->_addPoint(1,log_x);
}
void logAddition::addNegativeLogPoint(double log_x) {
    this->_addPoint(-1,log_x);
}
void logAddition::addZeroPoint() {
    return;
}
void logAddition::addPoint(double x) {
    if(x == 0) {
        return;
    }
    this->_addPoint(sgn(x),log(abs(x)));
}

void logVariance::_avgIsZero(int sign, double log_x) {
    this->sign_avg = sign;
    if(sign != 0) {
        this->log_x_avg = log_x - log(this->n);
    }
}

void logVariance::_updateAvg(int sign, double log_x) {
    
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

void logVariance::_updateM(int sign, double log_x, int old_sign_avg, double old_log_x_avg) {
    
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

void logVariance::_addPoint(int sign, double log_x) {
    this->n += 1;
    double old_log_x_avg = this->log_x_avg;
    int old_sign_avg = this->sign_avg;
    this->_updateAvg(sign,log_x);
    this->_updateM(sign,log_x,old_sign_avg,old_log_x_avg);
    if(this->n > 1) {
        this->log_var = this->log_m - log(this->n - 1);
    }
}

void logVariance::addPositiveLogPoint(double log_x) {
    this->_addPoint(1,log_x);
}
void logVariance::addNegativeLogPoint(double log_x) {
    this->_addPoint(-1,log_x);
}
void logVariance::addZeroPoint() {
    this->_addPoint(0,__DBL_MAX__);
}
void logVariance::addPoint(double x) {
    if(x == 0) {
        this->_addPoint(0,__DBL_MAX__);
        return;
    }
    this->_addPoint(sgn(x),log(abs(x)));
}

double logVariance::getLogStdev() {
    return this->log_var*0.5;
}

