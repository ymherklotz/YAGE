/** ---------------------------------------------------------------------------
 * @file: engine.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#include "engine.h"

namespace yage
{

void Engine::init()
{
    window_.create("Game Engine", 800, 640);
}

void Engine::mainLoop()
{
    while (!window_.shouldClose()) {
        window_.clearBuffer();

        update();

        window_.swapBuffer();
    }
}

void Engine::update()
{
}

Engine &Engine::instance()
{
    static Engine engine_instance;

    return engine_instance;
}

} // namespace yage