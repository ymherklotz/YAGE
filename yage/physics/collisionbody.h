/** ---------------------------------------------------------------------------
 * -*- c++ -*-
 * @file: collisionbody.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#pragma once

#include "body.h"

namespace yage
{

// a collision body will be a body that is static and not affected by gravity,
// with infinite mass
class CollisionBody : public Body
{
public:
    CollisionBody();
    virtual ~CollisionBody();
};

} // namespace yage
