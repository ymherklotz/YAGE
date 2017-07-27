/* ----------------------------------------------------------------------------
 * spritebatch.hpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com> -- MIT License
 * See file LICENSE for more details
 * ----------------------------------------------------------------------------
 */

#ifndef SPRITE_BATCH_HPP
#define SPRITE_BATCH_HPP

#include "vertex.hpp"

#include <GL/glew.h>
#include <glm/glm.hpp>

#include <vector>

namespace yage
{

class SpriteBatch;

class Glyph
{
    // member variables
private:
    GLuint texture_;
    float depth_;
    Vertex top_left_;
    Vertex top_right_;
    Vertex bottom_right_;
    Vertex bottom_left_;

    // member functions
public:
    Glyph(GLuint texture, float depth, const Vertex &top_left, const Vertex &top_right, const Vertex &bottom_right, const Vertex &bottom_left);

    inline GLuint texture() const { return texture_; }
    inline float depth() const { return depth_; }
    inline Vertex top_left() const { return top_left_; }
    inline Vertex top_right() const { return top_right_; }
    inline Vertex bottom_right() const { return bottom_right_; }
    inline Vertex bottom_left() const { return bottom_left_; }
};

class RenderBatch
{
    friend SpriteBatch;
    // member variables
private:
    GLsizei num_vertices_;    
    GLint offset_;
    GLuint texture_;

    // member functions
public:
    RenderBatch(GLint offset, GLsizei num_vertices, GLuint texture);

    // getters
    inline GLint offset() const { return offset_; }
    inline GLsizei num_vertices() const { return num_vertices_; }
    inline GLuint texture() const { return texture_; }
};

class SpriteBatch
{
    // member variables
public:
    static const int NUM_VERTICES=6;
private:
    GLuint vbo_=0;
    GLuint vao_=0;
    std::vector<Glyph> glyphs_;
    std::vector<Glyph *> glyph_ptrs_;
    std::vector<RenderBatch> render_batches_;

    // member functions
public:
    SpriteBatch();
    ~SpriteBatch();

    // initialize vaos and vbos
    void init();
    void begin();
    void end();
    // adds a sprite to the sprite batch to be rendered later
    void draw(const glm::vec4 &destination_rect, const glm::vec4 &uv_rect, GLuint texture, const Color &color, float depth);
    // render the batch
    void render();
private:
    void createVertexArray();
    void createRenderBatches();
    void sortGlyphs();
};
    
} // yage

#endif
