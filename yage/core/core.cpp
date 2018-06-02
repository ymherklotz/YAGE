/** ---------------------------------------------------------------------------
 * -*- c++ -*-
 * @file: core.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#include "core.h"

#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>

namespace yage
{

void glfwErrorCallback(int, const char *description)
{
    std::cerr << "Error: " << description;
}

void init()
{
    glfwSetErrorCallback(glfwErrorCallback);
    if (glfwInit() == GLFW_FALSE) {
        throw std::runtime_error("GLFW couldn't be initialised");
    }
}

void quit()
{
    glfwTerminate();
}

} // namespace yage
