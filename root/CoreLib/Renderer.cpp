#include "Renderer.h"
#include "../GuiLib/Application.h"
#include "../GuiLib/Layer.h"
#include "../GuiLib/MainWindow.h"
#include "../PacmanApp/Characters.h"
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

    // \todo will get reworked to handle entities and layer content in general manner
    const auto entityList = mApplication->getActiveLayer()->getEntityList();
    SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

    for (const auto& entity : entityList) {
        SDL_Rect rectangle;
        rectangle.x = entity->position.x;
        rectangle.y = entity->position.y;
        rectangle.w = entity->bbox.w;
        rectangle.h = entity->bbox.h;
        SDL_RenderDrawRect(mRenderer, &rectangle);
    }
}
