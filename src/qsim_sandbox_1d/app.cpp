#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
#include <SFGUI/SFGUI.hpp>
#include <memory>
#include "app.h"


qsim_sandbox_1d::App::App() {

    // Initialize the render window
    window = std::shared_ptr<sf::RenderWindow>(new sf::RenderWindow(
                sf::VideoMode(800, 600),
                "QSim Sandbox 1D",
                sf::Style::Close | sf::Style::Titlebar));

}

qsim_sandbox_1d::App::~App() {}

int qsim_sandbox_1d::App::run() {

    // Initialize SFGUI
    auto sfg_button = sfg::Button::Create("Hello");
    auto box = sfg::Box::Create( sfg::Box::Orientation::VERTICAL, 5.0f );
    box->Pack( sfg_button, false );

    auto sfg_window = sfg::Window::Create();
    sfg_window->SetTitle("SFGUI Window");
    sfg_window->Add(box);

    sfg::Desktop sfg_desktop;
    sfg_desktop.Add(sfg_window);

    // Rest OpenGL?? Necessary??
    window->resetGLStates();

    // Create the vertex array for the plot
    auto N = qsim1d.get_N();
    auto data = qsim1d.get_data();
    auto range = qsim1d.get_range();
    auto size = window->getSize();
    sf::VertexArray vertex_array(sf::LinesStrip, N);
    for (int i = 0; i < qsim1d.get_N(); i ++)
        vertex_array[i].position = sf::Vector2f(
            i * ((float)size.x / (float)(N - 1)),
            (float)size.y - (data[i] - range[0]) * ((float)size.y) / (range[1] - range[0]));

    // Begin the main loop
    sf::Clock clock;
    sf::Event event;
    while (window->isOpen()) {

        // Poll for events
        while (window->pollEvent(event)) {

            // Pass events on to the SFGUI desktop
            sfg_desktop.HandleEvent(event);

            // Handle closing
            if (event.type == sf::Event::Closed)
                window->close();
        }

        // Update SFGUI
        sfg_desktop.Update(clock.restart().asSeconds());

        // Render stuff
        window->clear(sf::Color(100, 100, 100));
        window->draw(vertex_array);
        sfgui.Display(*window);
        window->display();
    }

    return 0;
}

void qsim_sandbox_1d::App::step() {}
