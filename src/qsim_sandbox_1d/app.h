#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
//#include <SFGUI/SFGUI.hpp>
#include <memory>
#include "qsim/qsim1d.h"


namespace qsim_sandbox_1d {
    class App {
    public:
        App();
        ~App();

    public:
        int run();
        void step();

    private:
        qsim::QSim1D qsim1d;
        std::shared_ptr<sf::RenderWindow> window;
        //sfg::SFGUI sfgui;

    private:
        void set_verts(sf::VertexArray& verts, const gsl_complex* data, int N, const double* range);
    };
}
