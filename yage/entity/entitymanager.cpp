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

EntityManager::EntityManager(Space *space) : next_handle_(0), space_(space) {}

EntityManager::EntityManager(Space *space, std::size_t n)
    : next_handle_(0), space_(space)
{
    entities_.reserve(n);
}

unsigned EntityManager::createEntity()
{
    return createEntityInstance().getHandle();
}

Entity EntityManager::createEntityInstance()
{
    Entity entity(next_handle_++);
    entities_.push_back(entity);
    return entity;
}

} // namespace yage
