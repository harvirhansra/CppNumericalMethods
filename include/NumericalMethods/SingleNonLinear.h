#ifndef SINGLENONLINEAR_H
#define SINGLENONLINEAR_H

#include <string>

class SingleNonLinear {
public:
  SingleNonLinear(double (*func)(double));
  double newton(double &x0);
  double secant(double &x0, double &x1);
  double bisection(double &x0, double &x1);
  std::string method;
private:
  double (*f)(double);

};

#endif /* SINGLENONLINEAR_H */

