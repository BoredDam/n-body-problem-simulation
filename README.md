# N-Body simulation projects

This projects consists in an implementation of the **naive algorithm for the n-body problem simulation**.

![alt text](image.png)

For the **visualization of the particles**, I used the graphical library **SFML**.

I decided to use OOP offered by C++ to **encapsulate** the datas related to every particle of the simulation, inside instances of the `Particle` class.

## To compile

Use the -O2 optimization flag for better performances.

```
g++ n-body-sim.cpp particle.hpp simulation.hpp fileparser.hpp -I"C:/C++Lib/SFML-3.0.0-windows-gcc-14.2.0-mingw-64-bit/SFML-3.0.0/include" -L"C:/C++Lib/SFML-3.0.0-windows-gcc-14.2.0-mingw-64-bit/SFML-3.0.0/lib" -lsfml-graphics -lsfml-window -lsfml-system -O2 -o n-body-sim-3.exe
```
