YAGE {#mainpage}
====
![master-build](https://travis-ci.org/ymherklotz/YAGE.svg?branch=master)

Introduction
------------

YAGE stands for Yet Another Game Engine. It is a game engine that I am
developing for a game called [Arider](https://github.com/ymherklotz/Arider).
It uses OpenGL and SDL2 for the window creation and management and graphics.

The full documentation can be seen [here](https://www.yannherklotz.com/YAGE).

Installation and usage
----------------------

To use YAGE for your own game, you should link it as a static library and
include the [yage.h](/include/YAGE/yage.h) header in your project.

Build and Testing
-----------------

To compile YAGE, create a build directory from the base directory. Then call
cmake and point it to the directory containing.
[CMakeLists.txt](/CMakeLists.txt).

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
