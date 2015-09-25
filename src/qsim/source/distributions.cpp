#include <cmath>
#include <gsl/gsl_math.h>
#include <gsl/gsl_complex.h>
#include <gsl/gsl_complex_math.h>
#include "qsim/distributions.h"

gsl_complex qsim::distributions::gaussian(double x, double x0, double p, double alpha) {
    double constants = sqrt(sqrt(alpha / M_PI));
    gsl_complex momentum = gsl_complex_exp(gsl_complex_rect(0.0, p * x));
    gsl_complex shape = gsl_complex_exp(gsl_complex_rect(-(x - x0) * (x - x0) * alpha / 2.0, 0.0));
    //gsl_complex shape = gsl_complex_exp(gsl_complex_rect(-(x - x0) * (x - x0) / (4.0 * alpha * alpha), 0.0));
    gsl_complex final = gsl_complex_mul(gsl_complex_mul_real(momentum, constants), shape);
    return final;
}

gsl_complex qsim::distributions::gaussian_centered(double x, double* range, double p, double alpha) {
    alpha = M_PI;
    return gaussian(x, (range[0] + range[1]) * .5, p, alpha);
}

/*
void qsim::distributions::apply_distribution(gsl_complex* data, int N, double* range, gsl_complex (*func)(double, double, double)) {
    for (int i = 0; i < N; i ++) {
        double x = range[0] + (range[1] - range[0]) * (double)i / (double)(N - 1);
        data[i] = (x, range[0], range[1]);
    }
}

gsl_complex qsim::distributions::flat(double x, double x_min, double x_max) {
    return gsl_complex_rect(0, 0);
}

gsl_complex qsim::distributions::gaussian(double x, double x_min, double x_max) {
    double x0 = (x_min + x_max) * 0.5;
    double aa = .1;
    double      a = 1 / sqrt(sqrt(2 * M_PI) * aa);
    gsl_complex b = gsl_complex_exp(gsl_complex_rect(0.0, 0.0));
    gsl_complex c = gsl_complex_exp(gsl_complex_rect(-(x - x0) * (x - x0) / (4.0 * aa * aa), 0.0));
    gsl_complex d = gsl_complex_mul_real(b, a);
                d = gsl_complex_mul(d, c);
    return d;
}
*/
