#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


double f(double x){
    return pow(x, x);
}

double df(double x){
    return pow(x, x)*(log(x)+1);
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

int main(int argc, char* argv[]) {
    double x = atof(argv[1]);
    double step = atof(argv[2]);
    double df_approx = central_difference(x, step);
    double df_actual = df(x);
    cout << "xi: " << x << endl;
    cout << "Step: " << step << endl;
    cout << "Approximately: " << df_approx << endl;
    cout << "Actual: " << df_actual << endl;
    cout << "Difference: " << abs(df_actual - df_approx) << endl;
    
    return 0;
}

