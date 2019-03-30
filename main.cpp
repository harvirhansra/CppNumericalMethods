#include <iostream>
#include <cmath>
#include "FiniteDifferences.h"

using namespace std;

double f(double x){
    return std::pow(x, x);
}

double df(double x){
    return pow(x, x)*(log(x)+1);
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
    FiniteDifferences fd(func);
    double x = atof(argv[1]);
    double step = atof(argv[2]);
    double df_approx = fd.richardson_extrapolation(x, step);
    double df_actual = df(x);
    cout << "Using " << fd.method << endl;
    print_stats(x, step, df_approx, df_actual);
    
    return 0;
}

