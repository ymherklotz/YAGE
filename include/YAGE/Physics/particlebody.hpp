#ifndef YAGE_PARTICLE_BODY_HPP
#define YAGE_PARTICLE_BODY_HPP

#include <glm/glm.hpp>

#include "body.hpp"

namespace yage
{

class ParticleBody : public Body
{
public:
	ParticleBody(const glm::vec2 &position=glm::vec2(0.f, 0.f),
	             double mass=1.0,
	             const glm::vec2 &velocity=glm::vec2(0.f, 0.f),
	             bool gravity=true);

	// apply a force to the rigid body
	virtual void applyForce(const glm::vec2 &force);
	virtual void update();
};

} // yage

#endif
