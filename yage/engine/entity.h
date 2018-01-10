/** ---------------------------------------------------------------------------
 * @file: entity.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#ifndef YAGE_ENGINE_ENTITY_H
#define YAGE_ENGINE_ENTITY_H

#include <vector>

namespace yage
{

class Space;

/**
 * Entity convenience class. It contains handles to where the entity is in the
 * entity manager of the space, and a pointer back to the space itself.
 *
 * This class cannot be instantiated outside of a Space and should only be
 * instantiated through an entity manager, as otherwise the handle will not have
 * a meaning.
 */
class Entity
{
public:
    /**
     * Creates an instance of an Entity with a handle that is associated to it.
     * This handle refers to the position of he Entity in the list that is held
     * by the EntityManager, and therefore the id is enough to refer to it.
     */
    Entity(unsigned handle);

    /**
     * Handle getter, as the user will only interact with the id itself. The
     * handle is the unique identifier that the user can use to refer to the
     * entity.
     */
    unsigned getHandle() const;

private:
    /**
     * Entity handle for the entity manager.
     */
    unsigned handle_;
};

} // namespace yage

#endif
