#include "PacmanApp/GameLayer.h"
#include "CoreLib/SceneNode.h"
#include "GuiLib/Application.h"
#include "GuiLib/Layer.h"
#include "GuiLib/MainWindow.h"
#include "PacmanApp/Characters.h"
#include "PacmanApp/Style.h"
#include "PacmanApp/TileMapLoader.h"
#include <algorithm>
#include <optional>

PACMAN_NAMESPACE_BEGIN

GameLayer::GameLayer(Application& application)
    : Layer(application) {

    std::list<std::shared_ptr<SceneNode>> collisions;

    mPlayer = std::make_shared<Player>(Pos(200.f, 100.f));
    mMonstersList.emplace_back(std::make_shared<Monster>(Pos(100.f, 100.f)));
    mMonstersList.emplace_back(std::make_shared<Monster>(Pos(300.f, 150.f)));

    mEntityList.emplace_back(mPlayer);
    for (const auto& monster : mMonstersList) {
        mEntityList.emplace_back(monster);
        collisions.emplace_back(monster);
    }

    TileMapLoader tileMapLoader = TileMapLoader();
    mTileMap                    = tileMapLoader.parse();
    for (const auto& tileCollision : mTileMap->getCollisionTiles()) {
        collisions.emplace_back(tileCollision);
    }

    collisions.emplace_back(mPlayer);
    mCollisionManager.registerCollision(collisions);

    mApplication.runNewThread([this]() {
        runMonsterLogic();
    });
}

void GameLayer::onKeyboard(SDL_Keycode key) {
    // \Todo better design for menu, pause menu
    switch (key) {
    case SDLK_LEFT:
    case SDLK_RIGHT:
    case SDLK_UP:
    case SDLK_DOWN:
        onPlayerAction(key);
        break;
    case SDLK_ESCAPE:
        mApplication.shutdown();
        break;
    }
}

// \todo DEDUPLICATE THIS SHIT
// \todo make the boundary control more generic and move to CoreLib?
void GameLayer::onMoveLeft() {
    const Pos  playerPosition = mPlayer->getPos();
    const auto newPosition    = Pos(playerPosition.x - 10.f, playerPosition.y);
    mPlayer->setPos(newPosition);
    if (mCollisionManager.testCollision(mPlayer)) {
        mPlayer->setPos(playerPosition);
    }
}

void GameLayer::onMoveRight() {
    const Pos  playerPosition = mPlayer->getPos();
    const auto newPosition    = Pos(playerPosition.x + 10.f, playerPosition.y);
    mPlayer->setPos(newPosition);
    if (mCollisionManager.testCollision(mPlayer)) {
        mPlayer->setPos(playerPosition);
    }
}

void GameLayer::onMoveUp() {
    const Pos  playerPosition = mPlayer->getPos();
    const auto newPosition    = Pos(playerPosition.x, playerPosition.y - 10.f);
    mPlayer->setPos(newPosition);
    if (mCollisionManager.testCollision(mPlayer)) {
        mPlayer->setPos(playerPosition);
    }
}
void GameLayer::onMoveDown() {
    const Pos  playerPosition = mPlayer->getPos();
    const auto newPosition    = Pos(playerPosition.x, playerPosition.y + 10.f);
    mPlayer->setPos(newPosition);
    if (mCollisionManager.testCollision(mPlayer)) {
        mPlayer->setPos(playerPosition);
    }
}

void GameLayer::onPlayerAction(SDL_Keycode key) {
    switch (key) {
    case SDLK_LEFT:
        onMoveLeft();
        break;
    case SDLK_RIGHT:
        onMoveRight();
        break;
    case SDLK_UP:
        onMoveUp();
        break;
    case SDLK_DOWN:
        onMoveDown();
        break;
    default:
        CASSERT(false, "No defined action for the key");
    };
}

void GameLayer::runMonsterLogic() {
    while (mApplication.isRunning()) {
        SDL_Delay(60);
        for (auto& monster : mMonstersList) {
            const Pos  oldPosition = monster->getPos();
            monster->setPos(monster->generateNewPosition());
            while (mCollisionManager.testCollision(monster)) {
                monster->setPos(oldPosition);
                monster->setPos(monster->generateNewPosition());
            }
        }
    }
}

PACMAN_NAMESPACE_END