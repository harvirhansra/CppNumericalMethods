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
  double first, h;
  double sum = 0;
  vector<double> second;
  this->method = "trapezoidal method";
  cout << "Integrating between " << a << " and " << b << endl;
    
  first = (b-a)/(2*n);
  h = (b-a)/n;
  
  second.push_back((*f)(a));
  for(double x = a; x < b; x+=h){
    second.push_back(2*((*f)(x)));
  }
  second.push_back((*f)(b));

  for(auto& i : second){
    sum += i;
  }
       
  return first*sum;
}

