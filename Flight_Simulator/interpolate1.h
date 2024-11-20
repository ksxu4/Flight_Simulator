#ifndef INTERPOLATE1_H
#define INTERPOLATE1_H

#include <vector>

double interpolate1(const std::vector<double>& x, const std::vector<double>& y, double x_interp);
double interpolate1(const double* x, const double* y, size_t size, double x_interp);
double interpolate1(const double* x, const double* y, double x_interp);

#endif