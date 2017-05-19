#include "Physics/particlebody.hpp"

#include <cmath>

namespace yage
{

ParticleBody::ParticleBody(const glm::vec2 &position,
                           double mass,
                           const glm::vec2 &velocity,
                           bool gravity) :
	Body(position, mass, velocity, gravity)
{}

void ParticleBody::applyForce(const glm::vec2 &force)
{
	force_+=force;
}

void ParticleBody::update()
{
	// set the time_step for 60fps
	double time_step=1.0/60.0;

	// set the last acceleration
	glm::vec2 last_acceleration=acceleration_;

	// update the position of the body
	position_.x+=velocity_.x*time_step+(0.5*last_acceleration.x*std::pow(time_step, 2));
	position_.y+=velocity_.y*time_step+(0.5*last_acceleration.y*std::pow(time_step, 2));

	// update the acceleration
	if(gravity_)
		acceleration_=glm::vec2(force_.x/mass_, (GRAVITY+force_.y)/mass_);
	else
		acceleration_=glm::vec2(force_.x/mass_, force_.y/mass_);	

	glm::vec2 avg_acceleration=glm::vec2((acceleration_.x+last_acceleration.x)/2,
	                                     (acceleration_.y+last_acceleration.y)/2);

	// update the velocity of the body
	velocity_.x+=avg_acceleration.x*time_step;
	velocity_.y+=avg_acceleration.y*time_step;
}

} // yage
