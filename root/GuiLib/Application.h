#pragma once
#include "CoreLib/Common.h"
#include "GuiLib/EventPoll.h"

class MainWindow;
class Renderer;
class Layer;

class Application {
private:
    bool mRunning = false;

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

protected:
    virtual void installEventHandlers() = 0;
};