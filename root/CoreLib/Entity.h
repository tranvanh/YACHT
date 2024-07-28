#pragma once

#include "BoundingBox.h"

class Renderer;
struct Pos {
    float x = 0;
    float y = 0;
};

class Entity {
public:
    Pos         position;

public:
    Entity() = delete;
    explicit Entity(float x, float y)
        : position({ .x = x, .y = y }) {

        }

    void        setPosition(float x, float y) { position = { .x = x, .y = y }; }
    BoundingBox getBoundingBox() { return BoundingBox(position.x-10.,position.y-10.,position.x+10,position.y+10); }

    virtual void render(const Renderer& renderer, const bool drawBbox) = 0;
};