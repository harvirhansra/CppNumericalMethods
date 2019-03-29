#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


double f(double x){
    return 2*pow(x, 2);
}

double df(double x){
    return 4*x;
}

double forward_difference(double x, double step){
    
    return (f(x+step) - f(x)) / step;
    
}

double backward_difference(double x, double step){
    
    return (f(x) - f(x-step)) / step;
    
}

double central_difference(double x, double step){
    
    return (f(x+step) - f(x-step)) / (2*step);
    
}

int main() {
    double x = 4;
    double step = 0.1;
    double df_approx = central_difference(x, step);
    double df_actual = df(x);

    cout << "Approximately: " << df_approx << endl;
    cout << "Actual: " << df_actual << endl;
    cout << "Difference: " << abs(df_actual - df_approx) << endl;
    
    return 0;
}

