/** ---------------------------------------------------------------------------
 * @file: test.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

/** ---------------------------------------------------------------------------
 * @file: test.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

/** ---------------------------------------------------------------------------
 * @file: test.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

/** ---------------------------------------------------------------------------
 * @file: test.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

/** ---------------------------------------------------------------------------
 * @file: test.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#include <gtest/gtest.h>
#include <yage/yage.h>

#include <cstdlib>
#include <ctime>

using namespace yage;

TEST(Vector4, Initialize)
{
    Vector4i vec{{rand(), rand(), rand(), rand()}};
    ASSERT_EQ(vec.x, vec[0]);
    ASSERT_EQ(vec.y, vec[1]);
    ASSERT_EQ(vec.z, vec[2]);
    ASSERT_EQ(vec.w, vec[3]);
}

TEST(Vector4, Assigning_x)
{
    Vector4i vec{{rand(), rand(), rand(), rand()}};
    vec.x = rand();
    ASSERT_EQ(vec.x, vec[0]);
    vec[0] = rand();
    ASSERT_EQ(vec.x, vec[0]);
}

TEST(Vector4, Assigning_y)
{
    Vector4i vec{{rand(), rand(), rand(), rand()}};
    vec.y = rand();
    ASSERT_EQ(vec.y, vec[1]);
    vec[1] = rand();
    ASSERT_EQ(vec.y, vec[1]);
}

TEST(Vector4, Assigning_z)
{
    Vector4i vec{{rand(), rand(), rand(), rand()}};
    vec.z = rand();
    ASSERT_EQ(vec.z, vec[2]);
    vec[2] = rand();
    ASSERT_EQ(vec.z, vec[2]);
}

TEST(Vector4, Assigning_w)
{
    Vector4i vec{{rand(), rand(), rand(), rand()}};
    vec.w = rand();
    ASSERT_EQ(vec.w, vec[3]);
    vec[3] = rand();
    ASSERT_EQ(vec.w, vec[3]);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    srand(time(nullptr));
    return RUN_ALL_TESTS();
}
