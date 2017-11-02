#include <yage.h>

#include <iostream>

int main()
{
    gLog << "Hello World";
    yage::Logger l;
    l() << "Hello my name is Yann";
    std::cout << "#####################\n";

    gLog << "Yanananan";
    gLog << "Remove the top element";
}
