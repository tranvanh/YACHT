#pragma once
#include "CoreLib/Common.h"

class SDL_Window;

class MainWindow {
private:
    SDL_Window* mWindowSdl;

public:
    MainWindow(const char* title, int w, int h);
    ~MainWindow();

    void                show() const;
    SDL_Window*         sdl() const;
    std::pair<int, int> getWindowSize() const;
};