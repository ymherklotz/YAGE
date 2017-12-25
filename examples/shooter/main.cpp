#include <yage/yage.h>

#include <iostream>

using std::cout;

int main(int argc, char** argv)
{
    cout << "Starting Shooter example...\n";

    yage::Window window;
    window.create("Shooter example", 1920, 1080);

    while(!window.shouldClose()) {
        window.pollEvents();
        window.clearBuffer();

        

        window.swapBuffer();
    }
}
