#pragma once

#include "SDL2/SDL_keyboard.h"
#include <list>
#include <memory>
#include <CoreLib/Entity.h>
#include <CoreLib/StateManager.h>

YACHT_NAMESPACE_BEGIN

class Application;
class SceneNode;

class Layer : public Entity {
protected:
    Application& mApplication;

public:
    Layer(Application& application)
        : mApplication(application) {}
    virtual ~Layer() {}
    virtual void onKeyboard(SDL_Keycode key) = 0;
};

YACHT_NAMESPACE_END