#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>


int main(int argc, char** argv) {
    auto window = 
        new sf::RenderWindow(
            sf::VideoMode(800, 600),
            "QSim Sandbox 1D",
            sf::Style::Close | sf::Style::Titlebar);

    while (true) {
        window->clear(sf::Color(100, 100, 100));
    }

    return 0;
}
