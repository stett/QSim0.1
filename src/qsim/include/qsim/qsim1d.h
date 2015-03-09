#include <gsl/gsl_complex.h>

namespace qsim {

    class QSim1D {
    public:
        QSim1D(unsigned int N = 100);
        ~QSim1D();

    public:
        const int get_N() { return N; }
        const float* get_range() { return range; }
        const float* get_data() { return data; }

    private:
        float range[2];
        int N;
        float* data;
    };
};