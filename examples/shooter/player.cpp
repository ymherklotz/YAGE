#include "player.h"

Player::Player(const glm::vec4 &bound, const yage::Texture &texture)
    : bound_(bound), texture_(texture), direction_(Direction::DOWN),
      action_(Action::IDLE), speed_(4)
{
}

void Player::setTexture(const yage::Texture &texture) {
    texture_ = texture;
}

void Player::draw(yage::SpriteBatch &sp) const
{
    static int time      = 0;
    static int iteration = 0;
    float width          = 1.f / static_cast<float>(texture_.x);
    float height         = 1.f / static_cast<float>(texture_.y);

    switch (action_) {
    case Action::IDLE:
        sp.draw(bound_,
                {width, static_cast<int>(direction_) * height, width, height},
                texture_.id, yage::Colour(255, 255, 255, 255), 0);
        break;
    case Action::MOVING:
        if(time % 15 == 0) {
            iteration = (iteration + 1) % 2;
        }
        sp.draw(bound_,
                {iteration * 2 * width, static_cast<int>(direction_) * height, width, height},
                texture_.id, yage::Colour(255, 255, 255, 255), 0);
        time = (time + 1) % 59;
        break;
    }
}

void Player::move(Direction direction)
{
    direction_ = direction;
    action_ = Action::MOVING;

    switch (direction_) {
    case Direction::LEFT:
        bound_.x -= speed_;
        break;
    case Direction::DOWN:
        bound_.y -= speed_;
        break;
    case Direction::RIGHT:
        bound_.x += speed_;
        break;
    case Direction::UP:
        bound_.y += speed_;
        break;
    }
}

void Player::idle()
{
    action_    = Action::IDLE;
}

glm::vec4 Player::position() const
{
    return bound_;
}
