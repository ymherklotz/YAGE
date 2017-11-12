#include <yage.cpp>

using namespace yage;

int main()
{
    Window window;
    SpriteBatch sp;
    GlslProgram program;

    window.create("Simple Game", 800, 640);
    sp.init();

    program.compileShaders("/home/yannherklotz/Github/YAGE/tests/resources/simplegame.vert", "/home/yannherklotz/Github/YAGE/tests/resources/simplegame.vert");
    program.addAttribute("vertex_position");
    program.addAttribute("vertex_color");
    program.addAttribute("vertex_uv");
    program.linkShaders();

    Texture fountain = ResourceManager::getTexture("/home/yannherklotz/Github/YAGE/tests/resources/dngn_blood_fountain.png");

    while(!window.shouldClose()) {
        window.clearBuffer();

        sp.begin();
        sp.draw(std::vector<float>({0, 0, 50, 50}), std::vector<float>({0, 0, 1, 1}), fountain.id, Color(), 0);
        sp.render();

        window.pollEvents();
        window.swapBuffer();
    }
}
