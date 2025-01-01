#pragma once
#include "CoreLib/Entity.h"
#include "CoreLib/BoundingBox.h"
#include <memory>

struct SDL_Surface;
struct SDL_Texture;

YACHT_NAMESPACE_BEGIN

class Renderer;
class SceneNode;

/// \todo 2024-10 improve the hierarchy for surface, texture, sprite 
class Surface : public Entity{
    SDL_Surface* mSurfaceSdl;
    SceneNode& mSceneNode;

public:
    Surface(const char* filePath, SceneNode& sceneNode);
    ~Surface();
    SDL_Surface* sdl() const;
    virtual void render(const Renderer& renderer, [[maybe_unused]] const bool drawBbox) const override;
};

class Texture {
    SDL_Texture* mTextureSdl;
public:
    Texture(const Surface& surface, const Renderer& renderer);
    ~Texture();
    SDL_Texture* sdl() const;
};

YACHT_NAMESPACE_END
