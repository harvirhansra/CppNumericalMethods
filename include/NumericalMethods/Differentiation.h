#ifndef FINITEDIFFERENCES_H
#define FINITEDIFFERENCES_H

#include <string>
#include <cmath>

class Differentiation {
public:
    Differentiation(double (*func)(double));
    double forward_difference(double &x, double &h);
    double backward_difference(double &x, double &h);
    double central_difference(double &x, double &h);
    double five_point(double &x, double &h);
    double richardson_extrapolation(double &x, double &h);
    std::string method;
private:
    double (*f)(double);
};

#endif /* FINITEDIFFERENCES_H */

