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

double FiniteDifferences::five_point(double x, double step){
    this->method = "five point";
    double first, second, third, fourth;
    first = (*f)(x+(2*step));
    second = (*f)(x+step);
    third = (*f)(x-step);
    fourth = (*f)(x-(2*step));
    
    return (-first + 8*second - 8*third + fourth)/(12*step);
}

