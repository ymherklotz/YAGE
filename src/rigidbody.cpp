#include "Physics/rigidbody.hpp"

namespace yage
{

RigidBody::RigidBody(const glm::vec2 &center_of_mass, double mass, const glm::vec2 &velocity, bool gravity) :
	Body(center_of_mass, mass, velocity, gravity)
{}

void RigidBody::applyForce(const glm::vec2 &force)
{
	// a=F/m
	glm::vec2 acceleration(force.x/mass_, force.y/mass_);
}

} // yage
