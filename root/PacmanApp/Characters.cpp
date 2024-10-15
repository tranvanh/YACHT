#include "PacmanApp/Characters.h"
#include "CoreLib/Renderer.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

void GameEntity::render(const Renderer& renderer, const bool drawBbox) {
    auto rectangle = getBoundingBox().sdl();
    if (drawBbox) {
        SDL_RenderDrawRect(renderer.sdl(), &rectangle);
    }
    mSurface->render(renderer, drawBbox);
}

bool GameEntity::collidesWith(const GameEntity& other) const {
    return BoundingBox::collision(getBoundingBox(), other.getBoundingBox());
}

BoundingBox StaticItem::getBoundingBox() const {
    auto& metrics = style().METRICS;
    return BoundingBox(Pos(mPosition.x - metrics.PLAYER_SIZE, mPosition.y - metrics.PLAYER_SIZE),
                       Pos(mPosition.x + metrics.PLAYER_SIZE, mPosition.y + metrics.PLAYER_SIZE));
}

BoundingBox Player::getBoundingBox() const {
    auto& metrics = style().METRICS;
    return BoundingBox(Pos(mPosition.x - metrics.PLAYER_SIZE, mPosition.y - metrics.PLAYER_SIZE),
                       Pos(mPosition.x + metrics.PLAYER_SIZE, mPosition.y + metrics.PLAYER_SIZE));
}