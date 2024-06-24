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

constexpr int WINDOW_X = 0;
constexpr int WINDOW_Y = 2500;
constexpr int WINDOW_W = 640;
constexpr int WINDOW_H = 480;

const char* NAME = "PACMAN VOLE";

Application::Application() {
    mMainWindow = new MainWindow(NAME, WINDOW_X, WINDOW_Y, WINDOW_W, WINDOW_H);
    mGame = new Game(*this);
    mRenderer = new Renderer(this);
    installEventHandlers();
}

Application::~Application() {
    delete mMainWindow;
    delete mRenderer;
    delete mGame;
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
    const auto onKeyboard = [this](SDL_Keycode key) {
        mGame->onKeyboard(key);
        };

    // \todo more universal approach with custom onKeyboard handles
    // Have something like screenManager which switches the handler?
    mEventPoll.setKeyboardHandler(onKeyboard);
}