/** ---------------------------------------------------------------------------
 * @file: test.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#include <gtest/gtest.h>
#include <yage/yage.h>

#include "../testshared.h"

using namespace yage;

TEST(SpriteSheet, Load)
{
    SpriteSheet sp("tests/spritesheet/floor_atlas.png", "tests/spritesheet/floor_atlas.json");
    ASSERT_TRUE(true);
}

OPENGL_TEST_MAIN(LogLevel::DEBUG)
