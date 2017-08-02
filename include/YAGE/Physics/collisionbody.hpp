/* ----------------------------------------------------------------------------
 * collisionbody.hpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com> -- MIT License
 * See file LICENSE for more details
 * ----------------------------------------------------------------------------
 */

#ifndef YAGE_COLLISION_BODY_HPP
#define YAGE_COLLISION_BODY_HPP

#include "Physics/body.hpp"

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

} // yage

#endif
