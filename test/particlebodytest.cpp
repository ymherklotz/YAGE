/* ----------------------------------------------------------------------------
 * rigidbodytest.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com> -- MIT License
 * See file LICENSE for more details
 * ----------------------------------------------------------------------------
 */

#include <YAGE/Physics/particlebody.h>
#include <gtest/gtest.h>

#include <cmath>
#include <cstdlib>

double gravityAcceleration(int iterations)
{
    yage::ParticleBody body;
    for (int i = 0; i < 60 * iterations; ++i) {
        body.update();
    }

    return body.yPosition();
}

// Tests

TEST(ParticleBody, Gravity)
{
    int randomItr = rand() % 10;
    double idealPosition = 0.5 * -9.81 * std::pow(randomItr, 2);

    ASSERT_GE(idealPosition * 0.95, gravityAcceleration(randomItr));
    ASSERT_LE(idealPosition * 1.05, gravityAcceleration(randomItr));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    srand(static_cast<unsigned>(time(nullptr)));
    return RUN_ALL_TESTS();
}
