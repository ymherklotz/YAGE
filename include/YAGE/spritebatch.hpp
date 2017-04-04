#ifndef SPRITE_BATCH_HPP
#define SPRITE_BATCH_HPP

#include "vertex.hpp"

#include <GL/glew.h>
#include <glm/glm.hpp>

#include <vector>

namespace yage
{

struct Glyph
{
    GLuint texture;
    float depth;
	
    Vertex top_left;
    Vertex top_right;
    Vertex bottom_right;
    Vertex bottom_left;	
};

class SpriteBatch
{
public: // member variables
private:
    GLuint vbo_=0;
    GLuint vao_=0;

    std::vector<Glyph> glyphs_;
    std::vector<Glyph *> glyph_ptrs_;
	
public: // member functions
    SpriteBatch();
    ~SpriteBatch();

    void begin();
    void end();

    void draw(const glm::vec4 &destination_rect, const glm::vec4 &uv_rect, GLuint texture, const Color &color, float depth);

    void renderBatch();
private:
    void createVertexArray();
    void sortGlyphs();
};
    
} // yage

#endif
