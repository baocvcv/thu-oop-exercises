#ifndef FUNC_H_
#define FUNC_H_

#include <vector>

double power(double x, int n);
double polynomial_fast(std::vector<double>& coef, double x);
double polynomial_slow(std::vector<double>& coef, double x);

#endif // FUNC_H_
