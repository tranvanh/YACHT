#include "EventPoll.h"

#include "SDL2/SDL.h"
#include <iostream>

void EventPoll::run() {
    mRunning = true;
    // \todo Do proper event handling 
    while (true) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            // Handle each specific event
            if (event.type == SDL_QUIT) {
                mRunning = false;
                return;
            }
            if (event.type == SDL_KEYDOWN) {
                onMove(event.key.keysym.sym);
            }
        }
    }
}