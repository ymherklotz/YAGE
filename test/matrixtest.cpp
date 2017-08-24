/* ----------------------------------------------------------------------------
 * matrixtest.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com> -- MIT License
 * See file LICENSE for more details
 * ----------------------------------------------------------------------------
 */

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector>

#include "Math/math.hpp"

#include "gtest/gtest.h"

template <int Size>
int matrixAssign(int number, int i, int j)
{
    yage::Matrix<Size, Size, int> m;
    m[j][i] = number;

    return m[j][i];
}

template <int Size>
int matrixAddition(int num1, int num2)
{
    yage::Matrix<Size, Size, int> m1, m2;
    m1[1][1] = num1;
    m2[1][1] = num2;

    yage::Matrix<Size, Size, int> m3 = m1 + m2;

    return m3[1][1];
}

int vectorDotProduct(const std::vector<int> &vec_contents_f,
                     const std::vector<int> &vec_contents_s)
{
    yage::Vector<3, int> v1(vec_contents_f);
    yage::Vector<3, int> v2(vec_contents_s);

    int x = yage::matrix::dot(v1, v2);

    return x;
}

bool matrixMultiplication()
{
    return false;
}

// TESTS

TEST(Matrix, Assign)
{
    int rand_num = rand();
    ASSERT_EQ(rand_num, matrixAssign<10>(rand_num, 4, 2));
}

TEST(Matrix, Addition)
{
    int rand_x = rand();
    int rand_y = rand();
    ASSERT_EQ(rand_x + rand_y, matrixAddition<10>(rand_x, rand_y));
}

TEST(Vector, DotProduct)
{
    std::vector<int> contents_i = {rand() % 100, rand() % 100, rand() % 100};
    std::vector<int> contents_j = {rand() % 100, rand() % 100, rand() % 100};
    int sum = 0;
    for (std::size_t i = 0; i < contents_i.size(); ++i) {
        sum += contents_i[i] * contents_j[i];
    }
    ASSERT_EQ(sum, vectorDotProduct(contents_i, contents_j));
}

int main(int argc, char **argv)
{
    srand(static_cast<unsigned>(time(nullptr)));
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
