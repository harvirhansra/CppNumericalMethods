#include <vector>

using namespace std;

PolynomialApproximation::PolynomialApproximation(double (*func)(double)){
    f= func;
}

double PolynomialApproximation::p(double x, int i, vector<double> xs){
  double result = 1;
  xi = xs[i];
  xs.erase(i);
  for(double xj : xs){
    result = result * (x-xj)/(xi-xj);
  }

  return result;
  
}

double PolynomialApproximation::lagrange(double x, vector<double> xs, vector<double> ys){
  double result = 0;
  
  for(int i = 0; i < xs.size(); i++){
    result = result + ys[i]*p(x, i, xs);
  }

  return result;
  
}

// TODO: Add Chebyshev points option



