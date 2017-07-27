/* ------------------------------------------------------------------------------
 * MIT License
 *
 * Copyright (c) 2017 Yann Herklotz Grave
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * ------------------------------------------------------------------------------
 * Description: 
 *
 * Tests the math class using different tests to see if matrix operations work 
 * correctly.
 * ------------------------------------------------------------------------------
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

	bool all_passed=false;

	try
	{
		test(tb, "Matrix Assign", matrixAssign());
	}
	catch(std::exception e)
	{
		std::cout<<e.what()<<'\n';
	}

	try
	{
		test(tb, "Matrix Addition", matrixAddition());
	}
	catch(std::exception e)
	{
		std::cout<<e.what()<<'\n';
	}

	try
	{
		test(tb, "Vector Dot Product", vectorDotProduct());
	}
	catch(std::string e)
	{
		std::cout<<e<<'\n';
	}
	
	tb.printResults();
	return all_passed;
}
