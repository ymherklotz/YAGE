#ifndef YAGE_BODY_HPP
#define YAGE_BODY_HPP

#include <glm/glm.hpp>

namespace yage
{

class Body
{
public:
	// gravity constant
	static const double GRAVITY;	
protected:
	// center of mass of the object
	glm::vec2 position_=glm::vec2(0.f, 0.f);

	// mass of the object
    double mass_=1.0;
	
	// current velocity of the object
	glm::vec2 velocity_=glm::vec2(0.f, 0.f);

	// boolean that defines if gravity can act on the object
	bool gravity_=true;
	
	// current acceleration
	glm::vec2 acceleration_=glm::vec2(0.f, 0.f);

	// force acting on the body
	glm::vec2 force_=glm::vec2(0.f, 0.f);
	
public:
	virtual ~Body();

	// apply force to the object and update the velocity
	virtual void applyForce(const glm::vec2 &force)=0;
	virtual void update()=0;

	float xPosition() const;
	float yPosition() const;
protected:
	// protected constructor to initialize member variables
	Body(const glm::vec2 &position=glm::vec2(0.f, 0.f),
	     double mass=1.0,
	     const glm::vec2 &velocity=glm::vec2(0.f, 0.f),
	     bool gravity=false);
};

} // yage

#endif
