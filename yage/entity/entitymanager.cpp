/** ---------------------------------------------------------------------------
 * @file: entitymanager.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#include "entitymanager.h"

namespace yage
{

EntityManager::EntityManager(Space *space) : space_(space) {}

EntityManager::EntityManager(Space *space, std::size_t n)
    : space_(space)
{
    entities_.reserve(n);
}

Entity EntityManager::createEntity()
{
    Entity entity = next_entity_++;
    entities_.push_back(entity);
    return entity;
}

} // namespace yage
