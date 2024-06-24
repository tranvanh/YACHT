#include "EventPoll.h"

#include "SDL2/SDL.h"
#include <iostream>

void EventPoll::run() {
    mRunning = true;
    while (mRunning) {
        SDL_Event event;
        if (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                mRunning = false;
                break;
            case SDL_KEYDOWN:
                onKeyboard(event.key.keysym.sym);
                break;
            }
        }
    }
}