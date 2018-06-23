/** ---------------------------------------------------------------------------
 * -*- c++ -*-
 * @file: core.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#pragma once

/**
 * Project namespace.
 *
 * Avoids collision as all the classes and global functions are wrapped in.
 */
namespace yage
{

/**
 *
 */
extern void glfwErrorCallback(int, char const *);

/**
 * Initializes YAGE.
 *
 * This is there to initialize GLFW, which is the current
 * window manager that is used with OpenGL.
 */
extern void init();

/**
 * Quit and cleanup YAGE.
 *
 * This also cleans up GLFW after it was initialized.
 */
extern void quit();

} // namespace yage
