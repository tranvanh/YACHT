#include "GuiLib/Application.h"
#include "GuiLib/EventPoll.h"
#include "SDL2/SDL.h"
#include <functional>
#include <iostream>
#include <unordered_map>

YACHT_NAMESPACE_BEGIN

EventPoll::EventPoll(Application& application):mApplication(application){}

void EventPoll::run() {
   
    while (mApplication.isRunning()) {
        SDL_Event event;
        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                mApplication.shutdown();
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

YACHT_NAMESPACE_END