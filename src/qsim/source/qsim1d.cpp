#include "qsim/qsim1d.h"

using qsim::QSim1D;


QSim1D::QSim1D(unsigned int N) : N(N) {
    data = new float[N];
    range[0] = 0;
    range[1] = (float)N;

    for (unsigned int i = 0; i < N; i ++)
        data[i] = i;
}

QSim1D::~QSim1D() {
    delete[] data;
}
