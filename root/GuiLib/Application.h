#pragma once

#include "EventPoll.h"
#include "Common.h"

class MainWindow;
class Renderer;
class Layer;

class Application {
protected:
    std::shared_ptr<MainWindow> mMainWindow;
    std::shared_ptr<Renderer>   mRenderer;

    // \todo Add some kind of layer manager
    std::shared_ptr<Layer> mActiveLayer;
    EventPoll              mEventPoll;

public:
    Application(const char* name);
    ~Application();
    void                   run();
    MainWindow&            getMainWindow() const;
    std::shared_ptr<Layer> getActiveLayer() const;

protected:
    virtual void installEventHandlers() = 0;
};