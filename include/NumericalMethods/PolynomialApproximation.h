#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <string>
#include <vector>

class PolynomialApproximation {
public:
  PolynomialApproximation(double (*func)(double));
  double lagrange(double &x, std::vector<double> xs, std::vector<double> ys);
  std::string method;
private:
  double pi(double &x, int &i, std::vector<double> xs);
  double (*f)(double);

};

#endif /* POLYNOMIAL_H */

