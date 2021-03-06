/** ---------------------------------------------------------------------------
 * -*- c++ -*-
 * @file: spritebatch.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#include "spritebatch.h"

#include "../core/logger.h"
#include <algorithm>
#include <stdexcept>

#include <GLFW/glfw3.h>

namespace yage
{

const int SpriteBatch::NUM_VERTICES;

SpriteBatch::SpriteBatch() : vao_(0), vbo_(0)
{
    glGenVertexArrays(1, &vao_);
    if (vao_ == 0) {
        throw std::runtime_error("failed to generate VAO");
    }
    // bind vertex array object
    glBindVertexArray(vao_);

    glGenBuffers(1, &vbo_);
    if (vbo_ == 0) {
        throw std::runtime_error("failed to generate VBO");
    }
    // bind vertex buffer object
    glBindBuffer(GL_ARRAY_BUFFER, vbo_);

    // set the vertex attribute pointers
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                          (void *)offsetof(Vertex, position));
    glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex),
                          (void *)offsetof(Vertex, colour));
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                          (void *)offsetof(Vertex, uv));

    // enable vertex attribute arrays
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
}

SpriteBatch::~SpriteBatch()
{
    if (vbo_ != 0) {
        glDeleteBuffers(1, &vbo_);
    }
    if (vao_ != 0) {
        glDeleteVertexArrays(1, &vao_);
    }
}

void SpriteBatch::begin()
{
    glyphs_.clear();
    glyph_ptrs_.clear();
    render_batches_.clear();
}

void SpriteBatch::end()
{
    sortGlyphs();
    createRenderBatches();
}

void SpriteBatch::draw(const glm::vec4 &destination_rect,
                       const glm::vec4 &uv_rect, GLuint texture,
                       const Colour &colour, float depth)
{
    Vertex top_left, top_right, bottom_right, bottom_left;

    top_left.colour = colour;
    top_left.setPosition(destination_rect.x,
                         destination_rect.y + destination_rect.w);
    top_left.setUv(uv_rect.x, uv_rect.y + uv_rect.w);

    top_right.colour = colour;
    top_right.setPosition(destination_rect.x + destination_rect.z,
                          destination_rect.y + destination_rect.w);
    top_right.setUv(uv_rect.x + uv_rect.z, uv_rect.y + uv_rect.w);

    bottom_right.colour = colour;
    bottom_right.setPosition(destination_rect.x + destination_rect.z,
                             destination_rect.y);
    bottom_right.setUv(uv_rect.x + uv_rect.z, uv_rect.y);

    bottom_left.colour = colour;
    bottom_left.setPosition(destination_rect.x, destination_rect.y);
    bottom_left.setUv(uv_rect.x, uv_rect.y);

    // deal with fragmenting by creating vector of pointers
    glyphs_.emplace_back(texture, depth, top_left, top_right, bottom_right,
                         bottom_left);
}

void SpriteBatch::render()
{
    glBindVertexArray(vao_);
    // sort and create render batches
    sortGlyphs();
    createRenderBatches();
    glActiveTexture(GL_TEXTURE0);
    for (auto &&batch : render_batches_) {
        yLogDebug << "Drawing " << batch.num_vertices
                  << " vertices bound to texture: " << batch.texture;
        glBindTexture(GL_TEXTURE_2D, batch.texture);
        glDrawArrays(GL_TRIANGLES, batch.offset, batch.num_vertices);
    }

    // clear and reset the vectors
    glyphs_.clear();
    glyph_ptrs_.clear();
    render_batches_.clear();
}

void SpriteBatch::createRenderBatches()
{
    std::vector<Vertex> vertices;
    if (glyph_ptrs_.empty()) {
        return;
    }

    vertices.reserve(glyph_ptrs_.size() * NUM_VERTICES);

    for (int i = 0; i < (int)glyph_ptrs_.size(); ++i) {
        if (i == 0 || (i > 0 && (glyph_ptrs_[i]->texture !=
                                 glyph_ptrs_[i - 1]->texture))) {
            render_batches_.emplace_back(i * NUM_VERTICES, NUM_VERTICES,
                                         glyph_ptrs_[i]->texture);

        } else {
            render_batches_.back().num_vertices += NUM_VERTICES;
        }

        vertices.push_back(glyph_ptrs_[i]->bottom_left);
        vertices.push_back(glyph_ptrs_[i]->top_left);
        vertices.push_back(glyph_ptrs_[i]->top_right);

        vertices.push_back(glyph_ptrs_[i]->top_right);
        vertices.push_back(glyph_ptrs_[i]->bottom_right);
        vertices.push_back(glyph_ptrs_[i]->bottom_left);
    }

    // orphan the buffer
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), nullptr,
                 GL_DYNAMIC_DRAW);
    glBufferSubData(GL_ARRAY_BUFFER, 0, vertices.size() * sizeof(Vertex),
                    vertices.data());
}

void SpriteBatch::sortGlyphs()
{
    glyph_ptrs_.reserve(glyphs_.size());
    for (auto &glyph : glyphs_) {
        glyph_ptrs_.push_back(&glyph);
    }

    // sort using introsort or quicksort
    std::sort(glyph_ptrs_.begin(), glyph_ptrs_.end(),
              [](details::Glyph *a, details::Glyph *b) -> bool {
                  if (a->depth == b->depth) {
                      return a->texture < b->texture;
                  }
                  return a->depth < b->depth;
              });
}

} // namespace yage
