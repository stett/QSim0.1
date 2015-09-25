#include <gsl/gsl_complex.h>

namespace qsim {

    class QSim1D {
    public:
        QSim1D(int N = 256);
        ~QSim1D();

    public:
        int get_N() { return N; }
        const double* get_range() { return range; }
        const gsl_complex* get_psi() { return psi; }
        const gsl_complex* get_V() { return V; }
        double get_normalization();

        void evolve(double dt);

        // Chebychev functions
        void cheb_u(double dt);

    private:
        double range[2];
        int N;
        double DeltaE;
        gsl_complex* psi;
        gsl_complex* V;
    };
};
