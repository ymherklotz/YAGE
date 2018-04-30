/** ---------------------------------------------------------------------------
 * @file: engine.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#include "engine.h"

#include "space.h"
#include "entity.h"

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
    for(auto &space : spaces_) {
        
    }
}

void Engine::addSpace(std::unique_ptr<Space> space)
{
    spaces_.push_back(std::move(space));
}

Engine &Engine::instance()
{
    static Engine engine_instance;

    return engine_instance;
}

} // namespace yage
