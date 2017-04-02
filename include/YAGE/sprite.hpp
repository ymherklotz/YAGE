#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "gl_texture.hpp"

#include <GL/glew.h>

#include <string>

class Sprite
{
private:
    float x_;
    float y_;
    float width_;
    float height_;
    GLuint vbo_id_ = 0;
    GlTexture texture_;
public:
    Sprite();
    ~Sprite();

    void init(float x, float y, float width, float height, const std::string &texture_path);
    void draw();
};

#endif
