#include <gtest/gtest.h>
#include <yage/yage.h>

using namespace yage;

TEST(SpriteSheet, Load)
{
    yage::init();
    Window window;
    window.create("SpriteSheet test", 800, 640);
    window.hide();
    SpriteSheet("resources/floor_atlas.png", "resources/floor_atlas.json");
    yage::quit();
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
