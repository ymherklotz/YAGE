/* ----------------------------------------------------------------------------
 * window.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com> -- MIT License
 * See file LICENSE for more details
 * ----------------------------------------------------------------------------
 */

#include "window.h"

#include <iostream>
#include <stdexcept>

namespace yage
{

Window::Window() = default;

Window::~Window()
{
    glfwDestroyWindow(window_);
}

void Window::create(const std::string &window_name, int width, int height,
                    unsigned flags)
{
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    window_ = glfwCreateWindow(width, height, window_name.c_str(), nullptr, nullptr);
    if (window_ == nullptr) {
        throw std::runtime_error("GLFW Window creation failed");
    }

    // initialize the gl context
    glfwMakeContextCurrent(window_);

    // print out the current OpenGL version to debug
    std::cout << "***  OpenGL version: " << glGetString(GL_VERSION)
              << "  ***\n";

    // set vsync on
    glfwSwapInterval(1);

    // set the clear color to black
    glClearColor(0.f, 0.5f, 0.f, 1.f);
    // set alpha blending
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void Window::swapBuffer()
{
    // swap the window buffer
    glfwSwapBuffers(window_);
}

void Window::clearBuffer()
{
    // set the clear depth
    glClearDepth(1.f);
    // clears buffer with clear color
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

} // namespace yage
