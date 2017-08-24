/* ----------------------------------------------------------------------------
 * yagetest.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com> -- MIT License
 * See file LICENSE for more details
 * ----------------------------------------------------------------------------
 */

#include "gtest/gtest.h"

#include "yage.hpp"

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
