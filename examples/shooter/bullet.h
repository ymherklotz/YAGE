#ifndef EXAMPLES_SHOOTER_BULLET_H
#define EXAMPLES_SHOOTER_BULLET_H

#include <yage/yage.h>

class Bullet : public yage::Drawable
{
public:
    Bullet(const glm::vec4 &bound);

    void draw(yage::SpriteBatch &sp) const;

private:
    glm::vec4 bound_;
};

#endif
