/** ---------------------------------------------------------------------------
 * -*- c++ -*-
 * @file: body.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#pragma once

#include <math/matrix.h>

namespace yage
{

class Body
{
public:
    // gravity constant
    static const double GRAVITY;

protected:
    // center of mass of the object
    Vector2d position_ = Vector2d(0, 0);

    // mass of the object
    double mass_ = 1;

    // current velocity of the object
    Vector2d velocity_ = Vector2d(0, 0);

    // boolean that defines if gravity can act on the object
    bool gravity_ = true;

    // current acceleration
    Vector2d acceleration_ = Vector2d(0, 0);

    // force acting on the body
    Vector2d force_ = Vector2d(0, 0);

public:
    // apply force to the object and update the velocity
    virtual void applyForce(const Vector2d &force) = 0;
    virtual void update()                          = 0;

    double xPosition() const;
    double yPosition() const;

protected:
    // protected constructor to initialize member variables
    Body(Vector2d position = Vector2d(0, 0), double mass = 1,
         Vector2d velocity = Vector2d(0, 0), bool gravity = false);
};

} // namespace yage
