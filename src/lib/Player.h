#include "GameObject.h"
#pragma once

class Player : public GameObject
{
private:

public:
    Player();
    Player(Vector2 position);
    ~Player();
    void draw();
    void update();
    void keybinds();
};

Player::Player(Vector2 position)
{
    this->position = position;
    this->velocity = Vector2{0, 0};
    this->acceleration = Vector2{0, 0};
}

Player::Player()
{   
    Player(Vector2{0, 0});
}

Player::~Player() = default;

void Player::draw()
{
    DrawCircleV(position, 30, PURPLE);
}

void Player::update()
{
    position.x += velocity.x;
    position.y += velocity.y;

    velocity.x += acceleration.x;
    velocity.y += acceleration.y;
}

void Player::keybinds()
{
    if (IsKeyDown(KEY_LEFT)) velocity.x = -4;
    else if (IsKeyDown(KEY_RIGHT)) velocity.x = 4;
    else velocity.x = 0;

    if (IsKeyDown(KEY_UP)) velocity.y = -4;
    else if (IsKeyDown(KEY_DOWN)) velocity.y = 4;
    else velocity.y = 0;
}