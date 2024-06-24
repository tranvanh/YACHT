#pragma once

#include "../GuiLib/Control.h"

class Entity;

class Game : public Control {
    Entity* mCharacter;
public:
    Game();
    virtual void onKeyboard(SDL_Keycode key) override;
    Entity& getMainCharacter() const;
};