#pragma once

struct Pos {
    float x;
    float y;

    Pos() = default;
    Pos(const float x, const float y)
        : x(x)
        , y(y) {}
    Pos& operator*=(float number) {
        x *= number;
        y *= number;
        return *this;
    }

    bool operator==(const Pos& other) { return x == other.x && y == other.y; }
};