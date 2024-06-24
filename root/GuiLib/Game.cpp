#include "Game.h"
#include "Entity.h"
#include <iostream>

Game::Game(){
    mCharacter = new Entity;
    mCharacter->setPosition(50.f, 100.f);
}

void Game::onMove(SDL_Keycode key) {
    switch (key) {
    case SDLK_LEFT:
        std::cout << "left" << std::endl;
        mCharacter->position.x -= 10.f;
        break;
    case SDLK_RIGHT:
        std::cout << "right" << std::endl;
        mCharacter->position.x += 10.f;
        break;
    case SDLK_UP:
        mCharacter->position.y -= 10.f;
        std::cout << "up" << std::endl;
        break;
    case SDLK_DOWN:
        mCharacter->position.y += 10.f;
        std::cout << "down" << std::endl;
        break;
    }
}

Entity& Game::getMainCharacter()const{
    return *mCharacter;
}