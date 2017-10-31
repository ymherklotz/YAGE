/* ----------------------------------------------------------------------------
 * yage.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com> -- MIT License
 * See file LICENSE for more details
 * ----------------------------------------------------------------------------
 */

#include "yage.h"

#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>

namespace yage
{

void glfwErrorCallback(int, const char *description)
{
    std::cerr << "ERROR: %s\n" << description;
}

void init()
{
    glfwSetErrorCallback(glfwErrorCallback);
    if (!glfwInit()) {
        throw std::runtime_error("GLFW couldn't be initialised");
    }
}

void quit()
{
    glfwTerminate();
}

} // namespace yage
