#pragma once

struct BoundingBox {
    float x1 = 0;
    float y1 = 0;
    float x2 = 0;
    float y2 = 0;

    BoundingBox() = delete;
    BoundingBox(const float x1, const float y1, const float x2, const float y2)
        : x1(x1)
        , y1(y1)
        , x2(x2)
        , y2(y2) {}

    bool collidesWith(const BoundingBox& other) const {
        return x1 <= other.x2 && x2 >= other.x1 && y1 >= other.y2 && y2 <= other.y1;
    }
    static bool collision(const BoundingBox& a, const BoundingBox& b) { return a.collidesWith(b); }
};