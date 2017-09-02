/* ----------------------------------------------------------------------------
 * texture.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com> -- MIT License
 * See file LICENSE for more details
 * ----------------------------------------------------------------------------
 */

#ifndef GL_TEXTURE_H
#define GL_TEXTURE_H

#include <GL/glew.h>

namespace yage
{

struct Texture {
    GLuint id;
    int width;
    int height;
};

} // namespace yage

#endif
