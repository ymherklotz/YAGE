/** ---------------------------------------------------------------------------
 * @file: engine.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#include "engine.h"

#include "../core/window.h"

namespace yage
{

void Engine::mainLoop()
{
    Window window;

    window.create("Game Engine", 800, 640);

    while(!window.shouldClose()) {
        window.clearBuffer();

        update();

        window.swapBuffer();
    }
}

void Engine::update()
{
    const double dt = 1.0 / 60.0;

    for(auto &&system : systems_) {
        system->update(dt);
    }
}

void Engine::addSystem(System *system)
{
    systems_.push_back(system);
}

Engine &Engine::instance()
{
    static Engine engine_instance;

    return engine_instance;
}

} // namespace yage
