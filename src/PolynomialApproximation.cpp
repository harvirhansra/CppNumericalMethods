#include <vector>
#include "NumericalMethods/PolynomialApproximation.h"

using namespace std;

PolynomialApproximation::PolynomialApproximation(double (*func)(double)){
    f= func;
}

double PolynomialApproximation::pi(double &x, int &i, vector<double> xs){
  double result = 1;
  double xi = xs[i];
  
  xs[i] = 0;
  for(double xj : xs){
    result = result * (x-xj)/(xi-xj);
  }

  return result;
}

double PolynomialApproximation::lagrange(double &x, vector<double> xs, vector<double> ys){
  this->method = "Lagrange Interpolation";
  double result = 0;
  
  for(int i = 0; i < ys.size(); i++){
    result = result + ys[i]*pi(x, i, xs);
  }

  return result;
}