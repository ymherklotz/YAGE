/*
 * created 22-06-17 by Yann Herklotz
 *
 * Tests the math class using different tests to see if matrix operations work 
 * correctly.
 *
 */

#include "Math/math.hpp"

#include "testbench.hpp"

int main()
{
	TestBench tb;
	tb.startTest("Hello");
	tb.endTest(true);
	tb.startTest("Bye");
	tb.endTest(true);

	tb.printResults();
	return 0;
}
