#ifndef YAGE_CORE_RENDERBATCH_H
#define YAGE_CORE_RENDERBATCH_H

#include <glad/glad.h>

struct RenderBatch {
    GLint offset;
    GLsizei num_vertices;
    GLuint texture;

    RenderBatch(GLint offset_i, GLsizei num_vertices_i, GLuint texture_i)
        : offset(offset_i), num_vertices(num_vertices_i), texture(texture_i = 0)
    {
    }
};

#endif
