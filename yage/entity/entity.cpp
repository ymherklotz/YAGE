/** ---------------------------------------------------------------------------
 * @file: entity.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#include "entity.h"

#include <algorithm>

namespace yage
{

BaseComponent::Group BaseComponent::group_id_counter_ = 0;

EntityManager::EntityManager(Space *space) : space_(space) {}

EntityManager::EntityManager(Space *space, std::size_t n) : space_(space)
{
    entities_.reserve(n);
}

Entity EntityManager::createEntity()
{
    Entity entity = next_entity_++;
    entities_.push_back(entity);
    return entity;
}

void EntityManager::deleteEntity(Entity entity)
{
    auto index = std::find_if(entities_.begin(), entities_.end(),
                              [&](Entity &value) { return value == entity; });
    if (index != entities_.end()) {
        entities_.erase(index);
    }
}

} // namespace yage
