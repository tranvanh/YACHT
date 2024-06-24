#pragma once

#include "EventPoll.h"

class MainWindow;
class Renderer;
class Game;

class Application {
private:
    MainWindow* mMainWindow;
    Renderer* mRenderer;
    Game* mGame;
    EventPoll mEventPoll;
public:
    Application();
    ~Application();
    void run();
    MainWindow& getMainWindow() const;
    Game& getGame() const;
};