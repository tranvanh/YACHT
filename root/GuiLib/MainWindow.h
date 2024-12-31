#pragma once

class SDL_Window;

YACHT_NAMESPACE_BEGIN

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

YACHT_NAMESPACE_END