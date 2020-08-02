#include "NumericalMethods/Integration.h"
#include "NumericalMethods/Differentiation.h"

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

Integration::Integration(double (*func)(double)) {
    f = func;
}

double Integration::trapezoidal(double &a, double &b, double &n){
  double first;
  double h = (b-a)/n;
  double sum;
  vector<double> points;
  this->method = "trapezoidal method";

  first = (b-a)/(2*n);
  
  points.push_back((*f)(a));
  for(double x = a; x <= b; x+=h){
    points.push_back(2*((*f)(x)));
  }
  points.push_back((*f)(b));

  for(auto& i : points){
    sum += i;
  }
       
  return first*sum;
}

double Integration::middlepoint(double &a, double &b, double &n){
  double h = (b-a)/n;
  vector<double> points;
  double sum;
  this->method = "middlepoint rule";
  
  for(double x = a; x < b; x+=h){
    double y = (*f)(x+(h/2));
    points.push_back(h*y);
  }
  
  for(auto& i : points){
    sum += i;
  }

  return sum;
}


double Integration::simpsons(double &a, double &b, double &n){
  double h = (b-a)/n;
  vector<double> points;
  double sum, first;
  this->method = "simpsons rule";

  first = h/3.0;
  points.push_back((*f)(a));
  for(double x = a+h; x < b; x+=(2*h)){
    double y = (*f)(x);
    points.push_back(4*y);
  }
  for(double x = a+(2*h); x < b; x+=(2*h)){
    double y = (*f)(x);
    points.push_back(2*y);
  }
  points.push_back((*f)(b));

  for(auto& i : points){
    sum += i;
  }

  return first*sum;  
}
