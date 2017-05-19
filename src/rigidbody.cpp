#include "Physics/rigidbody.hpp"

namespace yage
{

RigidBody::RigidBody(const glm::vec2 &position,
                     double mass,
                     const glm::vec2 &velocity,
                     bool gravity) :
	ParticleBody(position, mass, velocity, gravity)
{}

} // yage
