#include "Math/matrix.hpp"

#include <iostream>

int main()
{
	yage::Matrix<double, 10, 10> matrix;

	int x=matrix.get(5, 2);

	std::cout<<"at: "<<x<<'\n';
	return 0;
}
