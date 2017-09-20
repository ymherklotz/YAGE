/* ----------------------------------------------------------------------------
 * yagetest.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com> -- MIT License
 * See file LICENSE for more details
 * ----------------------------------------------------------------------------
 */

#include <yage/yage.h>
#include <gtest/gtest.h>

TEST(YAGE, InitQuit)
{
    try {
        yage::init();
        yage::quit();
    } catch(std::runtime_error e) {
        ASSERT_TRUE(false);
    }
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
