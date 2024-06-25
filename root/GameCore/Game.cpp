#include "Game.h"
#include "Characters.h"
#include "../GuiLib/Application.h"
#include "../GuiLib/MainWindow.h"

#include <iostream>
#include <algorithm>

Game::Game(Application& application) : mApplication(application) {
    mPlayer = new Player(50.f, 100.f);
}
Game::~Game() {
    delete mPlayer;
}

void Game::onKeyboard(SDL_Keycode key) {
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

Player& Game::getPlayer()const {
    return *mPlayer;
}

// \todo DEDUPLICATE THIS SHIT
void Game::onMoveLeft(){
    const Pos playerPosition = mPlayer->getPosition();
    const std::pair<int, int> widthHeight = mApplication.getMainWindow().getWindowSize();
    mPlayer->position.x = std::clamp( playerPosition.x - 10.f, 0.f, float(widthHeight.first));
}
void Game::onMoveRight(){
    const Pos playerPosition = mPlayer->getPosition();
    const BoundingBox playerBbox = mPlayer->getBoundingBox();
    const std::pair<int, int> widthHeight = mApplication.getMainWindow().getWindowSize();
    mPlayer->position.x = std::clamp( playerPosition.x + 10.f, 0.f, float(widthHeight.first) - playerBbox.w);
}
void Game::onMoveUp(){
    const Pos playerPosition = mPlayer->getPosition();
    const std::pair<int, int> widthHeight = mApplication.getMainWindow().getWindowSize();
    std::cout << float(widthHeight.second) << std::endl;
    mPlayer->position.y = std::clamp( playerPosition.y - 10.f, 0.f, float(widthHeight.second));
}
void Game::onMoveDown(){
    const Pos playerPosition = mPlayer->getPosition();
    const BoundingBox playerBbox = mPlayer->getBoundingBox();
    const std::pair<int, int> widthHeight = mApplication.getMainWindow().getWindowSize();
    mPlayer->position.y = std::clamp( playerPosition.y + 10.f, 0.f, float(widthHeight.second) - playerBbox.h);
    std::cout <<  mPlayer->position.y << std::endl;

}