#include "raylib.h"
#pragma once

class Object
{
protected:
    Vector2 position;
    Vector2 acceleration;
    Vector2 velocity;

public:
    Object() {};
    virtual ~Object() {};
    virtual void draw() = 0;
    virtual void update() = 0;
    virtual void keybinds() = 0;
};