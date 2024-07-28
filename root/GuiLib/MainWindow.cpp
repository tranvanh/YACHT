#include "GuiLib/MainWindow.h"
#include "Common.h"
#include <SDL2/SDL.h>

MainWindow::MainWindow(const char* title, int x, int y, int w, int h) {
    mWindow = SDL_CreateWindow(title, x, y, w, h, 0);
    CASSERT(mWindow, "Failed to initialized window");
}
MainWindow::~MainWindow() {
    SDL_DestroyWindow(mWindow);
}

void MainWindow::show() const {
    SDL_ShowWindow(mWindow);
}

SDL_Window* MainWindow::sdl() const {
    return mWindow;
}

std::pair<int, int> MainWindow::getWindowSize() const {
    int w = 0;
    int h = 0;
    SDL_GetWindowSize(mWindow, &w, &h);
    return { w, h };
}
