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
    yLogDebug << IoManager::parentDirectory(__FILE__) << '\n' << __FILE__;
    SpriteSheet sp(IoManager::parentDirectory(__FILE__), IoManager::parentDirectory(__FILE__));
    ASSERT_TRUE(true);
}

OPENGL_TEST_MAIN(LogLevel::DEBUG)
