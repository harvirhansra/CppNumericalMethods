#include <string>
#include <cmath>
#include "NumericalMethods/Differentiation.h"

using namespace std;

Differentiation::Differentiation(double (*func)(double)) {
   f = func;
}

double Differentiation::forward_difference(double &x, double &h){
    this->method = "forward difference";
    
    return ((*f)(x+h) - (*f)(x)) / h;
    
}

double Differentiation::backward_difference(double &x, double &h){
    this->method = "backward difference";
    
    return ((*f)(x) - (*f)(x-h)) / h;
    
}

double Differentiation::central_difference(double &x, double &h){
    this->method = "central difference";
    
    return ((*f)(x+h) - (*f)(x-h)) / (2*h);
    
}

double Differentiation::five_point(double &x, double &h){
    this->method = "five point";
    double first, second, third, fourth;
    first = (*f)(x+(2*h));
    second = (*f)(x+h);
    third = (*f)(x-h);
    fourth = (*f)(x-(2*h));
    
    return (-first + 8*second - 8*third + fourth)/(12*h);
}

double Differentiation::richardson_extrapolation(double &x, double &h){
    this->method = "richardson extrapolation";
    double first, second, third;
    first = ((*f)(x+(h/2)));
    second = ((*f)(x+h));
    third = ((*f)(x));
    
    return (4*first - second - 3*third) / h;
    
}

