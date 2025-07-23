#include "fileparser.hpp"

std::vector<Particle> FileParser::Parse(std::string filename) {

    std::ifstream part_file = open_file(filename);
    std::vector<Particle> particles = create_part_vec(part_file);
    part_file.close();

    return particles;
}

/**
 * Handles file opening, file-related error handling 
 * (TODO:) checking for file extension. 
 */
std::ifstream FileParser::open_file(std::string filename) {

    std::ifstream part_file;
    part_file.open(filename);
    
    if (!part_file.is_open()) {
        std::cerr << filename <<" is not the name of a file.\n";
        exit(EXIT_FAILURE);
    }

    std::cout << "File opened with success.\n";
    return part_file;
}

/**
 * handles the creation of the particle vector
 * (TODO:) checking if the file is formatted wrong
 */
std::vector<Particle> FileParser::create_part_vec(std::ifstream &file_stream) {

    std::vector<Particle> particles;

    float buf_x;
    float buf_y;
    float buf_mass;
    float buf_vel_x;
    float buf_vel_y;
    
    while (file_stream >> buf_x >> buf_y >> buf_mass >> buf_vel_x >> buf_vel_y) {
        particles.emplace_back(buf_x, buf_y, buf_mass, buf_vel_x, buf_vel_y);
    }
    

    return particles;
}

