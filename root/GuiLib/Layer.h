#pragma once

#include "SDL2/SDL_keyboard.h"
#include <list>
#include <memory>

class Application;
class Entity;

class Layer {
protected:
    Application& mApplication;

    // \todo do figure out how to store layer content
    std::list<std::shared_ptr<Entity>> mEntityList;

public:
    Layer(Application& application)
        : mApplication(application) {}
    virtual void                              onKeyboard(SDL_Keycode key) = 0;
    const std::list<std::shared_ptr<Entity>>& getEntityList() const { return mEntityList; }
};