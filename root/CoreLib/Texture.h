#pragma once

#include <memory>

class SDL_Surface;
class SDL_Texture;
class Renderer;

class Surface {
    SDL_Surface* mSurface;

public:
    Surface(const char* filePath);
    ~Surface();
    SDL_Surface* sdl();
};


class Texture{
    SDL_Texture* mTexture;
public:
    Texture(std::shared_ptr<Surface> surface, const Renderer& renderer);
    ~Texture();
    SDL_Texture* sdl();
};