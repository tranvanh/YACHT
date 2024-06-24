#pragma once

#include "Control.h"

class Entity;

class Game : public Control {
    Entity* mCharacter;
public:
    Game();
    virtual void onMove(SDL_Keycode key) override;
    Entity& getMainCharacter() const;
};