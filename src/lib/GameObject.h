#include <vector>
#include "raylib.h"
#pragma once

using namespace std;

class GameObject
{
protected:
    Vector2 position;
    Vector2 acceleration;
    Vector2 velocity;

public:
    bool toDelete = false;

public:
    GameObject() {};
    virtual ~GameObject() {};
    virtual void draw() = 0;
    virtual void update() = 0;
    virtual void keybinds() = 0;
};