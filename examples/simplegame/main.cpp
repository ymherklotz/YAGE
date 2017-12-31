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
    window.create("Simple Game", 1920, 1080);

    Shader textureProgram("examples/resources/textureshader.vert",
                          "examples/resources/textureshader.frag");
    SpriteBatch sp;

    Texture fountain = ResourceManager::getTexture(
        "examples/resources/dngn_blood_fountain.png");
    Texture breast_plate =
        ResourceManager::getTexture("examples/resources/breast_black.png");

    Texture brick = ResourceManager::getTexture("examples/resources/wall.png");

    cout << "texture: " << brick.width << ", " << brick.height << '\n';

    Camera camera(1920, 1080);
    textureProgram.use();
    textureProgram.setUniform("texture_sampler", 0);

    double prev_time  = glfwGetTime();
    double final_time = 0;
    double diff       = 0;
    double fps        = 0;
    int i             = 0;
    double time;

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

        camera.update(textureProgram);

        int amount = 5;
        time = glfwGetTime();
        for (int i = 0; i < 1920/amount; i++) {
            for(int j = 0; j < 1080/amount; j++)
                sp.draw({(float)(amount*i), (float)(amount*j), (float)amount, (float)amount}, {0.f, 0.f, 1.f, 1.f}, fountain.id,
                    Colour(255, 255, 255, 255), 0);
        }

        sp.draw({50, 50, 100, 100}, {0, 0, 1, 1}, brick.id, Colour(255, 255, 255, 255), 1);
        yLog << "draw: " << glfwGetTime() - time;

        time = glfwGetTime();
        sp.render();
        yLog << "render: " << glfwGetTime() - time;
        window.swapBuffer();

        if (i == 0) {
            final_time = glfwGetTime();
            diff       = final_time - prev_time;
            prev_time  = final_time;
            fps        = 1 / diff * 30;
            yLog << "fps: " << fps;
        }
        i = (i + 1) % 30;
    }
}
