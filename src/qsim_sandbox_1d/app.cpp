#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
#include <SFGUI/SFGUI.hpp>
#include <gsl/gsl_complex.h>
#include <memory>
#include "app.h"
#include "colors.h"


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
    sfg_window->SetTitle("Controls");
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
    float x;
    gsl_complex val;
    double abs_val;
    sf::VertexArray vertex_array(sf::TrianglesStrip, 2*N);
    int i_vert = 0;
    for (int i = 0; i < qsim1d.get_N(); i ++) {
        val = data[i];
        abs_val = gsl_complex_abs(val);

        x = i * ((float)size.x / (float)(N - 1));

        vertex_array[i_vert].position = sf::Vector2f(
            x, (float)size.y - (abs_val - range[0]) * ((float)size.y) / (range[1] - range[0]));
        vertex_array[i_vert].color = color_complex(val);
        i_vert ++;

        vertex_array[i_vert].position = sf::Vector2f(x, (float)size.y);
        vertex_array[i_vert].color = sf::Color(0, 0, 0);
        i_vert ++;
    }

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
        window->clear(sf::Color(0, 0, 0));
        window->draw(vertex_array);
        sfgui.Display(*window);
        window->display();
    }

    return 0;
}

void qsim_sandbox_1d::App::step() {}
