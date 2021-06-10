#include <cmath>
#include <vector>
#include <iostream>
#include "NumericalMethods/Differentiation.h"
#include "NumericalMethods/SingleNonLinear.h"

using namespace std;


SingleNonLinear::SingleNonLinear(double (*func)(double)){
    f = func;
}


double SingleNonLinear::newton(double x0){
    cout << "Using Newton's Method" << endl;

    int n = 0;
    double step = 0.001;
    vector<double> xn;
    Differentiation d(f);

    xn.push_back(x0);
    while(abs((*f)(xn[n])) > 1/pow(10, 10)){
        n += 1;
        xn.push_back(xn[n-1] - ((*f)(xn[n-1]) / d.richardson_extrapolation(xn[n-1], step)));
    }

    return xn[n];
}

double SingleNonLinear::secant(double x0, double x1){
    cout << "Using Secant Method" << endl;
    
    int n = 1;
    double first, second, third;
    vector<double> xn;

    xn.push_back(x0);
    xn.push_back(x1);
    while(abs((*f)(xn[n])) > 1/pow(10, 10)){
        n += 1;
    first = xn[n-1] * (*f)(xn[n-2]);
    second = xn[n-2] * (*f)(xn[n-1]);
    third = ((*f)(xn[n-2])) - ((*f)(xn[n-1])); 
    xn.push_back((first - second)/third);
      }
      
    return xn[n];
}

double SingleNonLinear::bisection(double x0, double x1){
    cout << "Using Bisection Method" << endl;
    
    double a, b, c, d;
    a = x0;
    b = x1;
    c = (x0+x1)/2;

    while(abs((*f)(c)) > 1/pow(10, 10)){
      c = (a+b)/2;
      d = (*f)(a) * (*f)(c);
      if (d < 0){
        b = c;
      }
      else{
        a = c;
      }
    }
    return c;
}
