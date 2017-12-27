/** ---------------------------------------------------------------------------
 * @file: simplegame.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#include <yage.cpp>

#include <iostream>

using std::cout;

using namespace yage;

int main()
{
    Window window;
    window.create("Simple Game", 800, 640);

    Shader textureProgram("examples/resources/learnopenglshader.vert",
                          "examples/resources/learnopenglshader.frag");
    SpriteBatch sp;

    Texture fountain = ResourceManager::getTexture(
        "examples/resources/dngn_blood_fountain.png");
    Texture breast_plate =
        ResourceManager::getTexture("examples/resources/breast_black.png");

    Texture brick = ResourceManager::getTexture("examples/resources/wall.png");

    cout << "texture: " << brick.width << ", " << brick.height << '\n';

    Camera camera(800, 640);
    textureProgram.use();
    textureProgram.setUniform("ourTexture", 0);

    while (!window.shouldClose()) {
        window.clearBuffer();
        Texture texture = fountain;

        window.pollEvents();
        if (window.keyPressed(yage::key::SPACE)) {
            cout << "Pressed A" << '\n';
        }
        if (window.keyPressed(yage::key::E)) {
            texture = breast_plate;
        }

        sp.draw({-0.5, -0.5, 1, 1}, {0, 0, 1, 1}, brick.id, Colour(255, 255, 255, 255), 0);

        sp.render();

        window.swapBuffer();
    }
}
