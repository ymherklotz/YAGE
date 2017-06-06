#include "Math/matrix.hpp"

#include <iostream>

int main()
{
	yage::Matrix<4, 4> matrix;

	double x=matrix[2][2];
	matrix[2][2]=4;

	std::cout<<"at: "<<x<<", "<<matrix[2][2]<<'\n';

	if(matrix[2][2]==4 && x==0)
		return 0;
	return 1;
}
