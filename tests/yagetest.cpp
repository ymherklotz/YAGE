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
    ASSERT_TRUE(yage::init());
    yage::quit();
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
