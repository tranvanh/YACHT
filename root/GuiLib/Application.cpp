#include "CoreLib/Renderer.h"
#include "GuiLib/Application.h"
#include "GuiLib/EventPoll.h"
#include "GuiLib/Layer.h"
#include "GuiLib/MainWindow.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
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
    IMG_Quit();
}

MainWindow& Application::getMainWindow() const {
    return *mMainWindow;
}

std::shared_ptr<Layer> Application::getActiveLayer() const {
    return mActiveLayer;
}

void Application::run() {
    int flags      = IMG_INIT_PNG;
    int initStatus = IMG_Init(flags);
    // \todo Bi 2024-07 Do custom asserts to handle messages
    CASSERT(false, "SDL2_Image format not available");
    CASSERT(!((initStatus & flags) != flags), "SDL2_Image format not available");

    installEventHandlers();
    mMainWindow->show();
    std::thread eventPoll_thread(&EventPoll::run, &mEventPoll);
    SDL_Delay(1000);
    while (mEventPoll.isRunning()) {
        mRenderer->synchronize();
    }
}