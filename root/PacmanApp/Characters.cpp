#include "PacmanApp/Characters.h"
#include "CoreLib/Renderer.h"
#include "SDL2/SDL.h"
#include "SDL_image.h"
#include <cstdlib>

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

BoundingBox Monster::getBoundingBox() const {
    return getBoundingBoxForPosition(getPos());
}

Pos Monster::generateNewPosition() const {

    // \todo Bi 2024-12 make proper movement logic
    Pos currentPos = getPos();
    bool   isHorizontal = rand() % 2;
    float* modified     = isHorizontal ? &currentPos.x : &currentPos.y;
    bool   isPositive   = rand() % 2;
    *modified += isPositive ? 10.f : -10.f;
    return currentPos;
}

BoundingBox Monster::getBoundingBoxForPosition(const Pos& position) const {
    auto& metrics  = style().METRICS;
    return BoundingBox(Pos(position.x - metrics.MONSTER_SIZE*0.5f, position.y - metrics.MONSTER_SIZE*0.5f),
                       Pos(position.x + metrics.MONSTER_SIZE*0.5f, position.y + metrics.MONSTER_SIZE*0.5f));
}

BoundingBox Player::getBoundingBox() const {
    return getBoundingBoxForPosition(getPos());
}

BoundingBox Player::getBoundingBoxForPosition(const Pos& position) const {
    auto& metrics  = style().METRICS;
    return BoundingBox(Pos(position.x - metrics.PLAYER_SIZE*0.5f, position.y - metrics.PLAYER_SIZE*0.5f),
                       Pos(position.x + metrics.PLAYER_SIZE*0.5f, position.y + metrics.PLAYER_SIZE*0.5f));
}

PACMAN_NAMESPACE_END