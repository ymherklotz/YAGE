/** ---------------------------------------------------------------------------
 * -*- c++ -*-
 * @file: body.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#include <yage/physics/body.h>

#include <utility>

namespace yage
{

const double Body::GRAVITY = -9.81;

double Body::xPosition() const
{
    return position_[0];
}

double Body::yPosition() const
{
    return position_[1];
}

Body::Body(Vector2d position, double mass, Vector2d velocity, bool gravity)
    : position_(std::move(position)), mass_(mass),
      velocity_(std::move(velocity)), gravity_(gravity)
{
}

} // namespace yage
