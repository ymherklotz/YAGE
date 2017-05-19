#include <iostream>

int main()
{
	std::cout<<"Size of double: "<<sizeof(double)<<'\n';
	std::cout<<"Size of long double: "<<sizeof(long double)<<'\n';

	if(sizeof(long double) > 8)
		return 0;
	return 1;
}
