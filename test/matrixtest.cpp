/*
 * created 22-06-17 by Yann Herklotz
 *
 * Tests the math class using different tests to see if matrix operations work 
 * correctly.
 *
 */

#include "Math/math.hpp"

#include "testbench.hpp"

void test(TestBench &tb, const std::string &test_name, bool result)
{
	tb.startTest(test_name);
	tb.endTest(result);
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
	m1[1][1] = 293;
	m2[1][1] = 583;

	yage::Matrix<4, 4, int> m3 = m1 + m2;

	return m3[1][1] == 876;
}

int main()
{
	TestBench tb;

	test(tb, "Matrix Assign", matrixAssign());
	test(tb, "Matrix Addition", matrixAddition());
	
	tb.printResults();
	return 0;
}
