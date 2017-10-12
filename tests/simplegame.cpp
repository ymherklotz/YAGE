#include <yage.cpp>

using namespace yage;

int main()
{
    Window window;

    window.create("Simple Game", 800, 640);

    while(!window.shouldClose()) {
        SpriteBatch sp;
        sp.begin();
        window.pollEvents();
    }
}
