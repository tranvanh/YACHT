#include "Renderer.h"
#include "MainWindow.h"
#include "../GameCore/Game.h"
#include "../GameCore/Characters.h"
#include "Application.h"

#include "SDL2/SDL.h"

Renderer::Renderer(Application* application) : mApplication(application) {
    mRenderer = SDL_CreateRenderer(mApplication->getMainWindow().getSDL(), -1, SDL_RENDERER_ACCELERATED);
}

void Renderer::update() {
    SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(mRenderer);
    draw();
    SDL_RenderPresent(mRenderer);
}

void Renderer::draw() {
    const Player& mc = mApplication->getGame().getPlayer();
    SDL_Rect rectangle;
    rectangle.x = mc.position.x;
    rectangle.y = mc.position.y;
    rectangle.w = mc.bbox.w;
    rectangle.h = mc.bbox.h;
    SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawRect(mRenderer, &rectangle);
}
