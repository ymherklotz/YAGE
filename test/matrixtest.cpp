/* ----------------------------------------------------------------------------
 * matrixtest.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com> -- MIT License
 * See file LICENSE for more details
 * ----------------------------------------------------------------------------
 */

#include "Math/math.hpp"

#include "testbench.hpp"

void test(TestBench &tb, const std::string &test_name, bool result)
{
	tb.startTest(test_name);
	tb.endTest(result);
	if(!result)
	{
		throw std::runtime_error(test_name+" failed...");
	}
}

bool matrixAssign()
{
	yage::Matrix<4, 5, int> m;
	m[2][3]=5;

	return m[2][3]==5;
}

bool matrixAddition()
{
	yage::Matrix<4, 4, int> m1, m2;
	m1[1][1]=293;
	m2[1][1]=583;

	yage::Matrix<4, 4, int> m3=m1+m2;

	std::cout<<m3<<'\n';

	return m3[1][1]==876;
}

bool vectorDotProduct()
{
	yage::Vector<3, int> v1, v2;
	v1[0] = 2;
	v1[1] = 3;
	v1[2] = 5;
	v2[0] = 9;
	v2[1] = 6;
	v2[2] = 8;

	int x = yage::matrix::dot(v1, v2);

	return x==76;
}

bool matrixMultiplication()
{
	
}

int main()
{
	TestBench tb;

	bool all_passed=true;

	try{ test(tb, "Matrix Assign", matrixAssign()); }
	catch(std::exception e) { std::cout<<e.what()<<'\n'; }

	try{ test(tb, "Matrix Addition", matrixAddition()); }
	catch(std::exception e) { std::cout<<e.what()<<'\n'; }

	try{ test(tb, "Vector Dot Product", vectorDotProduct()); }
	catch(std::string e) { std::cout<<e<<'\n'; }
	
	tb.printResults();
	return all_passed;
}
