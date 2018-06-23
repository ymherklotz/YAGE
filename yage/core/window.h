/** ---------------------------------------------------------------------------
 * -*- c++ -*-
 * @file: window.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#pragma once

#include <string>

class GLFWwindow;

namespace yage
{

enum class key;

// window flags that can change it's appearance
enum WindowFlags : unsigned {
    SHOWN      = 0x1,
    HIDDEN     = 0x2,
    FULLSCREEN = 0x4,
    BORDERLESS = 0x8,
};

// window wrapper around GLFWwindow pointer
class Window
{
private:
    /// window handle
    GLFWwindow *window_ = nullptr;

public:
    Window()               = default;
    Window(Window const &) = delete;
    Window(Window &&)      = delete;
    /// destroys the window handle
    ~Window();

    Window &operator=(Window const &) = delete;
    Window &operator=(Window &&) = delete;

    /// create the window, initialize the handle and update the width and height
    void create(std::string window_name, int width, int height);
    /// swap the buffer
    void swapBuffer();
    /// clear buffer
    void clearBuffer();
    /// hide windowProc
    void hide();
    /// show window
    void show();
    bool shouldClose();
    void pollEvents() const;

    bool keyPressed(key k) const;
};

} // namespace yage
