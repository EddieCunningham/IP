#include "VEGAS.h"
#define ALPH 1.5
#define NDMX 50 // number of segments to split each dimension (K)
#define MXDIM 10 // maximum value for d
#define TINY 1.0e-30

using namespace std;

void vegas(float regn[], // rectangular volume specified by regn[1..2*ndim], consisting of ndim lower left coordinates of the region followed by ndim upper right coordinates
           int ndim, // number of dimensions
           float (*fxn)(const vector<float>&, float), // user supplied ndim-dimensional function
           int init, // signals whether call is a new start or not
           unsigned long ncall, // number of function calls per iterations
           int itmx, // number of iterations (should be 5-10 at most)
           int nprn, // controls the amount of diagnostic output (usually 0)
           float *tgral, // best estimate of the integral
           float *sd, // standard deviation
           float *chi2a // chi squared per degree of freedom
           ) {

    void rebin(float rc,
               int nd,
               vector<float> &r,
               vector<float> &xin,
               vector<vector<float>> &xi,
               int j);

    static int i,
               it,
               j,
               k,
               mds,
               nd,
               ndo,
               ng,
               npg;
               
    static vector<int> ia(MXDIM);
    static vector<int> kg(MXDIM);

    static float calls,
                 dv2g,
                 dxg,
                 f,
                 f2,
                 f2b,
                 fb,
                 rc,
                 ti,
                 tsi,
                 wgt,
                 xjac,
                 xn,
                 xnd,
                 xo;

//    static float d[NDMX][MXDIM],
//                 di[NDMX][MXDIM],
//                 dt[MXDIM],
//                 dx[MXDIM],
//                 r[NDMX],
//                 x[MXDIM],
//                 xi[MXDIM][NDMX], // the split up regions of each dimension
//                 xin[NDMX];
               
               
   static vector<vector<float>> d(NDMX,vector<float>(MXDIM));
   static vector<vector<float>> di(NDMX,vector<float>(MXDIM));
   static vector<vector<float>> xi(MXDIM,vector<float>(NDMX));
   static vector<float> dt(MXDIM);
   static vector<float> dx(MXDIM);
   static vector<float> r(NDMX);
   static vector<float> x(MXDIM);
   static vector<float> xin(NDMX);


    static double schi,
                  si,
                  swgt;

    if(init <= 0) {
        mds = ndo = 1;
        for(j=0; j<ndim; ++j) xi[j][0] = 1.0;
    }
    if(init <= 1) si = swgt = schi = 0.0;
    if(init <= 2) {
        nd = NDMX;
        ng = 1;
        if(mds) {
            ng = (int)(pow(ncall/2.0 + 0.25, 1.0/ndim));
            mds = 1;
            if((2*ng - NDMX) >= 0) {
                mds = -1;
                npg = ng/NDMX + 1;
                nd = ng/npg;
                ng = npg*nd;
            }
        }
        for(k=1,i=0; i<ndim; ++i) k *= ng;
        npg = max(int(ncall/k),2);
        calls = (float)npg*(float)k;
        dxg = 1.0/ng;
        for(dv2g=1,i=0; i<ndim; ++i) dv2g *= dxg;
        dv2g = pow(calls*dv2g,2)/npg/npg/(npg-1.0);
        xnd = nd;
        dxg *= xnd;
        xjac = 1.0/calls;
        for(j=0; j<ndim; ++j) {
            dx[j] = regn[j+ndim]-regn[j];
            xjac *= dx[j];
        }
        if(nd != ndo) {
            for(i=0; i<max(nd,ndo); ++i) r[i] = 1.0;
            for(j=0; j<ndim; ++j) rebin(ndo/xnd,nd,r,xin,xi,j);
            ndo = nd;
        }
        if(nprn >= 0) {
            printf("%s: ndim = %3d ncall = %8.0f\n"," Input parameters for vegas",ndim,calls);
            printf("%28s it=%5d itmx=%5d\n"," ",it,itmx);
            printf("%28s nprn=%3d ALPH=%5.2f\n"," ",nprn,ALPH);
            printf("%28s mds=%3d nd=%4d\n"," ",mds,nd);
            for(j=0; j<ndim; ++j) {
                printf("%30s xl[%2d]= %11.4g xu[%2d]= %11.4g\n"," ",j,regn[j],j,regn[j+ndim]);
            }
        }
    }


    for(it=0; it<itmx; ++it) {
        ti = tsi = 0.0;
        for(j=0; j<ndim; ++j) {
            kg[j] = 1;
            for(i=0; i<nd; ++i) d[i][j] = di[i][j] = 0.0;
        }
        for(;;) {
            fb = f2b = 0.0;
            for(k=0; k<npg; ++k) {
                wgt = xjac;
                for(j=0; j<ndim; ++j) {
                    // cout << "\n";
                    xn = (kg[j] - rand()/(double)RAND_MAX)*dxg + 1.0;
                    // cout << "kg[" << j << "]: " << kg[j] << endl;
                    // cout << "dxg: " << dxg << endl;
                    // xn = (kg[j] - ran2(&idum))*dxg + 1.0;
                    ia[j] = max(min((int)(xn),NDMX),1);
                    if(ia[j] > 1) {
                        xo = xi[j][ia[j]-1] - xi[j][ia[j]-2];
                        // cout << "xo: " << xo << endl;
                        // cout << "ia[" << j << "]: " << ia[j] << endl;
                        // cout << "xi[" << j << "][ia[" << j << "]]: " << xi[j][ia[j]] << endl;
                        // cout << "xi[" << j << "][ia[" << j << "]-1]: " << xi[j][ia[j]-1] << endl;
                        rc = xi[j][ia[j]-2] + (xn - ia[j])*xo;
                    }
                    else {
                        xo = xi[j][ia[j]-1];
                        rc = (xn - ia[j])*xo;
                    }
                    // cout << "regn[" << j << "]: " << regn[j] << endl;
                    // cout << "rc: " << rc << endl;
                    // cout << "dx[" << j << "]: " << dx[j] << endl;
                    x[j] = regn[j] + rc*dx[j];
//                    assert(x[j] <= 2*M_PI and x[j] >= 0.0);
                    wgt *= xo*xnd;
                }
                f = wgt*(*fxn)(x,wgt);
                f2 = f*f;
                fb += f;
                f2b += f2;
                for(j=0; j<ndim; ++j) {
                    di[ia[j]-1][j] += f;
                    if(mds >= 0) {
                        d[ia[j]-1][j] += f2;
                        assert(d[ia[j]-1][j] > 0);
                    }
                }
            }
            f2b = sqrt(f2b*npg);
            f2b = (f2b - fb)*(f2b + fb);
            if(f2b <= 0.0) f2b = TINY;
            ti += fb;
            tsi += f2b;
            if(mds < 0) {
                for(j=0; j<ndim; ++j) {
                    d[ia[j]-1][j] += f2b;
                }
            }
            for(k=ndim-1; k>=0; --k) {
                kg[k] %= ng;
                if(++kg[k] != 1) break;
            }
            if(k < 0) break;
        }
        tsi *= dv2g;
        wgt = 1.0/tsi;
        si += wgt*ti;
        schi += wgt*ti*ti;
        swgt += wgt;
        *tgral = si/swgt;
        *chi2a = (schi - si*(*tgral))/(it+0.00001);
        if(*chi2a < 0.0) *chi2a = 0.0;
        *sd = sqrt(1.0/swgt);
        tsi = sqrt(tsi);
        if(nprn >= 0) {
            printf("%s %3d : integral = %14.7g +/- %9.2g\n"," iteration no.",it,ti,tsi);
            printf("%s integral =%14.7g+/-%9.2g chi**2/IT n = %9.2g\n"," all iterations: ",*tgral,*sd,*chi2a);
            if(nprn) {
                for(j=0; j<ndim; ++j) {
                    printf(" DATA FOR axis %2d\n",j);
                    printf("%6s%13s%11s%13s%11s%13s\n","X","delta i","X","delta i","X","delta i");
                    for(i=nprn/2; i<nd; i+=nprn+2) {
                        printf("%8.5f%12.4g%12.5f%12.4g%12.5f%12.4g\n",xi[j][i],di[i][j],xi[j][i+1],di[i+1][j],xi[j][i+2],di[i+2][j]);
                    }
                }
            }
        }
        for(j=0; j<ndim; ++j) {
            xo = d[0][j];
            xn = d[1][j];
            assert(xo>0 or xn>0);
            d[0][j] = (xo + xn)/2.0;
            dt[j] = d[0][j];
            for(i=2; i<nd; ++i) {
                rc = xo + xn;
                xo = xn;
                xn = d[i][j];
                d[i-1][j] = (rc + xn)/3.0;
                dt[j] += d[i-1][j];
            }
            d[nd-1][j] = (xo + xn)/2.0;
            dt[j] += d[nd-1][j];
            assert(dt[j] > 0.0);
        }
        for(j=0; j<ndim; ++j) {
            rc = 0.0;
            for(i=0; i<nd; ++i) {
                if(d[i][j] < TINY) d[i][j] = TINY;
                r[i] = pow((1.0 - d[i][j]/dt[j])/(log(dt[i]) - log(d[i][j])),ALPH);
                assert(r[i] < INT_MAX and r[i] > -INT_MAX);
                rc += r[i];
            }
            rebin(rc/xnd,nd-1,r,xin,xi,j);
        }
    }
}

void rebin(float rc,
           int nd,
           vector<float> &r,
           vector<float> &xin,
           vector<vector<float>> &xi,
           int j) {
    int i,
        k = 0;
    float dr = 0.0,
          xn = 0.0,
          xo = 0.0;
    for(i=0; i<nd-1; ++i) {
        while(rc > dr)
            dr += r[(++k)-1];
        assert(k < NDMX);
        if(k > 1) xo = xi[j][k-2];
        xn = xi[j][k-1];
        dr -= rc;
        xin[i] = xn - (xn - xo)*dr/r[k-1];
        assert(xin[i] > -INT_MAX && xin[i] < INT_MAX);
    }
    for(i=0; i<nd-1; ++i) xi[j][i] = xin[i];
    xi[j][nd-1] = 1.0;
}













