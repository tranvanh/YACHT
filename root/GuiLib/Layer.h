#pragma once

#include "SDL2/SDL_keyboard.h"
#include <list>
#include <memory>

YACHT_NAMESPACE_BEGIN

class Application;
class TileMap;
class SceneNode;

class Layer {
protected:
    Application&             mApplication;
    std::shared_ptr<TileMap> mTileMap;

    // \todo do figure out how to store layer content
    std::list<std::shared_ptr<SceneNode>> mEntityList;

public:
    Layer(Application& application)
        : mApplication(application) {}
    virtual ~Layer() {}
    virtual void                                 onKeyboard(SDL_Keycode key) = 0;
    const std::list<std::shared_ptr<SceneNode>>& getEntityList() const { return mEntityList; }
    std::shared_ptr<TileMap>                     getTileMap() const { return mTileMap; }
};

YACHT_NAMESPACE_END