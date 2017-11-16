/* ----------------------------------------------------------------------------
 * rigidbody.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#ifndef YAGE_RIGID_BODY_H
#define YAGE_RIGID_BODY_H

#include "particlebody.h"

#include <glm/glm.hpp>

namespace yage
{

class RigidBody : public ParticleBody
{
public:
    RigidBody(const Vector2d &position = Vector2d(0, 0), double mass = 1,
              const Vector2d &velocity = Vector2d(0, 0), bool gravity = true);
};

} // namespace yage

#endif
