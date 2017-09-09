/* ----------------------------------------------------------------------------
 * spritebatch.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com> -- MIT License
 * See file LICENSE for more details
 * ----------------------------------------------------------------------------
 */

#include <YAGE/spritebatch.h>

#include <algorithm>
#include <stdexcept>

namespace yage
{

const int SpriteBatch::NUM_VERTICES;

Glyph::Glyph(GLuint texture, float depth, const Vertex &top_left,
             const Vertex &top_right, const Vertex &bottom_right,
             const Vertex &bottom_left)
    : texture_(texture), depth_(depth), top_left_(top_left),
      top_right_(top_right), bottom_right_(bottom_right),
      bottom_left_(bottom_left)
{
}

RenderBatch::RenderBatch(GLint offset, GLsizei num_vertices, GLuint texture)
    : num_vertices_(num_vertices), offset_(offset), texture_(texture)
{
}

SpriteBatch::SpriteBatch() = default;

SpriteBatch::~SpriteBatch()
{
    if (vao_ != 0) {
        glDeleteVertexArrays(1, &vao_);
    }

    if (vbo_ != 0) {
        glDeleteVertexArrays(1, &vbo_);
    }
}

void SpriteBatch::init()
{
    createVertexArray();
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
                       const Color &color, float depth)
{
    Vertex top_left, top_right, bottom_right, bottom_left;

    top_left.color = color;
    top_left.setPosition(destination_rect.x,
                         destination_rect.y + destination_rect.w);
    top_left.setUv(uv_rect.x, uv_rect.y + uv_rect.w);

    top_right.color = color;
    top_right.setPosition(destination_rect.x + destination_rect.z,
                          destination_rect.y + destination_rect.w);
    top_right.setUv(uv_rect.x + uv_rect.z, uv_rect.y + uv_rect.w);

    bottom_right.color = color;
    bottom_right.setPosition(destination_rect.x + destination_rect.z,
                             destination_rect.y);
    bottom_right.setUv(uv_rect.x + uv_rect.z, uv_rect.y);

    bottom_left.color = color;
    bottom_left.setPosition(destination_rect.x, destination_rect.y);
    bottom_left.setUv(uv_rect.x, uv_rect.y);

    // deal with fragmenting by creating vector of pointers
    glyphs_.emplace_back(texture, depth, top_left, top_right, bottom_right,
                         bottom_left);
    glyph_ptrs_.push_back(&glyphs_.back());
}

void SpriteBatch::render()
{
    glBindVertexArray(vao_);
    for (auto &&batch : render_batches_) {
        glBindTexture(GL_TEXTURE_2D, batch.texture());
        glDrawArrays(GL_TRIANGLES, batch.offset(), batch.num_vertices());
    }
    glBindVertexArray(0);
}

void SpriteBatch::createVertexArray()
{
    if (vao_ == 0) {
        glGenVertexArrays(1, &vao_);
        if (vao_ == 0) {
            throw std::runtime_error("glGenVertexArrays failed");
        }
    }
    // bind vertex array object
    glBindVertexArray(vao_);

    if (vbo_ == 0) {
        glGenBuffers(1, &vbo_);
        if (vbo_ == 0) {
            throw std::runtime_error("glGenBuffers failed");
        }
    }
    // bind vertex buffer object
    glBindBuffer(GL_ARRAY_BUFFER, vbo_);

    // enable vertex attribute arrays
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);

    // set the vertex attribute pointers
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                          (void *)offsetof(Vertex, position));
    glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex),
                          (void *)offsetof(Vertex, color));
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                          (void *)offsetof(Vertex, uv));
    glDrawArrays(GL_TRIANGLES, 0, 6);

    // unbind vertex array object
    glBindVertexArray(0);
}

void SpriteBatch::createRenderBatches()
{
    std::vector<Vertex> vertices;
    if (glyph_ptrs_.empty()) {
        return;
    }

    render_batches_.reserve(glyph_ptrs_.size() * NUM_VERTICES);

    for (int i = 0; i < (int)glyph_ptrs_.size(); ++i) {
        if (i == 0 || (i > 0 && (glyph_ptrs_[i]->texture() !=
                                 glyph_ptrs_[i - 1]->texture()))) {
            render_batches_.emplace_back(i * NUM_VERTICES, NUM_VERTICES,
                                         glyph_ptrs_[i]->texture());
        } else {
            render_batches_.back().num_vertices_ += NUM_VERTICES;
        }

        vertices.push_back(glyph_ptrs_[i]->bottom_left());
        vertices.push_back(glyph_ptrs_[i]->top_left());
        vertices.push_back(glyph_ptrs_[i]->top_right());
        vertices.push_back(glyph_ptrs_[i]->bottom_left());
        vertices.push_back(glyph_ptrs_[i]->bottom_right());
        vertices.push_back(glyph_ptrs_[i]->top_right());

        // bind vbo
        glBindBuffer(GL_ARRAY_BUFFER, vbo_);
        // orphan the buffer
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), nullptr,
                     GL_DYNAMIC_DRAW);
        // upload the data
        glBufferSubData(GL_ARRAY_BUFFER, 0, vertices.size() * sizeof(Vertex),
                        vertices.data());
        // unbind buffer
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
}

void SpriteBatch::sortGlyphs()
{
    // sort using introsort or quicksort
    std::sort(glyph_ptrs_.begin(), glyph_ptrs_.end(),
              [](Glyph *a, Glyph *b) -> bool {
                  if (a->depth() == b->depth()) {
                      return a->texture() < b->texture();
                  }
                  return a->depth() < b->depth();
              });
}

} // namespace yage
