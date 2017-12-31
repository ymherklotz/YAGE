#ifndef EXAMPLE_SHOOTER_PLAYER_H
#define EXAMPLE_SHOOTER_PLAYER_H

#include "yage/yage.h"

enum class Direction {
    LEFT,
    DOWN,
    RIGHT,
    UP,
};

enum class Action {
    IDLE,
    MOVING,
};

class Player
{
public:
    Player(const glm::vec4 &bound, const yage::Texture &texture);

    void setTexture(const yage::Texture &texture);

    void draw(yage::SpriteBatch &sp) const;

    void move(Direction direction);
    void idle();
private:
    glm::vec4 bound_;
    yage::Texture texture_;
    Direction direction_;
    Action action_;
    int speed_;
};

#endif
