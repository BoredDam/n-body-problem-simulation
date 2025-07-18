#include "particle.hpp"
#include "simulation.hpp"
#include "fileparser.hpp"

int main(int argc, char *argv[]) {
    
    bool flags[8] = {1,1,0,0,0,0,0,0};
    FileParser file_parser;
    Simulation sim;
    
    sim.run(file_parser.Parse(argv[1]), flags);

}

