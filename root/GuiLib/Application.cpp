#include "Application.h"
#include "MainWindow.h"
#include "Renderer.h"
#include "EventPoll.h"
#include "Control.h"
#include "../GameCore/Game.h"

#include "SDL2/SDL.h"
#include <cassert>
#include <iostream>
#include <thread>
#include <memory>

constexpr int WINDOW_X = 0;
constexpr int WINDOW_Y = 2500;
constexpr int WINDOW_W = 640;
constexpr int WINDOW_H = 480;

const char* NAME = "PACMAN VOLE";

Application::Application() {
    mMainWindow = std::make_shared<MainWindow>(NAME, WINDOW_X, WINDOW_Y, WINDOW_W, WINDOW_H);
    mGame = std::make_shared<Game>(*this);
    mRenderer = std::make_shared<Renderer>(this);
    installEventHandlers();
}

Application::~Application() {
    SDL_Quit();
}

MainWindow& Application::getMainWindow()const {
    return *mMainWindow;
}

Game& Application::getGame()const {
    return *mGame;
}

void Application::run() {
    mMainWindow->show();
    std::thread eventPoll_thread(&EventPoll::run, &mEventPoll);
    while (mEventPoll.isRunning()) {
        mRenderer->update();
    }
}

void Application::installEventHandlers() {
    // \todo more universal approach with custom onKeyboard handles
    // Have something like screenManager which switches the handler?
    mEventPoll.registerHandler(SDL_KEYDOWN, [this](const SDL_Event event) {mGame->onKeyboard(event.key.keysym.sym);});
}