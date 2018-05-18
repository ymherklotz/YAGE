/** ---------------------------------------------------------------------------
 * @file: test.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#include <gtest/gtest.h>
#include <yage/yage.h>

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector>

// TESTS

TEST(Matrix, Assign)
{
    double rand_num = rand();
    yage::Matrix<5, 5, double> mat1;

    mat1[3][2] = rand_num;

    ASSERT_EQ(rand_num, mat1[3][2]);

    yage::Matrix<2, 2, double> mat2{{rand_num, rand_num, rand_num, rand_num}};

    ASSERT_EQ(rand_num, mat2[1][0]);
}

TEST(Matrix, Addition)
{
    int rand_x = rand();
    int rand_y = rand();
    yage::Matrix<5, 5, int> m1, m2;

    m1[2][4] = rand_x;
    m2[2][4] = rand_y;

    ASSERT_EQ(rand_x + rand_y, (m1 + m2)[2][4]);
}

TEST(Vector, DotProduct)
{
    std::vector<int> contents_i = {rand() % 100, rand() % 100, rand() % 100};
    std::vector<int> contents_j = {rand() % 100, rand() % 100, rand() % 100};
    yage::Vector<3, int> v1{contents_i};
    yage::Vector<3, int> v2{contents_j};

    int sum = 0;
    for (std::size_t i = 0; i < contents_i.size(); ++i) {
        sum += contents_i[i] * contents_j[i];
    }

    ASSERT_EQ(sum, yage::matrix::dot(v1, v2));
}

int main(int argc, char **argv)
{
    srand(static_cast<unsigned>(time(nullptr)));
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
