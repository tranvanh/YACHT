#pragma once

#include "SDL2/SDL_keyboard.h"

class Control {
public:
    virtual void onMove(SDL_Keycode keysym) = 0;
};