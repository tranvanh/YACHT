#include "CoreLib/BoundingBox.h"
#include "SDL2/SDL.h"

BoundingBox::BoundingBox(const Pos tL, const Pos bR)
    : topLeft(tL)
    , bottomRight(bR) {}

bool BoundingBox::collidesWith(const BoundingBox& other) const {
    return topLeft.x <= other.bottomRight.x && bottomRight.x >= other.topLeft.x &&
           topLeft.y <= other.bottomRight.y && bottomRight.y >= other.topLeft.y;
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