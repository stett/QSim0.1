#pragma once
#include <gsl/gsl_complex.h>

namespace qsim {
    namespace distributions {
        gsl_complex gaussian(double x, double x0, double p, double alpha);
        gsl_complex gaussian_centered(double x, double* range, double p, double alpha);
    };
};
