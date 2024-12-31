#include "CoreLib/BoundingBox.h"
#include "SDL2/SDL.h"
#include "Common.h"

YACHT_NAMESPACE_BEGIN

BoundingBox::BoundingBox(const Pos tL, const Pos bR)
    : topLeft(tL)
    , bottomRight(bR) {
        CASSERT(topLeft != bottomRight, "Invalid bounding box");
    }

bool BoundingBox::collidesWith(const BoundingBox& other) const {
    SDL_Rect thisSdl = sdl();
    SDL_Rect otherSdl = other.sdl();
    return SDL_HasIntersection(&thisSdl, &otherSdl);
}

bool BoundingBox::collision(const BoundingBox& a, const BoundingBox& b) {
    return a.collidesWith(b);
}

SDL_Rect BoundingBox::sdl() const {
    SDL_Rect rectangle;
    rectangle.x = topLeft.x;
    rectangle.y = topLeft.y;
    rectangle.w = abs(topLeft.x - bottomRight.x);
    rectangle.h = abs(topLeft.y - bottomRight.y);
    return rectangle;
}

YACHT_NAMESPACE_END