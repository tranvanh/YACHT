#pragma once

#include "SDL2/SDL_keyboard.h"
#include <atomic>
#include <functional>
#include <unordered_map>

using EventType = Uint32;

class EventPoll {
private:
  std::atomic<bool> mRunning = true;
  std::unordered_map<EventType, std::function<void(SDL_Event)>> mHandlers;

public:
  void run();
  bool isRunning() { return mRunning; }
  void registerHandler(const EventType eventType,
                       const std::function<void(SDL_Event)> &handler);
};