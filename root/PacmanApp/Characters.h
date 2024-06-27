#pragma once

#include "../CoreLib/Entity.h"
#include "SDL2/SDL_keyboard.h"

class Player : public Entity {
public:
    Player(float x, float y)
        : Entity(x, y) {
        setBoundingBox(20, 20);
    }
};