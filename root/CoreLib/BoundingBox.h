#pragma once
#include "CoreLib/Position.h"
#include "SDL2/SDL.h"

struct BoundingBox {
    Pos topLeft;
    Pos bottomRight;

    BoundingBox() = delete;
    BoundingBox(const Pos tL, const Pos bR);
    bool        collidesWith(const BoundingBox& other) const;
    static bool collision(const BoundingBox& a, const BoundingBox& b);
    SDL_Rect    sdl() const;
};