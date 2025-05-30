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

std::optional<float> BoundingBox::horizontalCollisionDiff(const BoundingBox& other) const {
    if(topLeft.x < other.bottomRight.x && bottomRight.x > other.topLeft.x){
        float right = abs(topLeft.x - other.bottomRight.x);
        float left = abs(bottomRight.x - other.topLeft.x);
        return left < right ? left : right;
    }
    return std::nullopt;
}

std::optional<float> BoundingBox::verticalCollisionDiff(const BoundingBox& other) const {
    if(topLeft.y < other.bottomRight.y && bottomRight.y > other.topLeft.y){
        float up = abs(topLeft.y - other.bottomRight.y);
        float down = abs(bottomRight.y - other.topLeft.y);
        return up < down ? up : down;
    }
    return std::nullopt;
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