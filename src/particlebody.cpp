#include "Physics/particlebody.hpp"

#include <cmath>

namespace yage
{

ParticleBody::ParticleBody(const Vector2d &position,
                           double mass,
                           const Vector2d &velocity,
                           bool gravity) :
	Body(position, mass, velocity, gravity)
{}

void ParticleBody::applyForce(const Vector2d &force)
{
	force_+=force;
}

void ParticleBody::update()
{
	// set the time_step for 60fps
	double time_step=1.0/60.0;

	// set the last acceleration
	Vector2d last_acceleration=acceleration_;

	// update the position of the body
	//position_.x+=velocity_.x*time_step+(0.5*last_acceleration.x*std::pow(time_step, 2));
	//position_.y+=velocity_.y*time_step+(0.5*last_acceleration.y*std::pow(time_step, 2));

	position_+=velocity_*time_step+(0.5*last_acceleration*std::pow(time_step, 2));

	// update the acceleration
	if(gravity_)
		acceleration_=Vector2d(force_.x()/mass_, (GRAVITY+force_.y())/mass_);
	else
		acceleration_=Vector2d(force_.x()/mass_, force_.y()/mass_);	

	Vector2d avg_acceleration=(acceleration_+last_acceleration)/2.0;

	// update the velocity of the body
	velocity_=avg_acceleration*time_step;
}

} // yage
