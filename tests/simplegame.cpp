/* ----------------------------------------------------------------------------
 * simplegame.cpp
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
    GlslProgram program;

    window.create("Simple Game", 800, 640);
    SpriteBatch sp;

    program.compileShaders(
        "/home/yannherklotz/Github/YAGE/resources/defaultshader.vert",
        "/home/yannherklotz/Github/YAGE/resources/defaultshader.frag");
    program.addAttribute("vertex_position");
    program.addAttribute("vertex_colour");
    program.addAttribute("vertex_uv");
    program.linkShaders();

    Texture fountain =
        ResourceManager::getTexture("/home/yannherklotz/Github/YAGE/tests/"
                                    "resources/dngn_blood_fountain.png");

    cout << "texture: " << fountain.width << ", " << fountain.height << '\n';

    Camera2D camera(800, 640);

    while (!window.shouldClose()) {
        window.clearBuffer();

        program.use();
        camera.update(program);

        glActiveTexture(GL_TEXTURE0);

        GLint texture_location = program.getUniformLocation("texture_sampler");
        glUniform1i(texture_location, 0);

        sp.draw({0.f, 0.f, 64.f, 64.f}, {0, 0, 1, 1}, fountain.id, Colour(), 0);
        sp.render();

        glBindTexture(GL_TEXTURE_2D, 0);
        program.unuse();

        window.pollEvents();
        window.swapBuffer();
    }
}
