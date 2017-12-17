YAGE {#mainpage}
====
![master-build](https://travis-ci.org/ymherklotz/YAGE.svg?branch=master)

Introduction
------------

YAGE stands for Yet Another Game Engine. It is a game engine that is being
developed for a game called [Arider](https://github.com/ymherklotz/Arider).
It uses OpenGL and GLFW for the window creation and management and graphics.
It is also going to be a general game engine for use with other games in the
similar style.

The inspiration for this game engine is to learn about OpenGL and create an
optimised 2D game engine with a simple API that can be used to easily create
simple 2D games.

The full documentation can be seen [here](https://www.yannherklotz.com/YAGE).

Installation and usage
----------------------

To use YAGE for your own game, you should link it as a static library and
include the [yage.h](/include/YAGE/yage.h) header in your project. To link the
project using cmake, the library has to be added as a subdirectory and then linked
with the name `yage`.

Build and Testing
-----------------

To compile YAGE, create a build directory from the base directory. Then call
cmake and point it to the directory containing.
[CMakeLists.txt](/CMakeLists.txt).
For example, one can use the following commands

``` shell
mkdir -p build
cd build
cmake -DENABLE_TESTING=1 ..
```

You can then run google test on YAGE.

``` shell
ctest
```

License
-------

Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com> -- MIT License,
see file [LICENSE](/LICENSE) for more details.
