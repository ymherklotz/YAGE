/* ----------------------------------------------------------------------------
 * texture.hpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com> -- MIT License
 * See file LICENSE for more details
 * ----------------------------------------------------------------------------
 */

#ifndef GL_TEXTURE_HPP
#define GL_TEXTURE_HPP

#include <GL/glew.h>

namespace yage {

struct Texture {
    GLuint id;
    int width;
    int height;
};

}  // yage

#endif
