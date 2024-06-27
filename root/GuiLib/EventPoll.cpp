#include "EventPoll.h"
#include "SDL2/SDL.h"
#include <functional>
#include <iostream>
#include <unordered_map>

void EventPoll::run() {
    mRunning = true;
    while (mRunning) {
        SDL_Event event;
        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                mRunning = false;
                return;
            }
            processEvent(event);
        }
    }
}

void EventPoll::registerHandler(const EventType eventType, const std::function<void(SDL_Event)>& handler) {
    mHandlers[eventType] = handler;
}

void EventPoll::processEvent(const SDL_Event event) const {
    const auto handler = mHandlers.find(event.type);

    // Check if event handler is present
    if (handler != mHandlers.end()) {
        handler->second(event);
    }
}