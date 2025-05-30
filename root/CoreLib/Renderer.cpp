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
#include "SDL_image.h"
#include "Common.h"

YACHT_NAMESPACE_BEGIN

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
    SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    mApplication->getActiveLayer()->render(*this, SHOW_BOUNDING_BOX);
    SDL_RenderPresent(mRenderer);
}

YACHT_NAMESPACE_END