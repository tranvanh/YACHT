#pragma once

#include "SDL2/SDL_keyboard.h"

class Control {
public:
    virtual void onKeyboard(SDL_Keycode keysym) = 0;
};