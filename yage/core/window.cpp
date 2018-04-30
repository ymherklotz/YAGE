/** ---------------------------------------------------------------------------
 * @file: window.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#include "window.h"
#include "../data/input.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <stdexcept>

using std::runtime_error;

namespace yage
{

namespace
{

void key_callback(GLFWwindow *window, int key, int scanCode, int action,
                  int mods)
{
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

} // namespace

Window::~Window()
{
    glfwDestroyWindow(window_);
}

void Window::create(std::string window_name, int width, int height)
{
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window_ =
        glfwCreateWindow(width, height, window_name.c_str(), nullptr, nullptr);

    if (window_ == nullptr) {
        throw runtime_error("GLFW Window creation failed");
    }

    // initialize the gl context
    glfwMakeContextCurrent(window_);

    // initialize glad
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    // set key callback
    glfwSetKeyCallback(window_, key_callback);
    // set resize callback
    glfwSetFramebufferSizeCallback(window_, framebuffer_size_callback);

    // set vsync on
    glfwSwapInterval(1);

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
    // set the clear colour to black
    glClearColor(0.18f, 0.18f, 0.18f, 1.f);
    // set the clear depth
    glClearDepth(1.f);
    // clears buffer with clear colour
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::hide()
{
    glfwHideWindow(window_);
}

void Window::show()
{
    glfwShowWindow(window_);
}

bool Window::shouldClose()
{
    return glfwWindowShouldClose(window_);
}

void Window::pollEvents() const
{
    glfwPollEvents();
}

bool Window::keyPressed(key k)
{
    if (window_ == nullptr) {
        throw runtime_error("Window is not initialized");
    }

    if (glfwGetKey(window_, static_cast<int>(k)) == GLFW_PRESS) {
        return true;
    }

    return false;
}

} // namespace yage
