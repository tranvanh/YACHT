#pragma once

#include <utility>

class SDL_Window;

class MainWindow {
private:
    SDL_Window* mWindow;

public:
    MainWindow(const char* title, int x, int y, int w, int h);
    ~MainWindow();

    void                show() const;
    SDL_Window*         getSDL() const;
    std::pair<int, int> getWindowSize() const;
};