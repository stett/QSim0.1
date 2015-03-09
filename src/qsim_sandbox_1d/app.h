#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
#include <SFGUI/SFGUI.hpp>
#include <memory>


namespace qsim_sandbox_1d {
    class App {
    public:
        App();
        ~App();

    public:
        int run();
        void step();

    public:
        std::shared_ptr<sf::RenderWindow> window;
        //std::shared_ptr<sfg::SFGUI> sfgui;
        //std::shared_ptr<sfg::Desktop> sfg_desktop;
        //std::shared_ptr<sfg::Window> sfg_window;

    private:
        sfg::SFGUI sfgui;
    };
}
