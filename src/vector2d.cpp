#include "vector2d.hpp"

namespace yage
{

Vector2D::Vector2D(long double x, long double y) :
	Vector({ x, y })
{}

long double Vector2D::getX() const
{
	return (*this)[0];
}

long double Vector2D::getY() const
{
	return (*this)[1];
}

} // yage
