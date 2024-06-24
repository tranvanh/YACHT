#pragma once

struct Pos {
    float x = 0;
    float y = 0;
};

class Entity {
public:
    Pos position;
    Pos getPosition() { return position; }
    void setPosition(float x, float y) { position = { .x = x, .y = y }; }
};