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
