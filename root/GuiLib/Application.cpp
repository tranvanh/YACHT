#include "Application.h"
#include "../CoreLib/Renderer.h"
#include "../GuiLib/Layer.h"
#include "EventPoll.h"
#include "MainWindow.h"
#include "SDL2/SDL.h"
#include <cassert>
#include <memory>
#include <thread>

constexpr int WINDOW_X = 0;
constexpr int WINDOW_Y = 2500;
constexpr int WINDOW_W = 640;
constexpr int WINDOW_H = 480;


Application::Application(const char* name) {
    mMainWindow = std::make_shared<MainWindow>(name, WINDOW_X, WINDOW_Y, WINDOW_W, WINDOW_H);
    mRenderer   = std::make_shared<Renderer>(this);
}

Application::~Application() {
    SDL_Quit();
}

MainWindow& Application::getMainWindow() const {
    return *mMainWindow;
}

std::shared_ptr<Layer> Application::getActiveLayer() const {
    return mActiveLayer;
}

void Application::run() {
    installEventHandlers();
    mMainWindow->show();
    std::thread eventPoll_thread(&EventPoll::run, &mEventPoll);
    SDL_Delay(1000);
    while (mEventPoll.isRunning()) {
        mRenderer->synchronize();
    }
}