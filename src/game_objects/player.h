#include "object.h"
#pragma once

class Player : public Object
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