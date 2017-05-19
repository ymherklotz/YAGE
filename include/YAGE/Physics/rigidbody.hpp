#ifndef YAGE_RIGID_BODY_HPP
#define YAGE_RIGID_BODY_HPP

#include <glm/glm.hpp>

#include "particlebody.hpp"

namespace yage
{

class RigidBody : public ParticleBody
{
public:
	RigidBody(const glm::vec2 &position=glm::vec2(0.f, 0.f),
	          double mass=1.0,
 	          const glm::vec2 &velocity=glm::vec2(0.f, 0.f),
	          bool gravity=true);
};

} // yage

#endif
