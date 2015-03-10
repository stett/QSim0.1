#include <gsl/gsl_complex.h>
#include <cmath>
#include "qsim/qsim1d.h"

using qsim::QSim1D;


QSim1D::QSim1D(int N) : N(N) {
    data = new gsl_complex[N];
    range[0] = 0;
    range[1] = 1;

    for (int i = 0; i < N; i ++) {
        float theta = (float)M_PI * ((float)i / ((float)N-1.f));
        GSL_SET_COMPLEX(&data[i], cos(theta)*.5, sin(theta)*.5);
    }
}

QSim1D::~QSim1D() {
    delete[] data;
}
