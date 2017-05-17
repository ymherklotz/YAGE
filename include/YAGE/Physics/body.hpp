#ifndef YAGE_BODY_HPP
#define YAGE_BODY_HPP

#include <glm/glm.hpp>

namespace yage
{

class Body
{
protected:
	// current force acting on object
	glm::vec2 force_;

	// current acceleration
	glm::vec2 acceleration_=glm::vec2(0.f, 0.f);
	
	// current velocity of the object
	glm::vec2 velocity_;

	// center of mass of the object
    glm::vec2 center_of_mass_;

	// mass of the object
    double mass_;

	// boolean that defines if gravity can act on the object
	bool gravity_;
    
public:
	virtual ~Body();

	// apply force to the object and update the velocity
	virtual void applyForce(const glm::vec2 &force)=0;
	virtual void update()=0;

	float xPosition() const;
	float yPosition() const;
protected:
	// protected constructor to initialize member variables
	Body(const glm::vec2 &center_of_mass, double mass, const glm::vec2 &force, const glm::vec2 &velocity, bool gravity);
};

} // yage

#endif
