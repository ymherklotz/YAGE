#include <yage.cpp>

using namespace yage;

int main()
{
    Window window;

    window.create("Simple Game", 800, 640);

    while(!window.shouldClose()) {
        window.clearBuffer();

        SpriteBatch sp;
        sp.begin();

        window.pollEvents();
        window.swapBuffer();
    }
}
