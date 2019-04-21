#ifndef SINGLENONLINEAR_H
#define SINGLENONLINEAR_H

#include <string>

class SingleNonLinear {
public:
  SingleNonLinear(double (*func)(double));
  double newton(double x0);
  std::string method;
private:
  double (*f)(double);

};

#endif /* SINGLENONLINEAR_H */

