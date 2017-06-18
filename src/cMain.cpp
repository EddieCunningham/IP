// g++ logProbIPNew.cpp helperFunctions.cpp uniformMonteCarloIntegration.cpp pdfSamplingMonteCarloIntegration.cpp cMain.cpp -I/usr/local/include -L/usr/local/lib -lgsl -lgslcblas -O3 -std=c++11

#include "logProbIPNew.h"
#include "BMIP.h"

using namespace std;

int main() {
    
personClass x_z0z1(1,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z0z4(4,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z0z5(5,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z0z11(11,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z0z14(14,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z0z29(29,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z0z30(30,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z0z31(31,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z0z_1(-1,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z0z_2(-2,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z0z_12(-12,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z0z_9(-9,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z0z_6(-6,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z0z_15(-15,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z0z_18(-18,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z0z_21(-21,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z0z_24(-24,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z0z_3(-3,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z1z1(1,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z1z3(3,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z1z19(19,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z1z20(20,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z1z_1(-1,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z1z_18(-18,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z1z_12(-12,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z1z_15(-15,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z2z2(2,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z2z3(3,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z2z7(7,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z2z8(8,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z2z9(9,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z2z_1(-1,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z2z_15(-15,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z2z_4(-4,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z3z1(1,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z3z2(2,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z3z3(3,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z3z14(14,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z3z50(50,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z3z_10(-10,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z3z_7(-7,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z3z_4(-4,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z3z_1(-1,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z3z_23(-23,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z3z_26(-26,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z3z_29(-29,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z3z_99(-99,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z4z1(1,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z4z2(2,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z4z3(3,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z4z6(6,nullptr,nullptr,true,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),true,"shaded","male");

personClass x_z4z7(7,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z4z_1(-1,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z4z_11(-11,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z4z_14(-14,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z4z_4(-4,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z4z_17(-17,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z4z_20(-20,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z4z_23(-23,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z5z6(6,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z5z8(8,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z5z27(27,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z5z_1(-1,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z5z_2(-2,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z5z_3(-3,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z5z_15(-15,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z5z_16(-16,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z5z_32(-32,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z5z_6(-6,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z5z_9(-9,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z5z_17(-17,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z5z_20(-20,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z5z_23(-23,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z5z_26(-26,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z5z_12(-12,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z6z1(1,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z6z8(8,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z6z19(19,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z6z_1(-1,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z6z_2(-2,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z6z_3(-3,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z6z_6(-6,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z6z_9(-9,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z6z_15(-15,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z6z_20(-20,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z6z_25(-25,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z6z_28(-28,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z6z_31(-31,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z6z_12(-12,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z7z1(1,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z7z2(2,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z7z5(5,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z7z6(6,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z7z_23(-23,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z7z_26(-26,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z7z_29(-29,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z7z_1(-1,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z7z_4(-4,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z7z_7(-7,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z7z_10(-10,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z7z_15(-15,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z7z_20(-20,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z8z1(1,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z8z2(2,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z8z9(9,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z8z10(10,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z8z_1(-1,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z8z_4(-4,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z8z_7(-7,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z8z_21(-21,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z8z_10(-10,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z8z_13(-13,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z8z_16(-16,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z8z_26(-26,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z9z1(1,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z9z2(2,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z9z3(3,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z9z4(4,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z9z5(5,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z9z_4(-4,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z9z_1(-1,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z10z1(1,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z10z2(2,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z10z3(3,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z10z4(4,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z10z_7(-7,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z10z_4(-4,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z10z_1(-1,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z10z_13(-13,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z10z_10(-10,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z11z1(1,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z11z2(2,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z11z14(14,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z11z18(18,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z11z19(19,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z11z_4(-4,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z11z_7(-7,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z11z_10(-10,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z11z_13(-13,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z11z_1(-1,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z12z1(1,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z12z2(2,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z12z14(14,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z12z18(18,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z12z19(19,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z12z_4(-4,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z12z_7(-7,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z12z_10(-10,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z12z_13(-13,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z12z_1(-1,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z13z1(1,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z13z2(2,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z13z3(3,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z13z4(4,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z13z35(35,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z13z36(36,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z13z37(37,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z13z38(38,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z13z_1(-1,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z13z_17(-17,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z13z_20(-20,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z13z_4(-4,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z13z_7(-7,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z13z_11(-11,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z13z_14(-14,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z14z1(1,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z14z2(2,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z14z8(8,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z14z9(9,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z14z_4(-4,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z14z_1(-1,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z15z1(1,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z15z2(2,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z15z10(10,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z15z11(11,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z15z_1(-1,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z15z_4(-4,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z15z_11(-11,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z16z3(3,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z16z_1(-1,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z16z_2(-2,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z16z_3(-3,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z16z_6(-6,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z16z_9(-9,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z16z_12(-12,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z16z_15(-15,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z16z_18(-18,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z16z_21(-21,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z16z_24(-24,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z17z1(1,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z17z2(2,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z17z3(3,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z17z4(4,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z17z5(5,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z17z6(6,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z17z_1(-1,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z17z_4(-4,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z17z_10(-10,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z17z_23(-23,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z17z_20(-20,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z17z_13(-13,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z17z_7(-7,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z18z1(1,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z18z2(2,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z18z3(3,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z18z_4(-4,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z18z_5(-5,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z18z_9(-9,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z18z_6(-6,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z18z_1(-1,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z19z30(30,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z19z31(31,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z19z34(34,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z19z44(44,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z19z45(45,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z19z_10(-10,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z19z_13(-13,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z19z_7(-7,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z19z_4(-4,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z19z_1(-1,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z19z_24(-24,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z19z_27(-27,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z19z_30(-30,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z19z_33(-33,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z19z_36(-36,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z20z1(1,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z20z2(2,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z20z3(3,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z20z9(9,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z20z13(13,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z20z23(23,nullptr,nullptr,true,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),true,"shaded","male");

personClass x_z20z24(24,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z20z_1(-1,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z20z_4(-4,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z20z_7(-7,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z20z_10(-10,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");


















personClass x_z0z2(2,&x_z0z_1,&x_z0z_2,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z0z3(3,&x_z0z_1,&x_z0z_2,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z0z6(6,&x_z0z1,&x_z0z2,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z0z7(7,&x_z0z1,&x_z0z2,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z0z8(8,&x_z0z1,&x_z0z2,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z0z9(9,&x_z0z1,&x_z0z2,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z0z10(10,&x_z0z1,&x_z0z2,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z0z12(12,&x_z0z1,&x_z0z2,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),true,"shaded","male");

personClass x_z0z13(13,&x_z0z4,&x_z0z5,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z0z15(15,&x_z0z4,&x_z0z5,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z0z16(16,&x_z0z4,&x_z0z5,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z0z17(17,&x_z0z4,&x_z0z5,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z0z18(18,&x_z0z4,&x_z0z5,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z0z19(19,&x_z0z4,&x_z0z5,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z0z21(21,&x_z0z7,&x_z0z_12,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),false,"unshaded","female");

personClass x_z0z22(22,&x_z0z7,&x_z0z_12,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");

personClass x_z0z23(23,&x_z0z8,&x_z0z_9,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z0z24(24,&x_z0z10,&x_z0z_6,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z0z25(25,&x_z0z11,&x_z0z12,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");

personClass x_z0z26(26,&x_z0z12,&x_z0z13,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z0z27(27,&x_z0z12,&x_z0z13,false,0.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),true,"shaded","female");

personClass x_z0z28(28,&x_z0z13,&x_z0z14,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");

personClass x_z0z32(32,&x_z0z16,&x_z0z_15,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");

personClass x_z0z33(33,&x_z0z16,&x_z0z_15,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");

personClass x_z0z34(34,&x_z0z17,&x_z0z_18,false,1.000000,0.500000,0.000000,3,5,8,vector<double>(8),false,vector<vector<vector<double>>>({{{0.500000,0.500000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.500000,0.500000,0.500000,0.500000},{0.250000,0.250000,0.250000,0.250000},{0.250000,0.250000,0.250000,0.250000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000}},{{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.500000,0.500000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.250000,0.250000,0.250000,0.250000},{0.250000,0.250000,0.250000,0.250000},{0.500000,0.500000,0.500000,0.500000}}}),false,"unshaded","unknown");

personClass x_z0z35(35,&x_z0z18,&x_z0z_21,false,1.000000,0.500000,0.000000,3,5,8,vector<double>(8),false,vector<vector<vector<double>>>({{{0.500000,0.500000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.500000,0.500000,0.500000,0.500000},{0.250000,0.250000,0.250000,0.250000},{0.250000,0.250000,0.250000,0.250000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000}},{{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.500000,0.500000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.250000,0.250000,0.250000,0.250000},{0.250000,0.250000,0.250000,0.250000},{0.500000,0.500000,0.500000,0.500000}}}),false,"unshaded","unknown");

personClass x_z0z36(36,&x_z0z19,&x_z0z_24,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");

personClass x_z0z37(37,&x_z0z19,&x_z0z_24,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),false,"unshaded","female");

personClass x_z0z38(38,&x_z0z26,&x_z0z_3,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),false,"unshaded","female");

personClass x_z0z39(39,&x_z0z26,&x_z0z_3,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");

personClass x_z0z40(40,&x_z0z26,&x_z0z_3,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");

personClass x_z0z41(41,&x_z0z28,&x_z0z29,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z0z42(42,&x_z0z28,&x_z0z30,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z0z43(43,&x_z0z28,&x_z0z30,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z0z44(44,&x_z0z28,&x_z0z31,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");









personClass x_z1z2(2,&x_z1z1,&x_z1z_1,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");

personClass x_z1z4(4,&x_z1z2,&x_z1z3,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z1z5(5,&x_z1z2,&x_z1z3,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z1z6(6,&x_z1z2,&x_z1z3,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z1z7(7,&x_z1z19,&x_z1z20,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z1z8(8,&x_z1z19,&x_z1z20,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z1z9(9,&x_z1z19,&x_z1z20,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z1z10(10,&x_z1z5,&x_z1z_18,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z1z11(11,&x_z1z5,&x_z1z_18,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z1z12(12,&x_z1z6,&x_z1z7,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z1z13(13,&x_z1z6,&x_z1z7,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z1z14(14,&x_z1z6,&x_z1z7,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),true,"shaded","male");

personClass x_z1z15(15,&x_z1z8,&x_z1z_12,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z1z16(16,&x_z1z8,&x_z1z_12,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z1z17(17,&x_z1z9,&x_z1z_15,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),false,"unshaded","female");

personClass x_z1z18(18,&x_z1z9,&x_z1z_15,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");









personClass x_z2z4(4,&x_z2z2,&x_z2z3,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z2z5(5,&x_z2z2,&x_z2z3,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),true,"shaded","male");

personClass x_z2z6(6,&x_z2z2,&x_z2z3,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),true,"shaded","male");

personClass x_z2z10(10,&x_z2z8,&x_z2z9,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z2z11(11,&x_z2z8,&x_z2z9,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z2z12(12,&x_z2z7,&x_z2z4,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z2z13(13,&x_z2z10,&x_z2z_15,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");

personClass x_z2z14(14,&x_z2z10,&x_z2z_15,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");

personClass x_z2z15(15,&x_z2z11,&x_z2z12,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z2z16(16,&x_z2z11,&x_z2z12,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),true,"shaded","male");

personClass x_z2z18(18,&x_z2z7,&x_z2z4,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z2z19(19,&x_z2z6,&x_z2z_1,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z2z20(20,&x_z2z19,&x_z2z_4,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");














personClass x_z3z4(4,&x_z3z1,&x_z3z2,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z3z5(5,&x_z3z1,&x_z3z2,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z3z6(6,&x_z3z1,&x_z3z2,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z3z7(7,&x_z3z1,&x_z3z2,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z3z8(8,&x_z3z1,&x_z3z2,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z3z10(10,&x_z3z3,&x_z3z4,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z3z11(11,&x_z3z3,&x_z3z4,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z3z12(12,&x_z3z3,&x_z3z4,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z3z13(13,&x_z3z3,&x_z3z4,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),true,"shaded","male");

personClass x_z3z26(26,&x_z3z4,&x_z3z_10,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");

personClass x_z3z27(27,&x_z3z4,&x_z3z_10,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),false,"unshaded","female");

personClass x_z3z28(28,&x_z3z6,&x_z3z_7,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),false,"unshaded","female");

personClass x_z3z29(29,&x_z3z6,&x_z3z_7,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");

personClass x_z3z30(30,&x_z3z7,&x_z3z_4,false,1.000000,0.500000,0.000000,3,5,8,vector<double>(8),false,vector<vector<vector<double>>>({{{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000}},{{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000}},{{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","unknown");

personClass x_z3z31(31,&x_z3z8,&x_z3z_1,false,1.000000,0.500000,0.000000,3,5,8,vector<double>(8),false,vector<vector<vector<double>>>({{{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000}},{{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000}},{{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","unknown");

personClass x_z3z32(32,&x_z3z10,&x_z3z_23,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");

personClass x_z3z33(33,&x_z3z10,&x_z3z_23,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),false,"unshaded","female");

personClass x_z3z35(35,&x_z3z11,&x_z3z_26,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),false,"unshaded","female");

personClass x_z3z36(36,&x_z3z11,&x_z3z_26,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");

personClass x_z3z38(38,&x_z3z12,&x_z3z_29,false,1.000000,0.500000,0.000000,3,5,8,vector<double>(8),false,vector<vector<vector<double>>>({{{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000}},{{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000}},{{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","unknown");

personClass x_z3z41(41,&x_z3z13,&x_z3z14,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z3z42(42,&x_z3z13,&x_z3z14,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z3z43(43,&x_z3z13,&x_z3z14,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z3z51(51,&x_z3z43,&x_z3z50,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),false,"unshaded","female");

personClass x_z3z52(52,&x_z3z43,&x_z3z50,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),true,"shaded","male");

personClass x_z3z53(53,&x_z3z43,&x_z3z50,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");

personClass x_z3z54(54,&x_z3z43,&x_z3z50,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),true,"shaded","male");

personClass x_z3z188(188,&x_z3z41,&x_z3z_99,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),false,"unshaded","female");













personClass x_z4z4(4,&x_z4z6,&x_z4z7,false,0.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),true,"shaded","female");

personClass x_z4z5(5,&x_z4z6,&x_z4z7,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z4z8(8,&x_z4z1,&x_z4z2,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z4z9(9,&x_z4z1,&x_z4z2,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z4z10(10,&x_z4z1,&x_z4z2,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z4z11(11,&x_z4z1,&x_z4z2,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z4z12(12,&x_z4z3,&x_z4z4,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z4z13(13,&x_z4z3,&x_z4z4,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z4z14(14,&x_z4z3,&x_z4z4,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z4z15(15,&x_z4z3,&x_z4z4,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),true,"shaded","male");

personClass x_z4z16(16,&x_z4z5,&x_z4z_1,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");

personClass x_z4z17(17,&x_z4z5,&x_z4z_1,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),true,"shaded","male");

personClass x_z4z18(18,&x_z4z8,&x_z4z_11,false,1.000000,0.500000,0.000000,3,5,8,vector<double>(8),false,vector<vector<vector<double>>>({{{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000}},{{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000}},{{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","unknown");

personClass x_z4z19(19,&x_z4z10,&x_z4z_14,false,1.000000,0.500000,0.000000,3,5,8,vector<double>(8),false,vector<vector<vector<double>>>({{{0.500000,0.500000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.500000,0.500000,0.500000,0.500000},{0.250000,0.250000,0.250000,0.250000},{0.250000,0.250000,0.250000,0.250000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000}},{{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.500000,0.500000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.250000,0.250000,0.250000,0.250000},{0.250000,0.250000,0.250000,0.250000},{0.500000,0.500000,0.500000,0.500000}}}),false,"unshaded","unknown");

personClass x_z4z20(20,&x_z4z11,&x_z4z12,false,0.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),true,"shaded","female");

personClass x_z4z21(21,&x_z4z11,&x_z4z12,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z4z22(22,&x_z4z12,&x_z4z_4,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),false,"unshaded","female");

personClass x_z4z23(23,&x_z4z13,&x_z4z_17,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");

personClass x_z4z24(24,&x_z4z13,&x_z4z_17,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),true,"shaded","male");

personClass x_z4z25(25,&x_z4z14,&x_z4z_20,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z4z26(26,&x_z4z15,&x_z4z_23,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

















personClass x_z5z2(2,&x_z5z_1,&x_z5z_2,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z5z3(3,&x_z5z_1,&x_z5z_2,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z5z4(4,&x_z5z_1,&x_z5z_2,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z5z5(5,&x_z5z_1,&x_z5z_2,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z5z7(7,&x_z5z_15,&x_z5z_16,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z5z9(9,&x_z5z_15,&x_z5z_16,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z5z10(10,&x_z5z_15,&x_z5z_16,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z5z11(11,&x_z5z_15,&x_z5z_16,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z5z12(12,&x_z5z2,&x_z5z_3,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");

personClass x_z5z13(13,&x_z5z2,&x_z5z_3,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),false,"unshaded","female");

personClass x_z5z14(14,&x_z5z2,&x_z5z_3,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),false,"unshaded","female");

personClass x_z5z15(15,&x_z5z5,&x_z5z6,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z5z16(16,&x_z5z5,&x_z5z6,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z5z17(17,&x_z5z7,&x_z5z8,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z5z18(18,&x_z5z7,&x_z5z8,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z5z19(19,&x_z5z7,&x_z5z8,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z5z20(20,&x_z5z10,&x_z5z_32,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");

personClass x_z5z22(22,&x_z5z10,&x_z5z_32,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");

personClass x_z5z23(23,&x_z5z_1,&x_z5z_2,false,1.000000,0.500000,0.000000,3,5,8,vector<double>(8),false,vector<vector<vector<double>>>({{{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000}},{{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000}},{{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","unknown");

personClass x_z5z24(24,&x_z5z13,&x_z5z_6,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),false,"unshaded","female");

personClass x_z5z25(25,&x_z5z15,&x_z5z_9,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z5z26(26,&x_z5z15,&x_z5z_9,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z5z28(28,&x_z5z16,&x_z5z17,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),true,"shaded","male");

personClass x_z5z29(29,&x_z5z16,&x_z5z17,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z5z30(30,&x_z5z18,&x_z5z_17,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z5z31(31,&x_z5z18,&x_z5z_17,false,1.000000,0.500000,0.000000,3,5,8,vector<double>(8),false,vector<vector<vector<double>>>({{{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000}},{{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000}},{{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","unknown");

personClass x_z5z32(32,&x_z5z19,&x_z5z_20,false,1.000000,0.500000,0.000000,3,5,8,vector<double>(8),false,vector<vector<vector<double>>>({{{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000}},{{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000}},{{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","unknown");

personClass x_z5z33(33,&x_z5z20,&x_z5z_23,false,1.000000,0.500000,0.000000,3,5,8,vector<double>(8),false,vector<vector<vector<double>>>({{{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000}},{{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000}},{{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","unknown");

personClass x_z5z34(34,&x_z5z22,&x_z5z_26,false,1.000000,0.500000,0.000000,3,5,8,vector<double>(8),false,vector<vector<vector<double>>>({{{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000}},{{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000}},{{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","unknown");

personClass x_z5z35(35,&x_z5z27,&x_z5z28,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),false,"unshaded","female");

personClass x_z5z36(36,&x_z5z27,&x_z5z28,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),false,"unshaded","female");

personClass x_z5z37(37,&x_z5z27,&x_z5z28,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");

personClass x_z5z38(38,&x_z5z27,&x_z5z28,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");

personClass x_z5z39(39,&x_z5z29,&x_z5z_12,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");

personClass x_z5z40(40,&x_z5z29,&x_z5z_12,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");

personClass x_z5z41(41,&x_z5z29,&x_z5z_12,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");

personClass x_z5z43(43,&x_z5z7,&x_z5z8,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");















personClass x_z6z2(2,&x_z6z_1,&x_z6z_2,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z6z3(3,&x_z6z_1,&x_z6z_2,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z6z4(4,&x_z6z3,&x_z6z_3,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),true,"shaded","male");

personClass x_z6z5(5,&x_z6z1,&x_z6z2,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z6z6(6,&x_z6z1,&x_z6z2,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),true,"shaded","male");

personClass x_z6z7(7,&x_z6z1,&x_z6z2,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),true,"shaded","male");

personClass x_z6z9(9,&x_z6z1,&x_z6z2,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),true,"shaded","male");

personClass x_z6z10(10,&x_z6z1,&x_z6z2,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),true,"shaded","male");

personClass x_z6z11(11,&x_z6z1,&x_z6z2,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z6z12(12,&x_z6z1,&x_z6z2,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z6z13(13,&x_z6z1,&x_z6z2,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z6z14(14,&x_z6z5,&x_z6z_6,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z6z15(15,&x_z6z5,&x_z6z_6,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z6z16(16,&x_z6z6,&x_z6z_9,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z6z17(17,&x_z6z6,&x_z6z_9,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z6z18(18,&x_z6z6,&x_z6z_9,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z6z20(20,&x_z6z7,&x_z6z8,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z6z21(21,&x_z6z7,&x_z6z8,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z6z22(22,&x_z6z7,&x_z6z8,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z6z23(23,&x_z6z7,&x_z6z8,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z6z24(24,&x_z6z9,&x_z6z_15,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z6z25(25,&x_z6z9,&x_z6z_20,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z6z26(26,&x_z6z10,&x_z6z_25,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z6z27(27,&x_z6z11,&x_z6z_28,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z6z28(28,&x_z6z12,&x_z6z_31,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z6z29(29,&x_z6z12,&x_z6z_31,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z6z30(30,&x_z6z19,&x_z6z20,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),true,"shaded","male");

personClass x_z6z31(31,&x_z6z21,&x_z6z_12,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),true,"shaded","male");

personClass x_z6z32(32,&x_z6z21,&x_z6z_12,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");

personClass x_z6z33(33,&x_z6z21,&x_z6z_12,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),false,"unshaded","female");














personClass x_z7z3(3,&x_z7z1,&x_z7z2,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),true,"shaded","male");

personClass x_z7z4(4,&x_z7z1,&x_z7z2,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),true,"shaded","male");

personClass x_z7z7(7,&x_z7z4,&x_z7z5,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z7z8(8,&x_z7z4,&x_z7z5,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z7z9(9,&x_z7z4,&x_z7z5,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z7z10(10,&x_z7z4,&x_z7z5,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z7z11(11,&x_z7z6,&x_z7z7,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z7z12(12,&x_z7z6,&x_z7z7,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z7z13(13,&x_z7z6,&x_z7z7,false,1.000000,1.000000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"shaded","female");

personClass x_z7z14(14,&x_z7z6,&x_z7z7,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),true,"shaded","male");

personClass x_z7z15(15,&x_z7z6,&x_z7z7,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z7z16(16,&x_z7z6,&x_z7z7,false,1.000000,1.000000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"shaded","female");

personClass x_z7z17(17,&x_z7z8,&x_z7z_23,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),true,"shaded","male");

personClass x_z7z18(18,&x_z7z8,&x_z7z_23,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),false,"unshaded","female");

personClass x_z7z19(19,&x_z7z8,&x_z7z_23,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");

personClass x_z7z20(20,&x_z7z9,&x_z7z_26,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");

personClass x_z7z21(21,&x_z7z9,&x_z7z_26,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),false,"unshaded","female");

personClass x_z7z22(22,&x_z7z10,&x_z7z_29,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z7z23(23,&x_z7z10,&x_z7z_29,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z7z24(24,&x_z7z11,&x_z7z_1,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z7z25(25,&x_z7z12,&x_z7z_4,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");

personClass x_z7z26(26,&x_z7z13,&x_z7z_7,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),true,"shaded","male");

personClass x_z7z27(27,&x_z7z13,&x_z7z_7,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),false,"unshaded","female");

personClass x_z7z28(28,&x_z7z14,&x_z7z_10,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z7z29(29,&x_z7z14,&x_z7z_15,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z7z30(30,&x_z7z14,&x_z7z_15,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z7z31(31,&x_z7z16,&x_z7z_20,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),true,"shaded","male");

personClass x_z7z32(32,&x_z7z16,&x_z7z_20,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),false,"unshaded","female");













personClass x_z8z3(3,&x_z8z1,&x_z8z2,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z8z4(4,&x_z8z1,&x_z8z2,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z8z5(5,&x_z8z1,&x_z8z2,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z8z6(6,&x_z8z1,&x_z8z2,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z8z7(7,&x_z8z9,&x_z8z10,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z8z8(8,&x_z8z9,&x_z8z10,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),true,"shaded","male");

personClass x_z8z11(11,&x_z8z3,&x_z8z_1,false,1.000000,0.500000,0.000000,3,5,8,vector<double>(8),false,vector<vector<vector<double>>>({{{0.500000,0.500000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.500000,0.500000,0.500000,0.500000},{0.250000,0.250000,0.250000,0.250000},{0.250000,0.250000,0.250000,0.250000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000}},{{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.500000,0.500000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.250000,0.250000,0.250000,0.250000},{0.250000,0.250000,0.250000,0.250000},{0.500000,0.500000,0.500000,0.500000}}}),false,"unshaded","unknown");

personClass x_z8z12(12,&x_z8z4,&x_z8z_4,false,1.000000,0.500000,0.000000,3,5,8,vector<double>(8),false,vector<vector<vector<double>>>({{{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000}},{{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000}},{{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","unknown");

personClass x_z8z13(13,&x_z8z5,&x_z8z_7,false,1.000000,0.500000,0.000000,3,5,8,vector<double>(8),false,vector<vector<vector<double>>>({{{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000}},{{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000}},{{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","unknown");

personClass x_z8z14(14,&x_z8z6,&x_z8z7,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),true,"shaded","male");

personClass x_z8z15(15,&x_z8z6,&x_z8z7,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),true,"shaded","male");

personClass x_z8z16(16,&x_z8z14,&x_z8z_10,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z8z17(17,&x_z8z14,&x_z8z_10,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z8z18(18,&x_z8z14,&x_z8z_10,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z8z19(19,&x_z8z15,&x_z8z_13,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z8z20(20,&x_z8z8,&x_z8z_21,false,0.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),true,"shaded","female");

personClass x_z8z21(21,&x_z8z8,&x_z8z_21,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z8z22(22,&x_z8z8,&x_z8z_21,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z8z23(23,&x_z8z20,&x_z8z_16,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),false,"unshaded","female");

personClass x_z8z24(24,&x_z8z20,&x_z8z_16,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),false,"unshaded","female");

personClass x_z8z25(25,&x_z8z21,&x_z8z_26,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),false,"unshaded","female");








personClass x_z9z6(6,&x_z9z1,&x_z9z2,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z9z7(7,&x_z9z1,&x_z9z2,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z9z8(8,&x_z9z3,&x_z9z4,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z9z9(9,&x_z9z3,&x_z9z4,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z9z10(10,&x_z9z3,&x_z9z4,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z9z11(11,&x_z9z3,&x_z9z4,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z9z12(12,&x_z9z3,&x_z9z4,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z9z13(13,&x_z9z5,&x_z9z6,false,1.000000,1.000000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"shaded","female");

personClass x_z9z14(14,&x_z9z5,&x_z9z6,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z9z15(15,&x_z9z5,&x_z9z6,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z9z16(16,&x_z9z10,&x_z9z_4,false,1.000000,0.500000,0.000000,3,5,8,vector<double>(8),false,vector<vector<vector<double>>>({{{0.500000,0.500000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.500000,0.500000,0.500000,0.500000},{0.250000,0.250000,0.250000,0.250000},{0.250000,0.250000,0.250000,0.250000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000}},{{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.500000,0.500000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.250000,0.250000,0.250000,0.250000},{0.250000,0.250000,0.250000,0.250000},{0.500000,0.500000,0.500000,0.500000}}}),false,"unshaded","unknown");

personClass x_z9z17(17,&x_z9z11,&x_z9z_1,false,1.000000,0.500000,0.000000,3,5,8,vector<double>(8),false,vector<vector<vector<double>>>({{{0.500000,0.500000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.500000,0.500000,0.500000,0.500000},{0.250000,0.250000,0.250000,0.250000},{0.250000,0.250000,0.250000,0.250000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000}},{{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.500000,0.500000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.250000,0.250000,0.250000,0.250000},{0.250000,0.250000,0.250000,0.250000},{0.500000,0.500000,0.500000,0.500000}}}),false,"unshaded","unknown");

personClass x_z9z18(18,&x_z9z12,&x_z9z13,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),true,"shaded","male");

personClass x_z9z19(19,&x_z9z12,&x_z9z13,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z9z20(20,&x_z9z12,&x_z9z13,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");










personClass x_z10z5(5,&x_z10z1,&x_z10z2,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z10z6(6,&x_z10z1,&x_z10z2,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z10z7(7,&x_z10z1,&x_z10z2,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z10z8(8,&x_z10z1,&x_z10z2,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z10z9(9,&x_z10z3,&x_z10z4,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z10z10(10,&x_z10z3,&x_z10z4,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z10z11(11,&x_z10z5,&x_z10z_7,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z10z12(12,&x_z10z5,&x_z10z_7,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z10z13(13,&x_z10z6,&x_z10z_4,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z10z14(14,&x_z10z6,&x_z10z_4,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z10z15(15,&x_z10z7,&x_z10z_1,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");

personClass x_z10z16(16,&x_z10z8,&x_z10z9,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),true,"shaded","male");

personClass x_z10z17(17,&x_z10z8,&x_z10z9,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");

personClass x_z10z18(18,&x_z10z8,&x_z10z9,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");

personClass x_z10z19(19,&x_z10z18,&x_z10z_10,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z10z20(20,&x_z10z18,&x_z10z_10,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z10z21(21,&x_z10z10,&x_z10z_13,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),false,"unshaded","female");

personClass x_z10z22(22,&x_z10z10,&x_z10z_13,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),false,"unshaded","female");











personClass x_z11z3(3,&x_z11z1,&x_z11z2,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z11z4(4,&x_z11z1,&x_z11z2,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z11z5(5,&x_z11z1,&x_z11z2,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z11z6(6,&x_z11z1,&x_z11z2,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");
    
    personClass x_z11z15(15,&x_z11z18,&x_z11z19,false,1.000000,1.000000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"shaded","female");

personClass x_z11z7(7,&x_z11z14,&x_z11z15,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z11z8(8,&x_z11z14,&x_z11z15,false,1.000000,1.000000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"shaded","female");

personClass x_z11z9(9,&x_z11z14,&x_z11z15,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z11z10(10,&x_z11z14,&x_z11z15,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z11z11(11,&x_z11z14,&x_z11z15,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z11z12(12,&x_z11z14,&x_z11z15,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),true,"shaded","male");

personClass x_z11z13(13,&x_z11z14,&x_z11z15,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z11z16(16,&x_z11z18,&x_z11z19,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z11z17(17,&x_z11z16,&x_z11z_1,false,1.000000,0.500000,0.000000,3,5,8,vector<double>(8),false,vector<vector<vector<double>>>({{{0.500000,0.500000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.500000,0.500000,0.500000,0.500000},{0.250000,0.250000,0.250000,0.250000},{0.250000,0.250000,0.250000,0.250000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000}},{{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.500000,0.500000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.250000,0.250000,0.250000,0.250000},{0.250000,0.250000,0.250000,0.250000},{0.500000,0.500000,0.500000,0.500000}}}),false,"unshaded","unknown");

personClass x_z11z20(20,&x_z11z6,&x_z11z7,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z11z21(21,&x_z11z6,&x_z11z7,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),true,"shaded","male");

personClass x_z11z22(22,&x_z11z8,&x_z11z_4,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");

personClass x_z11z23(23,&x_z11z8,&x_z11z_4,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),true,"shaded","male");

personClass x_z11z24(24,&x_z11z8,&x_z11z_4,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),true,"shaded","male");

personClass x_z11z25(25,&x_z11z8,&x_z11z_4,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");

personClass x_z11z26(26,&x_z11z8,&x_z11z_4,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),false,"unshaded","female");

personClass x_z11z27(27,&x_z11z10,&x_z11z_7,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),false,"unshaded","female");

personClass x_z11z28(28,&x_z11z11,&x_z11z_10,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z11z29(29,&x_z11z11,&x_z11z_10,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z11z30(30,&x_z11z13,&x_z11z_13,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");











personClass x_z12z3(3,&x_z12z1,&x_z12z2,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z12z4(4,&x_z12z1,&x_z12z2,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z12z5(5,&x_z12z1,&x_z12z2,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z12z6(6,&x_z12z1,&x_z12z2,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");
    
    personClass x_z12z15(15,&x_z12z18,&x_z12z19,false,1.000000,1.000000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"shaded","female");
    

personClass x_z12z7(7,&x_z12z14,&x_z12z15,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z12z8(8,&x_z12z14,&x_z12z15,false,1.000000,1.000000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"shaded","female");

personClass x_z12z9(9,&x_z12z14,&x_z12z15,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z12z10(10,&x_z12z14,&x_z12z15,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z12z11(11,&x_z12z14,&x_z12z15,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z12z12(12,&x_z12z14,&x_z12z15,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),true,"shaded","male");

personClass x_z12z13(13,&x_z12z14,&x_z12z15,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),true,"shaded","male");
personClass x_z12z16(16,&x_z12z18,&x_z12z19,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z12z17(17,&x_z12z16,&x_z12z_1,false,1.000000,0.500000,0.000000,3,5,8,vector<double>(8),false,vector<vector<vector<double>>>({{{0.500000,0.500000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.500000,0.500000,0.500000,0.500000},{0.250000,0.250000,0.250000,0.250000},{0.250000,0.250000,0.250000,0.250000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000}},{{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.500000,0.500000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.250000,0.250000,0.250000,0.250000},{0.250000,0.250000,0.250000,0.250000},{0.500000,0.500000,0.500000,0.500000}}}),false,"unshaded","unknown");

personClass x_z12z20(20,&x_z12z6,&x_z12z7,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z12z21(21,&x_z12z6,&x_z12z7,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),true,"shaded","male");

personClass x_z12z22(22,&x_z12z8,&x_z12z_4,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");

personClass x_z12z23(23,&x_z12z8,&x_z12z_4,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),true,"shaded","male");

personClass x_z12z24(24,&x_z12z8,&x_z12z_4,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),true,"shaded","male");

personClass x_z12z25(25,&x_z12z8,&x_z12z_4,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");

personClass x_z12z26(26,&x_z12z8,&x_z12z_4,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),false,"unshaded","female");

personClass x_z12z27(27,&x_z12z10,&x_z12z_7,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),false,"unshaded","female");

personClass x_z12z28(28,&x_z12z11,&x_z12z_10,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z12z29(29,&x_z12z11,&x_z12z_10,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z12z30(30,&x_z12z13,&x_z12z_13,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");
















personClass x_z13z5(5,&x_z13z1,&x_z13z2,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z13z6(6,&x_z13z1,&x_z13z2,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z13z7(7,&x_z13z3,&x_z13z4,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z13z8(8,&x_z13z6,&x_z13z7,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),true,"shaded","male");

personClass x_z13z10(10,&x_z13z6,&x_z13z7,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),true,"shaded","male");

personClass x_z13z12(12,&x_z13z6,&x_z13z7,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),true,"shaded","male");

personClass x_z13z14(14,&x_z13z6,&x_z13z7,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z13z15(15,&x_z13z6,&x_z13z7,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z13z16(16,&x_z13z6,&x_z13z7,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z13z39(39,&x_z13z8,&x_z13z36,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z13z40(40,&x_z13z8,&x_z13z36,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z13z41(41,&x_z13z8,&x_z13z36,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z13z42(42,&x_z13z10,&x_z13z37,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z13z43(43,&x_z13z12,&x_z13z38,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z13z44(44,&x_z13z12,&x_z13z38,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z13z45(45,&x_z13z14,&x_z13z_1,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");

personClass x_z13z46(46,&x_z13z14,&x_z13z_1,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),false,"unshaded","female");

personClass x_z13z47(47,&x_z13z35,&x_z13z39,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),false,"unshaded","female");

personClass x_z13z48(48,&x_z13z40,&x_z13z_4,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z13z49(49,&x_z13z41,&x_z13z_7,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");

personClass x_z13z50(50,&x_z13z41,&x_z13z_7,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),false,"unshaded","female");

personClass x_z13z51(51,&x_z13z43,&x_z13z_11,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),false,"unshaded","female");

personClass x_z13z52(52,&x_z13z43,&x_z13z_11,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),false,"unshaded","female");

personClass x_z13z53(53,&x_z13z44,&x_z13z_14,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),false,"unshaded","female");

personClass x_z13z54(54,&x_z13z15,&x_z13z_17,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");

personClass x_z13z55(55,&x_z13z15,&x_z13z_17,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),false,"unshaded","female");

personClass x_z13z56(56,&x_z13z15,&x_z13z_17,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),false,"unshaded","female");

personClass x_z13z57(57,&x_z13z16,&x_z13z_20,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");

personClass x_z13z58(58,&x_z13z16,&x_z13z_20,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");

personClass x_z13z59(59,&x_z13z16,&x_z13z_20,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),false,"unshaded","female");







personClass x_z14z3(3,&x_z14z1,&x_z14z2,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z14z4(4,&x_z14z1,&x_z14z2,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z14z5(5,&x_z14z1,&x_z14z2,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z14z6(6,&x_z14z8,&x_z14z9,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z14z7(7,&x_z14z8,&x_z14z9,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z14z10(10,&x_z14z7,&x_z14z_1,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");

personClass x_z14z11(11,&x_z14z5,&x_z14z6,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z14z12(12,&x_z14z5,&x_z14z6,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),true,"shaded","male");

personClass x_z14z13(13,&x_z14z3,&x_z14z_4,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");








personClass x_z15z3(3,&x_z15z1,&x_z15z2,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z15z4(4,&x_z15z1,&x_z15z2,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z15z5(5,&x_z15z1,&x_z15z2,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z15z6(6,&x_z15z1,&x_z15z2,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z15z7(7,&x_z15z1,&x_z15z2,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z15z8(8,&x_z15z1,&x_z15z2,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z15z9(9,&x_z15z1,&x_z15z2,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z15z12(12,&x_z15z10,&x_z15z11,false,1.000000,1.000000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"shaded","female");

personClass x_z15z13(13,&x_z15z10,&x_z15z11,false,1.000000,1.000000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"shaded","female");

personClass x_z15z14(14,&x_z15z10,&x_z15z11,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z15z15(15,&x_z15z10,&x_z15z11,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z15z16(16,&x_z15z10,&x_z15z11,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z15z17(17,&x_z15z9,&x_z15z12,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z15z18(18,&x_z15z9,&x_z15z12,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),true,"shaded","male");

personClass x_z15z19(19,&x_z15z9,&x_z15z12,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z15z20(20,&x_z15z13,&x_z15z_1,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),true,"shaded","male");

personClass x_z15z21(21,&x_z15z13,&x_z15z_1,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),true,"shaded","male");

personClass x_z15z22(22,&x_z15z14,&x_z15z_4,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");

personClass x_z15z23(23,&x_z15z16,&x_z15z_11,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),false,"unshaded","female");

personClass x_z15z24(24,&x_z15z16,&x_z15z_11,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");












personClass x_z16z1(1,&x_z16z_1,&x_z16z_2,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),true,"shaded","male");

personClass x_z16z2(2,&x_z16z_1,&x_z16z_2,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z16z4(4,&x_z16z1,&x_z16z_3,false,0.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),true,"shaded","female");

personClass x_z16z5(5,&x_z16z3,&x_z16z4,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),true,"shaded","male");

personClass x_z16z6(6,&x_z16z3,&x_z16z4,false,1.000000,1.000000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"shaded","female");

personClass x_z16z7(7,&x_z16z3,&x_z16z4,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),true,"shaded","male");

personClass x_z16z8(8,&x_z16z3,&x_z16z4,false,1.000000,1.000000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"shaded","female");

personClass x_z16z9(9,&x_z16z5,&x_z16z_6,false,1.000000,1.000000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"shaded","female");

personClass x_z16z10(10,&x_z16z5,&x_z16z_6,false,1.000000,1.000000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"shaded","female");

personClass x_z16z11(11,&x_z16z5,&x_z16z_6,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z16z12(12,&x_z16z5,&x_z16z_6,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z16z13(13,&x_z16z6,&x_z16z_9,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),false,"unshaded","female");

personClass x_z16z14(14,&x_z16z6,&x_z16z_9,false,0.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),true,"shaded","female");

personClass x_z16z15(15,&x_z16z6,&x_z16z_9,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),false,"unshaded","female");

personClass x_z16z16(16,&x_z16z7,&x_z16z_12,false,0.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),true,"shaded","female");

personClass x_z16z17(17,&x_z16z7,&x_z16z_12,false,1.000000,1.000000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"shaded","female");

personClass x_z16z18(18,&x_z16z7,&x_z16z_12,false,1.000000,1.000000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"shaded","female");

personClass x_z16z19(19,&x_z16z7,&x_z16z_12,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z16z20(20,&x_z16z7,&x_z16z_12,false,1.000000,1.000000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"shaded","female");

personClass x_z16z21(21,&x_z16z8,&x_z16z_15,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),false,"unshaded","female");

personClass x_z16z22(22,&x_z16z8,&x_z16z_15,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),false,"unshaded","female");

personClass x_z16z23(23,&x_z16z8,&x_z16z_15,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),false,"unshaded","female");

personClass x_z16z24(24,&x_z16z8,&x_z16z_15,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");

personClass x_z16z25(25,&x_z16z16,&x_z16z_18,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");

personClass x_z16z26(26,&x_z16z16,&x_z16z_18,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");

personClass x_z16z27(27,&x_z16z17,&x_z16z_21,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");

personClass x_z16z28(28,&x_z16z18,&x_z16z_24,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),false,"unshaded","female");














personClass x_z17z7(7,&x_z17z1,&x_z17z2,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z17z8(8,&x_z17z1,&x_z17z2,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z17z9(9,&x_z17z1,&x_z17z2,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z17z10(10,&x_z17z1,&x_z17z2,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),true,"shaded","male");

personClass x_z17z11(11,&x_z17z3,&x_z17z4,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z17z12(12,&x_z17z3,&x_z17z4,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z17z13(13,&x_z17z5,&x_z17z6,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z17z14(14,&x_z17z5,&x_z17z6,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z17z15(15,&x_z17z5,&x_z17z6,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z17z16(16,&x_z17z10,&x_z17z11,false,1.000000,1.000000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"shaded","female");

personClass x_z17z17(17,&x_z17z10,&x_z17z_1,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z17z18(18,&x_z17z10,&x_z17z11,false,0.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),true,"shaded","female");

personClass x_z17z19(19,&x_z17z11,&x_z17z_4,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");

personClass x_z17z20(20,&x_z17z12,&x_z17z_10,false,1.000000,0.500000,0.000000,3,5,8,vector<double>(8),false,vector<vector<vector<double>>>({{{0.500000,0.500000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.500000,0.500000,0.500000,0.500000},{0.250000,0.250000,0.250000,0.250000},{0.250000,0.250000,0.250000,0.250000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000}},{{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.500000,0.500000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.250000,0.250000,0.250000,0.250000},{0.250000,0.250000,0.250000,0.250000},{0.500000,0.500000,0.500000,0.500000}}}),false,"unshaded","unknown");

personClass x_z17z21(21,&x_z17z13,&x_z17z_23,false,1.000000,0.500000,0.000000,3,5,8,vector<double>(8),false,vector<vector<vector<double>>>({{{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000}},{{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000}},{{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","unknown");

personClass x_z17z22(22,&x_z17z14,&x_z17z_20,false,1.000000,0.500000,0.000000,3,5,8,vector<double>(8),false,vector<vector<vector<double>>>({{{0.500000,0.500000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.500000,0.500000,0.500000,0.500000},{0.250000,0.250000,0.250000,0.250000},{0.250000,0.250000,0.250000,0.250000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000}},{{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.500000,0.500000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.250000,0.250000,0.250000,0.250000},{0.250000,0.250000,0.250000,0.250000},{0.500000,0.500000,0.500000,0.500000}}}),false,"unshaded","unknown");

personClass x_z17z23(23,&x_z17z15,&x_z17z16,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z17z24(24,&x_z17z15,&x_z17z16,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z17z25(25,&x_z17z15,&x_z17z16,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),true,"shaded","male");

personClass x_z17z26(26,&x_z17z16,&x_z17z_13,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");

personClass x_z17z27(27,&x_z17z19,&x_z17z_7,false,1.000000,0.500000,0.000000,3,5,8,vector<double>(8),false,vector<vector<vector<double>>>({{{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000}},{{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000}},{{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","unknown");









personClass x_z18z4(4,&x_z18z_4,&x_z18z_5,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),true,"shaded","male");

personClass x_z18z5(5,&x_z18z_4,&x_z18z_5,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),true,"shaded","male");

personClass x_z18z6(6,&x_z18z_4,&x_z18z_5,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),true,"shaded","male");

personClass x_z18z7(7,&x_z18z_4,&x_z18z_5,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z18z8(8,&x_z18z_4,&x_z18z_5,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z18z9(9,&x_z18z_4,&x_z18z_5,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z18z10(10,&x_z18z1,&x_z18z2,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z18z11(11,&x_z18z1,&x_z18z2,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z18z12(12,&x_z18z1,&x_z18z2,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z18z13(13,&x_z18z1,&x_z18z2,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z18z14(14,&x_z18z3,&x_z18z4,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),false,"unshaded","female");

personClass x_z18z15(15,&x_z18z3,&x_z18z4,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),false,"unshaded","female");

personClass x_z18z16(16,&x_z18z3,&x_z18z4,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),false,"unshaded","female");

personClass x_z18z17(17,&x_z18z3,&x_z18z4,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");

personClass x_z18z18(18,&x_z18z13,&x_z18z14,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),true,"shaded","male");

personClass x_z18z19(19,&x_z18z13,&x_z18z14,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z18z20(20,&x_z18z18,&x_z18z_1,false,1.000000,0.500000,0.000000,3,5,8,vector<double>(8),false,vector<vector<vector<double>>>({{{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000}},{{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000}},{{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","unknown");

personClass x_z18z21(21,&x_z18z16,&x_z18z_9,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),false,"unshaded","female");

personClass x_z18z22(22,&x_z18z17,&x_z18z_6,false,1.000000,0.500000,0.000000,3,5,8,vector<double>(8),false,vector<vector<vector<double>>>({{{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000}},{{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000}},{{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","unknown");













    personClass x_z19z21(21,&x_z19z30,&x_z19z31,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");
    
    personClass x_z19z35(35,&x_z19z45,&x_z19z44,false,0.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),true,"shaded","female");

    
    personClass x_z19z18(18,&x_z19z34,&x_z19z35,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");
    
    personClass x_z19z16(16,&x_z19z34,&x_z19z35,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

    
    personClass x_z19z26(26,&x_z19z30,&x_z19z31,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");


personClass x_z19z1(1,&x_z19z26,&x_z19z_10,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z19z2(2,&x_z19z26,&x_z19z_10,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z19z3(3,&x_z19z21,&x_z19z_13,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z19z4(4,&x_z19z21,&x_z19z_13,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z19z9(9,&x_z19z18,&x_z19z_7,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),false,"unshaded","female");

personClass x_z19z10(10,&x_z19z18,&x_z19z_7,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),false,"unshaded","female");
    
    personClass x_z19z17(17,&x_z19z34,&x_z19z35,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");
    

personClass x_z19z11(11,&x_z19z17,&x_z19z_4,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),false,"unshaded","female");

personClass x_z19z12(12,&x_z19z17,&x_z19z_4,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");

personClass x_z19z13(13,&x_z19z16,&x_z19z_1,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z19z14(14,&x_z19z16,&x_z19z_1,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z19z15(15,&x_z19z16,&x_z19z_1,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");
personClass x_z19z23(23,&x_z19z18,&x_z19z_7,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");

personClass x_z19z24(24,&x_z19z34,&x_z19z35,false,0.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),true,"shaded","female");

personClass x_z19z25(25,&x_z19z30,&x_z19z31,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z19z27(27,&x_z19z25,&x_z19z24,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z19z28(28,&x_z19z25,&x_z19z24,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),true,"shaded","male");

personClass x_z19z29(29,&x_z19z25,&x_z19z24,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z19z32(32,&x_z19z30,&x_z19z_24,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z19z33(33,&x_z19z30,&x_z19z_24,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z19z36(36,&x_z19z45,&x_z19z44,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),true,"shaded","male");

personClass x_z19z37(37,&x_z19z45,&x_z19z44,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),true,"shaded","male");

personClass x_z19z38(38,&x_z19z45,&x_z19z44,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z19z39(39,&x_z19z45,&x_z19z44,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z19z40(40,&x_z19z36,&x_z19z_27,false,1.000000,0.500000,0.000000,3,5,8,vector<double>(8),false,vector<vector<vector<double>>>({{{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000}},{{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000}},{{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","unknown");

personClass x_z19z41(41,&x_z19z37,&x_z19z_30,false,1.000000,0.500000,0.000000,3,5,8,vector<double>(8),false,vector<vector<vector<double>>>({{{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000}},{{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000}},{{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","unknown");

personClass x_z19z42(42,&x_z19z38,&x_z19z_33,false,1.000000,0.500000,0.000000,3,5,8,vector<double>(8),false,vector<vector<vector<double>>>({{{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000}},{{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000}},{{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","unknown");

personClass x_z19z43(43,&x_z19z39,&x_z19z_36,false,1.000000,0.500000,0.000000,3,5,8,vector<double>(8),false,vector<vector<vector<double>>>({{{0.500000,0.500000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.500000,0.500000,0.500000,0.500000},{0.250000,0.250000,0.250000,0.250000},{0.250000,0.250000,0.250000,0.250000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000}},{{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.500000,0.500000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.250000,0.250000,0.250000,0.250000},{0.250000,0.250000,0.250000,0.250000},{0.500000,0.500000,0.500000,0.500000}}}),false,"unshaded","unknown");












personClass x_z20z4(4,&x_z20z1,&x_z20z2,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");
    
    personClass x_z20z14(14,&x_z20z23,&x_z20z24,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");
    

personClass x_z20z5(5,&x_z20z13,&x_z20z14,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z20z6(6,&x_z20z3,&x_z20z4,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),false,"unshaded","female");

personClass x_z20z7(7,&x_z20z4,&x_z20z5,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),true,"shaded","male");

personClass x_z20z8(8,&x_z20z4,&x_z20z5,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),true,"shaded","male");

personClass x_z20z10(10,&x_z20z5,&x_z20z9,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");

personClass x_z20z11(11,&x_z20z13,&x_z20z14,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z20z12(12,&x_z20z11,&x_z20z_1,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),false,"unshaded","female");
personClass x_z20z15(15,&x_z20z23,&x_z20z24,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z20z16(16,&x_z20z23,&x_z20z24,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z20z17(17,&x_z20z23,&x_z20z24,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z20z18(18,&x_z20z23,&x_z20z24,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z20z19(19,&x_z20z15,&x_z20z_4,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),true,"shaded","male");

personClass x_z20z20(20,&x_z20z16,&x_z20z_7,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z20z21(21,&x_z20z17,&x_z20z_10,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z20z22(22,&x_z20z17,&x_z20z_10,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");


x_z0z1.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z0z2,vector<personClass*>({&x_z0z6,&x_z0z7,&x_z0z8,&x_z0z9,&x_z0z10,&x_z0z12}))});

x_z0z4.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z0z5,vector<personClass*>({&x_z0z13,&x_z0z15,&x_z0z16,&x_z0z17,&x_z0z18,&x_z0z19}))});

x_z0z5.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z0z4,vector<personClass*>({&x_z0z13,&x_z0z15,&x_z0z16,&x_z0z17,&x_z0z18,&x_z0z19}))});

x_z0z11.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z0z12,vector<personClass*>({&x_z0z25}))});

x_z0z14.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z0z13,vector<personClass*>({&x_z0z28}))});

x_z0z29.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z0z28,vector<personClass*>({&x_z0z41}))});

x_z0z30.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z0z28,vector<personClass*>({&x_z0z42,&x_z0z43}))});

x_z0z31.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z0z28,vector<personClass*>({&x_z0z44}))});

x_z0z_1.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z0z_2,vector<personClass*>({&x_z0z2,&x_z0z3}))});

x_z0z_2.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z0z_1,vector<personClass*>({&x_z0z2,&x_z0z3}))});

x_z0z_12.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z0z7,vector<personClass*>({&x_z0z21,&x_z0z22}))});

x_z0z_9.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z0z8,vector<personClass*>({&x_z0z23}))});

x_z0z_6.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z0z10,vector<personClass*>({&x_z0z24}))});

x_z0z_15.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z0z16,vector<personClass*>({&x_z0z32,&x_z0z33}))});

x_z0z_18.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z0z17,vector<personClass*>({&x_z0z34}))});

x_z0z_21.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z0z18,vector<personClass*>({&x_z0z35}))});

x_z0z_24.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z0z19,vector<personClass*>({&x_z0z36,&x_z0z37}))});

x_z0z_3.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z0z26,vector<personClass*>({&x_z0z38,&x_z0z39,&x_z0z40}))});

x_z0z2.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z0z1,vector<personClass*>({&x_z0z6,&x_z0z7,&x_z0z8,&x_z0z9,&x_z0z10,&x_z0z12}))});

x_z0z3.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z0z6.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z0z7.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z0z_12,vector<personClass*>({&x_z0z21,&x_z0z22}))});

x_z0z8.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z0z_9,vector<personClass*>({&x_z0z23}))});

x_z0z9.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z0z10.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z0z_6,vector<personClass*>({&x_z0z24}))});

x_z0z12.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z0z13,vector<personClass*>({&x_z0z26,&x_z0z27})),pair<personClass*,vector<personClass*>>(&x_z0z11,vector<personClass*>({&x_z0z25}))});

x_z0z13.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z0z14,vector<personClass*>({&x_z0z28})),pair<personClass*,vector<personClass*>>(&x_z0z12,vector<personClass*>({&x_z0z26,&x_z0z27}))});

x_z0z15.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z0z16.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z0z_15,vector<personClass*>({&x_z0z32,&x_z0z33}))});

x_z0z17.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z0z_18,vector<personClass*>({&x_z0z34}))});

x_z0z18.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z0z_21,vector<personClass*>({&x_z0z35}))});

x_z0z19.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z0z_24,vector<personClass*>({&x_z0z36,&x_z0z37}))});

x_z0z21.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z0z22.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z0z23.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z0z24.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z0z25.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z0z26.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z0z_3,vector<personClass*>({&x_z0z38,&x_z0z39,&x_z0z40}))});

x_z0z27.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z0z28.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z0z31,vector<personClass*>({&x_z0z44})),pair<personClass*,vector<personClass*>>(&x_z0z29,vector<personClass*>({&x_z0z41})),pair<personClass*,vector<personClass*>>(&x_z0z30,vector<personClass*>({&x_z0z42,&x_z0z43}))});

x_z0z32.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z0z33.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z0z34.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z0z35.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z0z36.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z0z37.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z0z38.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z0z39.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z0z40.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z0z41.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z0z42.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z0z43.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z0z44.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

pedigreeClass2 pedigreez0z;
pedigreez0z.roots=vector<personClass*>({&x_z0z1,&x_z0z4,&x_z0z5,&x_z0z11,&x_z0z14,&x_z0z29,&x_z0z30,&x_z0z31,&x_z0z_1,&x_z0z_2,&x_z0z_12,&x_z0z_9,&x_z0z_6,&x_z0z_15,&x_z0z_18,&x_z0z_21,&x_z0z_24,&x_z0z_3});
pedigreez0z.allPeople=vector<personClass*>({&x_z0z1,&x_z0z2,&x_z0z3,&x_z0z4,&x_z0z5,&x_z0z6,&x_z0z7,&x_z0z8,&x_z0z9,&x_z0z10,&x_z0z11,&x_z0z12,&x_z0z13,&x_z0z14,&x_z0z15,&x_z0z16,&x_z0z17,&x_z0z18,&x_z0z19,&x_z0z21,&x_z0z22,&x_z0z23,&x_z0z24,&x_z0z25,&x_z0z26,&x_z0z27,&x_z0z28,&x_z0z29,&x_z0z30,&x_z0z31,&x_z0z32,&x_z0z33,&x_z0z34,&x_z0z35,&x_z0z36,&x_z0z37,&x_z0z38,&x_z0z39,&x_z0z40,&x_z0z41,&x_z0z42,&x_z0z43,&x_z0z44,&x_z0z_1,&x_z0z_2,&x_z0z_12,&x_z0z_9,&x_z0z_6,&x_z0z_15,&x_z0z_18,&x_z0z_21,&x_z0z_24,&x_z0z_3});
pedigreez0z.families=vector<vector<personClass*>>({{&x_z0z2,&x_z0z1,&x_z0z6,&x_z0z7,&x_z0z8,&x_z0z9,&x_z0z10,&x_z0z12},{&x_z0z31,&x_z0z28,&x_z0z44},{&x_z0z13,&x_z0z14,&x_z0z28},{&x_z0z_6,&x_z0z10,&x_z0z24},{&x_z0z17,&x_z0z_18,&x_z0z34},{&x_z0z29,&x_z0z28,&x_z0z41},{&x_z0z16,&x_z0z_15,&x_z0z32,&x_z0z33},{&x_z0z_9,&x_z0z8,&x_z0z23},{&x_z0z30,&x_z0z28,&x_z0z42,&x_z0z43},{&x_z0z18,&x_z0z_21,&x_z0z35},{&x_z0z5,&x_z0z4,&x_z0z13,&x_z0z15,&x_z0z16,&x_z0z17,&x_z0z18,&x_z0z19},{&x_z0z13,&x_z0z12,&x_z0z26,&x_z0z27},{&x_z0z11,&x_z0z12,&x_z0z25},{&x_z0z26,&x_z0z_3,&x_z0z38,&x_z0z39,&x_z0z40},{&x_z0z19,&x_z0z_24,&x_z0z36,&x_z0z37},{&x_z0z7,&x_z0z_12,&x_z0z21,&x_z0z22},{&x_z0z_2,&x_z0z_1,&x_z0z2,&x_z0z3}});
pedigreez0z.leaves=vector<personClass*>({&x_z0z3,&x_z0z6,&x_z0z9,&x_z0z15,&x_z0z21,&x_z0z22,&x_z0z23,&x_z0z24,&x_z0z25,&x_z0z27,&x_z0z32,&x_z0z33,&x_z0z34,&x_z0z35,&x_z0z36,&x_z0z37,&x_z0z38,&x_z0z39,&x_z0z40,&x_z0z41,&x_z0z42,&x_z0z43,&x_z0z44});
pedigreez0z.isDominant=true;
pedigreez0z.sexDependent=true;
pedigreez0z.mapToIndexRoots=unordered_map<personClass*,int>({{&x_z0z_3,17},{&x_z0z_24,16},{&x_z0z_18,14},{&x_z0z_15,13},{&x_z0z_9,11},{&x_z0z_1,8},{&x_z0z31,7},{&x_z0z_6,12},{&x_z0z30,6},{&x_z0z_21,15},{&x_z0z29,5},{&x_z0z_12,10},{&x_z0z14,4},{&x_z0z5,2},{&x_z0z11,3},{&x_z0z_2,9},{&x_z0z4,1},{&x_z0z1,0}});
pedigreez0z.mapToIndexAllPeople=unordered_map<personClass*,int>({{&x_z0z_3,52},{&x_z0z_15,48},{&x_z0z_6,47},{&x_z0z_9,46},{&x_z0z3,2},{&x_z0z_2,44},{&x_z0z43,41},{&x_z0z_12,45},{&x_z0z31,29},{&x_z0z39,37},{&x_z0z35,33},{&x_z0z18,17},{&x_z0z36,34},{&x_z0z34,32},{&x_z0z32,30},{&x_z0z25,23},{&x_z0z40,38},{&x_z0z38,36},{&x_z0z_24,51},{&x_z0z27,25},{&x_z0z4,3},{&x_z0z24,22},{&x_z0z41,39},{&x_z0z28,26},{&x_z0z23,21},{&x_z0z44,42},{&x_z0z21,19},{&x_z0z19,18},{&x_z0z26,24},{&x_z0z_1,43},{&x_z0z2,1},{&x_z0z9,8},{&x_z0z17,16},{&x_z0z16,15},{&x_z0z8,7},{&x_z0z6,5},{&x_z0z15,14},{&x_z0z13,12},{&x_z0z_21,50},{&x_z0z_18,49},{&x_z0z22,20},{&x_z0z12,11},{&x_z0z11,10},{&x_z0z10,9},{&x_z0z1,0},{&x_z0z30,28},{&x_z0z14,13},{&x_z0z37,35},{&x_z0z29,27},{&x_z0z7,6},{&x_z0z5,4},{&x_z0z42,40},{&x_z0z33,31}});

x_z1z1.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z1z_1,vector<personClass*>({&x_z1z2}))});

x_z1z3.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z1z2,vector<personClass*>({&x_z1z4,&x_z1z5,&x_z1z6}))});

x_z1z19.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z1z20,vector<personClass*>({&x_z1z7,&x_z1z8,&x_z1z9}))});

x_z1z20.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z1z19,vector<personClass*>({&x_z1z7,&x_z1z8,&x_z1z9}))});

x_z1z_1.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z1z1,vector<personClass*>({&x_z1z2}))});

x_z1z_18.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z1z5,vector<personClass*>({&x_z1z10,&x_z1z11}))});

x_z1z_12.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z1z8,vector<personClass*>({&x_z1z15,&x_z1z16}))});

x_z1z_15.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z1z9,vector<personClass*>({&x_z1z17,&x_z1z18}))});

x_z1z2.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z1z3,vector<personClass*>({&x_z1z4,&x_z1z5,&x_z1z6}))});

x_z1z4.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z1z5.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z1z_18,vector<personClass*>({&x_z1z10,&x_z1z11}))});

x_z1z6.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z1z7,vector<personClass*>({&x_z1z12,&x_z1z13,&x_z1z14}))});

x_z1z7.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z1z6,vector<personClass*>({&x_z1z12,&x_z1z13,&x_z1z14}))});

x_z1z8.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z1z_12,vector<personClass*>({&x_z1z15,&x_z1z16}))});

x_z1z9.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z1z_15,vector<personClass*>({&x_z1z17,&x_z1z18}))});

x_z1z10.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z1z11.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z1z12.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z1z13.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z1z14.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z1z15.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z1z16.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z1z17.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z1z18.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

pedigreeClass2 pedigreez1z;
pedigreez1z.roots=vector<personClass*>({&x_z1z1,&x_z1z3,&x_z1z19,&x_z1z20,&x_z1z_1,&x_z1z_18,&x_z1z_12,&x_z1z_15});
pedigreez1z.allPeople=vector<personClass*>({&x_z1z1,&x_z1z2,&x_z1z3,&x_z1z4,&x_z1z5,&x_z1z6,&x_z1z7,&x_z1z8,&x_z1z9,&x_z1z10,&x_z1z11,&x_z1z12,&x_z1z13,&x_z1z14,&x_z1z15,&x_z1z16,&x_z1z17,&x_z1z18,&x_z1z19,&x_z1z20,&x_z1z_1,&x_z1z_18,&x_z1z_12,&x_z1z_15});
pedigreez1z.families=vector<vector<personClass*>>({{&x_z1z3,&x_z1z2,&x_z1z4,&x_z1z5,&x_z1z6},{&x_z1z1,&x_z1z_1,&x_z1z2},{&x_z1z20,&x_z1z19,&x_z1z7,&x_z1z8,&x_z1z9},{&x_z1z_12,&x_z1z8,&x_z1z15,&x_z1z16},{&x_z1z9,&x_z1z_15,&x_z1z17,&x_z1z18},{&x_z1z_18,&x_z1z5,&x_z1z10,&x_z1z11},{&x_z1z7,&x_z1z6,&x_z1z12,&x_z1z13,&x_z1z14}});
pedigreez1z.leaves=vector<personClass*>({&x_z1z4,&x_z1z10,&x_z1z11,&x_z1z12,&x_z1z13,&x_z1z14,&x_z1z15,&x_z1z16,&x_z1z17,&x_z1z18});
pedigreez1z.isDominant=false;
pedigreez1z.sexDependent=true;
pedigreez1z.mapToIndexRoots=unordered_map<personClass*,int>({{&x_z1z_18,5},{&x_z1z19,2},{&x_z1z20,3},{&x_z1z3,1},{&x_z1z_15,7},{&x_z1z_1,4},{&x_z1z_12,6},{&x_z1z1,0}});
pedigreez1z.mapToIndexAllPeople=unordered_map<personClass*,int>({{&x_z1z_12,22},{&x_z1z18,17},{&x_z1z20,19},{&x_z1z19,18},{&x_z1z_18,21},{&x_z1z17,16},{&x_z1z15,14},{&x_z1z_15,23},{&x_z1z12,11},{&x_z1z4,3},{&x_z1z9,8},{&x_z1z13,12},{&x_z1z11,10},{&x_z1z16,15},{&x_z1z5,4},{&x_z1z10,9},{&x_z1z6,5},{&x_z1z14,13},{&x_z1z1,0},{&x_z1z2,1},{&x_z1z8,7},{&x_z1z_1,20},{&x_z1z7,6},{&x_z1z3,2}});

x_z2z2.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z2z3,vector<personClass*>({&x_z2z4,&x_z2z5,&x_z2z6}))});

x_z2z3.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z2z2,vector<personClass*>({&x_z2z4,&x_z2z5,&x_z2z6}))});

x_z2z7.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z2z4,vector<personClass*>({&x_z2z12,&x_z2z18}))});

x_z2z8.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z2z9,vector<personClass*>({&x_z2z10,&x_z2z11}))});

x_z2z9.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z2z8,vector<personClass*>({&x_z2z10,&x_z2z11}))});

x_z2z_1.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z2z6,vector<personClass*>({&x_z2z19}))});

x_z2z_15.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z2z10,vector<personClass*>({&x_z2z13,&x_z2z14}))});

x_z2z_4.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z2z19,vector<personClass*>({&x_z2z20}))});

x_z2z4.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z2z7,vector<personClass*>({&x_z2z12,&x_z2z18}))});

x_z2z5.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z2z6.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z2z_1,vector<personClass*>({&x_z2z19}))});

x_z2z10.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z2z_15,vector<personClass*>({&x_z2z13,&x_z2z14}))});

x_z2z11.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z2z12,vector<personClass*>({&x_z2z15,&x_z2z16}))});

x_z2z12.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z2z11,vector<personClass*>({&x_z2z15,&x_z2z16}))});

x_z2z13.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z2z14.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z2z15.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z2z16.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z2z18.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z2z19.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z2z_4,vector<personClass*>({&x_z2z20}))});

x_z2z20.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

pedigreeClass2 pedigreez2z;
pedigreez2z.roots=vector<personClass*>({&x_z2z2,&x_z2z3,&x_z2z7,&x_z2z8,&x_z2z9,&x_z2z_1,&x_z2z_15,&x_z2z_4});
pedigreez2z.allPeople=vector<personClass*>({&x_z2z2,&x_z2z3,&x_z2z4,&x_z2z5,&x_z2z6,&x_z2z7,&x_z2z8,&x_z2z9,&x_z2z10,&x_z2z11,&x_z2z12,&x_z2z13,&x_z2z14,&x_z2z15,&x_z2z16,&x_z2z18,&x_z2z19,&x_z2z20,&x_z2z_1,&x_z2z_15,&x_z2z_4});
pedigreez2z.families=vector<vector<personClass*>>({{&x_z2z3,&x_z2z2,&x_z2z4,&x_z2z5,&x_z2z6},{&x_z2z12,&x_z2z11,&x_z2z15,&x_z2z16},{&x_z2z9,&x_z2z8,&x_z2z10,&x_z2z11},{&x_z2z19,&x_z2z_4,&x_z2z20},{&x_z2z10,&x_z2z_15,&x_z2z13,&x_z2z14},{&x_z2z_1,&x_z2z6,&x_z2z19},{&x_z2z4,&x_z2z7,&x_z2z12,&x_z2z18}});
pedigreez2z.leaves=vector<personClass*>({&x_z2z5,&x_z2z13,&x_z2z14,&x_z2z15,&x_z2z16,&x_z2z18,&x_z2z20});
pedigreez2z.isDominant=false;
pedigreez2z.sexDependent=true;
pedigreez2z.mapToIndexRoots=unordered_map<personClass*,int>({{&x_z2z_15,6},{&x_z2z_1,5},{&x_z2z_4,7},{&x_z2z9,4},{&x_z2z7,2},{&x_z2z8,3},{&x_z2z3,1},{&x_z2z2,0}});
pedigreez2z.mapToIndexAllPeople=unordered_map<personClass*,int>({{&x_z2z_15,19},{&x_z2z_1,18},{&x_z2z20,17},{&x_z2z18,15},{&x_z2z15,13},{&x_z2z14,12},{&x_z2z19,16},{&x_z2z13,11},{&x_z2z10,8},{&x_z2z11,9},{&x_z2z9,7},{&x_z2z8,6},{&x_z2z_4,20},{&x_z2z7,5},{&x_z2z3,1},{&x_z2z16,14},{&x_z2z6,4},{&x_z2z12,10},{&x_z2z4,2},{&x_z2z5,3},{&x_z2z2,0}});

x_z3z1.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z3z2,vector<personClass*>({&x_z3z4,&x_z3z5,&x_z3z6,&x_z3z7,&x_z3z8}))});

x_z3z2.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z3z1,vector<personClass*>({&x_z3z4,&x_z3z5,&x_z3z6,&x_z3z7,&x_z3z8}))});

x_z3z3.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z3z4,vector<personClass*>({&x_z3z10,&x_z3z11,&x_z3z12,&x_z3z13}))});

x_z3z14.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z3z13,vector<personClass*>({&x_z3z41,&x_z3z42,&x_z3z43}))});

x_z3z50.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z3z43,vector<personClass*>({&x_z3z51,&x_z3z52,&x_z3z53,&x_z3z54}))});

x_z3z_10.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z3z4,vector<personClass*>({&x_z3z26,&x_z3z27}))});

x_z3z_7.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z3z6,vector<personClass*>({&x_z3z28,&x_z3z29}))});

x_z3z_4.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z3z7,vector<personClass*>({&x_z3z30}))});

x_z3z_1.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z3z8,vector<personClass*>({&x_z3z31}))});

x_z3z_23.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z3z10,vector<personClass*>({&x_z3z32,&x_z3z33}))});

x_z3z_26.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z3z11,vector<personClass*>({&x_z3z35,&x_z3z36}))});

x_z3z_29.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z3z12,vector<personClass*>({&x_z3z38}))});

x_z3z_99.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z3z41,vector<personClass*>({&x_z3z188}))});

x_z3z4.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z3z3,vector<personClass*>({&x_z3z10,&x_z3z11,&x_z3z12,&x_z3z13})),pair<personClass*,vector<personClass*>>(&x_z3z_10,vector<personClass*>({&x_z3z26,&x_z3z27}))});

x_z3z5.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z3z6.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z3z_7,vector<personClass*>({&x_z3z28,&x_z3z29}))});

x_z3z7.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z3z_4,vector<personClass*>({&x_z3z30}))});

x_z3z8.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z3z_1,vector<personClass*>({&x_z3z31}))});

x_z3z10.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z3z_23,vector<personClass*>({&x_z3z32,&x_z3z33}))});

x_z3z11.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z3z_26,vector<personClass*>({&x_z3z35,&x_z3z36}))});

x_z3z12.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z3z_29,vector<personClass*>({&x_z3z38}))});

x_z3z13.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z3z14,vector<personClass*>({&x_z3z41,&x_z3z42,&x_z3z43}))});

x_z3z26.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z3z27.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z3z28.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z3z29.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z3z30.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z3z31.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z3z32.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z3z33.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z3z35.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z3z36.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z3z38.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z3z41.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z3z_99,vector<personClass*>({&x_z3z188}))});

x_z3z42.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z3z43.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z3z50,vector<personClass*>({&x_z3z51,&x_z3z52,&x_z3z53,&x_z3z54}))});

x_z3z51.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z3z52.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z3z53.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z3z54.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z3z188.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

pedigreeClass2 pedigreez3z;
pedigreez3z.roots=vector<personClass*>({&x_z3z1,&x_z3z2,&x_z3z3,&x_z3z14,&x_z3z50,&x_z3z_10,&x_z3z_7,&x_z3z_4,&x_z3z_1,&x_z3z_23,&x_z3z_26,&x_z3z_29,&x_z3z_99});
pedigreez3z.allPeople=vector<personClass*>({&x_z3z1,&x_z3z2,&x_z3z3,&x_z3z4,&x_z3z5,&x_z3z6,&x_z3z7,&x_z3z8,&x_z3z10,&x_z3z11,&x_z3z12,&x_z3z13,&x_z3z14,&x_z3z26,&x_z3z27,&x_z3z28,&x_z3z29,&x_z3z30,&x_z3z31,&x_z3z32,&x_z3z33,&x_z3z35,&x_z3z36,&x_z3z38,&x_z3z41,&x_z3z42,&x_z3z43,&x_z3z50,&x_z3z51,&x_z3z52,&x_z3z53,&x_z3z54,&x_z3z188,&x_z3z_10,&x_z3z_7,&x_z3z_4,&x_z3z_1,&x_z3z_23,&x_z3z_26,&x_z3z_29,&x_z3z_99});
pedigreez3z.families=vector<vector<personClass*>>({{&x_z3z2,&x_z3z1,&x_z3z4,&x_z3z5,&x_z3z6,&x_z3z7,&x_z3z8},{&x_z3z10,&x_z3z_23,&x_z3z32,&x_z3z33},{&x_z3z_4,&x_z3z7,&x_z3z30},{&x_z3z14,&x_z3z13,&x_z3z41,&x_z3z42,&x_z3z43},{&x_z3z41,&x_z3z_99,&x_z3z188},{&x_z3z6,&x_z3z_7,&x_z3z28,&x_z3z29},{&x_z3z11,&x_z3z_26,&x_z3z35,&x_z3z36},{&x_z3z_29,&x_z3z12,&x_z3z38},{&x_z3z43,&x_z3z50,&x_z3z51,&x_z3z52,&x_z3z53,&x_z3z54},{&x_z3z4,&x_z3z3,&x_z3z10,&x_z3z11,&x_z3z12,&x_z3z13},{&x_z3z4,&x_z3z_10,&x_z3z26,&x_z3z27},{&x_z3z_1,&x_z3z8,&x_z3z31}});
pedigreez3z.leaves=vector<personClass*>({&x_z3z5,&x_z3z26,&x_z3z27,&x_z3z28,&x_z3z29,&x_z3z30,&x_z3z31,&x_z3z32,&x_z3z33,&x_z3z35,&x_z3z36,&x_z3z38,&x_z3z42,&x_z3z51,&x_z3z52,&x_z3z53,&x_z3z54,&x_z3z188});
pedigreez3z.isDominant=false;
pedigreez3z.sexDependent=true;
pedigreez3z.mapToIndexRoots=unordered_map<personClass*,int>({{&x_z3z_29,11},{&x_z3z1,0},{&x_z3z_1,8},{&x_z3z2,1},{&x_z3z_26,10},{&x_z3z_7,6},{&x_z3z_10,5},{&x_z3z_99,12},{&x_z3z14,3},{&x_z3z3,2},{&x_z3z50,4},{&x_z3z_23,9},{&x_z3z_4,7}});
pedigreez3z.mapToIndexAllPeople=unordered_map<personClass*,int>({{&x_z3z_4,35},{&x_z3z_10,33},{&x_z3z188,32},{&x_z3z52,29},{&x_z3z50,27},{&x_z3z_7,34},{&x_z3z43,26},{&x_z3z41,24},{&x_z3z38,23},{&x_z3z53,30},{&x_z3z33,20},{&x_z3z32,19},{&x_z3z31,18},{&x_z3z29,16},{&x_z3z28,15},{&x_z3z26,13},{&x_z3z_99,40},{&x_z3z_29,39},{&x_z3z14,12},{&x_z3z12,10},{&x_z3z13,11},{&x_z3z_1,36},{&x_z3z6,5},{&x_z3z30,17},{&x_z3z1,0},{&x_z3z_23,37},{&x_z3z35,21},{&x_z3z7,6},{&x_z3z2,1},{&x_z3z11,9},{&x_z3z10,8},{&x_z3z5,4},{&x_z3z_26,38},{&x_z3z36,22},{&x_z3z4,3},{&x_z3z42,25},{&x_z3z8,7},{&x_z3z54,31},{&x_z3z3,2},{&x_z3z51,28},{&x_z3z27,14}});

x_z4z1.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z4z2,vector<personClass*>({&x_z4z8,&x_z4z9,&x_z4z10,&x_z4z11}))});

x_z4z2.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z4z1,vector<personClass*>({&x_z4z8,&x_z4z9,&x_z4z10,&x_z4z11}))});

x_z4z3.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z4z4,vector<personClass*>({&x_z4z12,&x_z4z13,&x_z4z14,&x_z4z15}))});

x_z4z6.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z4z7,vector<personClass*>({&x_z4z4,&x_z4z5}))});

x_z4z7.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z4z6,vector<personClass*>({&x_z4z4,&x_z4z5}))});

x_z4z_1.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z4z5,vector<personClass*>({&x_z4z16,&x_z4z17}))});

x_z4z_11.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z4z8,vector<personClass*>({&x_z4z18}))});

x_z4z_14.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z4z10,vector<personClass*>({&x_z4z19}))});

x_z4z_4.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z4z12,vector<personClass*>({&x_z4z22}))});

x_z4z_17.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z4z13,vector<personClass*>({&x_z4z23,&x_z4z24}))});

x_z4z_20.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z4z14,vector<personClass*>({&x_z4z25}))});

x_z4z_23.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z4z15,vector<personClass*>({&x_z4z26}))});

x_z4z4.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z4z3,vector<personClass*>({&x_z4z12,&x_z4z13,&x_z4z14,&x_z4z15}))});

x_z4z5.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z4z_1,vector<personClass*>({&x_z4z16,&x_z4z17}))});

x_z4z8.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z4z_11,vector<personClass*>({&x_z4z18}))});

x_z4z9.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z4z10.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z4z_14,vector<personClass*>({&x_z4z19}))});

x_z4z11.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z4z12,vector<personClass*>({&x_z4z20,&x_z4z21}))});

x_z4z12.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z4z11,vector<personClass*>({&x_z4z20,&x_z4z21})),pair<personClass*,vector<personClass*>>(&x_z4z_4,vector<personClass*>({&x_z4z22}))});

x_z4z13.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z4z_17,vector<personClass*>({&x_z4z23,&x_z4z24}))});

x_z4z14.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z4z_20,vector<personClass*>({&x_z4z25}))});

x_z4z15.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z4z_23,vector<personClass*>({&x_z4z26}))});

x_z4z16.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z4z17.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z4z18.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z4z19.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z4z20.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z4z21.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z4z22.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z4z23.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z4z24.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z4z25.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z4z26.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

pedigreeClass2 pedigreez4z;
pedigreez4z.roots=vector<personClass*>({&x_z4z1,&x_z4z2,&x_z4z3,&x_z4z6,&x_z4z7,&x_z4z_1,&x_z4z_11,&x_z4z_14,&x_z4z_4,&x_z4z_17,&x_z4z_20,&x_z4z_23});
pedigreez4z.allPeople=vector<personClass*>({&x_z4z1,&x_z4z2,&x_z4z3,&x_z4z4,&x_z4z5,&x_z4z6,&x_z4z7,&x_z4z8,&x_z4z9,&x_z4z10,&x_z4z11,&x_z4z12,&x_z4z13,&x_z4z14,&x_z4z15,&x_z4z16,&x_z4z17,&x_z4z18,&x_z4z19,&x_z4z20,&x_z4z21,&x_z4z22,&x_z4z23,&x_z4z24,&x_z4z25,&x_z4z26,&x_z4z_1,&x_z4z_11,&x_z4z_14,&x_z4z_4,&x_z4z_17,&x_z4z_20,&x_z4z_23});
pedigreez4z.families=vector<vector<personClass*>>({{&x_z4z10,&x_z4z_14,&x_z4z19},{&x_z4z_23,&x_z4z15,&x_z4z26},{&x_z4z2,&x_z4z1,&x_z4z8,&x_z4z9,&x_z4z10,&x_z4z11},{&x_z4z13,&x_z4z_17,&x_z4z23,&x_z4z24},{&x_z4z_20,&x_z4z14,&x_z4z25},{&x_z4z_11,&x_z4z8,&x_z4z18},{&x_z4z5,&x_z4z_1,&x_z4z16,&x_z4z17},{&x_z4z4,&x_z4z3,&x_z4z12,&x_z4z13,&x_z4z14,&x_z4z15},{&x_z4z12,&x_z4z11,&x_z4z20,&x_z4z21},{&x_z4z7,&x_z4z6,&x_z4z4,&x_z4z5},{&x_z4z12,&x_z4z_4,&x_z4z22}});
pedigreez4z.leaves=vector<personClass*>({&x_z4z9,&x_z4z16,&x_z4z17,&x_z4z18,&x_z4z19,&x_z4z20,&x_z4z21,&x_z4z22,&x_z4z23,&x_z4z24,&x_z4z25,&x_z4z26});
pedigreez4z.isDominant=false;
pedigreez4z.sexDependent=true;
pedigreez4z.mapToIndexRoots=unordered_map<personClass*,int>({{&x_z4z_17,9},{&x_z4z_20,10},{&x_z4z_14,7},{&x_z4z_11,6},{&x_z4z_4,8},{&x_z4z6,3},{&x_z4z3,2},{&x_z4z2,1},{&x_z4z7,4},{&x_z4z_23,11},{&x_z4z_1,5},{&x_z4z1,0}});
pedigreez4z.mapToIndexAllPeople=unordered_map<personClass*,int>({{&x_z4z_23,32},{&x_z4z_20,31},{&x_z4z_11,27},{&x_z4z_1,26},{&x_z4z26,25},{&x_z4z25,24},{&x_z4z24,23},{&x_z4z20,19},{&x_z4z17,16},{&x_z4z16,15},{&x_z4z22,21},{&x_z4z15,14},{&x_z4z14,13},{&x_z4z23,22},{&x_z4z19,18},{&x_z4z12,11},{&x_z4z11,10},{&x_z4z5,4},{&x_z4z_17,30},{&x_z4z9,8},{&x_z4z18,17},{&x_z4z8,7},{&x_z4z_4,29},{&x_z4z2,1},{&x_z4z7,6},{&x_z4z10,9},{&x_z4z6,5},{&x_z4z4,3},{&x_z4z3,2},{&x_z4z_14,28},{&x_z4z21,20},{&x_z4z13,12},{&x_z4z1,0}});

x_z5z6.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z5z5,vector<personClass*>({&x_z5z15,&x_z5z16}))});

x_z5z8.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z5z7,vector<personClass*>({&x_z5z17,&x_z5z18,&x_z5z19,&x_z5z43}))});

x_z5z27.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z5z28,vector<personClass*>({&x_z5z35,&x_z5z36,&x_z5z37,&x_z5z38}))});

x_z5z_1.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z5z_2,vector<personClass*>({&x_z5z2,&x_z5z3,&x_z5z4,&x_z5z5,&x_z5z23}))});

x_z5z_2.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z5z_1,vector<personClass*>({&x_z5z2,&x_z5z3,&x_z5z4,&x_z5z5,&x_z5z23}))});

x_z5z_3.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z5z2,vector<personClass*>({&x_z5z12,&x_z5z13,&x_z5z14}))});

x_z5z_15.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z5z_16,vector<personClass*>({&x_z5z7,&x_z5z9,&x_z5z10,&x_z5z11}))});

x_z5z_16.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z5z_15,vector<personClass*>({&x_z5z7,&x_z5z9,&x_z5z10,&x_z5z11}))});

x_z5z_32.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z5z10,vector<personClass*>({&x_z5z20,&x_z5z22}))});

x_z5z_6.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z5z13,vector<personClass*>({&x_z5z24}))});

x_z5z_9.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z5z15,vector<personClass*>({&x_z5z25,&x_z5z26}))});

x_z5z_17.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z5z18,vector<personClass*>({&x_z5z30,&x_z5z31}))});

x_z5z_20.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z5z19,vector<personClass*>({&x_z5z32}))});

x_z5z_23.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z5z20,vector<personClass*>({&x_z5z33}))});

x_z5z_26.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z5z22,vector<personClass*>({&x_z5z34}))});

x_z5z_12.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z5z29,vector<personClass*>({&x_z5z39,&x_z5z40,&x_z5z41}))});

x_z5z2.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z5z_3,vector<personClass*>({&x_z5z12,&x_z5z13,&x_z5z14}))});

x_z5z3.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z5z4.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z5z5.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z5z6,vector<personClass*>({&x_z5z15,&x_z5z16}))});

x_z5z7.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z5z8,vector<personClass*>({&x_z5z17,&x_z5z18,&x_z5z19,&x_z5z43}))});

x_z5z9.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z5z10.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z5z_32,vector<personClass*>({&x_z5z20,&x_z5z22}))});

x_z5z11.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z5z12.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z5z13.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z5z_6,vector<personClass*>({&x_z5z24}))});

x_z5z14.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z5z15.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z5z_9,vector<personClass*>({&x_z5z25,&x_z5z26}))});

x_z5z16.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z5z17,vector<personClass*>({&x_z5z28,&x_z5z29}))});

x_z5z17.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z5z16,vector<personClass*>({&x_z5z28,&x_z5z29}))});

x_z5z18.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z5z_17,vector<personClass*>({&x_z5z30,&x_z5z31}))});

x_z5z19.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z5z_20,vector<personClass*>({&x_z5z32}))});

x_z5z20.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z5z_23,vector<personClass*>({&x_z5z33}))});

x_z5z22.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z5z_26,vector<personClass*>({&x_z5z34}))});

x_z5z23.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z5z24.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z5z25.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z5z26.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z5z28.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z5z27,vector<personClass*>({&x_z5z35,&x_z5z36,&x_z5z37,&x_z5z38}))});

x_z5z29.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z5z_12,vector<personClass*>({&x_z5z39,&x_z5z40,&x_z5z41}))});

x_z5z30.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z5z31.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z5z32.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z5z33.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z5z34.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z5z35.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z5z36.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z5z37.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z5z38.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z5z39.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z5z40.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z5z41.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z5z43.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

pedigreeClass2 pedigreez5z;
pedigreez5z.roots=vector<personClass*>({&x_z5z6,&x_z5z8,&x_z5z27,&x_z5z_1,&x_z5z_2,&x_z5z_3,&x_z5z_15,&x_z5z_16,&x_z5z_32,&x_z5z_6,&x_z5z_9,&x_z5z_17,&x_z5z_20,&x_z5z_23,&x_z5z_26,&x_z5z_12});
pedigreez5z.allPeople=vector<personClass*>({&x_z5z2,&x_z5z3,&x_z5z4,&x_z5z5,&x_z5z6,&x_z5z7,&x_z5z8,&x_z5z9,&x_z5z10,&x_z5z11,&x_z5z12,&x_z5z13,&x_z5z14,&x_z5z15,&x_z5z16,&x_z5z17,&x_z5z18,&x_z5z19,&x_z5z20,&x_z5z22,&x_z5z23,&x_z5z24,&x_z5z25,&x_z5z26,&x_z5z27,&x_z5z28,&x_z5z29,&x_z5z30,&x_z5z31,&x_z5z32,&x_z5z33,&x_z5z34,&x_z5z35,&x_z5z36,&x_z5z37,&x_z5z38,&x_z5z39,&x_z5z40,&x_z5z41,&x_z5z43,&x_z5z_1,&x_z5z_2,&x_z5z_3,&x_z5z_15,&x_z5z_16,&x_z5z_32,&x_z5z_6,&x_z5z_9,&x_z5z_17,&x_z5z_20,&x_z5z_23,&x_z5z_26,&x_z5z_12});
pedigreez5z.families=vector<vector<personClass*>>({{&x_z5z_17,&x_z5z18,&x_z5z30,&x_z5z31},{&x_z5z2,&x_z5z_3,&x_z5z12,&x_z5z13,&x_z5z14},{&x_z5z27,&x_z5z28,&x_z5z35,&x_z5z36,&x_z5z37,&x_z5z38},{&x_z5z_20,&x_z5z19,&x_z5z32},{&x_z5z_16,&x_z5z_15,&x_z5z7,&x_z5z9,&x_z5z10,&x_z5z11},{&x_z5z13,&x_z5z_6,&x_z5z24},{&x_z5z10,&x_z5z_32,&x_z5z20,&x_z5z22},{&x_z5z_23,&x_z5z20,&x_z5z33},{&x_z5z8,&x_z5z7,&x_z5z17,&x_z5z18,&x_z5z19,&x_z5z43},{&x_z5z_26,&x_z5z22,&x_z5z34},{&x_z5z6,&x_z5z5,&x_z5z15,&x_z5z16},{&x_z5z29,&x_z5z_12,&x_z5z39,&x_z5z40,&x_z5z41},{&x_z5z17,&x_z5z16,&x_z5z28,&x_z5z29},{&x_z5z_9,&x_z5z15,&x_z5z25,&x_z5z26},{&x_z5z_2,&x_z5z_1,&x_z5z2,&x_z5z3,&x_z5z4,&x_z5z5,&x_z5z23}});
pedigreez5z.leaves=vector<personClass*>({&x_z5z3,&x_z5z4,&x_z5z9,&x_z5z11,&x_z5z12,&x_z5z14,&x_z5z23,&x_z5z24,&x_z5z25,&x_z5z26,&x_z5z30,&x_z5z31,&x_z5z32,&x_z5z33,&x_z5z34,&x_z5z35,&x_z5z36,&x_z5z37,&x_z5z38,&x_z5z39,&x_z5z40,&x_z5z41,&x_z5z43});
pedigreez5z.isDominant=false;
pedigreez5z.sexDependent=true;
pedigreez5z.mapToIndexRoots=unordered_map<personClass*,int>({{&x_z5z_12,15},{&x_z5z_26,14},{&x_z5z_23,13},{&x_z5z_17,11},{&x_z5z_9,10},{&x_z5z27,2},{&x_z5z_32,8},{&x_z5z_15,6},{&x_z5z_3,5},{&x_z5z_16,7},{&x_z5z_20,12},{&x_z5z6,0},{&x_z5z_2,4},{&x_z5z_1,3},{&x_z5z8,1},{&x_z5z_6,9}});
pedigreez5z.mapToIndexAllPeople=unordered_map<personClass*,int>({{&x_z5z_12,52},{&x_z5z_26,51},{&x_z5z_23,50},{&x_z5z_20,49},{&x_z5z_17,48},{&x_z5z_6,46},{&x_z5z30,27},{&x_z5z_32,45},{&x_z5z_16,44},{&x_z5z_15,43},{&x_z5z18,16},{&x_z5z16,14},{&x_z5z_3,42},{&x_z5z_2,41},{&x_z5z40,37},{&x_z5z36,33},{&x_z5z9,7},{&x_z5z34,31},{&x_z5z33,30},{&x_z5z39,36},{&x_z5z29,26},{&x_z5z28,25},{&x_z5z27,24},{&x_z5z23,20},{&x_z5z43,39},{&x_z5z_1,40},{&x_z5z22,19},{&x_z5z20,18},{&x_z5z32,29},{&x_z5z31,28},{&x_z5z19,17},{&x_z5z26,23},{&x_z5z7,5},{&x_z5z13,11},{&x_z5z38,35},{&x_z5z17,15},{&x_z5z35,32},{&x_z5z11,9},{&x_z5z_9,47},{&x_z5z25,22},{&x_z5z41,38},{&x_z5z5,3},{&x_z5z8,6},{&x_z5z10,8},{&x_z5z37,34},{&x_z5z12,10},{&x_z5z14,12},{&x_z5z2,0},{&x_z5z4,2},{&x_z5z6,4},{&x_z5z24,21},{&x_z5z15,13},{&x_z5z3,1}});

x_z6z1.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z6z2,vector<personClass*>({&x_z6z5,&x_z6z6,&x_z6z7,&x_z6z9,&x_z6z10,&x_z6z11,&x_z6z12,&x_z6z13}))});

x_z6z8.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z6z7,vector<personClass*>({&x_z6z20,&x_z6z21,&x_z6z22,&x_z6z23}))});

x_z6z19.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z6z20,vector<personClass*>({&x_z6z30}))});

x_z6z_1.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z6z_2,vector<personClass*>({&x_z6z2,&x_z6z3}))});

x_z6z_2.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z6z_1,vector<personClass*>({&x_z6z2,&x_z6z3}))});

x_z6z_3.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z6z3,vector<personClass*>({&x_z6z4}))});

x_z6z_6.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z6z5,vector<personClass*>({&x_z6z14,&x_z6z15}))});

x_z6z_9.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z6z6,vector<personClass*>({&x_z6z16,&x_z6z17,&x_z6z18}))});

x_z6z_15.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z6z9,vector<personClass*>({&x_z6z24}))});

x_z6z_20.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z6z9,vector<personClass*>({&x_z6z25}))});

x_z6z_25.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z6z10,vector<personClass*>({&x_z6z26}))});

x_z6z_28.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z6z11,vector<personClass*>({&x_z6z27}))});

x_z6z_31.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z6z12,vector<personClass*>({&x_z6z28,&x_z6z29}))});

x_z6z_12.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z6z21,vector<personClass*>({&x_z6z31,&x_z6z32,&x_z6z33}))});

x_z6z2.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z6z1,vector<personClass*>({&x_z6z5,&x_z6z6,&x_z6z7,&x_z6z9,&x_z6z10,&x_z6z11,&x_z6z12,&x_z6z13}))});

x_z6z3.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z6z_3,vector<personClass*>({&x_z6z4}))});

x_z6z4.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z6z5.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z6z_6,vector<personClass*>({&x_z6z14,&x_z6z15}))});

x_z6z6.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z6z_9,vector<personClass*>({&x_z6z16,&x_z6z17,&x_z6z18}))});

x_z6z7.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z6z8,vector<personClass*>({&x_z6z20,&x_z6z21,&x_z6z22,&x_z6z23}))});

x_z6z9.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z6z_15,vector<personClass*>({&x_z6z24})),pair<personClass*,vector<personClass*>>(&x_z6z_20,vector<personClass*>({&x_z6z25}))});

x_z6z10.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z6z_25,vector<personClass*>({&x_z6z26}))});

x_z6z11.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z6z_28,vector<personClass*>({&x_z6z27}))});

x_z6z12.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z6z_31,vector<personClass*>({&x_z6z28,&x_z6z29}))});

x_z6z13.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z6z14.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z6z15.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z6z16.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z6z17.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z6z18.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z6z20.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z6z19,vector<personClass*>({&x_z6z30}))});

x_z6z21.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z6z_12,vector<personClass*>({&x_z6z31,&x_z6z32,&x_z6z33}))});

x_z6z22.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z6z23.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z6z24.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z6z25.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z6z26.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z6z27.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z6z28.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z6z29.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z6z30.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z6z31.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z6z32.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z6z33.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

pedigreeClass2 pedigreez6z;
pedigreez6z.roots=vector<personClass*>({&x_z6z1,&x_z6z8,&x_z6z19,&x_z6z_1,&x_z6z_2,&x_z6z_3,&x_z6z_6,&x_z6z_9,&x_z6z_15,&x_z6z_20,&x_z6z_25,&x_z6z_28,&x_z6z_31,&x_z6z_12});
pedigreez6z.allPeople=vector<personClass*>({&x_z6z1,&x_z6z2,&x_z6z3,&x_z6z4,&x_z6z5,&x_z6z6,&x_z6z7,&x_z6z8,&x_z6z9,&x_z6z10,&x_z6z11,&x_z6z12,&x_z6z13,&x_z6z14,&x_z6z15,&x_z6z16,&x_z6z17,&x_z6z18,&x_z6z19,&x_z6z20,&x_z6z21,&x_z6z22,&x_z6z23,&x_z6z24,&x_z6z25,&x_z6z26,&x_z6z27,&x_z6z28,&x_z6z29,&x_z6z30,&x_z6z31,&x_z6z32,&x_z6z33,&x_z6z_1,&x_z6z_2,&x_z6z_3,&x_z6z_6,&x_z6z_9,&x_z6z_15,&x_z6z_20,&x_z6z_25,&x_z6z_28,&x_z6z_31,&x_z6z_12});
pedigreez6z.families=vector<vector<personClass*>>({{&x_z6z2,&x_z6z1,&x_z6z5,&x_z6z6,&x_z6z7,&x_z6z9,&x_z6z10,&x_z6z11,&x_z6z12,&x_z6z13},{&x_z6z21,&x_z6z_12,&x_z6z31,&x_z6z32,&x_z6z33},{&x_z6z_9,&x_z6z6,&x_z6z16,&x_z6z17,&x_z6z18},{&x_z6z_28,&x_z6z11,&x_z6z27},{&x_z6z_31,&x_z6z12,&x_z6z28,&x_z6z29},{&x_z6z_3,&x_z6z3,&x_z6z4},{&x_z6z_25,&x_z6z10,&x_z6z26},{&x_z6z20,&x_z6z19,&x_z6z30},{&x_z6z_15,&x_z6z9,&x_z6z24},{&x_z6z_6,&x_z6z5,&x_z6z14,&x_z6z15},{&x_z6z8,&x_z6z7,&x_z6z20,&x_z6z21,&x_z6z22,&x_z6z23},{&x_z6z_20,&x_z6z9,&x_z6z25},{&x_z6z_2,&x_z6z_1,&x_z6z2,&x_z6z3}});
pedigreez6z.leaves=vector<personClass*>({&x_z6z4,&x_z6z13,&x_z6z14,&x_z6z15,&x_z6z16,&x_z6z17,&x_z6z18,&x_z6z22,&x_z6z23,&x_z6z24,&x_z6z25,&x_z6z26,&x_z6z27,&x_z6z28,&x_z6z29,&x_z6z30,&x_z6z31,&x_z6z32,&x_z6z33});
pedigreez6z.isDominant=false;
pedigreez6z.sexDependent=true;
pedigreez6z.mapToIndexRoots=unordered_map<personClass*,int>({{&x_z6z_12,13},{&x_z6z_31,12},{&x_z6z_25,10},{&x_z6z_20,9},{&x_z6z_3,5},{&x_z6z_2,4},{&x_z6z_9,7},{&x_z6z_1,3},{&x_z6z_15,8},{&x_z6z19,2},{&x_z6z8,1},{&x_z6z_6,6},{&x_z6z_28,11},{&x_z6z1,0}});
pedigreez6z.mapToIndexAllPeople=unordered_map<personClass*,int>({{&x_z6z_31,42},{&x_z6z_28,41},{&x_z6z_15,38},{&x_z6z_25,40},{&x_z6z_9,37},{&x_z6z_6,36},{&x_z6z_12,43},{&x_z6z_2,34},{&x_z6z33,32},{&x_z6z31,30},{&x_z6z27,26},{&x_z6z26,25},{&x_z6z25,24},{&x_z6z24,23},{&x_z6z23,22},{&x_z6z_1,33},{&x_z6z21,20},{&x_z6z28,27},{&x_z6z20,19},{&x_z6z19,18},{&x_z6z_3,35},{&x_z6z16,15},{&x_z6z_20,39},{&x_z6z30,29},{&x_z6z13,12},{&x_z6z12,11},{&x_z6z6,5},{&x_z6z2,1},{&x_z6z11,10},{&x_z6z10,9},{&x_z6z14,13},{&x_z6z22,21},{&x_z6z4,3},{&x_z6z15,14},{&x_z6z9,8},{&x_z6z1,0},{&x_z6z18,17},{&x_z6z7,6},{&x_z6z17,16},{&x_z6z29,28},{&x_z6z5,4},{&x_z6z32,31},{&x_z6z8,7},{&x_z6z3,2}});

x_z7z1.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z7z2,vector<personClass*>({&x_z7z3,&x_z7z4}))});

x_z7z2.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z7z1,vector<personClass*>({&x_z7z3,&x_z7z4}))});

x_z7z5.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z7z4,vector<personClass*>({&x_z7z7,&x_z7z8,&x_z7z9,&x_z7z10}))});

x_z7z6.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z7z7,vector<personClass*>({&x_z7z11,&x_z7z12,&x_z7z13,&x_z7z14,&x_z7z15,&x_z7z16}))});

x_z7z_23.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z7z8,vector<personClass*>({&x_z7z17,&x_z7z18,&x_z7z19}))});

x_z7z_26.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z7z9,vector<personClass*>({&x_z7z20,&x_z7z21}))});

x_z7z_29.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z7z10,vector<personClass*>({&x_z7z22,&x_z7z23}))});

x_z7z_1.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z7z11,vector<personClass*>({&x_z7z24}))});

x_z7z_4.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z7z12,vector<personClass*>({&x_z7z25}))});

x_z7z_7.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z7z13,vector<personClass*>({&x_z7z26,&x_z7z27}))});

x_z7z_10.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z7z14,vector<personClass*>({&x_z7z28}))});

x_z7z_15.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z7z14,vector<personClass*>({&x_z7z29,&x_z7z30}))});

x_z7z_20.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z7z16,vector<personClass*>({&x_z7z31,&x_z7z32}))});

x_z7z3.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z7z4.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z7z5,vector<personClass*>({&x_z7z7,&x_z7z8,&x_z7z9,&x_z7z10}))});

x_z7z7.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z7z6,vector<personClass*>({&x_z7z11,&x_z7z12,&x_z7z13,&x_z7z14,&x_z7z15,&x_z7z16}))});

x_z7z8.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z7z_23,vector<personClass*>({&x_z7z17,&x_z7z18,&x_z7z19}))});

x_z7z9.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z7z_26,vector<personClass*>({&x_z7z20,&x_z7z21}))});

x_z7z10.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z7z_29,vector<personClass*>({&x_z7z22,&x_z7z23}))});

x_z7z11.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z7z_1,vector<personClass*>({&x_z7z24}))});

x_z7z12.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z7z_4,vector<personClass*>({&x_z7z25}))});

x_z7z13.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z7z_7,vector<personClass*>({&x_z7z26,&x_z7z27}))});

x_z7z14.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z7z_15,vector<personClass*>({&x_z7z29,&x_z7z30})),pair<personClass*,vector<personClass*>>(&x_z7z_10,vector<personClass*>({&x_z7z28}))});

x_z7z15.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z7z16.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z7z_20,vector<personClass*>({&x_z7z31,&x_z7z32}))});

x_z7z17.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z7z18.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z7z19.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z7z20.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z7z21.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z7z22.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z7z23.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z7z24.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z7z25.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z7z26.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z7z27.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z7z28.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z7z29.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z7z30.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z7z31.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z7z32.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

pedigreeClass2 pedigreez7z;
pedigreez7z.roots=vector<personClass*>({&x_z7z1,&x_z7z2,&x_z7z5,&x_z7z6,&x_z7z_23,&x_z7z_26,&x_z7z_29,&x_z7z_1,&x_z7z_4,&x_z7z_7,&x_z7z_10,&x_z7z_15,&x_z7z_20});
pedigreez7z.allPeople=vector<personClass*>({&x_z7z1,&x_z7z2,&x_z7z3,&x_z7z4,&x_z7z5,&x_z7z6,&x_z7z7,&x_z7z8,&x_z7z9,&x_z7z10,&x_z7z11,&x_z7z12,&x_z7z13,&x_z7z14,&x_z7z15,&x_z7z16,&x_z7z17,&x_z7z18,&x_z7z19,&x_z7z20,&x_z7z21,&x_z7z22,&x_z7z23,&x_z7z24,&x_z7z25,&x_z7z26,&x_z7z27,&x_z7z28,&x_z7z29,&x_z7z30,&x_z7z31,&x_z7z32,&x_z7z_23,&x_z7z_26,&x_z7z_29,&x_z7z_1,&x_z7z_4,&x_z7z_7,&x_z7z_10,&x_z7z_15,&x_z7z_20});
pedigreez7z.families=vector<vector<personClass*>>({{&x_z7z_29,&x_z7z10,&x_z7z22,&x_z7z23},{&x_z7z2,&x_z7z1,&x_z7z3,&x_z7z4},{&x_z7z_15,&x_z7z14,&x_z7z29,&x_z7z30},{&x_z7z16,&x_z7z_20,&x_z7z31,&x_z7z32},{&x_z7z8,&x_z7z_23,&x_z7z17,&x_z7z18,&x_z7z19},{&x_z7z_10,&x_z7z14,&x_z7z28},{&x_z7z5,&x_z7z4,&x_z7z7,&x_z7z8,&x_z7z9,&x_z7z10},{&x_z7z_1,&x_z7z11,&x_z7z24},{&x_z7z7,&x_z7z6,&x_z7z11,&x_z7z12,&x_z7z13,&x_z7z14,&x_z7z15,&x_z7z16},{&x_z7z12,&x_z7z_4,&x_z7z25},{&x_z7z13,&x_z7z_7,&x_z7z26,&x_z7z27},{&x_z7z9,&x_z7z_26,&x_z7z20,&x_z7z21}});
pedigreez7z.leaves=vector<personClass*>({&x_z7z3,&x_z7z15,&x_z7z17,&x_z7z18,&x_z7z19,&x_z7z20,&x_z7z21,&x_z7z22,&x_z7z23,&x_z7z24,&x_z7z25,&x_z7z26,&x_z7z27,&x_z7z28,&x_z7z29,&x_z7z30,&x_z7z31,&x_z7z32});
pedigreez7z.isDominant=false;
pedigreez7z.sexDependent=true;
pedigreez7z.mapToIndexRoots=unordered_map<personClass*,int>({{&x_z7z_20,12},{&x_z7z_26,5},{&x_z7z6,3},{&x_z7z_7,9},{&x_z7z5,2},{&x_z7z_23,4},{&x_z7z_4,8},{&x_z7z_10,10},{&x_z7z_29,6},{&x_z7z_15,11},{&x_z7z_1,7},{&x_z7z2,1},{&x_z7z1,0}});
pedigreez7z.mapToIndexAllPeople=unordered_map<personClass*,int>({{&x_z7z_20,40},{&x_z7z_10,38},{&x_z7z_7,37},{&x_z7z_26,33},{&x_z7z_23,32},{&x_z7z_29,34},{&x_z7z32,31},{&x_z7z30,29},{&x_z7z29,28},{&x_z7z28,27},{&x_z7z26,25},{&x_z7z27,26},{&x_z7z25,24},{&x_z7z21,20},{&x_z7z19,18},{&x_z7z18,17},{&x_z7z17,16},{&x_z7z16,15},{&x_z7z15,14},{&x_z7z3,2},{&x_z7z22,21},{&x_z7z9,8},{&x_z7z20,19},{&x_z7z31,30},{&x_z7z14,13},{&x_z7z23,22},{&x_z7z13,12},{&x_z7z8,7},{&x_z7z11,10},{&x_z7z7,6},{&x_z7z_1,35},{&x_z7z10,9},{&x_z7z24,23},{&x_z7z6,5},{&x_z7z_15,39},{&x_z7z_4,36},{&x_z7z5,4},{&x_z7z4,3},{&x_z7z2,1},{&x_z7z12,11},{&x_z7z1,0}});

x_z8z1.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z8z2,vector<personClass*>({&x_z8z3,&x_z8z4,&x_z8z5,&x_z8z6}))});

x_z8z2.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z8z1,vector<personClass*>({&x_z8z3,&x_z8z4,&x_z8z5,&x_z8z6}))});

x_z8z9.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z8z10,vector<personClass*>({&x_z8z7,&x_z8z8}))});

x_z8z10.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z8z9,vector<personClass*>({&x_z8z7,&x_z8z8}))});

x_z8z_1.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z8z3,vector<personClass*>({&x_z8z11}))});

x_z8z_4.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z8z4,vector<personClass*>({&x_z8z12}))});

x_z8z_7.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z8z5,vector<personClass*>({&x_z8z13}))});

x_z8z_21.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z8z8,vector<personClass*>({&x_z8z20,&x_z8z21,&x_z8z22}))});

x_z8z_10.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z8z14,vector<personClass*>({&x_z8z16,&x_z8z17,&x_z8z18}))});

x_z8z_13.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z8z15,vector<personClass*>({&x_z8z19}))});

x_z8z_16.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z8z20,vector<personClass*>({&x_z8z23,&x_z8z24}))});

x_z8z_26.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z8z21,vector<personClass*>({&x_z8z25}))});

x_z8z3.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z8z_1,vector<personClass*>({&x_z8z11}))});

x_z8z4.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z8z_4,vector<personClass*>({&x_z8z12}))});

x_z8z5.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z8z_7,vector<personClass*>({&x_z8z13}))});

x_z8z6.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z8z7,vector<personClass*>({&x_z8z14,&x_z8z15}))});

x_z8z7.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z8z6,vector<personClass*>({&x_z8z14,&x_z8z15}))});

x_z8z8.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z8z_21,vector<personClass*>({&x_z8z20,&x_z8z21,&x_z8z22}))});

x_z8z11.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z8z12.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z8z13.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z8z14.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z8z_10,vector<personClass*>({&x_z8z16,&x_z8z17,&x_z8z18}))});

x_z8z15.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z8z_13,vector<personClass*>({&x_z8z19}))});

x_z8z16.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z8z17.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z8z18.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z8z19.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z8z20.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z8z_16,vector<personClass*>({&x_z8z23,&x_z8z24}))});

x_z8z21.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z8z_26,vector<personClass*>({&x_z8z25}))});

x_z8z22.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z8z23.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z8z24.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z8z25.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

pedigreeClass2 pedigreez8z;
pedigreez8z.roots=vector<personClass*>({&x_z8z1,&x_z8z2,&x_z8z9,&x_z8z10,&x_z8z_1,&x_z8z_4,&x_z8z_7,&x_z8z_21,&x_z8z_10,&x_z8z_13,&x_z8z_16,&x_z8z_26});
pedigreez8z.allPeople=vector<personClass*>({&x_z8z1,&x_z8z2,&x_z8z3,&x_z8z4,&x_z8z5,&x_z8z6,&x_z8z7,&x_z8z8,&x_z8z9,&x_z8z10,&x_z8z11,&x_z8z12,&x_z8z13,&x_z8z14,&x_z8z15,&x_z8z16,&x_z8z17,&x_z8z18,&x_z8z19,&x_z8z20,&x_z8z21,&x_z8z22,&x_z8z23,&x_z8z24,&x_z8z25,&x_z8z_1,&x_z8z_4,&x_z8z_7,&x_z8z_21,&x_z8z_10,&x_z8z_13,&x_z8z_16,&x_z8z_26});
pedigreez8z.families=vector<vector<personClass*>>({{&x_z8z2,&x_z8z1,&x_z8z3,&x_z8z4,&x_z8z5,&x_z8z6},{&x_z8z3,&x_z8z_1,&x_z8z11},{&x_z8z10,&x_z8z9,&x_z8z7,&x_z8z8},{&x_z8z21,&x_z8z_26,&x_z8z25},{&x_z8z_21,&x_z8z8,&x_z8z20,&x_z8z21,&x_z8z22},{&x_z8z_4,&x_z8z4,&x_z8z12},{&x_z8z_10,&x_z8z14,&x_z8z16,&x_z8z17,&x_z8z18},{&x_z8z20,&x_z8z_16,&x_z8z23,&x_z8z24},{&x_z8z_7,&x_z8z5,&x_z8z13},{&x_z8z7,&x_z8z6,&x_z8z14,&x_z8z15},{&x_z8z_13,&x_z8z15,&x_z8z19}});
pedigreez8z.leaves=vector<personClass*>({&x_z8z11,&x_z8z12,&x_z8z13,&x_z8z16,&x_z8z17,&x_z8z18,&x_z8z19,&x_z8z22,&x_z8z23,&x_z8z24,&x_z8z25});
pedigreez8z.isDominant=false;
pedigreez8z.sexDependent=true;
pedigreez8z.mapToIndexRoots=unordered_map<personClass*,int>({{&x_z8z_26,11},{&x_z8z_16,10},{&x_z8z10,3},{&x_z8z_13,9},{&x_z8z_10,8},{&x_z8z9,2},{&x_z8z_21,7},{&x_z8z_7,6},{&x_z8z2,1},{&x_z8z1,0},{&x_z8z_1,4},{&x_z8z_4,5}});
pedigreez8z.mapToIndexAllPeople=unordered_map<personClass*,int>({{&x_z8z_13,30},{&x_z8z_21,28},{&x_z8z_26,32},{&x_z8z_1,25},{&x_z8z25,24},{&x_z8z24,23},{&x_z8z22,21},{&x_z8z20,19},{&x_z8z21,20},{&x_z8z12,11},{&x_z8z18,17},{&x_z8z16,15},{&x_z8z23,22},{&x_z8z_7,27},{&x_z8z14,13},{&x_z8z13,12},{&x_z8z_10,29},{&x_z8z1,0},{&x_z8z17,16},{&x_z8z15,14},{&x_z8z11,10},{&x_z8z10,9},{&x_z8z8,7},{&x_z8z19,18},{&x_z8z_4,26},{&x_z8z3,2},{&x_z8z7,6},{&x_z8z_16,31},{&x_z8z5,4},{&x_z8z6,5},{&x_z8z9,8},{&x_z8z2,1},{&x_z8z4,3}});

x_z9z1.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z9z2,vector<personClass*>({&x_z9z6,&x_z9z7}))});

x_z9z2.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z9z1,vector<personClass*>({&x_z9z6,&x_z9z7}))});

x_z9z3.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z9z4,vector<personClass*>({&x_z9z8,&x_z9z9,&x_z9z10,&x_z9z11,&x_z9z12}))});

x_z9z4.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z9z3,vector<personClass*>({&x_z9z8,&x_z9z9,&x_z9z10,&x_z9z11,&x_z9z12}))});

x_z9z5.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z9z6,vector<personClass*>({&x_z9z13,&x_z9z14,&x_z9z15}))});

x_z9z_4.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z9z10,vector<personClass*>({&x_z9z16}))});

x_z9z_1.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z9z11,vector<personClass*>({&x_z9z17}))});

x_z9z6.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z9z5,vector<personClass*>({&x_z9z13,&x_z9z14,&x_z9z15}))});

x_z9z7.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z9z8.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z9z9.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z9z10.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z9z_4,vector<personClass*>({&x_z9z16}))});

x_z9z11.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z9z_1,vector<personClass*>({&x_z9z17}))});

x_z9z12.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z9z13,vector<personClass*>({&x_z9z18,&x_z9z19,&x_z9z20}))});

x_z9z13.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z9z12,vector<personClass*>({&x_z9z18,&x_z9z19,&x_z9z20}))});

x_z9z14.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z9z15.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z9z16.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z9z17.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z9z18.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z9z19.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z9z20.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

pedigreeClass2 pedigreez9z;
pedigreez9z.roots=vector<personClass*>({&x_z9z1,&x_z9z2,&x_z9z3,&x_z9z4,&x_z9z5,&x_z9z_4,&x_z9z_1});
pedigreez9z.allPeople=vector<personClass*>({&x_z9z1,&x_z9z2,&x_z9z3,&x_z9z4,&x_z9z5,&x_z9z6,&x_z9z7,&x_z9z8,&x_z9z9,&x_z9z10,&x_z9z11,&x_z9z12,&x_z9z13,&x_z9z14,&x_z9z15,&x_z9z16,&x_z9z17,&x_z9z18,&x_z9z19,&x_z9z20,&x_z9z_4,&x_z9z_1});
pedigreez9z.families=vector<vector<personClass*>>({{&x_z9z10,&x_z9z_4,&x_z9z16},{&x_z9z2,&x_z9z1,&x_z9z6,&x_z9z7},{&x_z9z4,&x_z9z3,&x_z9z8,&x_z9z9,&x_z9z10,&x_z9z11,&x_z9z12},{&x_z9z13,&x_z9z12,&x_z9z18,&x_z9z19,&x_z9z20},{&x_z9z11,&x_z9z_1,&x_z9z17},{&x_z9z6,&x_z9z5,&x_z9z13,&x_z9z14,&x_z9z15}});
pedigreez9z.leaves=vector<personClass*>({&x_z9z7,&x_z9z8,&x_z9z9,&x_z9z14,&x_z9z15,&x_z9z16,&x_z9z17,&x_z9z18,&x_z9z19,&x_z9z20});
pedigreez9z.isDominant=true;
pedigreez9z.sexDependent=true;
pedigreez9z.mapToIndexRoots=unordered_map<personClass*,int>({{&x_z9z_4,5},{&x_z9z2,1},{&x_z9z_1,6},{&x_z9z5,4},{&x_z9z1,0},{&x_z9z4,3},{&x_z9z3,2}});
pedigreez9z.mapToIndexAllPeople=unordered_map<personClass*,int>({{&x_z9z_1,21},{&x_z9z19,18},{&x_z9z17,16},{&x_z9z16,15},{&x_z9z15,14},{&x_z9z18,17},{&x_z9z4,3},{&x_z9z11,10},{&x_z9z10,9},{&x_z9z13,12},{&x_z9z9,8},{&x_z9z12,11},{&x_z9z7,6},{&x_z9z6,5},{&x_z9z2,1},{&x_z9z14,13},{&x_z9z5,4},{&x_z9z20,19},{&x_z9z8,7},{&x_z9z_4,20},{&x_z9z1,0},{&x_z9z3,2}});

x_z10z1.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z10z2,vector<personClass*>({&x_z10z5,&x_z10z6,&x_z10z7,&x_z10z8}))});

x_z10z2.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z10z1,vector<personClass*>({&x_z10z5,&x_z10z6,&x_z10z7,&x_z10z8}))});

x_z10z3.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z10z4,vector<personClass*>({&x_z10z9,&x_z10z10}))});

x_z10z4.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z10z3,vector<personClass*>({&x_z10z9,&x_z10z10}))});

x_z10z_7.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z10z5,vector<personClass*>({&x_z10z11,&x_z10z12}))});

x_z10z_4.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z10z6,vector<personClass*>({&x_z10z13,&x_z10z14}))});

x_z10z_1.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z10z7,vector<personClass*>({&x_z10z15}))});

x_z10z_13.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z10z10,vector<personClass*>({&x_z10z21,&x_z10z22}))});

x_z10z_10.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z10z18,vector<personClass*>({&x_z10z19,&x_z10z20}))});

x_z10z5.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z10z_7,vector<personClass*>({&x_z10z11,&x_z10z12}))});

x_z10z6.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z10z_4,vector<personClass*>({&x_z10z13,&x_z10z14}))});

x_z10z7.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z10z_1,vector<personClass*>({&x_z10z15}))});

x_z10z8.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z10z9,vector<personClass*>({&x_z10z16,&x_z10z17,&x_z10z18}))});

x_z10z9.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z10z8,vector<personClass*>({&x_z10z16,&x_z10z17,&x_z10z18}))});

x_z10z10.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z10z_13,vector<personClass*>({&x_z10z21,&x_z10z22}))});

x_z10z11.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z10z12.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z10z13.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z10z14.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z10z15.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z10z16.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z10z17.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z10z18.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z10z_10,vector<personClass*>({&x_z10z19,&x_z10z20}))});

x_z10z19.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z10z20.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z10z21.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z10z22.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

pedigreeClass2 pedigreez10z;
pedigreez10z.roots=vector<personClass*>({&x_z10z1,&x_z10z2,&x_z10z3,&x_z10z4,&x_z10z_7,&x_z10z_4,&x_z10z_1,&x_z10z_13,&x_z10z_10});
pedigreez10z.allPeople=vector<personClass*>({&x_z10z1,&x_z10z2,&x_z10z3,&x_z10z4,&x_z10z5,&x_z10z6,&x_z10z7,&x_z10z8,&x_z10z9,&x_z10z10,&x_z10z11,&x_z10z12,&x_z10z13,&x_z10z14,&x_z10z15,&x_z10z16,&x_z10z17,&x_z10z18,&x_z10z19,&x_z10z20,&x_z10z21,&x_z10z22,&x_z10z_7,&x_z10z_4,&x_z10z_1,&x_z10z_13,&x_z10z_10});
pedigreez10z.families=vector<vector<personClass*>>({{&x_z10z2,&x_z10z1,&x_z10z5,&x_z10z6,&x_z10z7,&x_z10z8},{&x_z10z_10,&x_z10z18,&x_z10z19,&x_z10z20},{&x_z10z4,&x_z10z3,&x_z10z9,&x_z10z10},{&x_z10z_7,&x_z10z5,&x_z10z11,&x_z10z12},{&x_z10z_4,&x_z10z6,&x_z10z13,&x_z10z14},{&x_z10z10,&x_z10z_13,&x_z10z21,&x_z10z22},{&x_z10z8,&x_z10z9,&x_z10z16,&x_z10z17,&x_z10z18},{&x_z10z7,&x_z10z_1,&x_z10z15}});
pedigreez10z.leaves=vector<personClass*>({&x_z10z11,&x_z10z12,&x_z10z13,&x_z10z14,&x_z10z15,&x_z10z16,&x_z10z17,&x_z10z19,&x_z10z20,&x_z10z21,&x_z10z22});
pedigreez10z.isDominant=false;
pedigreez10z.sexDependent=true;
pedigreez10z.mapToIndexRoots=unordered_map<personClass*,int>({{&x_z10z_1,6},{&x_z10z_10,8},{&x_z10z_4,5},{&x_z10z_13,7},{&x_z10z_7,4},{&x_z10z4,3},{&x_z10z3,2},{&x_z10z2,1},{&x_z10z1,0}});
pedigreez10z.mapToIndexAllPeople=unordered_map<personClass*,int>({{&x_z10z_1,24},{&x_z10z_7,22},{&x_z10z7,6},{&x_z10z21,20},{&x_z10z22,21},{&x_z10z20,19},{&x_z10z19,18},{&x_z10z15,14},{&x_z10z17,16},{&x_z10z16,15},{&x_z10z_4,23},{&x_z10z18,17},{&x_z10z14,13},{&x_z10z13,12},{&x_z10z_10,26},{&x_z10z12,11},{&x_z10z10,9},{&x_z10z_13,25},{&x_z10z2,1},{&x_z10z6,5},{&x_z10z9,8},{&x_z10z8,7},{&x_z10z1,0},{&x_z10z5,4},{&x_z10z4,3},{&x_z10z3,2},{&x_z10z11,10}});

x_z11z1.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z11z2,vector<personClass*>({&x_z11z3,&x_z11z4,&x_z11z5,&x_z11z6}))});

x_z11z2.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z11z1,vector<personClass*>({&x_z11z3,&x_z11z4,&x_z11z5,&x_z11z6}))});

x_z11z14.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z11z15,vector<personClass*>({&x_z11z7,&x_z11z8,&x_z11z9,&x_z11z10,&x_z11z11,&x_z11z12,&x_z11z13}))});

x_z11z18.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z11z19,vector<personClass*>({&x_z11z15,&x_z11z16}))});

x_z11z19.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z11z18,vector<personClass*>({&x_z11z15,&x_z11z16}))});

x_z11z_4.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z11z8,vector<personClass*>({&x_z11z22,&x_z11z23,&x_z11z24,&x_z11z25,&x_z11z26}))});

x_z11z_7.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z11z10,vector<personClass*>({&x_z11z27}))});

x_z11z_10.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z11z11,vector<personClass*>({&x_z11z28,&x_z11z29}))});

x_z11z_13.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z11z13,vector<personClass*>({&x_z11z30}))});

x_z11z_1.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z11z16,vector<personClass*>({&x_z11z17}))});

x_z11z3.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z11z4.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z11z5.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z11z6.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z11z7,vector<personClass*>({&x_z11z20,&x_z11z21}))});

x_z11z7.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z11z6,vector<personClass*>({&x_z11z20,&x_z11z21}))});

x_z11z8.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z11z_4,vector<personClass*>({&x_z11z22,&x_z11z23,&x_z11z24,&x_z11z25,&x_z11z26}))});

x_z11z9.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z11z10.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z11z_7,vector<personClass*>({&x_z11z27}))});

x_z11z11.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z11z_10,vector<personClass*>({&x_z11z28,&x_z11z29}))});

x_z11z12.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z11z13.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z11z_13,vector<personClass*>({&x_z11z30}))});

x_z11z15.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z11z14,vector<personClass*>({&x_z11z7,&x_z11z8,&x_z11z9,&x_z11z10,&x_z11z11,&x_z11z12,&x_z11z13}))});

x_z11z16.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z11z_1,vector<personClass*>({&x_z11z17}))});

x_z11z17.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z11z20.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z11z21.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z11z22.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z11z23.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z11z24.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z11z25.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z11z26.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z11z27.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z11z28.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z11z29.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z11z30.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

pedigreeClass2 pedigreez11z;
pedigreez11z.roots=vector<personClass*>({&x_z11z1,&x_z11z2,&x_z11z14,&x_z11z18,&x_z11z19,&x_z11z_4,&x_z11z_7,&x_z11z_10,&x_z11z_13,&x_z11z_1});
pedigreez11z.allPeople=vector<personClass*>({&x_z11z1,&x_z11z2,&x_z11z3,&x_z11z4,&x_z11z5,&x_z11z6,&x_z11z7,&x_z11z8,&x_z11z9,&x_z11z10,&x_z11z11,&x_z11z12,&x_z11z13,&x_z11z14,&x_z11z15,&x_z11z16,&x_z11z17,&x_z11z18,&x_z11z19,&x_z11z20,&x_z11z21,&x_z11z22,&x_z11z23,&x_z11z24,&x_z11z25,&x_z11z26,&x_z11z27,&x_z11z28,&x_z11z29,&x_z11z30,&x_z11z_4,&x_z11z_7,&x_z11z_10,&x_z11z_13,&x_z11z_1});
pedigreez11z.families=vector<vector<personClass*>>({{&x_z11z2,&x_z11z1,&x_z11z3,&x_z11z4,&x_z11z5,&x_z11z6},{&x_z11z8,&x_z11z_4,&x_z11z22,&x_z11z23,&x_z11z24,&x_z11z25,&x_z11z26},{&x_z11z19,&x_z11z18,&x_z11z15,&x_z11z16},{&x_z11z_13,&x_z11z13,&x_z11z30},{&x_z11z16,&x_z11z_1,&x_z11z17},{&x_z11z_10,&x_z11z11,&x_z11z28,&x_z11z29},{&x_z11z10,&x_z11z_7,&x_z11z27},{&x_z11z15,&x_z11z14,&x_z11z7,&x_z11z8,&x_z11z9,&x_z11z10,&x_z11z11,&x_z11z12,&x_z11z13},{&x_z11z7,&x_z11z6,&x_z11z20,&x_z11z21}});
pedigreez11z.leaves=vector<personClass*>({&x_z11z3,&x_z11z4,&x_z11z5,&x_z11z9,&x_z11z12,&x_z11z17,&x_z11z20,&x_z11z21,&x_z11z22,&x_z11z23,&x_z11z24,&x_z11z25,&x_z11z26,&x_z11z27,&x_z11z28,&x_z11z29,&x_z11z30});
pedigreez11z.isDominant=false;
pedigreez11z.sexDependent=true;
pedigreez11z.mapToIndexRoots=unordered_map<personClass*,int>({{&x_z11z_1,9},{&x_z11z_13,8},{&x_z11z_10,7},{&x_z11z_7,6},{&x_z11z1,0},{&x_z11z2,1},{&x_z11z18,3},{&x_z11z14,2},{&x_z11z_4,5},{&x_z11z19,4}});
pedigreez11z.mapToIndexAllPeople=unordered_map<personClass*,int>({{&x_z11z_7,31},{&x_z11z30,29},{&x_z11z29,28},{&x_z11z28,27},{&x_z11z27,26},{&x_z11z_10,32},{&x_z11z_4,30},{&x_z11z26,25},{&x_z11z25,24},{&x_z11z23,22},{&x_z11z11,10},{&x_z11z21,20},{&x_z11z20,19},{&x_z11z7,6},{&x_z11z18,17},{&x_z11z24,23},{&x_z11z16,15},{&x_z11z19,18},{&x_z11z15,14},{&x_z11z14,13},{&x_z11z12,11},{&x_z11z10,9},{&x_z11z22,21},{&x_z11z_1,34},{&x_z11z13,12},{&x_z11z_13,33},{&x_z11z3,2},{&x_z11z9,8},{&x_z11z17,16},{&x_z11z8,7},{&x_z11z6,5},{&x_z11z5,4},{&x_z11z4,3},{&x_z11z2,1},{&x_z11z1,0}});

x_z12z1.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z12z2,vector<personClass*>({&x_z12z3,&x_z12z4,&x_z12z5,&x_z12z6}))});

x_z12z2.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z12z1,vector<personClass*>({&x_z12z3,&x_z12z4,&x_z12z5,&x_z12z6}))});

x_z12z14.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z12z15,vector<personClass*>({&x_z12z7,&x_z12z8,&x_z12z9,&x_z12z10,&x_z12z11,&x_z12z12,&x_z12z13}))});

x_z12z18.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z12z19,vector<personClass*>({&x_z12z15,&x_z12z16}))});

x_z12z19.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z12z18,vector<personClass*>({&x_z12z15,&x_z12z16}))});

x_z12z_4.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z12z8,vector<personClass*>({&x_z12z22,&x_z12z23,&x_z12z24,&x_z12z25,&x_z12z26}))});

x_z12z_7.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z12z10,vector<personClass*>({&x_z12z27}))});

x_z12z_10.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z12z11,vector<personClass*>({&x_z12z28,&x_z12z29}))});

x_z12z_13.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z12z13,vector<personClass*>({&x_z12z30}))});

x_z12z_1.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z12z16,vector<personClass*>({&x_z12z17}))});

x_z12z3.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z12z4.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z12z5.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z12z6.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z12z7,vector<personClass*>({&x_z12z20,&x_z12z21}))});

x_z12z7.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z12z6,vector<personClass*>({&x_z12z20,&x_z12z21}))});

x_z12z8.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z12z_4,vector<personClass*>({&x_z12z22,&x_z12z23,&x_z12z24,&x_z12z25,&x_z12z26}))});

x_z12z9.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z12z10.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z12z_7,vector<personClass*>({&x_z12z27}))});

x_z12z11.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z12z_10,vector<personClass*>({&x_z12z28,&x_z12z29}))});

x_z12z12.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z12z13.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z12z_13,vector<personClass*>({&x_z12z30}))});

x_z12z15.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z12z14,vector<personClass*>({&x_z12z7,&x_z12z8,&x_z12z9,&x_z12z10,&x_z12z11,&x_z12z12,&x_z12z13}))});

x_z12z16.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z12z_1,vector<personClass*>({&x_z12z17}))});

x_z12z17.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z12z20.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z12z21.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z12z22.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z12z23.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z12z24.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z12z25.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z12z26.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z12z27.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z12z28.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z12z29.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z12z30.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

pedigreeClass2 pedigreez12z;
pedigreez12z.roots=vector<personClass*>({&x_z12z1,&x_z12z2,&x_z12z14,&x_z12z18,&x_z12z19,&x_z12z_4,&x_z12z_7,&x_z12z_10,&x_z12z_13,&x_z12z_1});
pedigreez12z.allPeople=vector<personClass*>({&x_z12z1,&x_z12z2,&x_z12z3,&x_z12z4,&x_z12z5,&x_z12z6,&x_z12z7,&x_z12z8,&x_z12z9,&x_z12z10,&x_z12z11,&x_z12z12,&x_z12z13,&x_z12z14,&x_z12z15,&x_z12z16,&x_z12z17,&x_z12z18,&x_z12z19,&x_z12z20,&x_z12z21,&x_z12z22,&x_z12z23,&x_z12z24,&x_z12z25,&x_z12z26,&x_z12z27,&x_z12z28,&x_z12z29,&x_z12z30,&x_z12z_4,&x_z12z_7,&x_z12z_10,&x_z12z_13,&x_z12z_1});
pedigreez12z.families=vector<vector<personClass*>>({{&x_z12z2,&x_z12z1,&x_z12z3,&x_z12z4,&x_z12z5,&x_z12z6},{&x_z12z8,&x_z12z_4,&x_z12z22,&x_z12z23,&x_z12z24,&x_z12z25,&x_z12z26},{&x_z12z19,&x_z12z18,&x_z12z15,&x_z12z16},{&x_z12z_13,&x_z12z13,&x_z12z30},{&x_z12z16,&x_z12z_1,&x_z12z17},{&x_z12z_10,&x_z12z11,&x_z12z28,&x_z12z29},{&x_z12z10,&x_z12z_7,&x_z12z27},{&x_z12z15,&x_z12z14,&x_z12z7,&x_z12z8,&x_z12z9,&x_z12z10,&x_z12z11,&x_z12z12,&x_z12z13},{&x_z12z7,&x_z12z6,&x_z12z20,&x_z12z21}});
pedigreez12z.leaves=vector<personClass*>({&x_z12z3,&x_z12z4,&x_z12z5,&x_z12z9,&x_z12z12,&x_z12z17,&x_z12z20,&x_z12z21,&x_z12z22,&x_z12z23,&x_z12z24,&x_z12z25,&x_z12z26,&x_z12z27,&x_z12z28,&x_z12z29,&x_z12z30});
pedigreez12z.isDominant=false;
pedigreez12z.sexDependent=true;
pedigreez12z.mapToIndexRoots=unordered_map<personClass*,int>({{&x_z12z_13,8},{&x_z12z_10,7},{&x_z12z_1,9},{&x_z12z_4,5},{&x_z12z_7,6},{&x_z12z18,3},{&x_z12z19,4},{&x_z12z14,2},{&x_z12z2,1},{&x_z12z1,0}});
pedigreez12z.mapToIndexAllPeople=unordered_map<personClass*,int>({{&x_z12z_1,34},{&x_z12z_13,33},{&x_z12z_10,32},{&x_z12z_7,31},{&x_z12z30,29},{&x_z12z29,28},{&x_z12z28,27},{&x_z12z26,25},{&x_z12z25,24},{&x_z12z27,26},{&x_z12z24,23},{&x_z12z18,17},{&x_z12z21,20},{&x_z12z12,11},{&x_z12z17,16},{&x_z12z15,14},{&x_z12z2,1},{&x_z12z16,15},{&x_z12z13,12},{&x_z12z23,22},{&x_z12z8,7},{&x_z12z9,8},{&x_z12z20,19},{&x_z12z3,2},{&x_z12z22,21},{&x_z12z11,10},{&x_z12z14,13},{&x_z12z7,6},{&x_z12z_4,30},{&x_z12z19,18},{&x_z12z5,4},{&x_z12z6,5},{&x_z12z10,9},{&x_z12z4,3},{&x_z12z1,0}});

x_z13z1.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z13z2,vector<personClass*>({&x_z13z5,&x_z13z6}))});

x_z13z2.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z13z1,vector<personClass*>({&x_z13z5,&x_z13z6}))});

x_z13z3.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z13z4,vector<personClass*>({&x_z13z7}))});

x_z13z4.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z13z3,vector<personClass*>({&x_z13z7}))});

x_z13z35.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z13z39,vector<personClass*>({&x_z13z47}))});

x_z13z36.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z13z8,vector<personClass*>({&x_z13z39,&x_z13z40,&x_z13z41}))});

x_z13z37.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z13z10,vector<personClass*>({&x_z13z42}))});

x_z13z38.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z13z12,vector<personClass*>({&x_z13z43,&x_z13z44}))});

x_z13z_1.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z13z14,vector<personClass*>({&x_z13z45,&x_z13z46}))});

x_z13z_17.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z13z15,vector<personClass*>({&x_z13z54,&x_z13z55,&x_z13z56}))});

x_z13z_20.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z13z16,vector<personClass*>({&x_z13z57,&x_z13z58,&x_z13z59}))});

x_z13z_4.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z13z40,vector<personClass*>({&x_z13z48}))});

x_z13z_7.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z13z41,vector<personClass*>({&x_z13z49,&x_z13z50}))});

x_z13z_11.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z13z43,vector<personClass*>({&x_z13z51,&x_z13z52}))});

x_z13z_14.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z13z44,vector<personClass*>({&x_z13z53}))});

x_z13z5.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z13z6.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z13z7,vector<personClass*>({&x_z13z8,&x_z13z10,&x_z13z12,&x_z13z14,&x_z13z15,&x_z13z16}))});

x_z13z7.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z13z6,vector<personClass*>({&x_z13z8,&x_z13z10,&x_z13z12,&x_z13z14,&x_z13z15,&x_z13z16}))});

x_z13z8.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z13z36,vector<personClass*>({&x_z13z39,&x_z13z40,&x_z13z41}))});

x_z13z10.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z13z37,vector<personClass*>({&x_z13z42}))});

x_z13z12.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z13z38,vector<personClass*>({&x_z13z43,&x_z13z44}))});

x_z13z14.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z13z_1,vector<personClass*>({&x_z13z45,&x_z13z46}))});

x_z13z15.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z13z_17,vector<personClass*>({&x_z13z54,&x_z13z55,&x_z13z56}))});

x_z13z16.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z13z_20,vector<personClass*>({&x_z13z57,&x_z13z58,&x_z13z59}))});

x_z13z39.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z13z35,vector<personClass*>({&x_z13z47}))});

x_z13z40.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z13z_4,vector<personClass*>({&x_z13z48}))});

x_z13z41.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z13z_7,vector<personClass*>({&x_z13z49,&x_z13z50}))});

x_z13z42.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z13z43.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z13z_11,vector<personClass*>({&x_z13z51,&x_z13z52}))});

x_z13z44.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z13z_14,vector<personClass*>({&x_z13z53}))});

x_z13z45.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z13z46.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z13z47.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z13z48.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z13z49.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z13z50.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z13z51.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z13z52.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z13z53.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z13z54.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z13z55.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z13z56.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z13z57.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z13z58.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z13z59.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

pedigreeClass2 pedigreez13z;
pedigreez13z.roots=vector<personClass*>({&x_z13z1,&x_z13z2,&x_z13z3,&x_z13z4,&x_z13z35,&x_z13z36,&x_z13z37,&x_z13z38,&x_z13z_1,&x_z13z_17,&x_z13z_20,&x_z13z_4,&x_z13z_7,&x_z13z_11,&x_z13z_14});
pedigreez13z.allPeople=vector<personClass*>({&x_z13z1,&x_z13z2,&x_z13z3,&x_z13z4,&x_z13z5,&x_z13z6,&x_z13z7,&x_z13z8,&x_z13z10,&x_z13z12,&x_z13z14,&x_z13z15,&x_z13z16,&x_z13z35,&x_z13z36,&x_z13z37,&x_z13z38,&x_z13z39,&x_z13z40,&x_z13z41,&x_z13z42,&x_z13z43,&x_z13z44,&x_z13z45,&x_z13z46,&x_z13z47,&x_z13z48,&x_z13z49,&x_z13z50,&x_z13z51,&x_z13z52,&x_z13z53,&x_z13z54,&x_z13z55,&x_z13z56,&x_z13z57,&x_z13z58,&x_z13z59,&x_z13z_1,&x_z13z_17,&x_z13z_20,&x_z13z_4,&x_z13z_7,&x_z13z_11,&x_z13z_14});
pedigreez13z.families=vector<vector<personClass*>>({{&x_z13z2,&x_z13z1,&x_z13z5,&x_z13z6},{&x_z13z41,&x_z13z_7,&x_z13z49,&x_z13z50},{&x_z13z44,&x_z13z_14,&x_z13z53},{&x_z13z35,&x_z13z39,&x_z13z47},{&x_z13z15,&x_z13z_17,&x_z13z54,&x_z13z55,&x_z13z56},{&x_z13z14,&x_z13z_1,&x_z13z45,&x_z13z46},{&x_z13z38,&x_z13z12,&x_z13z43,&x_z13z44},{&x_z13z4,&x_z13z3,&x_z13z7},{&x_z13z16,&x_z13z_20,&x_z13z57,&x_z13z58,&x_z13z59},{&x_z13z43,&x_z13z_11,&x_z13z51,&x_z13z52},{&x_z13z7,&x_z13z6,&x_z13z8,&x_z13z10,&x_z13z12,&x_z13z14,&x_z13z15,&x_z13z16},{&x_z13z37,&x_z13z10,&x_z13z42},{&x_z13z36,&x_z13z8,&x_z13z39,&x_z13z40,&x_z13z41},{&x_z13z_4,&x_z13z40,&x_z13z48}});
pedigreez13z.leaves=vector<personClass*>({&x_z13z5,&x_z13z42,&x_z13z45,&x_z13z46,&x_z13z47,&x_z13z48,&x_z13z49,&x_z13z50,&x_z13z51,&x_z13z52,&x_z13z53,&x_z13z54,&x_z13z55,&x_z13z56,&x_z13z57,&x_z13z58,&x_z13z59});
pedigreez13z.isDominant=false;
pedigreez13z.sexDependent=true;
pedigreez13z.mapToIndexRoots=unordered_map<personClass*,int>({{&x_z13z_11,13},{&x_z13z_7,12},{&x_z13z_4,11},{&x_z13z4,3},{&x_z13z37,6},{&x_z13z_20,10},{&x_z13z_1,8},{&x_z13z38,7},{&x_z13z_14,14},{&x_z13z36,5},{&x_z13z1,0},{&x_z13z3,2},{&x_z13z35,4},{&x_z13z2,1},{&x_z13z_17,9}});
pedigreez13z.mapToIndexAllPeople=unordered_map<personClass*,int>({{&x_z13z_14,44},{&x_z13z_7,42},{&x_z13z_17,39},{&x_z13z_4,41},{&x_z13z_1,38},{&x_z13z59,37},{&x_z13z58,36},{&x_z13z56,34},{&x_z13z54,32},{&x_z13z53,31},{&x_z13z57,35},{&x_z13z52,30},{&x_z13z51,29},{&x_z13z49,27},{&x_z13z48,26},{&x_z13z46,24},{&x_z13z45,23},{&x_z13z44,22},{&x_z13z55,33},{&x_z13z1,0},{&x_z13z14,10},{&x_z13z42,20},{&x_z13z38,16},{&x_z13z2,1},{&x_z13z36,14},{&x_z13z35,13},{&x_z13z40,18},{&x_z13z39,17},{&x_z13z15,11},{&x_z13z10,8},{&x_z13z47,25},{&x_z13z37,15},{&x_z13z12,9},{&x_z13z8,7},{&x_z13z_11,43},{&x_z13z3,2},{&x_z13z4,3},{&x_z13z7,6},{&x_z13z6,5},{&x_z13z50,28},{&x_z13z43,21},{&x_z13z_20,40},{&x_z13z16,12},{&x_z13z5,4},{&x_z13z41,19}});

x_z14z1.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z14z2,vector<personClass*>({&x_z14z3,&x_z14z4,&x_z14z5}))});

x_z14z2.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z14z1,vector<personClass*>({&x_z14z3,&x_z14z4,&x_z14z5}))});

x_z14z8.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z14z9,vector<personClass*>({&x_z14z6,&x_z14z7}))});

x_z14z9.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z14z8,vector<personClass*>({&x_z14z6,&x_z14z7}))});

x_z14z_4.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z14z3,vector<personClass*>({&x_z14z13}))});

x_z14z_1.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z14z7,vector<personClass*>({&x_z14z10}))});

x_z14z3.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z14z_4,vector<personClass*>({&x_z14z13}))});

x_z14z4.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z14z5.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z14z6,vector<personClass*>({&x_z14z11,&x_z14z12}))});

x_z14z6.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z14z5,vector<personClass*>({&x_z14z11,&x_z14z12}))});

x_z14z7.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z14z_1,vector<personClass*>({&x_z14z10}))});

x_z14z10.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z14z11.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z14z12.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z14z13.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

pedigreeClass2 pedigreez14z;
pedigreez14z.roots=vector<personClass*>({&x_z14z1,&x_z14z2,&x_z14z8,&x_z14z9,&x_z14z_4,&x_z14z_1});
pedigreez14z.allPeople=vector<personClass*>({&x_z14z1,&x_z14z2,&x_z14z3,&x_z14z4,&x_z14z5,&x_z14z6,&x_z14z7,&x_z14z8,&x_z14z9,&x_z14z10,&x_z14z11,&x_z14z12,&x_z14z13,&x_z14z_4,&x_z14z_1});
pedigreez14z.families=vector<vector<personClass*>>({{&x_z14z2,&x_z14z1,&x_z14z3,&x_z14z4,&x_z14z5},{&x_z14z6,&x_z14z5,&x_z14z11,&x_z14z12},{&x_z14z_4,&x_z14z3,&x_z14z13},{&x_z14z7,&x_z14z_1,&x_z14z10},{&x_z14z9,&x_z14z8,&x_z14z6,&x_z14z7}});
pedigreez14z.leaves=vector<personClass*>({&x_z14z4,&x_z14z10,&x_z14z11,&x_z14z12,&x_z14z13});
pedigreez14z.isDominant=false;
pedigreez14z.sexDependent=true;
pedigreez14z.mapToIndexRoots=unordered_map<personClass*,int>({{&x_z14z_4,4},{&x_z14z8,2},{&x_z14z9,3},{&x_z14z_1,5},{&x_z14z2,1},{&x_z14z1,0}});
pedigreez14z.mapToIndexAllPeople=unordered_map<personClass*,int>({{&x_z14z_4,13},{&x_z14z13,12},{&x_z14z12,11},{&x_z14z4,3},{&x_z14z11,10},{&x_z14z1,0},{&x_z14z9,8},{&x_z14z7,6},{&x_z14z10,9},{&x_z14z6,5},{&x_z14z5,4},{&x_z14z8,7},{&x_z14z3,2},{&x_z14z_1,14},{&x_z14z2,1}});

x_z15z1.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z15z2,vector<personClass*>({&x_z15z3,&x_z15z4,&x_z15z5,&x_z15z6,&x_z15z7,&x_z15z8,&x_z15z9}))});

x_z15z2.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z15z1,vector<personClass*>({&x_z15z3,&x_z15z4,&x_z15z5,&x_z15z6,&x_z15z7,&x_z15z8,&x_z15z9}))});

x_z15z10.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z15z11,vector<personClass*>({&x_z15z12,&x_z15z13,&x_z15z14,&x_z15z15,&x_z15z16}))});

x_z15z11.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z15z10,vector<personClass*>({&x_z15z12,&x_z15z13,&x_z15z14,&x_z15z15,&x_z15z16}))});

x_z15z_1.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z15z13,vector<personClass*>({&x_z15z20,&x_z15z21}))});

x_z15z_4.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z15z14,vector<personClass*>({&x_z15z22}))});

x_z15z_11.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z15z16,vector<personClass*>({&x_z15z23,&x_z15z24}))});

x_z15z3.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z15z4.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z15z5.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z15z6.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z15z7.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z15z8.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z15z9.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z15z12,vector<personClass*>({&x_z15z17,&x_z15z18,&x_z15z19}))});

x_z15z12.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z15z9,vector<personClass*>({&x_z15z17,&x_z15z18,&x_z15z19}))});

x_z15z13.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z15z_1,vector<personClass*>({&x_z15z20,&x_z15z21}))});

x_z15z14.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z15z_4,vector<personClass*>({&x_z15z22}))});

x_z15z15.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z15z16.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z15z_11,vector<personClass*>({&x_z15z23,&x_z15z24}))});

x_z15z17.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z15z18.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z15z19.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z15z20.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z15z21.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z15z22.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z15z23.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z15z24.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

pedigreeClass2 pedigreez15z;
pedigreez15z.roots=vector<personClass*>({&x_z15z1,&x_z15z2,&x_z15z10,&x_z15z11,&x_z15z_1,&x_z15z_4,&x_z15z_11});
pedigreez15z.allPeople=vector<personClass*>({&x_z15z1,&x_z15z2,&x_z15z3,&x_z15z4,&x_z15z5,&x_z15z6,&x_z15z7,&x_z15z8,&x_z15z9,&x_z15z10,&x_z15z11,&x_z15z12,&x_z15z13,&x_z15z14,&x_z15z15,&x_z15z16,&x_z15z17,&x_z15z18,&x_z15z19,&x_z15z20,&x_z15z21,&x_z15z22,&x_z15z23,&x_z15z24,&x_z15z_1,&x_z15z_4,&x_z15z_11});
pedigreez15z.families=vector<vector<personClass*>>({{&x_z15z2,&x_z15z1,&x_z15z3,&x_z15z4,&x_z15z5,&x_z15z6,&x_z15z7,&x_z15z8,&x_z15z9},{&x_z15z12,&x_z15z9,&x_z15z17,&x_z15z18,&x_z15z19},{&x_z15z16,&x_z15z_11,&x_z15z23,&x_z15z24},{&x_z15z13,&x_z15z_1,&x_z15z20,&x_z15z21},{&x_z15z11,&x_z15z10,&x_z15z12,&x_z15z13,&x_z15z14,&x_z15z15,&x_z15z16},{&x_z15z14,&x_z15z_4,&x_z15z22}});
pedigreez15z.leaves=vector<personClass*>({&x_z15z3,&x_z15z4,&x_z15z5,&x_z15z6,&x_z15z7,&x_z15z8,&x_z15z15,&x_z15z17,&x_z15z18,&x_z15z19,&x_z15z20,&x_z15z21,&x_z15z22,&x_z15z23,&x_z15z24});
pedigreez15z.isDominant=false;
pedigreez15z.sexDependent=true;
pedigreez15z.mapToIndexRoots=unordered_map<personClass*,int>({{&x_z15z_11,6},{&x_z15z_4,5},{&x_z15z11,3},{&x_z15z_1,4},{&x_z15z10,2},{&x_z15z2,1},{&x_z15z1,0}});
pedigreez15z.mapToIndexAllPeople=unordered_map<personClass*,int>({{&x_z15z_11,26},{&x_z15z24,23},{&x_z15z23,22},{&x_z15z4,3},{&x_z15z11,10},{&x_z15z22,21},{&x_z15z20,19},{&x_z15z18,17},{&x_z15z12,11},{&x_z15z19,18},{&x_z15z17,16},{&x_z15z16,15},{&x_z15z13,12},{&x_z15z15,14},{&x_z15z1,0},{&x_z15z10,9},{&x_z15z9,8},{&x_z15z14,13},{&x_z15z7,6},{&x_z15z8,7},{&x_z15z_1,24},{&x_z15z5,4},{&x_z15z6,5},{&x_z15z3,2},{&x_z15z21,20},{&x_z15z_4,25},{&x_z15z2,1}});

x_z16z3.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z16z4,vector<personClass*>({&x_z16z5,&x_z16z6,&x_z16z7,&x_z16z8}))});

x_z16z_1.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z16z_2,vector<personClass*>({&x_z16z1,&x_z16z2}))});

x_z16z_2.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z16z_1,vector<personClass*>({&x_z16z1,&x_z16z2}))});

x_z16z_3.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z16z1,vector<personClass*>({&x_z16z4}))});

x_z16z_6.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z16z5,vector<personClass*>({&x_z16z9,&x_z16z10,&x_z16z11,&x_z16z12}))});

x_z16z_9.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z16z6,vector<personClass*>({&x_z16z13,&x_z16z14,&x_z16z15}))});

x_z16z_12.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z16z7,vector<personClass*>({&x_z16z16,&x_z16z17,&x_z16z18,&x_z16z19,&x_z16z20}))});

x_z16z_15.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z16z8,vector<personClass*>({&x_z16z21,&x_z16z22,&x_z16z23,&x_z16z24}))});

x_z16z_18.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z16z16,vector<personClass*>({&x_z16z25,&x_z16z26}))});

x_z16z_21.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z16z17,vector<personClass*>({&x_z16z27}))});

x_z16z_24.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z16z18,vector<personClass*>({&x_z16z28}))});

x_z16z1.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z16z_3,vector<personClass*>({&x_z16z4}))});

x_z16z2.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z16z4.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z16z3,vector<personClass*>({&x_z16z5,&x_z16z6,&x_z16z7,&x_z16z8}))});

x_z16z5.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z16z_6,vector<personClass*>({&x_z16z9,&x_z16z10,&x_z16z11,&x_z16z12}))});

x_z16z6.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z16z_9,vector<personClass*>({&x_z16z13,&x_z16z14,&x_z16z15}))});

x_z16z7.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z16z_12,vector<personClass*>({&x_z16z16,&x_z16z17,&x_z16z18,&x_z16z19,&x_z16z20}))});

x_z16z8.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z16z_15,vector<personClass*>({&x_z16z21,&x_z16z22,&x_z16z23,&x_z16z24}))});

x_z16z9.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z16z10.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z16z11.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z16z12.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z16z13.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z16z14.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z16z15.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z16z16.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z16z_18,vector<personClass*>({&x_z16z25,&x_z16z26}))});

x_z16z17.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z16z_21,vector<personClass*>({&x_z16z27}))});

x_z16z18.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z16z_24,vector<personClass*>({&x_z16z28}))});

x_z16z19.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z16z20.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z16z21.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z16z22.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z16z23.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z16z24.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z16z25.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z16z26.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z16z27.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z16z28.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

pedigreeClass2 pedigreez16z;
pedigreez16z.roots=vector<personClass*>({&x_z16z3,&x_z16z_1,&x_z16z_2,&x_z16z_3,&x_z16z_6,&x_z16z_9,&x_z16z_12,&x_z16z_15,&x_z16z_18,&x_z16z_21,&x_z16z_24});
pedigreez16z.allPeople=vector<personClass*>({&x_z16z1,&x_z16z2,&x_z16z3,&x_z16z4,&x_z16z5,&x_z16z6,&x_z16z7,&x_z16z8,&x_z16z9,&x_z16z10,&x_z16z11,&x_z16z12,&x_z16z13,&x_z16z14,&x_z16z15,&x_z16z16,&x_z16z17,&x_z16z18,&x_z16z19,&x_z16z20,&x_z16z21,&x_z16z22,&x_z16z23,&x_z16z24,&x_z16z25,&x_z16z26,&x_z16z27,&x_z16z28,&x_z16z_1,&x_z16z_2,&x_z16z_3,&x_z16z_6,&x_z16z_9,&x_z16z_12,&x_z16z_15,&x_z16z_18,&x_z16z_21,&x_z16z_24});
pedigreez16z.families=vector<vector<personClass*>>({{&x_z16z6,&x_z16z_9,&x_z16z13,&x_z16z14,&x_z16z15},{&x_z16z_3,&x_z16z1,&x_z16z4},{&x_z16z8,&x_z16z_15,&x_z16z21,&x_z16z22,&x_z16z23,&x_z16z24},{&x_z16z17,&x_z16z_21,&x_z16z27},{&x_z16z4,&x_z16z3,&x_z16z5,&x_z16z6,&x_z16z7,&x_z16z8},{&x_z16z16,&x_z16z_18,&x_z16z25,&x_z16z26},{&x_z16z_6,&x_z16z5,&x_z16z9,&x_z16z10,&x_z16z11,&x_z16z12},{&x_z16z_12,&x_z16z7,&x_z16z16,&x_z16z17,&x_z16z18,&x_z16z19,&x_z16z20},{&x_z16z18,&x_z16z_24,&x_z16z28},{&x_z16z_2,&x_z16z_1,&x_z16z1,&x_z16z2}});
pedigreez16z.leaves=vector<personClass*>({&x_z16z2,&x_z16z9,&x_z16z10,&x_z16z11,&x_z16z12,&x_z16z13,&x_z16z14,&x_z16z15,&x_z16z19,&x_z16z20,&x_z16z21,&x_z16z22,&x_z16z23,&x_z16z24,&x_z16z25,&x_z16z26,&x_z16z27,&x_z16z28});
pedigreez16z.isDominant=false;
pedigreez16z.sexDependent=true;
pedigreez16z.mapToIndexRoots=unordered_map<personClass*,int>({{&x_z16z_24,10},{&x_z16z_15,7},{&x_z16z_12,6},{&x_z16z_9,5},{&x_z16z_6,4},{&x_z16z_18,8},{&x_z16z_2,2},{&x_z16z_21,9},{&x_z16z_3,3},{&x_z16z_1,1},{&x_z16z3,0}});
pedigreez16z.mapToIndexAllPeople=unordered_map<personClass*,int>({{&x_z16z_21,36},{&x_z16z_15,34},{&x_z16z_9,32},{&x_z16z_24,37},{&x_z16z_2,29},{&x_z16z_1,28},{&x_z16z28,27},{&x_z16z27,26},{&x_z16z24,23},{&x_z16z1,0},{&x_z16z3,2},{&x_z16z23,22},{&x_z16z_18,35},{&x_z16z7,6},{&x_z16z11,10},{&x_z16z16,15},{&x_z16z19,18},{&x_z16z18,17},{&x_z16z20,19},{&x_z16z17,16},{&x_z16z15,14},{&x_z16z2,1},{&x_z16z14,13},{&x_z16z26,25},{&x_z16z5,4},{&x_z16z13,12},{&x_z16z_3,30},{&x_z16z25,24},{&x_z16z12,11},{&x_z16z_12,33},{&x_z16z9,8},{&x_z16z22,21},{&x_z16z8,7},{&x_z16z10,9},{&x_z16z6,5},{&x_z16z_6,31},{&x_z16z21,20},{&x_z16z4,3}});

x_z17z1.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z17z2,vector<personClass*>({&x_z17z7,&x_z17z8,&x_z17z9,&x_z17z10}))});

x_z17z2.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z17z1,vector<personClass*>({&x_z17z7,&x_z17z8,&x_z17z9,&x_z17z10}))});

x_z17z3.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z17z4,vector<personClass*>({&x_z17z11,&x_z17z12}))});

x_z17z4.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z17z3,vector<personClass*>({&x_z17z11,&x_z17z12}))});

x_z17z5.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z17z6,vector<personClass*>({&x_z17z13,&x_z17z14,&x_z17z15}))});

x_z17z6.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z17z5,vector<personClass*>({&x_z17z13,&x_z17z14,&x_z17z15}))});

x_z17z_1.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z17z10,vector<personClass*>({&x_z17z17}))});

x_z17z_4.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z17z11,vector<personClass*>({&x_z17z19}))});

x_z17z_10.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z17z12,vector<personClass*>({&x_z17z20}))});

x_z17z_23.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z17z13,vector<personClass*>({&x_z17z21}))});

x_z17z_20.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z17z14,vector<personClass*>({&x_z17z22}))});

x_z17z_13.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z17z16,vector<personClass*>({&x_z17z26}))});

x_z17z_7.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z17z19,vector<personClass*>({&x_z17z27}))});

x_z17z7.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z17z8.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z17z9.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z17z10.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z17z11,vector<personClass*>({&x_z17z16,&x_z17z18})),pair<personClass*,vector<personClass*>>(&x_z17z_1,vector<personClass*>({&x_z17z17}))});

x_z17z11.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z17z_4,vector<personClass*>({&x_z17z19})),pair<personClass*,vector<personClass*>>(&x_z17z10,vector<personClass*>({&x_z17z16,&x_z17z18}))});

x_z17z12.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z17z_10,vector<personClass*>({&x_z17z20}))});

x_z17z13.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z17z_23,vector<personClass*>({&x_z17z21}))});

x_z17z14.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z17z_20,vector<personClass*>({&x_z17z22}))});

x_z17z15.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z17z16,vector<personClass*>({&x_z17z23,&x_z17z24,&x_z17z25}))});

x_z17z16.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z17z_13,vector<personClass*>({&x_z17z26})),pair<personClass*,vector<personClass*>>(&x_z17z15,vector<personClass*>({&x_z17z23,&x_z17z24,&x_z17z25}))});

x_z17z17.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z17z18.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z17z19.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z17z_7,vector<personClass*>({&x_z17z27}))});

x_z17z20.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z17z21.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z17z22.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z17z23.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z17z24.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z17z25.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z17z26.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z17z27.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

pedigreeClass2 pedigreez17z;
pedigreez17z.roots=vector<personClass*>({&x_z17z1,&x_z17z2,&x_z17z3,&x_z17z4,&x_z17z5,&x_z17z6,&x_z17z_1,&x_z17z_4,&x_z17z_10,&x_z17z_23,&x_z17z_20,&x_z17z_13,&x_z17z_7});
pedigreez17z.allPeople=vector<personClass*>({&x_z17z1,&x_z17z2,&x_z17z3,&x_z17z4,&x_z17z5,&x_z17z6,&x_z17z7,&x_z17z8,&x_z17z9,&x_z17z10,&x_z17z11,&x_z17z12,&x_z17z13,&x_z17z14,&x_z17z15,&x_z17z16,&x_z17z17,&x_z17z18,&x_z17z19,&x_z17z20,&x_z17z21,&x_z17z22,&x_z17z23,&x_z17z24,&x_z17z25,&x_z17z26,&x_z17z27,&x_z17z_1,&x_z17z_4,&x_z17z_10,&x_z17z_23,&x_z17z_20,&x_z17z_13,&x_z17z_7});
pedigreez17z.families=vector<vector<personClass*>>({{&x_z17z2,&x_z17z1,&x_z17z7,&x_z17z8,&x_z17z9,&x_z17z10},{&x_z17z14,&x_z17z_20,&x_z17z22},{&x_z17z11,&x_z17z_4,&x_z17z19},{&x_z17z12,&x_z17z_10,&x_z17z20},{&x_z17z_23,&x_z17z13,&x_z17z21},{&x_z17z4,&x_z17z3,&x_z17z11,&x_z17z12},{&x_z17z_7,&x_z17z19,&x_z17z27},{&x_z17z16,&x_z17z_13,&x_z17z26},{&x_z17z11,&x_z17z10,&x_z17z16,&x_z17z18},{&x_z17z6,&x_z17z5,&x_z17z13,&x_z17z14,&x_z17z15},{&x_z17z16,&x_z17z15,&x_z17z23,&x_z17z24,&x_z17z25},{&x_z17z_1,&x_z17z10,&x_z17z17}});
pedigreez17z.leaves=vector<personClass*>({&x_z17z7,&x_z17z8,&x_z17z9,&x_z17z17,&x_z17z18,&x_z17z20,&x_z17z21,&x_z17z22,&x_z17z23,&x_z17z24,&x_z17z25,&x_z17z26,&x_z17z27});
pedigreez17z.isDominant=true;
pedigreez17z.sexDependent=true;
pedigreez17z.mapToIndexRoots=unordered_map<personClass*,int>({{&x_z17z_7,12},{&x_z17z_13,11},{&x_z17z6,5},{&x_z17z_1,6},{&x_z17z_20,10},{&x_z17z_10,8},{&x_z17z_4,7},{&x_z17z5,4},{&x_z17z4,3},{&x_z17z3,2},{&x_z17z_23,9},{&x_z17z2,1},{&x_z17z1,0}});
pedigreez17z.mapToIndexAllPeople=unordered_map<personClass*,int>({{&x_z17z_20,31},{&x_z17z_23,30},{&x_z17z_10,29},{&x_z17z_1,27},{&x_z17z26,25},{&x_z17z14,13},{&x_z17z15,14},{&x_z17z27,26},{&x_z17z18,17},{&x_z17z7,6},{&x_z17z4,3},{&x_z17z19,18},{&x_z17z22,21},{&x_z17z_13,32},{&x_z17z25,24},{&x_z17z13,12},{&x_z17z21,20},{&x_z17z12,11},{&x_z17z8,7},{&x_z17z23,22},{&x_z17z11,10},{&x_z17z_7,33},{&x_z17z6,5},{&x_z17z10,9},{&x_z17z9,8},{&x_z17z20,19},{&x_z17z17,16},{&x_z17z5,4},{&x_z17z3,2},{&x_z17z24,23},{&x_z17z16,15},{&x_z17z2,1},{&x_z17z_4,28},{&x_z17z1,0}});

x_z18z1.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z18z2,vector<personClass*>({&x_z18z10,&x_z18z11,&x_z18z12,&x_z18z13}))});

x_z18z2.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z18z1,vector<personClass*>({&x_z18z10,&x_z18z11,&x_z18z12,&x_z18z13}))});

x_z18z3.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z18z4,vector<personClass*>({&x_z18z14,&x_z18z15,&x_z18z16,&x_z18z17}))});

x_z18z_4.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z18z_5,vector<personClass*>({&x_z18z4,&x_z18z5,&x_z18z6,&x_z18z7,&x_z18z8,&x_z18z9}))});

x_z18z_5.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z18z_4,vector<personClass*>({&x_z18z4,&x_z18z5,&x_z18z6,&x_z18z7,&x_z18z8,&x_z18z9}))});

x_z18z_9.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z18z16,vector<personClass*>({&x_z18z21}))});

x_z18z_6.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z18z17,vector<personClass*>({&x_z18z22}))});

x_z18z_1.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z18z18,vector<personClass*>({&x_z18z20}))});

x_z18z4.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z18z3,vector<personClass*>({&x_z18z14,&x_z18z15,&x_z18z16,&x_z18z17}))});

x_z18z5.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z18z6.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z18z7.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z18z8.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z18z9.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z18z10.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z18z11.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z18z12.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z18z13.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z18z14,vector<personClass*>({&x_z18z18,&x_z18z19}))});

x_z18z14.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z18z13,vector<personClass*>({&x_z18z18,&x_z18z19}))});

x_z18z15.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z18z16.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z18z_9,vector<personClass*>({&x_z18z21}))});

x_z18z17.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z18z_6,vector<personClass*>({&x_z18z22}))});

x_z18z18.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z18z_1,vector<personClass*>({&x_z18z20}))});

x_z18z19.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z18z20.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z18z21.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z18z22.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

pedigreeClass2 pedigreez18z;
pedigreez18z.roots=vector<personClass*>({&x_z18z1,&x_z18z2,&x_z18z3,&x_z18z_4,&x_z18z_5,&x_z18z_9,&x_z18z_6,&x_z18z_1});
pedigreez18z.allPeople=vector<personClass*>({&x_z18z1,&x_z18z2,&x_z18z3,&x_z18z4,&x_z18z5,&x_z18z6,&x_z18z7,&x_z18z8,&x_z18z9,&x_z18z10,&x_z18z11,&x_z18z12,&x_z18z13,&x_z18z14,&x_z18z15,&x_z18z16,&x_z18z17,&x_z18z18,&x_z18z19,&x_z18z20,&x_z18z21,&x_z18z22,&x_z18z_4,&x_z18z_5,&x_z18z_9,&x_z18z_6,&x_z18z_1});
pedigreez18z.families=vector<vector<personClass*>>({{&x_z18z2,&x_z18z1,&x_z18z10,&x_z18z11,&x_z18z12,&x_z18z13},{&x_z18z14,&x_z18z13,&x_z18z18,&x_z18z19},{&x_z18z_1,&x_z18z18,&x_z18z20},{&x_z18z_5,&x_z18z_4,&x_z18z4,&x_z18z5,&x_z18z6,&x_z18z7,&x_z18z8,&x_z18z9},{&x_z18z3,&x_z18z4,&x_z18z14,&x_z18z15,&x_z18z16,&x_z18z17},{&x_z18z16,&x_z18z_9,&x_z18z21},{&x_z18z_6,&x_z18z17,&x_z18z22}});
pedigreez18z.leaves=vector<personClass*>({&x_z18z5,&x_z18z6,&x_z18z7,&x_z18z8,&x_z18z9,&x_z18z10,&x_z18z11,&x_z18z12,&x_z18z15,&x_z18z19,&x_z18z20,&x_z18z21,&x_z18z22});
pedigreez18z.isDominant=false;
pedigreez18z.sexDependent=true;
pedigreez18z.mapToIndexRoots=unordered_map<personClass*,int>({{&x_z18z_1,7},{&x_z18z_9,5},{&x_z18z_5,4},{&x_z18z_4,3},{&x_z18z2,1},{&x_z18z3,2},{&x_z18z_6,6},{&x_z18z1,0}});
pedigreez18z.mapToIndexAllPeople=unordered_map<personClass*,int>({{&x_z18z_9,24},{&x_z18z_5,23},{&x_z18z_4,22},{&x_z18z4,3},{&x_z18z20,19},{&x_z18z19,18},{&x_z18z16,15},{&x_z18z17,16},{&x_z18z14,13},{&x_z18z12,11},{&x_z18z10,9},{&x_z18z8,7},{&x_z18z15,14},{&x_z18z_1,26},{&x_z18z6,5},{&x_z18z3,2},{&x_z18z_6,25},{&x_z18z11,10},{&x_z18z21,20},{&x_z18z5,4},{&x_z18z18,17},{&x_z18z9,8},{&x_z18z7,6},{&x_z18z22,21},{&x_z18z2,1},{&x_z18z13,12},{&x_z18z1,0}});

x_z19z30.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z19z_24,vector<personClass*>({&x_z19z32,&x_z19z33})),pair<personClass*,vector<personClass*>>(&x_z19z31,vector<personClass*>({&x_z19z21,&x_z19z25,&x_z19z26}))});

x_z19z31.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z19z30,vector<personClass*>({&x_z19z21,&x_z19z25,&x_z19z26}))});

x_z19z34.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z19z35,vector<personClass*>({&x_z19z16,&x_z19z17,&x_z19z18,&x_z19z24}))});

x_z19z44.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z19z45,vector<personClass*>({&x_z19z35,&x_z19z36,&x_z19z37,&x_z19z38,&x_z19z39}))});

x_z19z45.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z19z44,vector<personClass*>({&x_z19z35,&x_z19z36,&x_z19z37,&x_z19z38,&x_z19z39}))});

x_z19z_10.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z19z26,vector<personClass*>({&x_z19z1,&x_z19z2}))});

x_z19z_13.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z19z21,vector<personClass*>({&x_z19z3,&x_z19z4}))});

x_z19z_7.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z19z18,vector<personClass*>({&x_z19z9,&x_z19z10,&x_z19z23}))});

x_z19z_4.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z19z17,vector<personClass*>({&x_z19z11,&x_z19z12}))});

x_z19z_1.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z19z16,vector<personClass*>({&x_z19z13,&x_z19z14,&x_z19z15}))});

x_z19z_24.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z19z30,vector<personClass*>({&x_z19z32,&x_z19z33}))});

x_z19z_27.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z19z36,vector<personClass*>({&x_z19z40}))});

x_z19z_30.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z19z37,vector<personClass*>({&x_z19z41}))});

x_z19z_33.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z19z38,vector<personClass*>({&x_z19z42}))});

x_z19z_36.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z19z39,vector<personClass*>({&x_z19z43}))});

x_z19z1.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z19z2.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z19z3.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z19z4.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z19z9.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z19z10.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z19z11.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z19z12.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z19z13.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z19z14.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z19z15.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z19z16.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z19z_1,vector<personClass*>({&x_z19z13,&x_z19z14,&x_z19z15}))});

x_z19z17.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z19z_4,vector<personClass*>({&x_z19z11,&x_z19z12}))});

x_z19z18.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z19z_7,vector<personClass*>({&x_z19z9,&x_z19z10,&x_z19z23}))});

x_z19z21.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z19z_13,vector<personClass*>({&x_z19z3,&x_z19z4}))});

x_z19z23.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z19z24.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z19z25,vector<personClass*>({&x_z19z27,&x_z19z28,&x_z19z29}))});

x_z19z25.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z19z24,vector<personClass*>({&x_z19z27,&x_z19z28,&x_z19z29}))});

x_z19z26.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z19z_10,vector<personClass*>({&x_z19z1,&x_z19z2}))});

x_z19z27.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z19z28.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z19z29.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z19z32.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z19z33.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z19z35.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z19z34,vector<personClass*>({&x_z19z16,&x_z19z17,&x_z19z18,&x_z19z24}))});

x_z19z36.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z19z_27,vector<personClass*>({&x_z19z40}))});

x_z19z37.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z19z_30,vector<personClass*>({&x_z19z41}))});

x_z19z38.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z19z_33,vector<personClass*>({&x_z19z42}))});

x_z19z39.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z19z_36,vector<personClass*>({&x_z19z43}))});

x_z19z40.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z19z41.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z19z42.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z19z43.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

pedigreeClass2 pedigreez19z;
pedigreez19z.roots=vector<personClass*>({&x_z19z30,&x_z19z31,&x_z19z34,&x_z19z44,&x_z19z45,&x_z19z_10,&x_z19z_13,&x_z19z_7,&x_z19z_4,&x_z19z_1,&x_z19z_24,&x_z19z_27,&x_z19z_30,&x_z19z_33,&x_z19z_36});
pedigreez19z.allPeople=vector<personClass*>({&x_z19z1,&x_z19z2,&x_z19z3,&x_z19z4,&x_z19z9,&x_z19z10,&x_z19z11,&x_z19z12,&x_z19z13,&x_z19z14,&x_z19z15,&x_z19z16,&x_z19z17,&x_z19z18,&x_z19z21,&x_z19z23,&x_z19z24,&x_z19z25,&x_z19z26,&x_z19z27,&x_z19z28,&x_z19z29,&x_z19z30,&x_z19z31,&x_z19z32,&x_z19z33,&x_z19z34,&x_z19z35,&x_z19z36,&x_z19z37,&x_z19z38,&x_z19z39,&x_z19z40,&x_z19z41,&x_z19z42,&x_z19z43,&x_z19z44,&x_z19z45,&x_z19z_10,&x_z19z_13,&x_z19z_7,&x_z19z_4,&x_z19z_1,&x_z19z_24,&x_z19z_27,&x_z19z_30,&x_z19z_33,&x_z19z_36});
pedigreez19z.families=vector<vector<personClass*>>({{&x_z19z_33,&x_z19z38,&x_z19z42},{&x_z19z_24,&x_z19z30,&x_z19z32,&x_z19z33},{&x_z19z18,&x_z19z_7,&x_z19z9,&x_z19z10,&x_z19z23},{&x_z19z24,&x_z19z25,&x_z19z27,&x_z19z28,&x_z19z29},{&x_z19z44,&x_z19z45,&x_z19z35,&x_z19z36,&x_z19z37,&x_z19z38,&x_z19z39},{&x_z19z_1,&x_z19z16,&x_z19z13,&x_z19z14,&x_z19z15},{&x_z19z35,&x_z19z34,&x_z19z16,&x_z19z17,&x_z19z18,&x_z19z24},{&x_z19z_10,&x_z19z26,&x_z19z1,&x_z19z2},{&x_z19z17,&x_z19z_4,&x_z19z11,&x_z19z12},{&x_z19z31,&x_z19z30,&x_z19z21,&x_z19z25,&x_z19z26},{&x_z19z_13,&x_z19z21,&x_z19z3,&x_z19z4},{&x_z19z_30,&x_z19z37,&x_z19z41},{&x_z19z39,&x_z19z_36,&x_z19z43},{&x_z19z_27,&x_z19z36,&x_z19z40}});
pedigreez19z.leaves=vector<personClass*>({&x_z19z1,&x_z19z2,&x_z19z3,&x_z19z4,&x_z19z9,&x_z19z10,&x_z19z11,&x_z19z12,&x_z19z13,&x_z19z14,&x_z19z15,&x_z19z23,&x_z19z27,&x_z19z28,&x_z19z29,&x_z19z32,&x_z19z33,&x_z19z40,&x_z19z41,&x_z19z42,&x_z19z43});
pedigreez19z.isDominant=false;
pedigreez19z.sexDependent=true;
pedigreez19z.mapToIndexRoots=unordered_map<personClass*,int>({{&x_z19z_36,14},{&x_z19z_30,12},{&x_z19z_27,11},{&x_z19z_13,6},{&x_z19z_24,10},{&x_z19z_4,8},{&x_z19z44,3},{&x_z19z_7,7},{&x_z19z_33,13},{&x_z19z_10,5},{&x_z19z30,0},{&x_z19z45,4},{&x_z19z31,1},{&x_z19z34,2},{&x_z19z_1,9}});
pedigreez19z.mapToIndexAllPeople=unordered_map<personClass*,int>({{&x_z19z_36,47},{&x_z19z38,30},{&x_z19z_33,46},{&x_z19z_30,45},{&x_z19z_27,44},{&x_z19z30,22},{&x_z19z_24,43},{&x_z19z32,24},{&x_z19z37,29},{&x_z19z_4,41},{&x_z19z3,2},{&x_z19z_10,38},{&x_z19z_7,40},{&x_z19z44,36},{&x_z19z43,35},{&x_z19z42,34},{&x_z19z41,33},{&x_z19z27,19},{&x_z19z39,31},{&x_z19z33,25},{&x_z19z31,23},{&x_z19z21,14},{&x_z19z1,0},{&x_z19z28,20},{&x_z19z26,18},{&x_z19z40,32},{&x_z19z24,16},{&x_z19z2,1},{&x_z19z10,5},{&x_z19z4,3},{&x_z19z29,21},{&x_z19z18,13},{&x_z19z17,12},{&x_z19z_1,42},{&x_z19z35,27},{&x_z19z16,11},{&x_z19z34,26},{&x_z19z15,10},{&x_z19z45,37},{&x_z19z13,8},{&x_z19z25,17},{&x_z19z14,9},{&x_z19z11,6},{&x_z19z9,4},{&x_z19z_13,39},{&x_z19z12,7},{&x_z19z36,28},{&x_z19z23,15}});

x_z20z1.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z20z2,vector<personClass*>({&x_z20z4}))});

x_z20z2.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z20z1,vector<personClass*>({&x_z20z4}))});

x_z20z3.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z20z4,vector<personClass*>({&x_z20z6}))});

x_z20z9.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z20z5,vector<personClass*>({&x_z20z10}))});

x_z20z13.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z20z14,vector<personClass*>({&x_z20z5,&x_z20z11}))});

x_z20z23.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z20z24,vector<personClass*>({&x_z20z14,&x_z20z15,&x_z20z16,&x_z20z17,&x_z20z18}))});

x_z20z24.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z20z23,vector<personClass*>({&x_z20z14,&x_z20z15,&x_z20z16,&x_z20z17,&x_z20z18}))});

x_z20z_1.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z20z11,vector<personClass*>({&x_z20z12}))});

x_z20z_4.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z20z15,vector<personClass*>({&x_z20z19}))});

x_z20z_7.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z20z16,vector<personClass*>({&x_z20z20}))});

x_z20z_10.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z20z17,vector<personClass*>({&x_z20z21,&x_z20z22}))});

x_z20z4.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z20z3,vector<personClass*>({&x_z20z6})),pair<personClass*,vector<personClass*>>(&x_z20z5,vector<personClass*>({&x_z20z7,&x_z20z8}))});

x_z20z5.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z20z9,vector<personClass*>({&x_z20z10})),pair<personClass*,vector<personClass*>>(&x_z20z4,vector<personClass*>({&x_z20z7,&x_z20z8}))});

x_z20z6.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z20z7.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z20z8.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z20z10.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z20z11.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z20z_1,vector<personClass*>({&x_z20z12}))});

x_z20z12.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z20z14.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z20z13,vector<personClass*>({&x_z20z5,&x_z20z11}))});

x_z20z15.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z20z_4,vector<personClass*>({&x_z20z19}))});

x_z20z16.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z20z_7,vector<personClass*>({&x_z20z20}))});

x_z20z17.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z20z_10,vector<personClass*>({&x_z20z21,&x_z20z22}))});

x_z20z18.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z20z19.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z20z20.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z20z21.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z20z22.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

pedigreeClass2 pedigreez20z;
pedigreez20z.roots=vector<personClass*>({&x_z20z1,&x_z20z2,&x_z20z3,&x_z20z9,&x_z20z13,&x_z20z23,&x_z20z24,&x_z20z_1,&x_z20z_4,&x_z20z_7,&x_z20z_10});
pedigreez20z.allPeople=vector<personClass*>({&x_z20z1,&x_z20z2,&x_z20z3,&x_z20z4,&x_z20z5,&x_z20z6,&x_z20z7,&x_z20z8,&x_z20z9,&x_z20z10,&x_z20z11,&x_z20z12,&x_z20z13,&x_z20z14,&x_z20z15,&x_z20z16,&x_z20z17,&x_z20z18,&x_z20z19,&x_z20z20,&x_z20z21,&x_z20z22,&x_z20z23,&x_z20z24,&x_z20z_1,&x_z20z_4,&x_z20z_7,&x_z20z_10});
pedigreez20z.families=vector<vector<personClass*>>({{&x_z20z2,&x_z20z1,&x_z20z4},{&x_z20z14,&x_z20z13,&x_z20z5,&x_z20z11},{&x_z20z3,&x_z20z4,&x_z20z6},{&x_z20z24,&x_z20z23,&x_z20z14,&x_z20z15,&x_z20z16,&x_z20z17,&x_z20z18},{&x_z20z5,&x_z20z9,&x_z20z10},{&x_z20z5,&x_z20z4,&x_z20z7,&x_z20z8},{&x_z20z15,&x_z20z_4,&x_z20z19},{&x_z20z_10,&x_z20z17,&x_z20z21,&x_z20z22},{&x_z20z11,&x_z20z_1,&x_z20z12},{&x_z20z_7,&x_z20z16,&x_z20z20}});
pedigreez20z.leaves=vector<personClass*>({&x_z20z6,&x_z20z7,&x_z20z8,&x_z20z10,&x_z20z12,&x_z20z18,&x_z20z19,&x_z20z20,&x_z20z21,&x_z20z22});
pedigreez20z.isDominant=false;
pedigreez20z.sexDependent=true;
pedigreez20z.mapToIndexRoots=unordered_map<personClass*,int>({{&x_z20z_10,10},{&x_z20z_1,7},{&x_z20z9,3},{&x_z20z_7,9},{&x_z20z_4,8},{&x_z20z3,2},{&x_z20z24,6},{&x_z20z23,5},{&x_z20z2,1},{&x_z20z13,4},{&x_z20z1,0}});
pedigreez20z.mapToIndexAllPeople=unordered_map<personClass*,int>({{&x_z20z_10,27},{&x_z20z_1,24},{&x_z20z24,23},{&x_z20z23,22},{&x_z20z3,2},{&x_z20z21,20},{&x_z20z20,19},{&x_z20z19,18},{&x_z20z18,17},{&x_z20z_4,25},{&x_z20z16,15},{&x_z20z15,14},{&x_z20z14,13},{&x_z20z_7,26},{&x_z20z22,21},{&x_z20z13,12},{&x_z20z7,6},{&x_z20z9,8},{&x_z20z11,10},{&x_z20z4,3},{&x_z20z8,7},{&x_z20z6,5},{&x_z20z10,9},{&x_z20z12,11},{&x_z20z5,4},{&x_z20z2,1},{&x_z20z17,16},{&x_z20z1,0}});


vector<pedigreeClass2*> trainingSet({&pedigreez0z,&pedigreez1z,&pedigreez2z,&pedigreez3z,&pedigreez4z,&pedigreez5z,&pedigreez6z,&pedigreez7z,&pedigreez8z,&pedigreez9z,&pedigreez10z,&pedigreez11z,&pedigreez12z,&pedigreez13z,&pedigreez14z,&pedigreez15z,&pedigreez16z,&pedigreez17z,&pedigreez18z,&pedigreez19z,&pedigreez20z});
    
    //vector<pedigreeClass2*> trainingSet({&pedigreez0z,&pedigreez1z});



personClass x_z990z1(1,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z990z2(2,nullptr,nullptr,true,0.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),true,"shaded","female");

personClass x_z990z21(21,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z990z22(22,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z990z_1(-1,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z990z_4(-4,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z990z_10(-10,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z990z_13(-13,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z990z_16(-16,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z990z_19(-19,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z990z_23(-23,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z990z_27(-27,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z990z_31(-31,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z990z_34(-34,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z990z_37(-37,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z990z_40(-40,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z990z_7(-7,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z990z_43(-43,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z990z_46(-46,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z990z_49(-49,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z990z_53(-53,nullptr,nullptr,true,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","female");

personClass x_z990z_74(-74,nullptr,nullptr,true,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({}),false,"unshaded","male");

personClass x_z990z3(3,&x_z990z1,&x_z990z2,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z990z4(4,&x_z990z1,&x_z990z2,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z990z5(5,&x_z990z1,&x_z990z2,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z990z6(6,&x_z990z1,&x_z990z2,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z990z7(7,&x_z990z1,&x_z990z2,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z990z8(8,&x_z990z1,&x_z990z2,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z990z9(9,&x_z990z1,&x_z990z2,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z990z10(10,&x_z990z1,&x_z990z2,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),true,"shaded","male");

personClass x_z990z11(11,&x_z990z1,&x_z990z2,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z990z12(12,&x_z990z1,&x_z990z2,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z990z13(13,&x_z990z1,&x_z990z2,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),true,"shaded","male");

personClass x_z990z14(14,&x_z990z22,&x_z990z21,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z990z15(15,&x_z990z22,&x_z990z21,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z990z16(16,&x_z990z22,&x_z990z21,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z990z17(17,&x_z990z22,&x_z990z21,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z990z18(18,&x_z990z22,&x_z990z21,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z990z19(19,&x_z990z22,&x_z990z21,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z990z20(20,&x_z990z22,&x_z990z21,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z990z32(32,&x_z990z1,&x_z990z2,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z990z33(33,&x_z990z3,&x_z990z_1,false,1.000000,0.500000,0.000000,3,5,8,vector<double>(8),false,vector<vector<vector<double>>>({{{0.500000,0.500000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.500000,0.500000,0.500000,0.500000},{0.250000,0.250000,0.250000,0.250000},{0.250000,0.250000,0.250000,0.250000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000}},{{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.500000,0.500000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.250000,0.250000,0.250000,0.250000},{0.250000,0.250000,0.250000,0.250000},{0.500000,0.500000,0.500000,0.500000}}}),false,"unshaded","unknown");

personClass x_z990z34(34,&x_z990z4,&x_z990z_4,false,1.000000,0.500000,0.000000,3,5,8,vector<double>(8),false,vector<vector<vector<double>>>({{{0.500000,0.500000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.500000,0.500000,0.500000,0.500000},{0.250000,0.250000,0.250000,0.250000},{0.250000,0.250000,0.250000,0.250000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000}},{{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.500000,0.500000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.250000,0.250000,0.250000,0.250000},{0.250000,0.250000,0.250000,0.250000},{0.500000,0.500000,0.500000,0.500000}}}),false,"unshaded","unknown");

personClass x_z990z35(35,&x_z990z32,&x_z990z_7,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),true,"shaded","male");

personClass x_z990z36(36,&x_z990z5,&x_z990z_10,false,1.000000,0.500000,0.000000,3,5,8,vector<double>(8),false,vector<vector<vector<double>>>({{{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000}},{{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000}},{{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","unknown");

personClass x_z990z37(37,&x_z990z6,&x_z990z_13,false,1.000000,0.500000,0.000000,3,5,8,vector<double>(8),false,vector<vector<vector<double>>>({{{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000}},{{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000}},{{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","unknown");

personClass x_z990z38(38,&x_z990z7,&x_z990z_16,false,1.000000,0.500000,0.000000,3,5,8,vector<double>(8),false,vector<vector<vector<double>>>({{{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000}},{{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000}},{{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","unknown");

personClass x_z990z39(39,&x_z990z9,&x_z990z_19,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),true,"shaded","male");

personClass x_z990z40(40,&x_z990z12,&x_z990z_23,false,1.000000,0.500000,0.000000,3,5,8,vector<double>(8),false,vector<vector<vector<double>>>({{{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.500000,0.250000,0.250000,0.000000},{0.500000,0.250000,0.250000,0.000000}},{{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000}},{{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000},{0.000000,0.250000,0.250000,0.500000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","unknown");

personClass x_z990z41(41,&x_z990z13,&x_z990z14,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z990z42(42,&x_z990z13,&x_z990z14,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),false,"unshaded","female");

personClass x_z990z43(43,&x_z990z13,&x_z990z14,false,0.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}}}),true,"shaded","female");

personClass x_z990z44(44,&x_z990z13,&x_z990z14,false,0.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),true,"shaded","male");

personClass x_z990z45(45,&x_z990z13,&x_z990z14,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z990z46(46,&x_z990z16,&x_z990z_27,false,1.000000,0.500000,0.000000,3,5,8,vector<double>(8),false,vector<vector<vector<double>>>({{{0.500000,0.500000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.500000,0.500000,0.500000,0.500000},{0.250000,0.250000,0.250000,0.250000},{0.250000,0.250000,0.250000,0.250000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000}},{{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.500000,0.500000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.250000,0.250000,0.250000,0.250000},{0.250000,0.250000,0.250000,0.250000},{0.500000,0.500000,0.500000,0.500000}}}),false,"unshaded","unknown");

personClass x_z990z47(47,&x_z990z17,&x_z990z_31,false,1.000000,0.500000,0.000000,3,5,8,vector<double>(8),false,vector<vector<vector<double>>>({{{0.500000,0.500000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.500000,0.500000,0.500000,0.500000},{0.250000,0.250000,0.250000,0.250000},{0.250000,0.250000,0.250000,0.250000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000}},{{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.500000,0.500000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.250000,0.250000,0.250000,0.250000},{0.250000,0.250000,0.250000,0.250000},{0.500000,0.500000,0.500000,0.500000}}}),false,"unshaded","unknown");

personClass x_z990z48(48,&x_z990z18,&x_z990z_34,false,1.000000,0.500000,0.000000,3,5,8,vector<double>(8),false,vector<vector<vector<double>>>({{{0.500000,0.500000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.500000,0.500000,0.500000,0.500000},{0.250000,0.250000,0.250000,0.250000},{0.250000,0.250000,0.250000,0.250000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000}},{{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.500000,0.500000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.250000,0.250000,0.250000,0.250000},{0.250000,0.250000,0.250000,0.250000},{0.500000,0.500000,0.500000,0.500000}}}),false,"unshaded","unknown");

personClass x_z990z49(49,&x_z990z19,&x_z990z_37,false,1.000000,0.500000,0.000000,3,5,8,vector<double>(8),false,vector<vector<vector<double>>>({{{0.500000,0.500000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.500000,0.500000,0.500000,0.500000},{0.250000,0.250000,0.250000,0.250000},{0.250000,0.250000,0.250000,0.250000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000}},{{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.500000,0.500000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.250000,0.250000,0.250000,0.250000},{0.250000,0.250000,0.250000,0.250000},{0.500000,0.500000,0.500000,0.500000}}}),false,"unshaded","unknown");

personClass x_z990z50(50,&x_z990z20,&x_z990z_40,false,1.000000,0.500000,0.000000,3,5,8,vector<double>(8),false,vector<vector<vector<double>>>({{{0.500000,0.500000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.500000,0.500000,0.500000,0.500000},{0.250000,0.250000,0.250000,0.250000},{0.250000,0.250000,0.250000,0.250000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000}},{{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.500000,0.500000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.250000,0.250000,0.250000,0.250000},{0.250000,0.250000,0.250000,0.250000},{0.500000,0.500000,0.500000,0.500000}}}),false,"unshaded","unknown");

personClass x_z990z51(51,&x_z990z41,&x_z990z_43,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");

personClass x_z990z52(52,&x_z990z42,&x_z990z_46,false,1.000000,0.500000,0.000000,3,5,8,vector<double>(8),false,vector<vector<vector<double>>>({{{0.500000,0.500000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.500000,0.500000,0.500000,0.500000},{0.250000,0.250000,0.250000,0.250000},{0.250000,0.250000,0.250000,0.250000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.250000,0.250000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000}},{{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.250000,0.250000},{0.000000,0.000000,0.500000,0.500000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.250000,0.250000,0.250000,0.250000},{0.250000,0.250000,0.250000,0.250000},{0.500000,0.500000,0.500000,0.500000}}}),false,"unshaded","unknown");

personClass x_z990z53(53,&x_z990z43,&x_z990z_49,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{1.000000,1.000000,1.000000,1.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.500000,0.500000},{0.500000,0.500000,0.500000,0.500000},{1.000000,1.000000,1.000000,1.000000}}}),false,"unshaded","male");

personClass x_z990z54(54,&x_z990z43,&x_z990z_49,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),false,"unshaded","female");

personClass x_z990z55(55,&x_z990z43,&x_z990z_49,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),false,"unshaded","female");

personClass x_z990z56(56,&x_z990z43,&x_z990z_49,false,0.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),true,"shaded","female");

personClass x_z990z57(57,&x_z990z44,&x_z990z_53,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z990z58(58,&x_z990z44,&x_z990z_53,false,1.000000,0.500000,0.000000,2,2,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000},{1.000000,0.500000,0.500000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000},{0.000000,0.500000,0.500000,1.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}}}),false,"unshaded","male");

personClass x_z990z602(602,&x_z990z56,&x_z990z_74,false,1.000000,0.500000,0.000000,1,3,4,vector<double>(4),false,vector<vector<vector<double>>>({{{1.000000,1.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{0.500000,0.500000,0.000000,0.000000},{1.000000,1.000000,0.000000,0.000000}},{{0.000000,0.000000,1.000000,1.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.000000,0.000000}},{{0.000000,0.000000,0.000000,0.000000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,0.500000,0.500000},{0.000000,0.000000,1.000000,1.000000}}}),false,"unshaded","female");






















x_z990z1.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z990z2,vector<personClass*>({&x_z990z3,&x_z990z4,&x_z990z5,&x_z990z6,&x_z990z7,&x_z990z8,&x_z990z9,&x_z990z10,&x_z990z11,&x_z990z12,&x_z990z13,&x_z990z32}))});

x_z990z2.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z990z1,vector<personClass*>({&x_z990z3,&x_z990z4,&x_z990z5,&x_z990z6,&x_z990z7,&x_z990z8,&x_z990z9,&x_z990z10,&x_z990z11,&x_z990z12,&x_z990z13,&x_z990z32}))});

x_z990z21.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z990z22,vector<personClass*>({&x_z990z14,&x_z990z15,&x_z990z16,&x_z990z17,&x_z990z18,&x_z990z19,&x_z990z20}))});

x_z990z22.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z990z21,vector<personClass*>({&x_z990z14,&x_z990z15,&x_z990z16,&x_z990z17,&x_z990z18,&x_z990z19,&x_z990z20}))});

x_z990z_1.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z990z3,vector<personClass*>({&x_z990z33}))});

x_z990z_4.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z990z4,vector<personClass*>({&x_z990z34}))});

x_z990z_10.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z990z5,vector<personClass*>({&x_z990z36}))});

x_z990z_13.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z990z6,vector<personClass*>({&x_z990z37}))});

x_z990z_16.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z990z7,vector<personClass*>({&x_z990z38}))});

x_z990z_19.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z990z9,vector<personClass*>({&x_z990z39}))});

x_z990z_23.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z990z12,vector<personClass*>({&x_z990z40}))});

x_z990z_27.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z990z16,vector<personClass*>({&x_z990z46}))});

x_z990z_31.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z990z17,vector<personClass*>({&x_z990z47}))});

x_z990z_34.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z990z18,vector<personClass*>({&x_z990z48}))});

x_z990z_37.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z990z19,vector<personClass*>({&x_z990z49}))});

x_z990z_40.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z990z20,vector<personClass*>({&x_z990z50}))});

x_z990z_7.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z990z32,vector<personClass*>({&x_z990z35}))});

x_z990z_43.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z990z41,vector<personClass*>({&x_z990z51}))});

x_z990z_46.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z990z42,vector<personClass*>({&x_z990z52}))});

x_z990z_49.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z990z43,vector<personClass*>({&x_z990z53,&x_z990z54,&x_z990z55,&x_z990z56}))});

x_z990z_53.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z990z44,vector<personClass*>({&x_z990z57,&x_z990z58}))});

x_z990z_74.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z990z56,vector<personClass*>({&x_z990z602}))});

x_z990z3.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z990z_1,vector<personClass*>({&x_z990z33}))});

x_z990z4.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z990z_4,vector<personClass*>({&x_z990z34}))});

x_z990z5.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z990z_10,vector<personClass*>({&x_z990z36}))});

x_z990z6.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z990z_13,vector<personClass*>({&x_z990z37}))});

x_z990z7.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z990z_16,vector<personClass*>({&x_z990z38}))});

x_z990z8.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z990z9.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z990z_19,vector<personClass*>({&x_z990z39}))});

x_z990z10.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z990z11.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z990z12.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z990z_23,vector<personClass*>({&x_z990z40}))});

x_z990z13.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z990z14,vector<personClass*>({&x_z990z41,&x_z990z42,&x_z990z43,&x_z990z44,&x_z990z45}))});

x_z990z14.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z990z13,vector<personClass*>({&x_z990z41,&x_z990z42,&x_z990z43,&x_z990z44,&x_z990z45}))});

x_z990z15.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z990z16.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z990z_27,vector<personClass*>({&x_z990z46}))});

x_z990z17.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z990z_31,vector<personClass*>({&x_z990z47}))});

x_z990z18.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z990z_34,vector<personClass*>({&x_z990z48}))});

x_z990z19.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z990z_37,vector<personClass*>({&x_z990z49}))});

x_z990z20.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z990z_40,vector<personClass*>({&x_z990z50}))});

x_z990z32.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z990z_7,vector<personClass*>({&x_z990z35}))});

x_z990z33.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z990z34.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z990z35.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z990z36.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z990z37.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z990z38.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z990z39.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z990z40.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z990z41.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z990z_43,vector<personClass*>({&x_z990z51}))});

x_z990z42.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z990z_46,vector<personClass*>({&x_z990z52}))});

x_z990z43.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z990z_49,vector<personClass*>({&x_z990z53,&x_z990z54,&x_z990z55,&x_z990z56}))});

x_z990z44.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z990z_53,vector<personClass*>({&x_z990z57,&x_z990z58}))});

x_z990z45.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z990z46.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z990z47.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z990z48.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z990z49.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z990z50.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z990z51.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z990z52.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z990z53.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z990z54.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z990z55.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z990z56.mateKids = vector<pair<personClass*,vector<personClass*>>>({pair<personClass*,vector<personClass*>>(&x_z990z_74,vector<personClass*>({&x_z990z602}))});

x_z990z57.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z990z58.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

x_z990z602.mateKids = vector<pair<personClass*,vector<personClass*>>>({});

pedigreeClass2 pedigreez990z;
pedigreez990z.roots=vector<personClass*>({&x_z990z1,&x_z990z2,&x_z990z21,&x_z990z22,&x_z990z_1,&x_z990z_4,&x_z990z_10,&x_z990z_13,&x_z990z_16,&x_z990z_19,&x_z990z_23,&x_z990z_27,&x_z990z_31,&x_z990z_34,&x_z990z_37,&x_z990z_40,&x_z990z_7,&x_z990z_43,&x_z990z_46,&x_z990z_49,&x_z990z_53,&x_z990z_74});
pedigreez990z.allPeople=vector<personClass*>({&x_z990z1,&x_z990z2,&x_z990z3,&x_z990z4,&x_z990z5,&x_z990z6,&x_z990z7,&x_z990z8,&x_z990z9,&x_z990z10,&x_z990z11,&x_z990z12,&x_z990z13,&x_z990z14,&x_z990z15,&x_z990z16,&x_z990z17,&x_z990z18,&x_z990z19,&x_z990z20,&x_z990z21,&x_z990z22,&x_z990z32,&x_z990z33,&x_z990z34,&x_z990z35,&x_z990z36,&x_z990z37,&x_z990z38,&x_z990z39,&x_z990z40,&x_z990z41,&x_z990z42,&x_z990z43,&x_z990z44,&x_z990z45,&x_z990z46,&x_z990z47,&x_z990z48,&x_z990z49,&x_z990z50,&x_z990z51,&x_z990z52,&x_z990z53,&x_z990z54,&x_z990z55,&x_z990z56,&x_z990z57,&x_z990z58,&x_z990z602,&x_z990z_1,&x_z990z_4,&x_z990z_10,&x_z990z_13,&x_z990z_16,&x_z990z_19,&x_z990z_23,&x_z990z_27,&x_z990z_31,&x_z990z_34,&x_z990z_37,&x_z990z_40,&x_z990z_7,&x_z990z_43,&x_z990z_46,&x_z990z_49,&x_z990z_53,&x_z990z_74});
pedigreez990z.families=vector<vector<personClass*>>({{&x_z990z9,&x_z990z_19,&x_z990z39},{&x_z990z2,&x_z990z1,&x_z990z3,&x_z990z4,&x_z990z5,&x_z990z6,&x_z990z7,&x_z990z8,&x_z990z9,&x_z990z10,&x_z990z11,&x_z990z12,&x_z990z13,&x_z990z32},{&x_z990z3,&x_z990z_1,&x_z990z33},{&x_z990z_23,&x_z990z12,&x_z990z40},{&x_z990z21,&x_z990z22,&x_z990z14,&x_z990z15,&x_z990z16,&x_z990z17,&x_z990z18,&x_z990z19,&x_z990z20},{&x_z990z14,&x_z990z13,&x_z990z41,&x_z990z42,&x_z990z43,&x_z990z44,&x_z990z45},{&x_z990z16,&x_z990z_27,&x_z990z46},{&x_z990z32,&x_z990z_7,&x_z990z35},{&x_z990z56,&x_z990z_74,&x_z990z602},{&x_z990z_16,&x_z990z7,&x_z990z38},{&x_z990z42,&x_z990z_46,&x_z990z52},{&x_z990z_10,&x_z990z5,&x_z990z36},{&x_z990z4,&x_z990z_4,&x_z990z34},{&x_z990z_53,&x_z990z44,&x_z990z57,&x_z990z58},{&x_z990z17,&x_z990z_31,&x_z990z47},{&x_z990z41,&x_z990z_43,&x_z990z51},{&x_z990z18,&x_z990z_34,&x_z990z48},{&x_z990z19,&x_z990z_37,&x_z990z49},{&x_z990z20,&x_z990z_40,&x_z990z50},{&x_z990z43,&x_z990z_49,&x_z990z53,&x_z990z54,&x_z990z55,&x_z990z56},{&x_z990z_13,&x_z990z6,&x_z990z37}});
pedigreez990z.leaves=vector<personClass*>({&x_z990z8,&x_z990z10,&x_z990z11,&x_z990z15,&x_z990z33,&x_z990z34,&x_z990z35,&x_z990z36,&x_z990z37,&x_z990z38,&x_z990z39,&x_z990z40,&x_z990z45,&x_z990z46,&x_z990z47,&x_z990z48,&x_z990z49,&x_z990z50,&x_z990z51,&x_z990z52,&x_z990z53,&x_z990z54,&x_z990z55,&x_z990z57,&x_z990z58,&x_z990z602});
pedigreez990z.isDominant=false;
pedigreez990z.sexDependent=true;
pedigreez990z.mapToIndexRoots=unordered_map<personClass*,int>({{&x_z990z_74,21},{&x_z990z_53,20},{&x_z990z_7,16},{&x_z990z_37,14},{&x_z990z_34,13},{&x_z990z_31,12},{&x_z990z_43,17},{&x_z990z_27,11},{&x_z990z_19,9},{&x_z990z_49,19},{&x_z990z1,0},{&x_z990z22,3},{&x_z990z_13,7},{&x_z990z_16,8},{&x_z990z_40,15},{&x_z990z_10,6},{&x_z990z_4,5},{&x_z990z_1,4},{&x_z990z_46,18},{&x_z990z2,1},{&x_z990z21,2},{&x_z990z_23,10}});
pedigreez990z.mapToIndexAllPeople=unordered_map<personClass*,int>({{&x_z990z_49,65},{&x_z990z_46,64},{&x_z990z_43,63},{&x_z990z_40,61},{&x_z990z_37,60},{&x_z990z_23,56},{&x_z990z_16,54},{&x_z990z_13,53},{&x_z990z_10,52},{&x_z990z_27,57},{&x_z990z_1,50},{&x_z990z57,47},{&x_z990z53,43},{&x_z990z50,40},{&x_z990z33,23},{&x_z990z44,34},{&x_z990z52,42},{&x_z990z39,29},{&x_z990z43,33},{&x_z990z48,38},{&x_z990z42,32},{&x_z990z_74,67},{&x_z990z_4,51},{&x_z990z40,30},{&x_z990z38,28},{&x_z990z55,45},{&x_z990z37,27},{&x_z990z32,22},{&x_z990z56,46},{&x_z990z_53,66},{&x_z990z49,39},{&x_z990z58,48},{&x_z990z16,15},{&x_z990z36,26},{&x_z990z19,18},{&x_z990z35,25},{&x_z990z_7,62},{&x_z990z46,36},{&x_z990z17,16},{&x_z990z47,37},{&x_z990z_31,58},{&x_z990z20,19},{&x_z990z9,8},{&x_z990z15,14},{&x_z990z13,12},{&x_z990z18,17},{&x_z990z10,9},{&x_z990z11,10},{&x_z990z_34,59},{&x_z990z602,49},{&x_z990z12,11},{&x_z990z7,6},{&x_z990z45,35},{&x_z990z8,7},{&x_z990z6,5},{&x_z990z3,2},{&x_z990z41,31},{&x_z990z5,4},{&x_z990z14,13},{&x_z990z_19,55},{&x_z990z4,3},{&x_z990z54,44},{&x_z990z51,41},{&x_z990z21,20},{&x_z990z2,1},{&x_z990z34,24},{&x_z990z22,21},{&x_z990z1,0}});


vector<pedigreeClass2*> testSet({&pedigreez990z});



    cout << "\n\n\n\n=====================================================================================================\n\n\n\n" << endl;

    EMPedigreeOptimizer empoXLR;
    bool rootProbUpdate = true;
    bool emissionProbUpdate = true;
    bool transitionProbUpdate = false;
    empoXLR.train(trainingSet,"XLR",false,rootProbUpdate,emissionProbUpdate,transitionProbUpdate);
    double xlrProbExpected = empoXLR.predictExpectedProbability(&pedigreez990z,"XLR",false);
    double xlrProb = empoXLR.predictMostLikelyProbability(&pedigreez990z,"XLR",false);
    

    cout << "XLR prob was: " << xlrProb << endl;

    cout << "XLR expected prob was: " << xlrProbExpected << endl;

    return 1;
}


