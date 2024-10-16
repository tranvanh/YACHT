#include "PacmanApp/PacmanApplication.h"
#include "PacmanApp/GameLayer.h"
#include "PacmanApp/Style.h"

PacmanApplication::PacmanApplication()
    : Application(Style::instance().NAME,
                  Style::instance().METRICS.WINDOW_W,
                  Style::instance().METRICS.WINDOW_H) {
    mActiveLayer = std::make_shared<GameLayer>(*this);
}

void PacmanApplication::installEventHandlers() {
    // \todo more universal approach with custom onKeyboard handles
    // Have something like layerManager which switches the active layer?
    mEventPoll.registerHandler(SDL_KEYDOWN, [this](const SDL_Event event) {
        mActiveLayer->onKeyboard(event.key.keysym.sym);
    });
}