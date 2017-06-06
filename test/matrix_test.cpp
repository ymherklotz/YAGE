#include "Math/matrix.hpp"

#include <iostream>

int main()
{
	yage::Matrix<4, 4, int> matrix;

	int x=matrix[2][2];
	
	std::cout<<"at: "<<x<<'\n';
	return 0;
}
