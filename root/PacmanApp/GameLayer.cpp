#include "PacmanApp/GameLayer.h"
#include "GuiLib/Application.h"
#include "GuiLib/Layer.h"
#include "GuiLib/MainWindow.h"
#include "PacmanApp/Characters.h"
#include <algorithm>
#include "CoreLib/Common.h"

GameLayer::GameLayer(Application& application)
    : Layer(application) {
    mPlayer = std::make_shared<Player>(Pos(50.f, 100.f));
    mEntityList.push_back(mPlayer);
    mEntityList.push_back(std::make_shared<StaticItem>(Pos(100.f, 50.f)));
    mEntityList.push_back(std::make_shared<StaticItem>(Pos(50.f, 200.f)));
}

void GameLayer::onKeyboard(SDL_Keycode key) {
    // \Todo better design for menu, pause menu
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
    case SDLK_ESCAPE:
        mApplication.shutdown();
        break;
    }
    if (collisionDetected()) {
        std::cout << "HIT!" << std::endl;
    }
}

bool GameLayer::collisionDetected() const{
    // \todo 2024-10 poor man solution, find more efficient solution
    for(const auto& entity : mEntityList){
        if(*mPlayer == *entity){
            continue;
        }
        if(mPlayer->collidesWith(*entity)){
            return true;
        }
    }
    return false;
}

// \todo DEDUPLICATE THIS SHIT
void GameLayer::onMoveLeft() {
    const Pos                 playerPosition = mPlayer->getPos();
    const std::pair<int, int> widthHeight    = mApplication.getMainWindow().getWindowSize();
    float x = std::clamp(playerPosition.x - 10.f, 0.f, float(widthHeight.first));
    mPlayer->setPos(Pos(x, playerPosition.y));
}

void GameLayer::onMoveRight() {
    const Pos                 playerPosition = mPlayer->getPos();
    const BoundingBox         playerBbox     = mPlayer->getBoundingBox();
    const std::pair<int, int> widthHeight    = mApplication.getMainWindow().getWindowSize();
    mPlayer->setPos(Pos(playerPosition.x + 10.f, playerPosition.y));

}
void GameLayer::onMoveUp() {
    const Pos                 playerPosition = mPlayer->getPos();
    const std::pair<int, int> widthHeight    = mApplication.getMainWindow().getWindowSize();
    mPlayer->setPos(Pos(playerPosition.x, playerPosition.y - 10.f));

}
void GameLayer::onMoveDown() {
    const Pos                 playerPosition = mPlayer->getPos();
    const BoundingBox         playerBbox     = mPlayer->getBoundingBox();
    const std::pair<int, int> widthHeight    = mApplication.getMainWindow().getWindowSize();
    mPlayer->setPos(Pos(playerPosition.x, playerPosition.y + 10.f));

}