#include "Physics/body.hpp"

namespace yage
{

Body::~Body()
{}

Body::Body(const glm::vec2 &center_of_mass, double mass, const glm::vec2 &force, const glm::vec2 &velocity, bool gravity) :
	force_(force), velocity_(velocity), center_of_mass_(center_of_mass),
	mass_(mass), gravity_(gravity)
{}

float Body::xPosition() const
{
	return center_of_mass_.x;
}

float Body::yPosition() const
{
	return center_of_mass_.y;
}

} // yage
