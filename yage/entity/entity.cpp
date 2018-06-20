#include "entity.h"

#include <algorithm>

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

Entity EntityManager::update_next_entity()
{
    if (deleted_.empty()) {
        return ++next_entity_;
    }
    next_entity_ = deleted_.back();
    deleted_.pop_back();
    return next_entity_;
}

} // namespace yage
