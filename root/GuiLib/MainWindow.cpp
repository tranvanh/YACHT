#include "MainWindow.h"
#include <SDL2/SDL.h>
#include <iostream>

MainWindow::MainWindow(const char* title, int x, int y, int w, int h) {
    mWindow = SDL_CreateWindow(title, x, y, w, h, 0);
}
MainWindow::~MainWindow() {
    SDL_DestroyWindow(mWindow);
}

void MainWindow::show(){
    SDL_ShowWindow(mWindow);
}

SDL_Window* MainWindow::getSDL() const{
    return mWindow;
}
