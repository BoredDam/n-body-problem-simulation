#include "particle.hpp"
#include "simulation.hpp"
#include "fileparser.hpp"
#include <string.h>

int main(int argc, char *argv[]) {
    
    bool fps = false;

    if (!strcmp(argv[2], "-fps")) {
        fps = true;
    }

    FileParser file_parser;
    Simulation sim;
    sim.run(file_parser.Parse(argv[1]), fps, atof(argv[3]), atof(argv[4]));

}

