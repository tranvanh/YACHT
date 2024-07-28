#include "PacmanApp/GameLayer.h"
#include "GuiLib/Application.h"
#include "GuiLib/Layer.h"
#include "GuiLib/MainWindow.h"
#include "PacmanApp/Characters.h"
#include <algorithm>
#include "Common.h"

GameLayer::GameLayer(Application& application)
    : Layer(application) {
    mPlayer = std::make_shared<Player>(50.f, 100.f);
    mEntityList.push_back(mPlayer);
    mEntityList.push_back(std::make_shared<Player>(100.f, 50.f));
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
    }
}

// \todo DEDUPLICATE THIS SHIT
void GameLayer::onMoveLeft() {
    const Pos                 playerPosition = mPlayer->position;
    const std::pair<int, int> widthHeight    = mApplication.getMainWindow().getWindowSize();
    mPlayer->position.x = std::clamp(playerPosition.x - 10.f, 0.f, float(widthHeight.first));
}
void GameLayer::onMoveRight() {
    const Pos                 playerPosition = mPlayer->position;
    const BoundingBox         playerBbox     = mPlayer->getBoundingBox();
    const std::pair<int, int> widthHeight    = mApplication.getMainWindow().getWindowSize();
    // mPlayer->position.x = std::clamp(playerPosition.x + 10.f, 0.f, float(widthHeight.first) - playerBbox.w);
    mPlayer->position.x = playerPosition.x + 10.f;
}
void GameLayer::onMoveUp() {
    const Pos                 playerPosition = mPlayer->position;
    const std::pair<int, int> widthHeight    = mApplication.getMainWindow().getWindowSize();
    // mPlayer->position.y = std::clamp(playerPosition.y - 10.f, 0.f, float(widthHeight.second));
    mPlayer->position.y = playerPosition.y - 10.f;

}
void GameLayer::onMoveDown() {
    const Pos                 playerPosition = mPlayer->position;
    const BoundingBox         playerBbox     = mPlayer->getBoundingBox();
    const std::pair<int, int> widthHeight    = mApplication.getMainWindow().getWindowSize();
    // mPlayer->position.y = std::clamp(playerPosition.y + 10.f, 0.f, float(widthHeight.second) - playerBbox.h);
    mPlayer->position.y = playerPosition.y + 10.f;
    std::cout << mPlayer->position.y << std::endl;

}