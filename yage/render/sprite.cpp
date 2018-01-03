/** ---------------------------------------------------------------------------
 * @file: sprite.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#include "sprite.h"
#include "../core/resourcemanager.h"
#include "../data/vertex.h"

#include <cstddef>

namespace yage
{

Sprite::~Sprite()
{
    if (vbo_id_ != 0) {
        glDeleteBuffers(1, &vbo_id_);
    }
}

void Sprite::init(float x, float y, float width, float height,
                  const std::string &texture_path)
{
    x_       = x;
    y_       = y;
    width_   = width;
    height_  = height;
    texture_ = ResourceManager::getTexture(texture_path);

    if (vbo_id_ == 0) {
        glGenBuffers(1, &vbo_id_);
    }

    Vertex vertex_data[6];

    vertex_data[0].setPosition(x + width, y + height);
    vertex_data[0].setUv(1.f, 1.f);

    vertex_data[1].setPosition(x, y + height);
    vertex_data[1].setUv(0.f, 1.f);

    vertex_data[2].setPosition(x, y);
    vertex_data[2].setUv(0.f, 0.f);

    vertex_data[3].setPosition(x, y);
    vertex_data[3].setUv(0.f, 0.f);

    vertex_data[4].setPosition(x + width, y + height);
    vertex_data[4].setUv(1.f, 1.f);

    vertex_data[5].setPosition(x + width, y);
    vertex_data[5].setUv(1.f, 0.f);

    for (auto &i : vertex_data) {
        i.setColour(255, 0, 255, 255);
    }

    vertex_data[1].setColour(0, 255, 255, 255);
    vertex_data[4].setColour(255, 0, 0, 255);

    glBindBuffer(GL_ARRAY_BUFFER, vbo_id_);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_data), vertex_data,
                 GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Sprite::draw()
{
    glBindTexture(GL_TEXTURE_2D, texture_.id);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_id_);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                          (void *)offsetof(Vertex, position));
    glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex),
                          (void *)offsetof(Vertex, colour));
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                          (void *)offsetof(Vertex, uv));
    glDrawArrays(GL_TRIANGLES, 0, 6);

    glDisableVertexAttribArray(2);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

} // namespace yage