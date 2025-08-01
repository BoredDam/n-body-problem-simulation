#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>

#define DELTA_TIME 0.2
#define CONST_G 1

class Particle {

    public:
        float mass;        
        float force_x;     // x-component-force
        float force_y;     // y-component-force
        float vel_x;       // x-component-velocity
        float vel_y;       // y-component-velocity
        float pos_x;       // x-position
        float pos_y;       // y-position
        
        Particle(float x_in, float y_in, float mass_in, float vel_x_in, float vel_y_in); // constructor

        inline void update_force(Particle other);   // FIRST run this on every body combination (O(n^2)). Cumulative sum of forces.
        inline void update_velocity();              // THEN run this to update velocity; vel = force/mass * DELTA_TIME.
        inline void update_position();              // THEN run this to update position; pos = vel * DELTA_TIME.
        inline void reset_force();                  // after every calculation, reset the cumulative sum of the forces on every particle
        inline void _print_position();
};


float attraction_between_bodies(Particle a, Particle b);

float distance_between_bodies(Particle a, Particle b);

inline void Particle::update_force(Particle other) {

    float f = attraction_between_bodies(*this, other);
    float dist = distance_between_bodies(*this, other);

    force_x = force_x + f * (other.pos_x - this->pos_x) / dist; // this is a cumulative sum used to account for every force
    force_y = force_y + f * (other.pos_y - this->pos_y) / dist; // involved in the simulation. run reset_force() at the end of every frame
}

inline void Particle::update_velocity() {
    vel_x = vel_x + force_x/mass * DELTA_TIME; // force/mass = accel; accel * time = velocity 
    vel_y = vel_y + force_y/mass * DELTA_TIME; 
}

inline void Particle::update_position() {
    pos_x = pos_x + vel_x * DELTA_TIME;
    pos_y = pos_y + vel_y * DELTA_TIME;
}

inline void Particle::reset_force() {
    force_x = 0;
    force_y = 0;
}

inline float distance_between_bodies(Particle a, Particle b) {
    return std::max(sqrtf(pow(a.pos_x - b.pos_x, 2) + pow(a.pos_y - b.pos_y, 2)), float(140));
}

inline float attraction_between_bodies(Particle a, Particle b) {
    return CONST_G*(a.mass * b.mass)/pow(distance_between_bodies(a,b), 2);
}

#endif