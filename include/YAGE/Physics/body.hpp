#ifndef YAGE_BODDY_HPP
#define YAGE_BODDY_HPP

#include <glm/glm.hpp>

namespace yage
{

class Body
{
protected:
	// current force acting on object
	glm::vec2 force_;
	// current velocity of the object
	glm::vec2 velocity_;

	// center of mass of the object
    glm::vec2 center_of_mass_;

	// mass of the object
    double mass_;

	// boolean that defines if gravity can act on the object
	bool gravity_;
    
public:
	virtual ~Body() {}

	// apply force to the object and update the velocity
	virtual void applyForce(const glm::vec2 &force)=0;
protected:
	// protected constructor to initialize member variables
	Body(const glm::vec2 &center_of_mass, double mass, const glm::vec2 &force, const glm::vec2 &velocity, bool gravity) :
		force_(force), velocity_(velocity), center_of_mass_(center_of_mass),
		mass_(mass), gravity_(gravity)
	{}
};

} // yage

#endif
