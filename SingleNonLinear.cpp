#include "SingleNonLinear.h"
#include "Differentiation.h"
#include <vector>
#include <cmath>

using namespace std;


SingleNonLinear::SingleNonLinear(double (*func)(double)){
    f = func;
}


double SingleNonLinear::newton(double x0){
    this->method = "Newton";
    vector<double> xn;
    Differentiation d(f);
    int n = 0;

    xn.push_back(x0);
    while(abs((*f)(xn[n])) > 1/pow(10, 10)){
        n += 1;
        xn.push_back(xn[n-1] - ((*f)(xn[n-1]) / d.richardson_extrapolation(xn[n-1], 0.00001)));
    }

    return xn[n];
}

