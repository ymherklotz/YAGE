/** ---------------------------------------------------------------------------
 * @file: spritebatch.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#ifndef YAGE_SPRITE_BATCH_H
#define YAGE_SPRITE_BATCH_H

#include "../data/vertex.h"
#include "batch.h"

#include <glad/glad.h>
#include <glm/glm.hpp>

#include <vector>

namespace yage
{

namespace details
{

struct RenderBatch {
    GLint offset;
    GLsizei num_vertices;
    GLuint texture;

    RenderBatch(GLint offset_i, GLsizei num_vertices_i, GLuint texture_i)
        : offset(offset_i), num_vertices(num_vertices_i), texture(texture_i)
    {
    }
};

/** Glyph with information of the texture.
 */
struct Glyph {
    GLuint texture;
    float depth;
    Vertex top_left;
    Vertex top_right;
    Vertex bottom_right;
    Vertex bottom_left;

    Glyph(GLuint texture_i, float depth_i, const Vertex &top_left_i,
          const Vertex &top_right_i, const Vertex &bottom_right_i,
          const Vertex &bottom_left_i)
        : texture(texture_i), depth(depth_i), top_left(top_left_i),
          top_right(top_right_i), bottom_right(bottom_right_i),
          bottom_left(bottom_left_i)
    {
    }
};

} // namespace details

class SpriteBatch
{
public:
    static const int NUM_VERTICES = 6;

private:
    GLuint vao_;
    GLuint vbo_;
    std::vector<details::Glyph> glyphs_;
    std::vector<details::Glyph *> glyph_ptrs_;
    std::vector<details::RenderBatch> render_batches_;

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
    void createRenderBatches();
    void sortGlyphs();
};

} // namespace yage

#endif
