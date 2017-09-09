/* ----------------------------------------------------------------------------
 * rigidbody.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com> -- MIT License
 * See file LICENSE for more details
 * ----------------------------------------------------------------------------
 */

#include <YAGE/Physics/rigidbody.h>

namespace yage
{

RigidBody::RigidBody(const Vector2d &position, double mass,
                     const Vector2d &velocity, bool gravity)
    : ParticleBody(position, mass, velocity, gravity)
{
}

} // namespace yage
