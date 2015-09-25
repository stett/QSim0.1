#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
//#include <SFGUI/SFGUI.hpp>
#include <gsl/gsl_complex.h>
#include <iostream>
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

    /*
    // Initialize SFGUI
    auto sfg_button = sfg::Button::Create("Hello");
    auto box = sfg::Box::Create( sfg::Box::Orientation::VERTICAL, 5.0f );
    box->Pack( sfg_button, false );

    auto sfg_window = sfg::Window::Create();
    sfg_window->SetTitle("Controls");
    sfg_window->Add(box);

    sfg::Desktop sfg_desktop;
    sfg_desktop.Add(sfg_window);
    */

    // TEMP: Output the normalization
    std::cout << "NORMALIZATION: " << qsim1d.get_normalization() << "\n";

    // Rest OpenGL?? Necessary??
    window->resetGLStates();

    // Create the vertex array for the plot
    sf::VertexArray psi_verts(sf::TrianglesStrip, 2*qsim1d.get_N());
    sf::VertexArray V_verts(sf::TrianglesStrip, 2*qsim1d.get_N());

    // Set up the vertex array for the potential field
    set_verts(V_verts, qsim1d.get_V(), qsim1d.get_N(), qsim1d.get_range());

    // Begin the main loop
    sf::Clock clock;
    sf::Event event;
    while (window->isOpen()) {

        // Poll for events
        while (window->pollEvent(event)) {

            // Pass events on to the SFGUI desktop
            //sfg_desktop.HandleEvent(event);

            // Handle closing
            if (event.type == sf::Event::Closed)
                window->close();
        }

        auto dt = clock.restart().asSeconds();

        // Update SFGUI
        //sfg_desktop.Update(dt);

        // Update simulation
        qsim1d.evolve(dt);

        // Update the graph vertices
        set_verts(psi_verts, qsim1d.get_psi(), qsim1d.get_N(), qsim1d.get_range());

        // Render stuff
        window->clear(sf::Color(0, 0, 0));
        window->draw(psi_verts);
        //sfgui.Display(*window);
        window->display();
    }

    return 0;
}

void qsim_sandbox_1d::App::step() {}

void qsim_sandbox_1d::App::set_verts(sf::VertexArray& verts, const gsl_complex* data, int N, const double* range) {
    auto size = window->getSize();
    double x;
    double abs_val;
    gsl_complex val;
    int i_vert = 0;
    for (int i = 0; i < N; i ++) {
        val = qsim1d.get_psi()[i];
        abs_val = gsl_complex_abs2(val);

        x = i * ((float)size.x / (float)(N - 1));

        verts[i_vert].position = sf::Vector2f(x, (float)size.y - (abs_val - range[0]) * ((float)size.y) / (range[1] - range[0]));
        verts[i_vert].color = color_complex(val);
        i_vert ++;

        verts[i_vert].position = sf::Vector2f(x, (float)size.y);
        verts[i_vert].color = sf::Color(0, 0, 0);
        i_vert ++;
    }
}
