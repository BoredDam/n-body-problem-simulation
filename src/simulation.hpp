#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <math.h>

#include <SFML/Graphics.hpp>
#include "particle.hpp"


struct simulation_params {
    bool show_fps;
    float part_size; 
    float trail_opacity;
};

class Simulation {

    public:
        struct simulation_params parse_command_line(int argc, char *argv[]);
        void run(std::vector<Particle> part_list, struct simulation_params params);
};

struct simulation_params Simulation::parse_command_line(int argc, char *argv[]) {

    struct simulation_params output_params = {.show_fps = false};


    for (int i = 0; i<argc; i++) {
        if (!strcmp(argv[i], "-fps")) {
            output_params.show_fps = true;
        }

        if (!strcmp(argv[i], "-h")) {
            std::cout << argv[0] << " <directory of particle text file> <particle-size, best:1|1.5> <trail opacity min:0 max:100> [-fps]\n";
            exit(EXIT_SUCCESS);
        }
    }

    output_params.part_size = atof(argv[2]);
    output_params.trail_opacity = atof(argv[3]);

    return output_params;
}


void Simulation::run(std::vector<Particle> part_list, struct simulation_params params) {
    
    sf::Clock clock;
    sf::Time time;
    
    sf::RenderWindow window(sf::VideoMode({1920, 1080}), "simulation");
    sf::Vector2u size = window.getSize();
    sf::View view(sf::Vector2f(0, 0), sf::Vector2f(size.x, size.y));
    view.setSize(view.getSize() * float(1));

    sf::CircleShape body(20);
    
    sf::RectangleShape clearScreen(sf::Vector2f(size.x * 2, size.y * 2));
    clearScreen.setOrigin(sf::Vector2f(size.x, size.y));
    float trail = 255 - params.trail_opacity/100 * 255; 
    clearScreen.setFillColor(sf::Color(0, 0, 0, trail)); 

    window.setView(view);
    window.setFramerateLimit(60);

    
    window.clear(sf::Color::Black);

    body.setRadius(params.part_size);
    body.setFillColor({255,255,255});

    while (window.isOpen()) {

        if (params.show_fps) {
            time = clock.getElapsedTime();
            std::cout<<"FPS: "<< 1.0f/time.asSeconds() << "\n";
            clock.restart();
        }
        sf::Event event;
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        
        for (size_t i = 0; i < part_list.size(); ++i) {
            for (size_t j = i + 1; j < part_list.size(); ++j) {

                part_list[i].update_force(part_list[j]);
                part_list[j].update_force(part_list[i]);
            }
        }
        
        window.draw(clearScreen);

        for (auto& part : part_list) {
            part.update_velocity();
            part.update_position();
            part.reset_force();
            body.setPosition({part.pos_x, part.pos_y});
            window.draw(body);
        }

        window.display();

    }
}

#endif