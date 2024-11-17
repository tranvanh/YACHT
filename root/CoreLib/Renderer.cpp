#include "CoreLib/Renderer.h"
#include "CoreLib/BoundingBox.h"
#include "CoreLib/Entity.h"
#include "CoreLib/TileMap.h"
#include "CoreLib/Texture.h"
#include "GuiLib/Application.h"
#include "GuiLib/Layer.h"
#include "GuiLib/MainWindow.h"
#include "PacmanApp/Characters.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "Common.h"

Renderer::Renderer(Application* application)
    : mApplication(application) {
    CASSERT(mApplication, "Application is nullptr");
    mRenderer = SDL_CreateRenderer(mApplication->getMainWindow().sdl(), -1, SDL_RENDERER_ACCELERATED);
    CASSERT(mRenderer, "Renderer failed to initialize");
}

SDL_Renderer* Renderer::sdl() const {
    return mRenderer;
}

void Renderer::synchronize() {
    SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(mRenderer);
    // \todo will get reworked to handle entities and layer content in general manner
    const auto entityList = mApplication->getActiveLayer()->getEntityList();
    SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    mApplication->getActiveLayer()->getTileMap()->render(*this, SHOW_BOUNDING_BOX);
    
    // \todo lock to avoid data race
    for (const auto& entity : entityList) {
        entity->render(*this, SHOW_BOUNDING_BOX);
    }
    SDL_RenderPresent(mRenderer);
}