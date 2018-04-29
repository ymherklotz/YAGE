/** ---------------------------------------------------------------------------
 * @file: engine.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#ifndef YAGE_CORE_ENGINE_H
#define YAGE_CORE_ENGINE_H

#include "../core/window.h"
#include "system.h"

#include <vector>

namespace yage
{

/// Main engine class that contains a systems, the main loop and the update
/// function that updates all the systems.
class Engine
{
public:
    /// Initialize window and other aspects of the engine.
    void init();

    /// Main game loop of the engine.
    void mainLoop();

    /// Updates the systems.
    void update();

    void registerSystem();

    /// Returns the instance of the engine, as there is only one instance of the
    /// engine.
    static Engine &instance();

private:
    /// Window
    Window window_;
};

} // namespace yage

#endif
