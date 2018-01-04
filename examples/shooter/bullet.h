#ifndef EXAMPLES_SHOOTER_BULLET_H
#define EXAMPLES_SHOOTER_BULLET_H

#include <yage/yage.h>

#include "direction.h"

class Bullet : public yage::Drawable
{
public:
    Bullet(const glm::vec4 &bound, Direction dir, float speed, float depth = 0.f);

    void draw(yage::SpriteBatch &sp);

    // getters
    glm::vec4 position() const;
private:
    glm::vec4 bound_;
    Direction dir_;
    float speed_;
    float depth_;
};

#endif
