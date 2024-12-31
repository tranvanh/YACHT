#pragma once
#include "GuiLib/Layer.h"


YACHT_NAMESPACE_BEGIN
class Application;
YACHT_NAMESPACE_END

PACMAN_NAMESPACE_BEGIN

class Player;
class TileMap;

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

PACMAN_NAMESPACE_END