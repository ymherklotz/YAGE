#include "bullet.h"

Bullet::Bullet(const glm::vec4 &bound) : bound_(bound) {}

void Bullet::draw(yage::SpriteBatch &sp) const
{
    sp.draw(bound_, {0, 0, 1, 1}, yage::ResourceManager::getTexture("examples/resources/bullet.png").id, yage::Colour(255, 255, 255, 255), 0);
}
