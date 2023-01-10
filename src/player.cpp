#include <iostream>
#include "player.h"

Player::Player()
{
    
    position = Vector2(0, 0);
    velocity = Vector2(0, 0);
    acceleration = Vector2(0, 0);
};

Player::~Player() = default;

void Player::draw()
{
    std::cout << "x: " << position.x << " y: " << position.y << std::endl;
}

void Player::update()
{
    position.x += velocity.x;
    position.y += velocity.y;

    velocity.x += acceleration.x;
    velocity.y += acceleration.y;
}