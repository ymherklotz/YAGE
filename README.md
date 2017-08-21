YAGE
====

YAGE stands for Yet Another Game Engine. It is a game engine that I am developing for a game called [Arider](https://github.com/ymherklotz/Arider). 

YAGE uses OpenGL and SDL2 for the window creation and management and graphics.

Installation and Usage
----------------------

To compile YAGE, create a build directory from the base directory. Then call cmake and point it to the directory containing [CMakeLists.txt](/CMakeLists.txt).

``` shell
mkdir build
cd build
cmake ..
```

You can then run google test on YAGE.

``` shell
ctest
```

License
-------

Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com> -- MIT License,
see file [LICENSE](/LICENSE) for more details.
