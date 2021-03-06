/** ---------------------------------------------------------------------------
 * -*- c++ -*-
 * @file: particlebody.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#pragma once

#include "body.h"
#include <math/matrix.h>

namespace yage
{

class ParticleBody : public Body
{
public:
    ParticleBody(const Vector2d &position = Vector2d(0, 0), double mass = 1,
                 const Vector2d &velocity = Vector2d(0, 0),
                 bool gravity             = true);

    // apply a force to the rigid body
    void applyForce(const Vector2d &force) override;
    void update() override;
};

} // namespace yage
