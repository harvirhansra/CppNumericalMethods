#include <iostream>
#include <cmath>
#include "NumericalMethods/Differentiation.h"
#include "NumericalMethods/Integration.h"
#include "NumericalMethods/SingleNonLinear.h"
#include "NumericalMethods/PolynomialApproximation.h"

using namespace std;

double f(double x){

  // return pow(x, x);
  return pow(x, 2);
  // return (pow(x,3)/3.0) - (2*pow(x,2)) + x - 4.0;
}

double df(double x){
//    return pow(x, x)*(log(x)+1);
    return 2*x;
}

double ff(double x){
  return (1.0/3.0)*pow(x, 3);
}

void print_stats(double &x, double &step, double &approx, double &actual){
    cout << "Xi: " << x << endl;
    if(step != 0) {
      cout << "Step: " << step << endl;
    }
    cout << "Approximation: " << approx << endl;
    cout << "Actual: " << actual << endl;
    cout << "Difference: " << abs(actual - approx) << endl;
}

int main(int argc, char* argv[]) {
    double (*func)(double) = f;
    
    // Differentiation
    Differentiation d = Differentiation(*func);
    double x = 12.5;
    double step = 0.01;
    double df_approx_1 = d.central_difference(x, step);
    double df_actual = df(x);
    cout << "Using " << d.method << endl;
    print_stats(x, step, df_approx_1, df_actual);
    cout << '\n';

    double df_approx_2 = d.richardson_extrapolation(x, step);
    cout << "Using " << d.method << endl;
    print_stats(x, step, df_approx_2, df_actual);
    cout << '\n';
    
    // // Integration
    Integration i(*func);
    double a = 1;
    double b = 3;
    double n = 100;
    double ff_approx = i.simpsons(a, b, n);
    cout << "Using " << i.method << endl;
    double ff_actual = abs(ff(b) - ff(a)) ;
    print_stats(a, n, ff_approx, ff_actual);
    cout << '\n';

    // Solutions to non-linear equations
    SingleNonLinear snl(*func);
    double x0 = -2;
    double x1 = 0;
    // double result = snl.newton(x0);
    double result = snl.secant(x0, x1);
    // double result = snl.bisection(x0, x1);
    cout << "Using " << snl.method << endl;
    cout << "Solution: x = " << result << endl;

    // Polynomial Approximation
    PolynomialApproximation pa(*func);
    // vector<double> lin_x = {1, 2, 3, 4, 5};
    // vector<double> lin_y = {1, 2, 3, 4, 5};
    double pa_step = 0;
    double pa_x = 8.235474;
    double actual = log(pa_x);
    vector<double> xs = {2, 3, 4, 5, 6, 7, 8, 9};
    vector<double> ys = {0.6931471805599453, 1.0986122886681098, 
                        1.3862943611198906, 1.6094379124341003, 
                        1.791759469228055, 1.9459101490553132, 
                        2.0794415416798357, 2.1972245773362196};
    double pa_result = pa.lagrange(pa_x, xs, ys);
    cout << "Using " << pa.method << endl;
    print_stats(pa_x, pa_step, pa_result, actual);
    
    return 0;
}

