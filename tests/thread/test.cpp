/** ---------------------------------------------------------------------------
 * @file: test.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#include <yage.h>

#include <iostream>
#include <thread>

int main()
{
    int n = 5;

    std::cout << "n before: " << n << "\n";

    auto f = [&]() { n = 8; };

    std::thread t1(f);

    std::cout << "n after: " << n << "\n";

    t1.join();

    std::cout << "n after thread: " << n << "\n";
}
