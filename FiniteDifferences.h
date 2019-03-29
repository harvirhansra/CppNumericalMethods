#include <string>
#include <cmath>

#ifndef FINITEDIFFERENCES_H
#define FINITEDIFFERENCES_H

class FiniteDifferences {
public:
    FiniteDifferences(double (*func)(double));
    double forward_difference(double x, double step);
    double backward_difference(double x, double step);
    double central_difference(double x, double step);
    std::string method;
private:
    double (*f)(double);
};

#endif /* FINITEDIFFERENCES_H */

