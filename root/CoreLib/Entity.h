#pragma once

class Renderer;
static int g_EntityId = 0;
class Entity {
    int mId;
public:
    Entity() : mId(g_EntityId++){}
    virtual void render(const Renderer& renderer, const bool drawBbox) const = 0;
    inline bool operator==(const Entity& other) { return mId == other.mId; }
    inline bool operator!=(const Entity& other) { return mId != other.mId; }
};