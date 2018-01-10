/** ---------------------------------------------------------------------------
 * @file: rectangle.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#include "rectangle.h"

#include "../data/vertex.h"

#include <glad/glad.h>

#include <cstddef>

namespace yage
{

Rectangle::Rectangle(glm::vec4 position) : position_(position) {}

void Rectangle::render() const
{
    // create vertex array
    GLuint rect_vao, rect_vbo;

    // bind vertex array object
    glGenVertexArrays(1, &rect_vao);
    glBindVertexArray(rect_vao);

    // bind vertex buffer object
    glGenBuffers(1, &rect_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, rect_vbo);

    // enable vertex attribute arrays
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    // set the vertex attribute pointers
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                          (void *)offsetof(Vertex, position));

    glBindVertexArray(0);
}

} // namepsace yage
