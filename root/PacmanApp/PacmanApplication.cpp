#include "PacmanApp/PacmanApplication.h"
#include "PacmanApp/GameLayer.h"

const char* NAME = "PACMAN VOLE";

PacmanApplication::PacmanApplication()
    : Application(NAME) {
    mActiveLayer = std::make_shared<GameLayer>(*this);
}

void PacmanApplication::installEventHandlers() {
    // \todo more universal approach with custom onKeyboard handles
    // Have something like layerManager which switches the active layer?
    mEventPoll.registerHandler(SDL_KEYDOWN, [this](const SDL_Event event) {
        mActiveLayer->onKeyboard(event.key.keysym.sym);
    });
}