/* ----------------------------------------------------------------------------
 * rigidbodytest.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com> -- MIT License
 * See file LICENSE for more details
 * ----------------------------------------------------------------------------
 */

#include "Physics/particlebody.hpp"

#include <iostream>

int main(int, char**) {
    yage::ParticleBody body;
    for (int i = 0; i < 60 * 3; ++i) {
        body.update();
        std::cout << "position: " << body.xPosition() << ", "
                  << body.yPosition() << "\n";
    }

    double ideal_position = 0.5 * -9.81 * 3 * 3;

    std::cout << "Ideal Position: " << ideal_position << "\n";

    if (body.yPosition() < ideal_position * 0.95 &&
        body.yPosition() > ideal_position * 1.05)
        return 0;
    return 1;
}
