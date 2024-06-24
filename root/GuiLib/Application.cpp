#include "Application.h"
#include "MainWindow.h"
#include "SDL2/SDL.h"

#include <cassert>
#include <iostream>

Application::Application() {
    mMainWindow = new MainWindow("Test", 0, 2500, 640, 480);
}

Application::~Application() {
    delete mMainWindow;
    SDL_Quit();
}

void Application::run() {
    mMainWindow->show();
    while (true) {
        SDL_Event event;
        // Start our event loop
        
        // \todo Do proper event handling 
        while (SDL_PollEvent(&event)) {
            // Handle each specific event
            if (event.type == SDL_QUIT) {
                return;
            }

            if (event.type == SDL_KEYDOWN) {
                std::string pressed;
                switch (event.key.keysym.sym) {
                case SDLK_LEFT:
                    pressed = "Left";
                    break;
                case SDLK_RIGHT:
                    pressed = "Right";
                    break;
                case SDLK_UP:
                    pressed = "Up";
                    break;
                case SDLK_DOWN:
                    pressed = "Down";
                    break;
                }
                std::cout << pressed << std::endl;
            }

        }
    }
    std::cout << "After" << std::endl;
}