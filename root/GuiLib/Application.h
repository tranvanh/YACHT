#pragma once
#include "GuiLib/EventPoll.h"
#include <functional>
#include <list>
#include <thread>

YACHT_NAMESPACE_BEGIN

class MainWindow;
class Renderer;
class Layer;

class Application {
private:
    std::atomic<bool> mRunning = false;
    std::list<std::thread> mThreadPool;
protected:
    std::shared_ptr<MainWindow> mMainWindow;
    std::shared_ptr<Renderer>   mRenderer;

    // \todo Add some kind of layer manager
    std::shared_ptr<Layer> mActiveLayer;
    EventPoll              mEventPoll;

public:
    Application(const char* name, const int width, const int height);
    ~Application();
    void                   run();
    void                   shutdown();
    MainWindow&            getMainWindow() const;
    std::shared_ptr<Layer> getActiveLayer() const;
    void                   runNewThread(const std::function<void(void)>& funct);

    bool isRunning() const { return mRunning; }

protected:
    virtual void installEventHandlers() = 0;

private:
    void render();
    void joinThreads();
};

YACHT_NAMESPACE_END