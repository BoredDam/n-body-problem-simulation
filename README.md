# N-Body simulation projects

This project consists in an implementation of the **naive algorithm for a "n-body problem" simulation**, written in C++.

[![Watch the video](https://raw.githubusercontent.com/username/repository/branch/path/to/thumbnail.jpg)](https://raw.githubusercontent.com/username/repository/branch/path/to/video.mp4)


## About the project

### Algorithm - Naive Approach
The chosen algorithm for this code for the n-nody problem, is the naive-algorithm.

It has a $O(n^2)$ time complexity (with $n = $ number of particles), since the forces that are applied to every particle are calculated based on the **attraction force between *every pair* of particles** of the simulation.

### Why C++?
Mainly three reasons:

- *Absolute OOP*. I decided to use C++ both for the performances of the language and the slight **layer of abstraction offered by OOP**. As an example, both the simulation and the particles are in fact instances of the `Simulation` and `Particle` class.

- The **Standard Template Library** offers some great data structures implementation. I decided to use the **vector** template class to gather the `Particle` objects, since it's the best option in terms of speed and ease of access (contiguous memory is the way to go, no iterator is also needed. Lists dont need contiguos memory, but they are also pretty slow for this type of situations.).

- For the **visualization of the particles**, I decided to use the graphical library **SFML** (I just picked it up! Every tip about this library is accepted).

### Loading the simulation

The code creates particles by parsing out a text file.
```
<x-position> <y-position> <mass> <x-speed> <y-speed>
```
This is an example of a correctly formatted text file for a 3-body problem.

```
0 0 10000.1 0 0
0 -200 200.7 -4 0
300.5 0 100 0 -3 
```

## To compile

Use the -O2 optimization flag for better performances.

```
g++ n-body-sim.cpp particle.hpp simulation.hpp fileparser.hpp -I"C:/C++Lib/SFML-3.0.0-windows-gcc-14.2.0-mingw-64-bit/SFML-3.0.0/include" -L"C:/C++Lib/SFML-3.0.0-windows-gcc-14.2.0-mingw-64-bit/SFML-3.0.0/lib" -lsfml-graphics -lsfml-window -lsfml-system -O2 -o n-body-sim-3.exe
```
