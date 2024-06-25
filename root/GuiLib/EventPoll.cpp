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
      mHandlers[event.type](event);
    }
  }
}

void EventPoll::registerHandler(const EventType eventType,
                                const std::function<void(SDL_Event)> &handler) {
  mHandlers[eventType] = std::move(handler);
}