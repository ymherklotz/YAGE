![yage-logo](/docs/yage.png "YAGE")

![master-build](https://travis-ci.org/ymherklotz/YAGE.svg?branch=master "Build Status")

## Introduction

YAGE stands for Yet Another Game Engine. It is a 2D game engine that is being
developed for the game [Arider](https://github.com/ymherklotz/Arider). However,
it will also be general game engine library for any other 2D games.

YAGE uses OpenGL for rendering of 2D graphics. OpenGL was chosen because it is
the most crossplatform Graphics API, and not as low level as Vulkan.

Yage uses GLFW for the creation and viewport as it is lightweight and easy to
manage. However, these features are completely wrapped behind the YAGE API.

The inspiration for this game engine is to learn about OpenGL and create an
optimised 2D game engine with a simple API that can be used to easily create
simple 2D games. To do this, a Component Entity System will be used to manage
the different systems in the game engine and make it as modular as possible.
Systems can easily be added to the game engine, and new entities with custom
Components can also be created by the user.

The game engine also supports asynchronous logging by using an `Active` class
that creates a new thread, and queues any functions that are sent to it. This
can help debugging programs, as one can increase the minimum log level of the
game engine to any required resolution. This output can also be piped to a
file without slowing down the program.

The full documentation of the API can be seen 
[here](https://www.yannherklotz.com/YAGE).

## Installation and usage

To use YAGE for your own game, you should link it as a static library and
include the [yage.h](/include/YAGE/yage.h) header in your project. To link the
project using cmake, the library has to be added as a subdirectory and then
linked with the name `yage`.

## Build and Testing

To compile YAGE, create a build directory from the base directory. Then call
cmake and point it to the directory containing.
[CMakeLists.txt](/CMakeLists.txt).
For example, one can use the following commands to build the library and run
tests on it.

``` shell
mkdir -p build
cd build
cmake ..
```

The test suite can then be run using

``` shell
cd build/tests && ctest
```

## Using the game engine

The game engine can be initialised as follows.

``` c++
yage::init();
```

It can be then cleaned up by running.

``` objective-c++
yage::quit();
```

## Future Improvements

The first step is to have full support of 3D meshes with their corresponding
textures, and making a useful API to interact with the 3D YAGE library.

Secondly, improvements to the Entity Component System 

## License

Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com> -- MIT License,
see file [LICENSE](/LICENSE) for more details.
