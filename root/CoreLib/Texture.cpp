#include "CoreLib/Texture.h"
#include "CoreLib/Renderer.h"
#include "CoreLib/SceneNode.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "Common.h"
#include <memory>


Texture::Texture(const Surface& surface, const Renderer& renderer) {
    mTextureSdl = SDL_CreateTextureFromSurface(renderer.sdl(), surface.sdl());
    CASSERT(mTextureSdl, "Failed to load the texture");
}

Texture::~Texture() {
    SDL_DestroyTexture(mTextureSdl);
}

SDL_Texture* Texture::sdl() const {
    return mTextureSdl;
}

Surface::Surface(const char* filePath, SceneNode& sceneNode) : mSceneNode(sceneNode) {
    // \todo Bi 2024-07 Make the executable search for resources from root folder
    mSurfaceSdl = IMG_Load(filePath);
    CASSERT(mSurfaceSdl, "error loading the file");
}

Surface::~Surface() {
    SDL_FreeSurface(mSurfaceSdl);
}

SDL_Surface* Surface::sdl() const {
    return mSurfaceSdl;
}

void Surface::render(const Renderer& renderer, const bool drawBbox) const {
    SDL_Rect    rectangle;
    BoundingBox bbox = mSceneNode.getBoundingBox();
    rectangle.x      = bbox.topLeft.x;
    rectangle.y      = bbox.topLeft.y;
    rectangle.w      = abs(bbox.topLeft.x - bbox.bottomRight.x);
    rectangle.h      = abs(bbox.topLeft.y - bbox.bottomRight.y);
    auto texture     = std::make_shared<Texture>(*this, renderer);
    SDL_RenderCopy(renderer.sdl(), texture->sdl(), NULL, &rectangle);
}