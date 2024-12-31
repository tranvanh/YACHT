#pragma once
#include "CoreLib/Position.h"
#include "SDL2/SDL.h"

YACHT_NAMESPACE_BEGIN
struct BoundingBox {
    Pos topLeft;
    Pos bottomRight;

    BoundingBox() = delete;
    BoundingBox(const Pos tL, const Pos bR);
    bool        collidesWith(const BoundingBox& other) const;
    static bool collision(const BoundingBox& a, const BoundingBox& b);
    SDL_Rect    sdl() const;
};

YACHT_NAMESPACE_END
