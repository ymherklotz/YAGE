#include "spritebatch.hpp"

#include <algorithm>

namespace yage
{

SpriteBatch::SpriteBatch()
{
    createVertexArray();
}

SpriteBatch::~SpriteBatch()
{
    if(vao_!=0)
	glDeleteVertexArrays(1, &vao_);

    if(vbo_!=0)
	glDeleteVertexArrays(1, &vbo_);
}

void SpriteBatch::begin()
{}

void SpriteBatch::end()
{}

void SpriteBatch::draw(const glm::vec4 &destination_rect, const glm::vec4 &uv_rect, GLuint texture, const Color &color, float depth)
{
    Glyph new_glyph;
    new_glyph.texture=texture;
    new_glyph.depth=depth;

    new_glyph.top_left.color=color;
    new_glyph.top_left.setPosition(destination_rect.x, destination_rect.y+destination_rect.w);
    new_glyph.top_left.setUv(uv_rect.x, uv_rect.y+uv_rect.w);

    new_glyph.top_right.color=color;
    new_glyph.top_right.setPosition(destination_rect.x+destination_rect.z, destination_rect.y+destination_rect.w);
    new_glyph.top_right.setUv(uv_rect.x+uv_rect.z, uv_rect.y+uv_rect.w);

    new_glyph.bottom_right.color=color;
    new_glyph.bottom_right.setPosition(destination_rect.x+destination_rect.z, destination_rect.y);
    new_glyph.bottom_right.setUv(uv_rect.x+uv_rect.z, uv_rect.y);

    new_glyph.bottom_right.color=color;
    new_glyph.bottom_right.setPosition(destination_rect.x, destination_rect.y);
    new_glyph.bottom_right.setUv(uv_rect.x, uv_rect.y);

    // deal with fragmenting
    glyphs_.push_back(new_glyph);
    glyph_ptrs_.push_back(&glyphs_.back());
}

void SpriteBatch::renderBatch()
{}

void SpriteBatch::sortGlyphs()
{
    std::sort(glyph_ptrs_.begin(), glyph_ptrs_.end(), [] (Glyph *a, Glyph *b)->bool {
	    if(a->depth==b->depth)
		return a->texture<b->texture;
	    return a->depth<b->depth;
	});
}

} // yage
