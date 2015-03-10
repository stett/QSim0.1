#include <SFML/Graphics.hpp>
#include <gsl/gsl_complex.h>
#include <gsl/gsl_complex_math.h>
#include <cmath>

sf::Color color_complex(const gsl_complex& z) {

    // Define color base vectors (splitting unit circle into 3rds)
    double rx = 0;
    double ry = 1;
    double gx = cos(M_PI * 7.0 / 6.0);
    double gy = sin(M_PI * 7.0 / 6.0);
    double bx = cos(M_PI * 11.0 / 6.0);
    double by = sin(M_PI * 11.0 / 6.0);

    // Get position on unit circle from complex argument
    double arg = gsl_complex_arg(z);
    double vx = cos(arg);
    double vy = sin(arg);

    // Project position onto color base vectors
    double r = std::max(vx * rx + vy * ry, 0.0);
    double g = std::max(vx * gx + vy * gy, 0.0);
    double b = std::max(vx * bx + vy * by, 0.0);

    // 
    return sf::Color(
        (unsigned int)(255.0 * r),
        (unsigned int)(255.0 * g),
        (unsigned int)(255.0 * b),
        255);
}
