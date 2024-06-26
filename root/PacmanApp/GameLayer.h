#pragma once

#include "../GuiLib/Layer.h"
#include <memory>

class Player;
class Application;

// \todo Game will have several screen types?
class GameLayer : public Layer {
    std::shared_ptr<Player> mPlayer;

public:
    GameLayer(Application& application);
    virtual void onKeyboard(SDL_Keycode key) override;

private:
    void onMoveLeft();
    void onMoveRight();
    void onMoveUp();
    void onMoveDown();
};