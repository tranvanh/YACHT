#include "../PacmanApp/GameLayer.h"
#include "../GuiLib/Application.h"
#include "../GuiLib/Layer.h"
#include "../GuiLib/MainWindow.h"
#include "Characters.h"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <memory>

GameLayer::GameLayer(Application& application)
    : Layer(application) {
    mPlayer = std::make_shared<Player>(50.f, 100.f);
    mEntityList.push_back(mPlayer);
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
    const Pos                 playerPosition = mPlayer->getPosition();
    const std::pair<int, int> widthHeight    = mApplication.getMainWindow().getWindowSize();
    mPlayer->position.x = std::clamp(playerPosition.x - 10.f, 0.f, float(widthHeight.first));
}
void GameLayer::onMoveRight() {
    const Pos                 playerPosition = mPlayer->getPosition();
    const BoundingBox         playerBbox     = mPlayer->getBoundingBox();
    const std::pair<int, int> widthHeight    = mApplication.getMainWindow().getWindowSize();
    mPlayer->position.x = std::clamp(playerPosition.x + 10.f, 0.f, float(widthHeight.first) - playerBbox.w);
}
void GameLayer::onMoveUp() {
    const Pos                 playerPosition = mPlayer->getPosition();
    const std::pair<int, int> widthHeight    = mApplication.getMainWindow().getWindowSize();
    std::cout << float(widthHeight.second) << std::endl;
    mPlayer->position.y = std::clamp(playerPosition.y - 10.f, 0.f, float(widthHeight.second));
}
void GameLayer::onMoveDown() {
    const Pos                 playerPosition = mPlayer->getPosition();
    const BoundingBox         playerBbox     = mPlayer->getBoundingBox();
    const std::pair<int, int> widthHeight    = mApplication.getMainWindow().getWindowSize();
    mPlayer->position.y = std::clamp(playerPosition.y + 10.f, 0.f, float(widthHeight.second) - playerBbox.h);
    std::cout << mPlayer->position.y << std::endl;
}