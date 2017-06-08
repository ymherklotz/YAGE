#include "Math/matrix.hpp"

#include <iostream>

int main()
{
	yage::Matrix<4, 4, int> m1, m2;

	yage::Vector<2, int> v1, v2;

	yage::Vector2d v3;

	m1[0][1]=1;
	m2[1][1]=2;

	v1[0]=2;
	v1[1]=3;
	v2[0]=5;
	v2[1]=2;

	v2 += v1+v1;

	v3.x() = 2;
	v3.y() = 1;

	yage::matrix::multiply(m1, m2);

	std::cout<<m2<<'\n';
	std::cout<<v3<<'\n';

	return 0;
}
