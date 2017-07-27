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

#include "testbench.hpp"

#include <algorithm>
#include <stdexcept>

void TestBench::startTest(const std::string &test_name)
{
	incrementer++;

	Test test(test_name, false);

	tests_.push_back(test);
}

void TestBench::endTest(bool pass)
{
	incrementer--;

	if(incrementer!=0)
		throw std::runtime_error("Start and End don't match");

	if(pass) 
		passed++;
	else 
		failed++;

	tests_[passed+failed-1].passed=pass;
}

void TestBench::printResults()
{
	std::sort(tests_.begin(), tests_.end(), [] (const Test &a, const Test &b) {
			if(a.name<b.name)
				return true;
			return false;
		});
	
	printf("Results:\n");
	printf("+---------------------------+---------+\n");
	printf("| Test Name                 | Result  |\n");
	printf("+---------------------------+---------+\n");
	for(auto test : tests_)
	{
		std::string result;
		if(test.passed)
			result="PASS";
		else
			result="FAIL";

		char test_name[25];
		
		for(std::size_t i=0; i<25; ++i)
		{
			if(i<test.name.size())
				test_name[i]=test.name[i];
			else
				test_name[i]=' ';
		}
		
		printf("| %25.25s | %6s  |\n", test_name, result.c_str());
	}
	printf("+---------------------------+---------+\n");
	printf("\nSummary:\n");
	printf("+--------+--------+\n");
	printf("| Passed | %6d |\n", passed);
	printf("| Failed | %6d |\n", failed);
	printf("| Ratio  | %5.1f%% |\n", (float)passed/(float)(failed+passed) * 100.f);
	printf("+--------+--------+\n");
}
