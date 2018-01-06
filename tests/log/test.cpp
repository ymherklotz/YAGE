/** ---------------------------------------------------------------------------
 * @file: test.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#include <yage.h>

#include <iostream>

int main()
{
    yLogError << "First message";

    yLogError << "Second Message";
    std::cout << "COUT\n";
}
