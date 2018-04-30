/** ---------------------------------------------------------------------------
 * @file: entitymanager.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#ifndef YAGE_ENGINE_ENTITYMANAGER_H
#define YAGE_ENGINE_ENTITYMANAGER_H

#include "entity.h"

#include <vector>

namespace yage
{

class Space;

/**
 * Manages entities in a space.
 */
class EntityManager
{
public:
    /**
     * Default instance of an EntityManager.
     */
    EntityManager() = default;

    /**
     * Creates an instance of the entity manager, which refers back to the space
     * it was created in and belongs to.
     *
     * @param space Current space that the EntityManager belongs to.
     */
    EntityManager(Space *space);

    /**
     * Creates an instance of the entitiy manager with an initial size.
     *
     * @param space Current space that the EntityManager belongs to.
     * @param n Initial size of the EntityManager.
     */
    EntityManager(Space *space, std::size_t n);

    /**
     * Creates an Entity and returns the handle to the entity, which can then be
     * used by the user to do operations on it.
     *
     * @return The handle to the entity that was created in the space.
     */
    unsigned createEntity();

private:
    /**
     * The next available handle to give to the user.
     */
    Entity next_entity_ = 0;

    /**
     * The space that the entity manager belongs to.
     */
    Space *space_;

    /**
     * The entities in the current space.
     */
    std::vector<Entity> entities_;
};

} // namespace yage

#endif
