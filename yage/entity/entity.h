/** ---------------------------------------------------------------------------
 * @file: entity.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#pragma once

#include <vector>
#include <memory>

namespace yage
{

class Space;
class ComponentPool;

typedef unsigned int Entity;

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
    Entity createEntity();

    /**
     * Delete an entity.
     */
    void deleteEntity(Entity entity);

private:
    /**
     * The next available handle to give to the user.
     */
    Entity next_entity_ = 0;

    /**
     * The space that the entity manager belongs to.
     */
    Space *space_ = nullptr;

    /**
     * The entities in the current space.
     */
    std::vector<Entity> entities_;

    std::vector<std::unique_ptr<ComponentPool>> components;
};

class BaseComponent {
public:
    typedef unsigned Group;

protected:
    static Group group_id_counter_;
};

template <typename Derived>
class Component : public BaseComponent {
private:
    BaseComponent::Group group();
};

class ComponentPool {
private:
    std::vector<BaseComponent *> components_;
};

} // namespace yage
