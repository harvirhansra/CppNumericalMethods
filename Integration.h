#ifndef INTEGRATION_H
#define INTEGRATION_H

#include <string>

class Integration {
public:
    Integration(double (*func)(double));
  double trapezoidal(double a, double b, double n);
    double middle_point(double x, double h);
    double simpsons(double x, double h);
    double gaussian(double x, double A);
    double monte_carlo(double x, double h);
    std::string method;
private:
    double (*f)(double);

};

#endif /* INTEGRATION_H */

