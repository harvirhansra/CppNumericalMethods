#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <vector>

class PolynomialApproximation {
public:
    PolynomialApproximation(double (*func)(double));
    double lagrange(double x, std::vector<double> xs, std::vector<double> ys);
private:
    double (*f)(double);
};

#endif /* POLYNOMIAL_H */

