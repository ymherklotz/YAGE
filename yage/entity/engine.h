/** ---------------------------------------------------------------------------
 * @file: engine.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#ifndef YAGE_CORE_ENGINE_H
#define YAGE_CORE_ENGINE_H

#include "system.h"
#include "../core/window.h"

#include <memory>
#include <vector>

namespace yage
{

class Space;

/**
 * Main engine class that contains a systems, the main loop and the update
 * function that updates all the systems.
 */
class Engine
{
public:
    /// Initialize window and other aspects of the engine.
    void init();

    /// Main game loop of the engine.
    void mainLoop();

    /// Updates the systems.
    void update();

    /// Add spaces to the engine
    void addSpace(std::unique_ptr<Space> space);

    /// Returns the instance of the engine, as there is only one instance of the
    /// engine.
    static Engine &instance();

private:
    /// Window
    Window window_;

    /// A vector of all the spaces
    std::vector<std::unique_ptr<Space>> spaces_;
};

} // namespace yage

#endif
