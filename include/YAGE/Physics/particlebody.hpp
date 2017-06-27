#ifndef YAGE_PARTICLE_BODY_HPP
#define YAGE_PARTICLE_BODY_HPP

#include "Math/matrix.hpp"

#include "body.hpp"

namespace yage
{

class ParticleBody : public Body
{
public:
	ParticleBody(const Vector2d &position=Vector2d(0.f, 0.f),
	             double mass=1.0,
	             const Vector2d &velocity=Vector2d(0.f, 0.f),
	             bool gravity=true);

	// apply a force to the rigid body
	virtual void applyForce(const Vector2d &force);
	virtual void update();
};

} // yage

#endif
