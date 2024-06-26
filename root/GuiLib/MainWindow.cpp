#include "MainWindow.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <utility>
#include <cassert>

MainWindow::MainWindow(const char* title, int x, int y, int w, int h) {
    mWindow = SDL_CreateWindow(title, x, y, w, h, 0);
}
MainWindow::~MainWindow() {
    SDL_DestroyWindow(mWindow);
}

void MainWindow::show() const{
    assert(mWindow);
    SDL_ShowWindow(mWindow);
}

SDL_Window* MainWindow::getSDL() const {
    assert(mWindow);
    return mWindow;
}

std::pair<int, int> MainWindow::getWindowSize() const{
    assert(mWindow);
    int w = 0;
    int h = 0;
    SDL_GetWindowSize(mWindow, &w, &h);
    return { w, h };
}
