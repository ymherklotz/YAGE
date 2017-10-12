/* ----------------------------------------------------------------------------
 * vector3test.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#include <gtest/gtest.h>
#include <yage/yage.h>

#include <ctime>
#include <cstdlib>

using namespace yage;

TEST(Vector4, Initialize)
{
    Vector3i vec{{rand(), rand(), rand()}};
    ASSERT_EQ(vec.x, vec[0]);
    ASSERT_EQ(vec.y, vec[1]);
    ASSERT_EQ(vec.z, vec[2]);
}

TEST(Vector3, Assigning)
{
    Vector3i vec{{rand(), rand(), rand()}};
    ASSERT_EQ(vec.x, vec[0]);
    vec.x = rand();
    ASSERT_EQ(vec.x, vec[0]);
    vec[0] = rand();
    ASSERT_EQ(vec.x, vec[0]);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    srand(time(nullptr));
    return RUN_ALL_TESTS();
}
