#include "GameObject.h"
#pragma once

enum BulletType
{
    NORMAL,
    SPIRAL    
};

class Bullet : public GameObject
{
public:
    int dir          = 0;      // Initial direction for the bullet
    int accel        = 0;      // Increases the bullet speed each frame
    int speed        = 4;      // Base speed value
    int amount       = 1;      // How much directions the bullets will go
    int offset       = 0;      // How much the bullets will turn (if you set it higher, turn the acceleration higher)
    int delay        = 15;     // Delay between bullets
    int rangeInit    = 0;      // 
    int rangeFinal   = 360;    // Range limit for the bullets in degrees
    int spiralSpeed  = 10;     // Spiral turning velocity
    bool aiming      = false;  // If bullets are going towards the player
    BulletType type  = NORMAL; //

public:
    Bullet();
    ~Bullet();
    void draw();
    void update();
    void keybinds();
};

Bullet::Bullet()
{
    this->position = Vector2{400, 0};
    this->velocity = Vector2{0, 500};
    this->acceleration = Vector2{0, 0};
}

Bullet::~Bullet()
{
    toDelete = false;
    TraceLog(LOG_ALL, "Deletting bullet");
};

void Bullet::draw()
{
    DrawCircleV(position, 10, PURPLE);
}

void Bullet::update()
{
    position.x += velocity.x * GetFrameTime();
    position.y += velocity.y * GetFrameTime();
    // velocity.x += acceleration.x;
    // velocity.y += acceleration.y;

    if (
        position.x > GetScreenWidth() || 
        position.x < 0 || 
        position.y > GetScreenHeight() ||
        position.y < 0
    )
    {
        toDelete = true;
    };
}

void Bullet::keybinds()
{

}