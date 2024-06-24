#pragma once

#include "SDL2/SDL_keyboard.h"
#include <functional>
#include <atomic>

class EventPoll {
private:
    std::atomic<bool> mRunning = true;
    std::function<void(SDL_Keycode)> onKeyboard;
public:
    void run();
    bool isRunning(){return mRunning;}
    void setKeyboardHandler(const std::function<void(SDL_Keycode)>& handler) {onKeyboard = handler;}
};