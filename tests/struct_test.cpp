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

TEST(StructTest, ColourDefault)
{
    yage::Colour c;
    ASSERT_EQ(c.r, 0);
    ASSERT_EQ(c.g, 0);
    ASSERT_EQ(c.b, 0);
    ASSERT_EQ(c.a, 0);
}

TEST(StructTest, ColourConstructor)
{
    int r = rand() % 255, g = rand() % 255, b = rand() % 255, a = rand() % 255;
    yage::Colour c(r, g, b, a);

    ASSERT_EQ(c.r, r);
    ASSERT_EQ(c.g, g);
    ASSERT_EQ(c.b, b);
    ASSERT_EQ(c.a, a);
}

TEST(StructTest, TextureDefault)
{
    yage::Texture t;
    ASSERT_EQ(t.id, static_cast<unsigned>(0));
    ASSERT_EQ(t.width, 0);
    ASSERT_EQ(t.height, 0);
}

TEST(StructTest, TextureConstructor)
{
    int id = rand(), width = rand(), height = rand();
    yage::Texture t(static_cast<unsigned>(id), width, height);
    ASSERT_EQ(t.id, static_cast<unsigned>(id));
    ASSERT_EQ(t.width, width);
    ASSERT_EQ(t.height, height);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    srand(static_cast<unsigned>(time(nullptr)));
    return RUN_ALL_TESTS();
}
