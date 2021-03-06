/** ---------------------------------------------------------------------------
 * -*- c++ -*-
 * @file: collider.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#pragma once

#include <glm/glm.hpp>

namespace yage
{

// The Collider class helps collision detection by providing a general shape
// for different shapes to have their own collision algorithms.
class Collider
{
protected:
    // position of the object
    glm::vec2 position_;

    // size of the object
    glm::vec2 size_;

public:
    Collider(const glm::vec2 &position, const glm::vec2 &size)
        : position_(position), size_(size)
    {
    }

    // function that checks if two colliders are colliding
    virtual bool collides(const Collider &collider) const = 0;

    // function that returns if a point is inside the shape
    virtual bool inside(const glm::vec2 &point) const = 0;
};

} // namespace yage
