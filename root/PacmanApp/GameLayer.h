#pragma once
#include "GuiLib/Layer.h"
#include "CoreLib/BoundingBox.h"
#include <optional>
#include <list>

YACHT_NAMESPACE_BEGIN
class Application;
YACHT_NAMESPACE_END

PACMAN_NAMESPACE_BEGIN

class Player;
class Monster;
class TileMap;

// \todo Game will have several screen types?
class GameLayer : public Layer {
    std::shared_ptr<Player> mPlayer;
    std::list<std::shared_ptr<Monster>> mMonstersList;

public:
    GameLayer(Application& application);
    virtual void onKeyboard(SDL_Keycode key) override;

private:
    void onPlayerAction(SDL_Keycode key);

    void onMoveLeft();
    void onMoveRight();
    void onMoveUp();
    void onMoveDown();

    // \todo 2024-10 Might be needed to move somewhere else with some more general collision manager
    // returns true on collision
    std::optional<BoundingBox> testSurroundingCollisionAtPosition(const BoundingBox& otherBbox) const;

    void runMonsterLogic();
};

PACMAN_NAMESPACE_END