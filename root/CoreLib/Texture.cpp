#include "CoreLib/Texture.h"
#include "CoreLib/Renderer.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "Common.h"

Texture::Texture(std::shared_ptr<Surface> surface, const Renderer& renderer) {
    mTexture = SDL_CreateTextureFromSurface(renderer.sdl(), surface->sdl());
    CASSERT(mTexture, "Failed to load the texture");
}

Texture::~Texture() {
    SDL_DestroyTexture(mTexture);
}

SDL_Texture* Texture::sdl() {
    return mTexture;
}

Surface::Surface(const char* filePath) {
    // \todo Bi 2024-07 Make the executable search for resources from root folder
    mSurface = IMG_Load(filePath);
    CASSERT(mSurface, "error loading the file");
}

Surface::~Surface() {
    SDL_FreeSurface(mSurface);
}

SDL_Surface* Surface::sdl() {
    return mSurface;
}