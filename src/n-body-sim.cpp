#include "simulation.hpp"
#include "fileparser.hpp"


int main(int argc, char *argv[]) {

    FileParser file_parser;
    Simulation sim;
    sim.run(file_parser.Parse(argv[1]), sim.parse_command_line(argc, argv));

}

