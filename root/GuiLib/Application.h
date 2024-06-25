#pragma once

#include "EventPoll.h"

#include <memory>

class MainWindow;
class Renderer;
class Game;

class Application {
private:
    std::shared_ptr<MainWindow> mMainWindow;
    std::shared_ptr<Renderer> mRenderer;
    std::shared_ptr<Game> mGame;
    EventPoll mEventPoll;
public:
    Application();
    ~Application();
    void run();
    MainWindow& getMainWindow() const;
    Game& getGame() const;
private:
    void installEventHandlers();
};