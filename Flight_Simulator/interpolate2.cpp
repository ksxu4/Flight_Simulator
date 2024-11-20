#include"interpolate2.h"
#include <stdexcept>

double interpolate2D(const double* x, const double* y, const double** z, size_t x_size, size_t y_size, double x_interp, double y_interp) {
    if (x_size == 0 || y_size == 0) {
        throw std::invalid_argument("interpolate2D: size must be at least 1");
    }
    if (x_size == 1 || y_size == 1) {
        throw std::invalid_argument("interpolate2D: requires at least two points in each dimension");
    }

    // Finding the bounding box for interpolation
    if (x_interp < x[0]) x_interp = x[0];
    if (x_interp > x[x_size - 1]) x_interp = x[x_size - 1];
    if (y_interp < y[0]) y_interp = y[0];
    if (y_interp > y[y_size - 1]) y_interp = y[y_size - 1];

    size_t i, j;
    for (i = 0; i < x_size - 1; ++i) {
        if (x_interp >= x[i] && x_interp <= x[i + 1]) {
            break;
        }
    }
    for (j = 0; j < y_size - 1; ++j) {
        if (y_interp >= y[j] && y_interp <= y[j + 1]) {
            break;
        }
    }

    // Bilinear interpolation
    double x1 = x[i], x2 = x[i + 1];
    double y1 = y[j], y2 = y[j + 1];
    double z11 = z[i][j], z12 = z[i][j + 1];
    double z21 = z[i + 1][j], z22 = z[i + 1][j + 1];

    double z_interp = (z11 * (x2 - x_interp) * (y2 - y_interp) +
        z21 * (x_interp - x1) * (y2 - y_interp) +
        z12 * (x2 - x_interp) * (y_interp - y1) +
        z22 * (x_interp - x1) * (y_interp - y1)) /
        ((x2 - x1) * (y2 - y1));

    return z_interp;
}
