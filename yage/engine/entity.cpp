/** ---------------------------------------------------------------------------
 * @file: entity.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#include "entity.h"

#include "space.h"

namespace yage
{

Entity::Entity(unsigned handle) : handle_(handle) {}

unsigned Entity::getHandle() const
{
    return handle_;
}

} // naemspace yage
