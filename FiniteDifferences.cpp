#include <string>
#include <cmath>
#include "FiniteDifferences.h"

using namespace std;

FiniteDifferences::FiniteDifferences(double (*func)(double)) {
   f = func;
}

double FiniteDifferences::forward_difference(double x, double step){
    this->method = "forward difference";
    
    return ((*f)(x+step) - (*f)(x)) / step;
    
}

double FiniteDifferences::backward_difference(double x, double step){
    this->method = "backward difference";
    
    return ((*f)(x) - (*f)(x-step)) / step;
    
}

double FiniteDifferences::central_difference(double x, double step){
    this->method = "central difference";
    
    return ((*f)(x+step) - (*f)(x-step)) / (2*step);
    
}

