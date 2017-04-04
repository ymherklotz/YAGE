#ifndef GL_TEXTURE_HPP
#define GL_TEXTURE_HPP

#include <GL/glew.h>

namespace yage
{

struct GlTexture
{
    GLuint id;
    int width;
    int height;
};
    
} // yage

#endif
