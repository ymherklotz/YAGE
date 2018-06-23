#include "entity.h"

#include "component.h"

#include <algorithm>
#include <iostream>
#include <memory>

namespace yage
{

Entity EntityManager::create_entity()
{
    Entity entity = update_next_entity();
    component_masks_.push_back(ComponentMask(0));
    return entity;
}

EntityManager &EntityManager::delete_entity(Entity entity)
{
    deleted_.push_back(entity);
    return *this;
}

bool EntityManager::is_valid(Entity entity) const
{
    auto it = std::find(deleted_.begin(), deleted_.end(), entity);
    if (it == deleted_.end()) {
        return true;
    }
    return false;
}

EntityManager &
EntityManager::add_component(Entity entity,
                             std::unique_ptr<BaseComponent> &&component)
{
    auto id = component->getGroup();
    component_masks_[entity] =
        component_masks_[entity] | ComponentMask(1 << id);
    if (id+1 > component_group_.size()) {
        component_group_.resize(id+1);
    }
    component_group_[id].add(std::move(component));
    return *this;
}

Entity EntityManager::update_next_entity()
{
    if (deleted_.empty()) {
        return next_entity_++;
    }
    Entity ent = deleted_.back();
    deleted_.pop_back();
    return ent;
}

} // namespace yage
