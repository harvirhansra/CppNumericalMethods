#ifndef INTEGRATION_H
#define INTEGRATION_H

#include <string>

class Integration {
public:
  Integration(double (*func)(double));
  double trapezoidal(double &a, double &b, double &n);
  double middlepoint(double &a, double &b, double &n);
  double simpsons(double &a, double &b, double &n);
  double gaussian(double &x, double &a);
  double monte_carlo(double &x, double &h);
  std::string method;
private:
  double (*f)(double);

};

#endif /* INTEGRATION_H */

