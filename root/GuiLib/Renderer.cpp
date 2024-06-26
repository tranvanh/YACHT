#include "Renderer.h"
#include "../GameCore/Characters.h"
#include "../GameCore/Game.h"
#include "Application.h"
#include "MainWindow.h"
#include "SDL2/SDL.h"

#include <cassert>

Renderer::Renderer(Application* application)
    : mApplication(application) {
    mRenderer = SDL_CreateRenderer(mApplication->getMainWindow().getSDL(), -1, SDL_RENDERER_ACCELERATED);
}

void Renderer::synchronize() {
    assert(mRenderer);
    SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(mRenderer);
    draw();
    SDL_RenderPresent(mRenderer);
}

void Renderer::draw() {
    assert(mApplication);
    assert(mRenderer);
    const Player& mc = mApplication->getGame().getPlayer();
    SDL_Rect      rectangle;
    rectangle.x = mc.position.x;
    rectangle.y = mc.position.y;
    rectangle.w = mc.bbox.w;
    rectangle.h = mc.bbox.h;
    SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawRect(mRenderer, &rectangle);
}
