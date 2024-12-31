#pragma once

#include "SDL2/SDL_events.h"
#include "SDL2/SDL_keyboard.h"
#include <atomic>
#include <functional>
#include <unordered_map>

YACHT_NAMESPACE_BEGIN

using EventType = Uint32;

class EventPoll {
private:
    std::atomic<bool>                                             mRunning;
    std::unordered_map<EventType, std::function<void(SDL_Event)>> mHandlers;

public:
    void run();
    bool isRunning() { return mRunning; }
    void registerHandler(const EventType eventType, const std::function<void(SDL_Event)>& handler);

private:
    void processEvent(const SDL_Event event) const;
};

YACHT_NAMESPACE_END