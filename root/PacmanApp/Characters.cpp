#include "PacmanApp/Characters.h"
#include "CoreLib/Renderer.h"
#include "SDL2/SDL.h"
#include "SDL_image.h"

PACMAN_NAMESPACE_BEGIN

void GameEntity::render(const Renderer& renderer, const bool drawBbox) const {
    auto rectangle = getBoundingBox().sdl();
    if (drawBbox) {
        SDL_RenderDrawRect(renderer.sdl(), &rectangle);
    }
    mSurface->render(renderer, drawBbox);
}

bool GameEntity::collidesWith(const SceneNode& other) const {
    return BoundingBox::collision(getBoundingBox(), other.getBoundingBox());
}

BoundingBox StaticItem::getBoundingBox() const {
    auto& metrics  = style().METRICS;
    Pos   position = getPos();

    // \todo use different size
    return BoundingBox(Pos(position.x - metrics.PLAYER_SIZE, position.y - metrics.PLAYER_SIZE),
                       Pos(position.x + metrics.PLAYER_SIZE, position.y + metrics.PLAYER_SIZE));
}

BoundingBox Player::getBoundingBox() const {
    auto& metrics  = style().METRICS;
    Pos   position = getPos();
    return BoundingBox(Pos(position.x - metrics.PLAYER_SIZE, position.y - metrics.PLAYER_SIZE),
                       Pos(position.x + metrics.PLAYER_SIZE, position.y + metrics.PLAYER_SIZE));
}

PACMAN_NAMESPACE_END