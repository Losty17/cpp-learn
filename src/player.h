#include "object.h"
#pragma once

class Player : public Object
{
private:

public:
    Player();
    ~Player();
    void draw();
    void update();
};