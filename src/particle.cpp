#include "particle.hpp"

Particle::Particle(float x_in, float y_in, float mass_in, float vel_x_in, float vel_y_in) {
    pos_x = x_in;
    pos_y = y_in;
    mass = mass_in;
    vel_x = vel_x_in;
    vel_y = vel_y_in;
    force_x = 0;
    force_y = 0;
}

void Particle::_print_position() {
    std::cout << "x : [" << pos_x << "] y : [" << pos_y << "]\n";
}