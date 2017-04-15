#ifndef YAGE_RIGID_BODY_HPP
#define YAGE_RIGID_BODY_HPP

#include "Physics/body.hpp"

namespace yage
{

class RigidBody : public Body
{
public:
	RigidBody(const glm::vec2 &center_of_mass,
	          double mass,
	          const glm::vec2 &velocity=glm::vec2(0.f, 0.f),
	          bool gravity=true);

	// apply a force to the rigid body
	virtual void applyForce(const glm::vec2 &force);
};

} // yage

#endif
