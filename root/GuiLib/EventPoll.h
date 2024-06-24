#pragma once

#include "SDL2/SDL_keyboard.h"
#include <functional>
#include <atomic>

class EventPoll {
private:
    std::atomic_bool mRunning = false;
    std::function<void(SDL_Keycode)> onMove;
public:
    void run();
    bool isRunning(){return mRunning;}
    void setMoveHandler(const std::function<void(SDL_Keycode)>& handler) {onMove = handler;}
};