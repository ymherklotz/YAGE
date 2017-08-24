/* ----------------------------------------------------------------------------
 * sprite.hpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com> -- MIT License
 * See file LICENSE for more details
 * ----------------------------------------------------------------------------
 */

#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "texture.hpp"

#include <GL/glew.h>

#include <string>

namespace yage
{

class Sprite
{
private:
    float x_;
    float y_;
    float width_;
    float height_;
    GLuint vbo_id_ = 0;
    Texture texture_;

public:
    Sprite();
    Sprite(const Sprite &) = delete;
    Sprite(Sprite &&) = delete;
    ~Sprite();

    Sprite &operator=(const Sprite &) = delete;
    Sprite &operator=(Sprite &&) = delete;

    void init(float x, float y, float width, float height,
              const std::string &texture_path);
    void draw();
};

} // namespace yage

#endif
