#pragma once
#include "GuiLib/Layer.h"

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

    // \todo 2024-10 Might be needed to move somewhere else with some more general collision manager
    bool collisionDetected() const;
};