#include <iostream>
#include <cmath>
#include "Differentiation.h"
#include "Integration.h"

using namespace std;

double f(double x){
//    return pow(x, x);
    return pow(x, 2);
}

double df(double x){
//    return pow(x, x)*(log(x)+1);
    return 2*x;
}

double ff(double x){
  return (1.0/3.0)*pow(x, 3);
}

void print_stats(double x, double step, double approx, double actual){
    cout << "Xi: " << x << endl;
    cout << "Step: " << step << endl;
    cout << "Approximately: " << approx << endl;
    cout << "Actual: " << actual << endl;
    cout << "Difference: " << abs(actual - approx) << endl;
}

int main(int argc, char* argv[]) {
    double (*func)(double) = f;
    Differentiation d(func);
    double a = 1;
    double b = 2;
    double n = 100000;
    //double x = atof(argv[1]);
    //double step = atof(argv[2]);
//    double df_approx = d.richardson_extrapolation(x, step);
//    double df_actual = df(x);
//    cout << "Using " << d.method << endl;
//    print_stats(x, step, df_approx, df_actual);
    Integration i (f);
    cout << "Using " << i.method << endl;
    double ff_approx = i.trapezoidal(a, b, n);
    double ff_actual = abs(ff(b) - ff(a)) ;
    print_stats(a, n, ff_approx, ff_actual);
    return 0;
}

