#include "GuiLib/Application.h"
#include "CoreLib/Renderer.h"
#include "GuiLib/EventPoll.h"
#include "GuiLib/Layer.h"
#include "GuiLib/MainWindow.h"
#include "SDL2/SDL.h"
#include "SDL_image.h"
#include <thread>

YACHT_NAMESPACE_BEGIN

Application::Application(const char* name, const int width, const int height) : mEventPoll(*this) {
    srand(time(0));
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

void Application::runNewThread(const std::function<void(void)>& funct){
    mThreadPool.emplace_back(std::thread(funct));
}

void Application::run() {
    mRunning = true;
    int flags      = IMG_INIT_PNG;
    int initStatus = IMG_Init(flags);
    CASSERT(!((initStatus & flags) != flags), "SDL2_Image format not available");

    installEventHandlers();
    mMainWindow->show();
    mThreadPool.emplace_back(std::thread(&EventPoll::run, &mEventPoll));
    render();
    joinThreads();
}

void Application::render() {
    while (mRunning) {
        mRenderer->synchronize();
        SDL_Delay(10);
    }
}

void Application::shutdown() {
    mRunning = false;
}

void Application::joinThreads() {
    for (auto& thread : mThreadPool) {
        thread.join();
    }
}

YACHT_NAMESPACE_END