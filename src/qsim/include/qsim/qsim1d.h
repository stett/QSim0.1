#include <gsl/gsl_complex.h>

namespace qsim {

    class QSim1D {
    public:
        QSim1D(int N = 128);
        ~QSim1D();

    public:
        int get_N() { return N; }
        const float* get_range() { return range; }
        const gsl_complex* get_data() { return data; }

    private:
        float range[2];
        int N;
        gsl_complex* data;
    };
};