# N-Body simulation project, naive approach.

This project consists in an implementation of the **naive algorithm for a "n-body problem" simulation**, written in C++.

Click on the images to open some videos on YouTube:

[![2000-bodysim](https://img.youtube.com/vi/z-a510rj_m4/0.jpg)](https://www.youtube.com/watch?v=z-a510rj_m4)

*2000-body demo*.


[![1500-bodysim](https://img.youtube.com/vi/ZODAdztqdFE/0.jpg)](https://www.youtube.com/watch?v=ZODAdztqdFE)

*my fav demo, 1500-body*.

[![fav-bodysim](https://img.youtube.com/vi/atKVO5fEWuM/0.jpg)](https://www.youtube.com/watch?v=atKVO5fEWuM)

*my first demo :)*.
## 👨‍💻 About the project

### Algorithm - Naive Approach
The chosen algorithm for this code for the n-nody problem, is the naive-algorithm.

It has a $O(n^2)$ time complexity (with $n =$ number of particles), since the forces that are applied to every particle are calculated based on the **attraction force between *every pair* of particles** of the simulation.

### Why C++?
Mainly three reasons:

- *Absolute OOP*. I decided to use C++ both for the performances of the language and the slight **layer of abstraction offered by OOP**. As an example, both the simulation and the particles are in fact instances of the `Simulation` and `Particle` classes.

- The **Standard Template Library** offers some great data structures implementation. I decided to use the **vector** template class to gather the `Particle` objects, since it's the best option in terms of speed and ease of access (contiguous memory is the way to go, no iterator is also needed. Lists dont need contiguos memory, but they are also pretty slow for this type of situations.).

- For the **visualization of the particles**, I decided to use the graphical library **SFML** (I just picked it up! Every tip about this library is accepted).

### Handling collisions

Collisions are a problem when simulating attraction between bodies. Given the formula:

$$
Force = G \cdot \frac{m_1 \cdot m_2}{r^2}
$$

When $r$ (the distance between the two masses) tends to 0, $F$ tends to infinity.

$$
\lim_{r \to 0} \\ G \cdot \frac{m_1 \cdot m_2}{r^2} = +\infty
$$

This situation is handled by **setting the minimum distance between two particles to a fixed value**, when the actual distance is lower than that. Particles won't go like crazy after they get very close, but real collisions are not really handled, **particles pass through each other**.

## Loading the simulation

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

## 👷 To compile the project

### Installing SFML library 

#### (Fedora)

```
sudo dnf install SFML SFML-devel
```

#### (Debian)
```
sudo apt-get install libsfml-dev
```

### Compiling the source code
```
g++ src/*.cpp [-O0|-O1|-O2|-O3|] -o n-body-sim -lsfml-graphics -lsfml-window -lsfml-system
```

Use the -O1, -O2 or -O3 optimization flag for better performances. 



## ▶️ To run a simulation

```
...> ./n-body-sim <directory of text file> <-fps|-nfps> <particle-size> <trail opacity [0,100]> 
```

Example:
```
./n-body-sim ./text-files/3-galaxies.txt -fps 1 0
```

## 🔧 Planned changes and fixes. 

- **Refactoring. A lot of refactoring.**
- **A better command line input parser**.
- Other demos.
- **Colors**(?).
- Better handling of the physics.
- **I (probably) won't further optimize this code** in computational terms, since I'll create other repositories (or folders in this one?) with other simulation approaches, such as the Barnes-Hut algorithm or a parallel strategy.
