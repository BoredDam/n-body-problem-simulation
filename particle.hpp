#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>

#define DELTA_TIME 0.2
#define CONST_G 1

/**
 * Particles are the objects that are displayed in the 
 * simulation. 
 */

class Particle {

    public:
        float mass;
        float force_x;     // x-force
        float force_y;     // y-force
        float vel_x;       // x-velocity
        float vel_y;       // y-velocity
        float pos_x;       // x-position
        float pos_y;       // y-position
        
        Particle();
        Particle(float x, float y, float mass);
        Particle(float x, float y, float mass, float vel_x, float vel_y);

        void update_force(Particle other);
        void update_velocity();
        void update_position();    
        void update(Particle other);
        void print_position();
        void reset_force();
};

float attraction_between_bodies(Particle a, Particle b);

float distance_between_bodies(Particle a, Particle b);

void Particle::update_force(Particle other) {
    float f = attraction_between_bodies(*this, other);
    float dist = distance_between_bodies(*this, other);
    force_x = force_x + f * (other.pos_x - this->pos_x) / dist;
    force_y = force_y + f * (other.pos_y - this->pos_y) / dist;
}

void Particle::update_velocity() {
    vel_x = vel_x + force_x/mass * DELTA_TIME;
    vel_y = vel_y + force_y/mass * DELTA_TIME;
}

void Particle::update_position() {
    pos_x = pos_x + vel_x * DELTA_TIME;
    pos_y = pos_y + vel_y * DELTA_TIME;
}

Particle::Particle() {
}

Particle::Particle(float x, float y, float mass) {
    pos_x = x;
    pos_y = y;
    this->mass = mass;
    force_x = 0;
    force_y = 0;
    vel_x = 0;
    vel_y = 0;
}

Particle::Particle(float x, float y, float mass, float vel_x, float vel_y) {
    pos_x = x;
    pos_y = y;
    this->mass = mass;
    force_x = 0;
    force_y = 0;
    this->vel_x = vel_x;
    this->vel_y = vel_y;
}

void Particle::update(Particle other) {
    this->update_force(other);
    this->update_velocity();
    this->update_position();
}

void Particle::print_position() {
    std::cout << "x : [" << pos_x << "] y : [" << pos_y << "]\n";
}

void Particle::reset_force() {
    force_x = 0;
    force_y = 0;
}

float distance_between_bodies(Particle a, Particle b) {
    return std::max(sqrtf(pow(a.pos_x - b.pos_x, 2) + pow(a.pos_y - b.pos_y, 2)), float(150));
}

float attraction_between_bodies(Particle a, Particle b) {
    return CONST_G*(a.mass * b.mass)/pow(distance_between_bodies(a,b), 2);
}

#endif