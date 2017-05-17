#include "Physics/rigidbody.hpp"

namespace yage
{

RigidBody::RigidBody(const glm::vec2 &center_of_mass, double mass, const glm::vec2 &force, const glm::vec2 &velocity, bool gravity) :
	Body(center_of_mass, mass, force, velocity, gravity)
{}

void RigidBody::applyForce(const glm::vec2 &force)
{
	force_+=force;
}

void RigidBody::update()
{
	// set the time_step for 60fps
	double time_step=1.0/60.0;

	// set the last acceleration
	glm::vec2 last_acceleration=acceleration_;

	// update the position of the body
	center_of_mass_.x+=velocity_.x*time_step+(0.5*last_acceleration.x*time_step*time_step);
	center_of_mass_.y+=velocity_.y*time_step+(0.5*last_acceleration.y*time_step*time_step);

	// update the acceleration
	acceleration_=glm::vec2(force_.x/mass_, force_.y/mass_);
	glm::vec2 avg_acceleration=glm::vec2((acceleration_.x+last_acceleration.x)/2,
	                                     (acceleration_.y+last_acceleration.y)/2);

	// update the velocity of the body
	velocity_.x+=avg_acceleration.x*time_step;
	velocity_.y+=avg_acceleration.y*time_step;
}

} // yage
