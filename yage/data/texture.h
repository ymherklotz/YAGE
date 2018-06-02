/** ---------------------------------------------------------------------------
 * -*- c++ -*-
 * @file: texture.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#pragma once

#include <glad/glad.h>

namespace yage
{

struct Texture {
    GLuint id;
    int width;
    int height;
    int x;
    int y;

    Texture() : id(0), width(0), height(0), x(0), y(0) {}

    Texture(GLuint id_i, int width_i, int height_i, int x_i = 1, int y_i = 1)
        : id(id_i), width(width_i), height(height_i), x(x_i), y(y_i)
    {
    }
};

} // namespace yage
