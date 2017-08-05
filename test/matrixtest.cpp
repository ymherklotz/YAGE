/* ----------------------------------------------------------------------------
 * matrixtest.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com> -- MIT License
 * See file LICENSE for more details
 * ----------------------------------------------------------------------------
 */

#include "Math/math.hpp"

#include "gtest/gtest.h"

int matrixAssign(int number)
{
	yage::Matrix<4, 5, int> m;
	m[2][3]=number;

	return m[2][3];
}

int matrixAddition(int num1, int num2)
{
	yage::Matrix<4, 4, int> m1, m2;
	m1[1][1]=num1;
	m2[1][1]=num2;

	yage::Matrix<4, 4, int> m3=m1+m2;

	return m3[1][1];
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
	return false;
}

// TESTS

TEST(Matrix, Assign)
{
	ASSERT_EQ(29348, matrixAssign(29348));
}

TEST(Matrix, Addition)
{
	ASSERT_EQ(5793+2389, matrixAddition(5793, 2389));
}

TEST(Matrix, DotProduct)
{
	ASSERT_TRUE(vectorDotProduct());
}

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
