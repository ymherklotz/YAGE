/* ----------------------------------------------------------------------------
 * sprite.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com> -- MIT License
 * See file LICENSE for more details
 * ----------------------------------------------------------------------------
 */

/** @file
  */

#ifndef SPRITE_H
#define SPRITE_H

#include "texture.h"

#include <GL/glew.h>

#include <string>

namespace yage
{

/** @deprecated Use SpriteBatch instead
  */
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
    Sprite() = default;
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
