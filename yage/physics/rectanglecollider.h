/** ---------------------------------------------------------------------------
 * @file: rectanglecollider.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#pragma once

#include "collider.h"

#include <glm/glm.hpp>

namespace yage
{

class RectangleCollider : public Collider
{
public:
    RectangleCollider(const glm::vec2 &position, const glm::vec2 &size);

    bool collides(const Collider &collider) const override;
    bool inside(const glm::vec2 &point) const override;
};

} // namespace yage
