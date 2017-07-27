/* ----------------------------------------------------------------------------
 * testbench.hpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com> -- MIT License
 * See file LICENSE for more details
 * ----------------------------------------------------------------------------
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
