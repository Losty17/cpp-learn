#include "GameObject.h"
#include "Bullet.h"
#pragma once

class BulletHandler : public GameObject
{
private:
    
public:
    BulletHandler();
    ~BulletHandler();
    void update();
};

BulletHandler::BulletHandler()
{
}

BulletHandler::~BulletHandler()
{
}

void BulletHandler::update()
{
    Bullet b;
    
}
