/** ---------------------------------------------------------------------------
 * @file: spritebatch.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#ifndef YAGE_SPRITE_BATCH_H
#define YAGE_SPRITE_BATCH_H

#include "batch.h"
#include "../data/vertex.h"
#include "../data/renderbatch.h"

#include <glad/glad.h>
#include <glm/glm.hpp>

#include <vector>

namespace yage
{

class SpriteBatch;

/** Glyph with information of the texture.
 */
class Glyph
{
private:
    GLuint texture_;
    float depth_;
    Vertex top_left_;
    Vertex top_right_;
    Vertex bottom_right_;
    Vertex bottom_left_;

public:
    Glyph(GLuint texture, float depth, const Vertex &top_left,
          const Vertex &top_right, const Vertex &bottom_right,
          const Vertex &bottom_left);

    GLuint texture() const { return texture_; }
    float depth() const { return depth_; }
    Vertex top_left() const { return top_left_; }
    Vertex top_right() const { return top_right_; }
    Vertex bottom_right() const { return bottom_right_; }
    Vertex bottom_left() const { return bottom_left_; }
};


class SpriteBatch
{
public:
    static const int NUM_VERTICES = 6;

private:
    GLuint vbo_ = 0;
    GLuint vao_ = 0;
    std::vector<Glyph> glyphs_;
    std::vector<Glyph *> glyph_ptrs_;
    std::vector<RenderBatch> render_batches_;

public:
    SpriteBatch();
    SpriteBatch(const SpriteBatch &) = delete;
    SpriteBatch(SpriteBatch &&)      = delete;
    ~SpriteBatch();

    SpriteBatch &operator=(const SpriteBatch &) = delete;
    SpriteBatch &operator=(SpriteBatch &&) = delete;

    // initialize vaos and vbos
    void begin();
    void end();

    // adds a sprite to the sprite batch to be rendered later
    void draw(const glm::vec4 &destination_rect, const glm::vec4 &uv_rect,
              GLuint texture, const Colour &colour, float depth);
    // render the batch
    void render();

private:
    void createVertexArray();
    void createRenderBatches();
    void sortGlyphs();
};

} // namespace yage

#endif
