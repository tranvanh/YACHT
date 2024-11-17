#include "GuiLib/Application.h"
#include "CoreLib/Renderer.h"
#include "GuiLib/EventPoll.h"
#include "GuiLib/Layer.h"
#include "GuiLib/MainWindow.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <thread>

Application::Application(const char* name, const int width, const int height) {
    mMainWindow = std::make_shared<MainWindow>(name, width, height);
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
    CASSERT(!((initStatus & flags) != flags), "SDL2_Image format not available");

    installEventHandlers();
    mMainWindow->show();
    std::thread eventPoll_thread(&EventPoll::run, &mEventPoll);

    // \todo remove delay and use some sort of signal
    SDL_Delay(1000);
    mRunning = true;
    while (mEventPoll.isRunning() && mRunning) {
        mRenderer->synchronize();
    }
    eventPoll_thread.join();
    
}

void Application::shutdown() {
    mRunning = false;
}