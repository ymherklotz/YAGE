#include "Physics/body.hpp"

namespace yage
{

const double Body::GRAVITY=-9.81;

Body::~Body()
{}

float Body::xPosition() const
{
	return position_.x;
}

float Body::yPosition() const
{
	return position_.y;
}

Body::Body(const glm::vec2 &position, double mass, const glm::vec2 &velocity, bool gravity) :
	position_(position), mass_(mass), velocity_(velocity), gravity_(gravity)
{}

} // yage
