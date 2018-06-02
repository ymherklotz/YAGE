/** ---------------------------------------------------------------------------
 * -*- c++ -*-
 * @file: rigidbody.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#include <yage/physics/rigidbody.h>

namespace yage
{

RigidBody::RigidBody(const Vector2d &position, double mass,
                     const Vector2d &velocity, bool gravity)
    : ParticleBody(position, mass, velocity, gravity)
{
}

} // namespace yage
