/* ----------------------------------------------------------------------------
 * spritesheettest.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */



/** @file */

#include <gtest/gtest.h>
#include <yage/yage.h>

using namespace yage;

TEST(SpriteSheet, Load)
{
    /// @todo add a test to test the spritesheet loading
    ASSERT_TRUE(true);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
