#include "vector2d.hpp"

#include <iostream>

int main()
{
	yage::Vector2D v;
	yage::Vector2D v2(1, 5);

	v=v2;

	std::cout<<v<<'\n';

	return 0;
}
