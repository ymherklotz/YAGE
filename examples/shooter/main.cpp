#include <yage/yage.h>

#include "glad/glad.h"

using std::cout;

int main(int argc, char **argv)
{
    yage::Window window;
    window.create("Shooter example", 800, 600);

    yage::Shader shader("examples/resources/textureshader.vert",
                        "examples/resources/textureshader.frag");

    while (!window.shouldClose()) {
        window.pollEvents();
        window.clearBuffer();

        window.swapBuffer();
    }
}
