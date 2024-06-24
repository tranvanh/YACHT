#include "Application.h"
#include "MainWindow.h"
#include "Renderer.h"
#include "EventPoll.h"
#include "Control.h"
#include "Game.h"

#include "SDL2/SDL.h"
#include <cassert>
#include <iostream>
#include <thread>

Application::Application() {
    mMainWindow = new MainWindow("Test", 0, 2500, 640, 480);
    mGame = new Game;
    mRenderer = new Renderer(this);
}

Application::~Application() {
    delete mMainWindow;
    delete mRenderer;
    delete mGame;
    SDL_Quit();
}

MainWindow& Application::getMainWindow()const{
    return *mMainWindow;
}

Game& Application::getGame()const{
    return *mGame;
}

void Application::run() {
    mMainWindow->show();
    const auto onMove = [this](SDL_Keycode key){
        mGame->onMove(key);
    };
    mEventPoll.setMoveHandler(onMove);
    std::thread eventPoll_thread(&EventPoll::run, &mEventPoll);
    SDL_Delay(1000);
    while (mEventPoll.isRunning()) {
        mRenderer->update();
    }
}