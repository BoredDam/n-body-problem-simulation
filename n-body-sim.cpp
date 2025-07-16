#include <cstddef>
#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include "particle.hpp"
#include "simulation.hpp"
#include "parser.hpp"

int main(int argc, char *argv[]) {
    
    Parser parser;
    Simulation sim;
    
    sim.run(parser.Parse("testo.txt"));

}

