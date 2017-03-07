// g++ -I /usr/local/include -L/usr/local/lib gmpTest.cpp -lgmpxx -lgmp


#include <gmpxx.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>

using namespace std;

int main (void)
{
  mpz_class a,c;

  a = 100;
  
  int b = 5;

  c = a*b;

  cout << "c: " << c << endl;

  return 0;
}