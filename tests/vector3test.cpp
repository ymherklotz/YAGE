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

TEST(Vector3, Initialize)
{
    Vector3i vec{{rand(), rand(), rand()}};
    ASSERT_EQ(vec.x, vec[0]);
    ASSERT_EQ(vec.y, vec[1]);
    ASSERT_EQ(vec.z, vec[2]);
}

TEST(Vector3, Assigning_x)
{
    Vector3i vec{{rand(), rand(), rand()}};
    ASSERT_EQ(vec.x, vec[0]);
    vec.x = rand();
    ASSERT_EQ(vec.x, vec[0]);
    vec[0] = rand();
    ASSERT_EQ(vec.x, vec[0]);
}

TEST(Vector3, Assigning_y)
{
    Vector3i vec{{rand(), rand(), rand()}};
    ASSERT_EQ(vec.y, vec[1]);
    vec.x = rand();
    ASSERT_EQ(vec.y, vec[1]);
    vec[1] = rand();
    ASSERT_EQ(vec.y, vec[1]);
}

TEST(Vector3, Assigning_z)
{
    Vector3i vec{{rand(), rand(), rand()}};
    ASSERT_EQ(vec.z, vec[2]);
    vec.z = rand();
    ASSERT_EQ(vec.z, vec[2]);
    vec[2] = rand();
    ASSERT_EQ(vec.z, vec[2]);
}

TEST(Vector3, Addition)
{    
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    srand(time(nullptr));
    return RUN_ALL_TESTS();
}
