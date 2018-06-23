#pragma once

#include "component.h"

#include <functional>
#include <iostream>
#include <memory>
#include <vector>

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
    EntityManager &add_component(Entity entity,
                                 std::unique_ptr<BaseComponent> &&component);
    template <typename T>
    EntityManager &each(std::function<void(T &)> update);

private:
    Entity update_next_entity();

    Entity next_entity_ = 0;

    std::vector<ComponentGroup> component_group_;
    std::vector<ComponentMask> component_masks_;
    std::vector<Entity> deleted_;
};

template <typename T>
EntityManager &EntityManager::each(std::function<void(T &)> update)
{
    T c;
    auto id = static_cast<BaseComponent *>(&c)->getGroup();
    for (auto it = component_group_[id].begin();
         it != component_group_[id].end(); ++it) {
        auto iteration = it - component_group_[id].begin();
        if (is_valid(iteration) && component_masks_[iteration][id]) {
            update(*static_cast<T *>((*it).get()));
        }
    }

    return *this;
}

} // namespace yage
