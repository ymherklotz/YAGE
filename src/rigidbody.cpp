#include "Physics/rigidbody.hpp"

namespace yage
{

RigidBody::RigidBody(const Vector2d &position,
                     double mass,
                     const Vector2d &velocity,
                     bool gravity) :
	ParticleBody(position, mass, velocity, gravity)
{}

} // yage
