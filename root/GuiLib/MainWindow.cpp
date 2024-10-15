#include "GuiLib/MainWindow.h"
#include "Common.h"
#include <SDL2/SDL.h>

MainWindow::MainWindow(const char* title, int x, int y, int w, int h) {
    mWindowSdl = SDL_CreateWindow(title, x, y, w, h, 0);
    CASSERT(mWindowSdl, "Failed to initialized window");
}
MainWindow::~MainWindow() {
    SDL_DestroyWindow(mWindowSdl);
}

void MainWindow::show() const {
    SDL_ShowWindow(mWindowSdl);
}

SDL_Window* MainWindow::sdl() const {
    return mWindowSdl;
}

std::pair<int, int> MainWindow::getWindowSize() const {
    int w = 0;
    int h = 0;
    SDL_GetWindowSize(mWindowSdl, &w, &h);
    return { w, h };
}
