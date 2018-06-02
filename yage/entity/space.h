/** ---------------------------------------------------------------------------
 * -*- c++ -*-
 * @file: space.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#pragma once

#include <memory>
#include <vector>

#include "entity.h"
#include "system.h"

struct Movement {
};

namespace yage
{

class System;

/**
 * Space that keeps track of all the entities, componenets and runs
 * the systems on the data to update them. There can be multiple
 * instances of a space, which can be used, for example, for different
 * levels in the game that can be loaded separately, or a game menu
 * that can be loaded above the other spaces when the user presses on
 * pause.
 */
class Space
{
public:
    /**
     * Default instance for a space.
     */
    Space();

    /**
     * Create an entity that will belong to this space, and return the
     * handle to the user. The Entity class itself should not be
     * visible to the user, as the user only needs to worry about the
     * handle when referring to the Entity and changing it.
     */
    Entity createEntity();

    /**
     * Update all the systems.
     */
    void update();

private:
    /**
     * The systems of the Space that act on the data and on their
     * respective component. These are specific to the Space, as other
     * spaces might have different Systems and not act on the same
     * entities.
     */
    std::vector<std::unique_ptr<System>> systems_;

    /**
     * Manages all the entities in the system, can create them for the
     * current space.
     */
    EntityManager em_;

    /**
     * Manages all the components
     */
    // ComponentManager cm_;
};

} // namespace yage
