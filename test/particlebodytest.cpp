/* ----------------------------------------------------------------------------
 * rigidbodytest.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com> -- MIT License
 * See file LICENSE for more details
 * ----------------------------------------------------------------------------
 */

#include <cmath>
#include <cstdlib>

#include "Physics/particlebody.hpp"
#include "gtest/gtest.h"

double gravityAcceleration(int iterations) {
    yage::ParticleBody body;
    for (int i = 0; i < 60 * iterations; ++i) {
        body.update();
    }

    return body.yPosition();
}

// Tests

TEST(ParticleBody, Gravity) {
    int random_itr = rand() % 25;
    double idealPosition = 0.5 * -9.81 * std::pow(random_itr, 2);

    ASSERT_GE(idealPosition * 0.95, gravityAcceleration(random_itr));
    ASSERT_LE(idealPosition * 1.05, gravityAcceleration(random_itr));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    srand(static_cast<unsigned>(time(nullptr)));
    return RUN_ALL_TESTS();
}
