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
