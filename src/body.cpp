#include "Physics/body.hpp"

namespace yage
{

const double Body::GRAVITY=-9.81;

Body::~Body()
{}

double Body::xPosition() const
{
	return position_[0];
}

double Body::yPosition() const
{
	return position_[1];
}

Body::Body(const Vector2d &position, double mass, const Vector2d &velocity, bool gravity) :
	position_(position), mass_(mass), velocity_(velocity), gravity_(gravity)
{}

} // yage
