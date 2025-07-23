#ifndef FILEPARSER_HPP
#define FILEPARSER_HPP

#include <fstream>
#include <vector>
#include "particle.hpp"

class FileParser {
    private:
        std::ifstream open_file(std::string filename);
        std::vector<Particle> create_part_vec(std::ifstream &file_stream);
    public:
        std::vector<Particle> Parse(std::string filename);
    
};

#endif