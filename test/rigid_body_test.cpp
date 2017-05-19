#include "particlebody.hpp"

#include <iostream>

int main(int, char**)
{
	yage::ParticleBody body;
	for(int i=0; i<60*3; ++i)
	{
		body.update();
		std::cout<<"position: "<<body.xPosition()<<", "<<body.yPosition()<<"\n";
	}

	double ideal_position=0.5*-9.81*3*3;

	if(body.yPosition()<ideal_position*0.95 && body.yPosition()>ideal_position*1.05)
		return 0;
	return 1;
}
