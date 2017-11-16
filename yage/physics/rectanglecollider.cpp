/* ----------------------------------------------------------------------------
 * rectanglecollider.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#include <yage/physics/rectanglecollider.h>

namespace yage
{

RectangleCollider::RectangleCollider(const glm::vec2 &position,
                                     const glm::vec2 &size)
    : Collider(position, size)
{
}

bool RectangleCollider::collides(const Collider &collider) const
{
    for (int i = position_.x; i < position_.x + size_.x; ++i) {
        for (int j = position_.y; j < position_.y + size_.y; ++j) {
            return collider.inside(glm::vec2(i, j));
        }
    }
    return false;
}

inline bool RectangleCollider::inside(const glm::vec2 &point) const
{
    return position_.x < point.x && position_.x + size_.x > point.x &&
           position_.y < point.y && position_.y + size_.y > point.y;
}

} // namespace yage
