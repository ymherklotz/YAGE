/* ----------------------------------------------------------------------------
 * texture.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com> -- MIT License
 * See file LICENSE for more details
 * ----------------------------------------------------------------------------
 */

#ifndef GL_TEXTURE_H
#define GL_TEXTURE_H

#include <glad/glad.h>

namespace yage
{

struct Texture {
    GLuint id;
    int width;
    int height;

    Texture(GLuint id_i, int width_i, int height_i)
        : id(id_i), width(width_i), height(height_i)
    {
    }
};

} // namespace yage

#endif
