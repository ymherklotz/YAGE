#ifndef YAGE_MATH_VECTOR2D_HPP
#define YAGE_MATH_VECTOR2D_HPP

#include "vector.hpp"

namespace yage
{

class Vector2D : public Vector
{
public:
	Vector2D(long double x=0.L, long double y=0.L);

	long double getX() const;
	long double getY() const;
};

} // yage

#endif
