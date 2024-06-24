#pragma once

struct Pos {
    float x = 0;
    float y = 0;
};

struct BoundingBox {
    float w = 0;
    float h = 0;
};

/// x,y denotes bottom left corner of the bounding box
class Entity {
public:
    Pos position;
    BoundingBox bbox;
public:
    Entity() = delete;
    explicit Entity(float x, float y) : position({ .x = x, .y = y }) {}

    Pos getPosition() { return position; }
    void setPosition(float x, float y) { position = { .x = x, .y = y }; }
    BoundingBox getBoundingBox() { return bbox; }
    void setBoundingBox(float w, float h) { bbox = { .w = w, .h = h }; }
};