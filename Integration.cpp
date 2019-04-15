#include "Integration.h"
#include "Differentiation.h"

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

Integration::Integration(double (*func)(double)) {
    f = func;
}

double Integration::trapezoidal(double a, double b, double n){
  double first;
  double h = (b-a)/n;
  double sum = 0;
  vector<double> second;
  this->method = "trapezoidal method";

  cout << "Integrating between " << a << " and " << b << endl;
    
  first = (b-a)/(2*n);
  
  second.push_back((*f)(a));
  for(double x = a; x <= b; x+=h){
    second.push_back(2*((*f)(x)));
  }
  second.push_back((*f)(b));

  for(auto& i : second){
    sum += i;
  }
       
  return first*sum;
}

double Integration::middlepoint(double a, double b, double n){
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
  

