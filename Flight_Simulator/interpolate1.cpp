#include "interpolate1.h"
#include <stdexcept>

double interpolate1(const std::vector<double>& x, const std::vector<double>& y, double x_interp) {
    if (x.size() != y.size()) {
        throw std::invalid_argument("interpolate1: x and y must have the same size");
    }
    if (x.size() == 0) {
        throw std::invalid_argument("interpolate1: x and y must have at least one element");
    }
    if (x.size() == 1) {
        return y[0];
    }
    if (x_interp < x[0]) {
        return y[0];
    }
    if (x_interp > x[x.size() - 1]) {
        return y[x.size() - 1];
    }
    for (size_t i = 0; i < x.size() - 1; ++i) {
        if (x_interp >= x[i] && x_interp <= x[i + 1]) {
            return y[i] + (y[i + 1] - y[i]) / (x[i + 1] - x[i]) * (x_interp - x[i]);
        }
    }
    throw std::logic_error("interpolate1: should never reach this point");
}

double interpolate1(const double* x, const double* y, size_t size, double x_interp) {
    if (size == 0) {
        throw std::invalid_argument("interpolate1: size must be at least 1");
    }
    if (size == 1) {
        return y[0];
    }
    if (x_interp < x[0]) {
        return y[0];
    }
    if (x_interp > x[size - 1]) {
        return y[size - 1];
    }
    for (size_t i = 0; i < size - 1; ++i) {
        if (x_interp >= x[i] && x_interp <= x[i + 1]) {
            return y[i] + (y[i + 1] - y[i]) / (x[i + 1] - x[i]) * (x_interp - x[i]);
        }
    }
    throw std::logic_error("interpolate1: should never reach this point");
}

double interpolate1(const double* x, const double* y, double x_interp) {
    auto is_nan = [](double value) { return value != value; }; // Simple check for NaN

    size_t size = 0;
    while (!is_nan(x[size])) {
        ++size;
    }

    if (size == 0) {
        throw std::invalid_argument("interpolate1: size must be at least 1");
    }
    if (size == 1) {
        return y[0];
    }
    if (x_interp < x[0]) {
        return y[0];
    }
    if (x_interp > x[size - 1]) {
        return y[size - 1];
    }
    for (size_t i = 0; i < size - 1; ++i) {
        if (x_interp >= x[i] && x_interp <= x[i + 1]) {
            return y[i] + (y[i + 1] - y[i]) / (x[i + 1] - x[i]) * (x_interp - x[i]);
        }
    }
    throw std::logic_error("interpolate1: should never reach this point");
}