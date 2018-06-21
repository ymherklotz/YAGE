#pragma once

#include <vector>

#include "component.h"

namespace yage
{

/**
 * The entity is currently just an unsigned integer, which may change to a
 * class in the future.
 */
typedef unsigned int Entity;

/**
 * Has to keep track of all the different entities and their current state.
 *
 * The key actions on an Entity are: deleting, creating.
 */
class EntityManager
{
public:
    Entity create_entity();
    EntityManager &delete_entity(Entity entity);
    bool is_valid(Entity entity) const;
    EntityManager &add_component(Entity entity, BaseComponent *component);

private:
    Entity update_next_entity();

    Entity next_entity_ = 0;

public:
    std::vector<ComponentGroup> component_group_;
    std::vector<ComponentMask> component_masks_;
    std::vector<Entity> deleted_;
};

} // namespace yage
