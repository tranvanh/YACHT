#include "PacmanApp/PacmanApplication.h"
#include "PacmanApp/GameLayer.h"
#include "PacmanApp/Style.h"

PACMAN_NAMESPACE_BEGIN

PacmanApplication::PacmanApplication()
    : Application(Style::instance().NAME,
                  Style::instance().LEVEL.MAP_WIDTH*Style::instance().LEVEL.TILE_SIZE,
                  Style::instance().LEVEL.MAP_HEIGHT*Style::instance().LEVEL.TILE_SIZE) {
    mActiveLayer = std::make_shared<GameLayer>(*this);
}

void PacmanApplication::installEventHandlers() {
    // \todo more universal approach with custom onKeyboard handles
    // Have something like layerManager which switches the active layer?
    mEventPoll.registerHandler(SDL_KEYDOWN, [this](const SDL_Event event) {
        mActiveLayer->onKeyboard(event.key.keysym.sym);
    });
}

PACMAN_NAMESPACE_END