#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include <math.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <vector>
#include "particle.hpp"

#define TRAIL_FLAG 0
#define FPS_FLAG 1
#define LINES_FLAG 2




class Simulation {
    
    public:
        void run(std::vector<Particle> part_list, const bool flags[8]);

};

void Simulation::run(std::vector<Particle> part_list, const bool flags[8]) {
    
    sf::Clock clock;
    sf::Time time;
    
    sf::RenderWindow window(sf::VideoMode({1920, 1080}), "simulation");
    sf::Vector2u size = window.getSize();
    sf::View view(sf::Vector2f(0, 0), sf::Vector2f(size.x, size.y));
    view.setSize(view.getSize() * float(1));
    

    sf::CircleShape body(20);
    
    sf::RectangleShape clearScreen(sf::Vector2f(size.x * 2, size.y * 2));
    clearScreen.setOrigin(sf::Vector2f(size.x, size.y)); 
    clearScreen.setFillColor(sf::Color(0, 0, 0, 255)); 

    window.setView(view);
    window.setFramerateLimit(60);

    
    window.clear(sf::Color::Black);

    body.setRadius(1.5f);
    body.setFillColor({255,255,255});

    while (window.isOpen()) {

        if (flags[FPS_FLAG]) {
            time = clock.getElapsedTime();
            std::cout<<"FPS: "<< 1.0f/time.asSeconds() << "\n";
            clock.restart();
        }
        
        while (std::optional event = window.pollEvent()) {

            if (event->is<sf::Event::Closed>()) {
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
        //window.clear();

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