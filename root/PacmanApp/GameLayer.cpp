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
    mPlayer = std::make_shared<Player>(Pos(200.f, 100.f));
    mMonstersList.emplace_back(std::make_shared<Monster>(Pos(100.f, 100.f)));
    mMonstersList.emplace_back(std::make_shared<Monster>(Pos(300.f, 150.f)));

    mEntityList.emplace_back(mPlayer);
    for (const auto& monster : mMonstersList) {
        mEntityList.emplace_back(monster);
    }

    TileMapLoader tileMapLoader = TileMapLoader();
    mTileMap                    = tileMapLoader.parse();
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

std::optional<BoundingBox> GameLayer::testSurroundingCollisionAtPosition(const BoundingBox& otherBbox) const {
    return mTileMap->collidesWith({otherBbox});
}

// \todo DEDUPLICATE THIS SHIT
// \todo make the boundary control more generic and move to CoreLib?
void GameLayer::onMoveLeft() {
    const Pos                 playerPosition = mPlayer->getPos();
    const auto                newPosition    = Pos(playerPosition.x - 10.f, playerPosition.y);
    if (auto bbox = testSurroundingCollisionAtPosition(mPlayer->getBoundingBoxForPosition(newPosition))) {
        auto& METRICS = Style::instance().METRICS;
        mPlayer->setPos(Pos(bbox->bottomRight.x + METRICS.PLAYER_SIZE * 0.5f, playerPosition.y));
    } else {
        mPlayer->setPos(newPosition);
    }
}

void GameLayer::onMoveRight() {
    const Pos                 playerPosition = mPlayer->getPos();
    const BoundingBox         playerBbox     = mPlayer->getBoundingBox();
    const auto                newPosition    = Pos(playerPosition.x + 10.f, playerPosition.y);
    if (auto bbox = testSurroundingCollisionAtPosition(mPlayer->getBoundingBoxForPosition(newPosition))) {
        auto& METRICS = Style::instance().METRICS;
        mPlayer->setPos(Pos(bbox->topLeft.x - METRICS.PLAYER_SIZE*0.5f,playerPosition.y));
    }
    else{
        mPlayer->setPos(newPosition);
    }
}

void GameLayer::onMoveUp() {
    const Pos                 playerPosition = mPlayer->getPos();
    const auto                newPosition    = Pos(playerPosition.x, playerPosition.y - 10.f);
    if (auto bbox = testSurroundingCollisionAtPosition(mPlayer->getBoundingBoxForPosition(newPosition))) {
        auto& METRICS = Style::instance().METRICS;
        mPlayer->setPos(Pos(playerPosition.x,bbox->bottomRight.y + METRICS.PLAYER_SIZE*0.5f));
    }
    else{
        mPlayer->setPos(newPosition);
    }
}
void GameLayer::onMoveDown() {
    const Pos                 playerPosition = mPlayer->getPos();
    const BoundingBox         playerBbox     = mPlayer->getBoundingBox();
    const auto                newPosition    = Pos(playerPosition.x, playerPosition.y + 10.f);
    if (auto bbox = testSurroundingCollisionAtPosition(mPlayer->getBoundingBoxForPosition(newPosition))) {
        auto& METRICS = Style::instance().METRICS;
        mPlayer->setPos(Pos(playerPosition.x,bbox->topLeft.y- METRICS.PLAYER_SIZE*0.5f));
    }
    else{
        mPlayer->setPos(newPosition);
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
            auto pos = monster->generateNewPosition();
            while (auto bbox = testSurroundingCollisionAtPosition(monster->getBoundingBoxForPosition(pos))) {
                pos = monster->generateNewPosition();
            }
            monster->setPos(pos);
        }
    }
}

PACMAN_NAMESPACE_END