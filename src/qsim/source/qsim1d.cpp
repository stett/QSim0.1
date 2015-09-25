#include <cmath>
#include <gsl/gsl_complex.h>
#include <gsl/gsl_complex_math.h>
#include "qsim/qsim1d.h"
#include "qsim/distributions.h"

using qsim::QSim1D;
using namespace qsim::distributions;


QSim1D::QSim1D(int N) : N(N) {
    psi = new gsl_complex[N];
    V = new gsl_complex[N];
    range[0] = -10;
    range[1] = 10;

    // Apply default configuration
    for (int i = 0; i < N; i ++) {
        double x = range[0] + (range[1] - range[0]) * (double)i / (double)(N - 1);
        psi[i] = qsim::distributions::gaussian_centered(x, range, 10.0, 0.1);
        V[i] = gsl_complex_rect(0.0, 0.0);
    }
}

QSim1D::~QSim1D() {
    delete[] psi;
    delete[] V;
}

double QSim1D::get_normalization() {
    double sum = 0.0;
    for (int i = 0; i < N; i ++)
        sum += gsl_complex_abs2(psi[i]) * (range[1] - range[0]) / (float)N;
    return sum;
}

void QSim1D::evolve(double dt) {
    cheb_u(dt);
}


void QSim1D::cheb_u(double dt) {
    for (int i = 0; i < N; i ++) {
    }
}
