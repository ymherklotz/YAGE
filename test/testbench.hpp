/*
 * created 22-06-17 by Yann Herklotz
 *
 * Test bench to test different functions in the yage library
 *
 */

#ifndef TEST_BENCH_HPP
#define TEST_BENCH_HPP

#include <string>
#include <vector>

struct Test
{
	std::string name;
	bool passed;

	Test(const std::string &_name, bool _passed) : name(_name), passed(_passed) {}
};

class TestBench
{
private:
	int incrementer=0;
	int passed=0;
	int failed=0;

	std::vector<Test> tests_;
	
public:
	TestBench() : tests_() {}

	void startTest(const std::string &test_name);
	void endTest(bool pass);
	void printResults();
};

#endif
