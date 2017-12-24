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
    GlslProgram textureProgram;

    window.create("Simple Game", 800, 640);
    SpriteBatch sp;

    textureProgram.compileShadersFromFile("examples/resources/textureshader.vert",
                                   "examples/resources/textureshader.frag");
    textureProgram.linkShaders();

    Texture fountain = ResourceManager::getTexture(
        "examples/resources/dngn_blood_fountain.png");
    Texture breast_plate =
        ResourceManager::getTexture("examples/resources/breast_black.png");

    cout << "texture: " << fountain.width << ", " << fountain.height << '\n';

    Camera camera(800, 640);

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

        textureProgram.use();
        camera.update(textureProgram);

        glActiveTexture(GL_TEXTURE0);

        GLint texture_location = textureProgram.getUniformLocation("texture_sampler");
        glUniform1i(texture_location, 0);

        sp.draw({0.f, 0.f, 64.f, 64.f}, {0, 0, 1, 1}, texture.id,
                Colour(255, 0, 255, 255), 0);
        sp.render();

        glBindTexture(GL_TEXTURE_2D, 0);
        textureProgram.unuse();

        window.swapBuffer();
    }
}
