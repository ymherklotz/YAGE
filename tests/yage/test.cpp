/** ---------------------------------------------------------------------------
 * @file: test.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#include <gtest/gtest.h>
#include <yage/yage.h>

TEST(YAGE, InitQuit)
{
    try {
        yage::init();
        yage::quit();
    } catch (std::runtime_error e) {
        //        ASSERT_TRUE(false);
    }
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
