#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <random>
#include <iostream>
#include <cassert>

void vegas(float regn[], // rectangular volume specified by regn[1..2*ndim], consisting of ndim lower left coordinates of the region followed by ndim upper right coordinates
           int ndim, // number of dimensions
           float (*fxn)(float [], float), // user supplied ndim-dimensional function
           int init, // signals whether call is a new start or not
           unsigned long ncall, // number of function calls per iterations
           int itmx, // number of iterations (should be 5-10 at most)
           int nprn, // controls the amount of diagnostic output (usually 0)
           float *tgral, // best estimate of the integral
           float *sd, // standard deviation
           float *chi2a // chi squared per degree of freedom
           );