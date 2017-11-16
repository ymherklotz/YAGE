#include <yage.h>

#include <iostream>

using namespace yage;

void print_random()
{
    std::cout << "hello world"
              << "\n";
}

void print_h()
{
    std::cout << "Helllllllo"
              << "\n";
}

void flush()
{
    std::cout << "flush" << std::endl;
}

int main()
{
    auto a = Active::create();

    a->send(print_random);
    a->send(print_h);
    a->send(flush);

    std::cout << std::endl;

    for (int i = 0; i < 1000000; i++) {
    }

    std::cout << std::endl;
}
