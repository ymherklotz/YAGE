#include "Physics/rigidbody.hpp"

namespace yage
{

RigidBody::RigidBody(const glm::vec2 &center_of_mass, double mass, const glm::vec2 &force, const glm::vec2 &velocity, bool gravity) :
	Body(center_of_mass, mass, force, velocity, gravity)
{}

void RigidBody::applyForce(const glm::vec2 &force)
{
	// set the time_step for 60fps
	double time_step=1.0/60.0;
	
	// a=F/m
	glm::vec2 acceleration((force_.x+force.x)/mass_, (force_.y+force.y)/mass_); // = a(t0)

	glm::vec2 intermediate_velocity=acceleration+glm::vec2(acceleration.x*time_step/2, acceleration.y*time_step/2);

	velocity_=acceleration+glm::vec2(intermediate_velocity.x*time_step, intermediate_velocity.y*time_step);
}

} // yage
