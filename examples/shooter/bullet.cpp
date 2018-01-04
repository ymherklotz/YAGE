#include "bullet.h"

Bullet::Bullet(const glm::vec4 &bound, Direction dir, float speed, float depth)
    : bound_(bound), dir_(dir), speed_(speed), depth_(depth)
{
}

void Bullet::draw(yage::SpriteBatch &sp)
{
    switch(dir_) {
    case Direction::UP:
        bound_.y += speed_;
        break;
    case Direction::DOWN:
        bound_.y -= speed_;
        break;
    case Direction::LEFT:
        bound_.x -= speed_;
        break;
    case Direction::RIGHT:
        bound_.x += speed_;
        break;
    }
    sp.draw(
        bound_, {0, 0, 1, 1},
        yage::ResourceManager::getTexture("examples/resources/bullet.png").id,
        yage::Colour(255, 255, 255, 255), depth_);
}

glm::vec4 Bullet::position() const
{
    return bound_;
}
