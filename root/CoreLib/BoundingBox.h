#pragma once
#include "CoreLib/Position.h"
#include "SDL2/SDL.h"
#include <optional>

YACHT_NAMESPACE_BEGIN
struct BoundingBox {
    Pos topLeft;
    Pos bottomRight;

    BoundingBox() = delete;
    BoundingBox(const Pos tL, const Pos bR);
    bool        collidesWith(const BoundingBox& other) const;
    std::optional<float>        horizontalCollisionDiff(const BoundingBox& other) const;
    std::optional<float>        verticalCollisionDiff(const BoundingBox& other) const;
    static bool collision(const BoundingBox& a, const BoundingBox& b);
    SDL_Rect    sdl() const;
};

YACHT_NAMESPACE_END
