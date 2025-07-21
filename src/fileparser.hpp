#ifndef FILEPARSER_HPP
#define FILEPARSER_HPP

#include <fstream>
#include <vector>
#include "particle.hpp"

class FileParser {
    public:
        std::ifstream part_file;

        std::vector<Particle> Parse(std::string filename);
        
};

std::vector<Particle> FileParser::Parse(std::string filename) {

    std::vector<Particle> lista_particelle;

    part_file.open(filename);

    if (!part_file.is_open()) {
        fprintf(stderr, "File non aperto.\n");
        exit(EXIT_FAILURE);
    } 

    std::cout << "File aperto con successo.\n";

    float x;
    float y;
    float mass;
    float vel_x;
    float vel_y;
    
    while (part_file >> x >> y >> mass >> vel_x >> vel_y) {
        lista_particelle.emplace_back(x, y, mass, vel_x, vel_y);
    }

    part_file.close();
    return lista_particelle;

}

#endif