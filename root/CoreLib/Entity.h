#pragma once
#include <mutex>

YACHT_NAMESPACE_BEGIN

class Renderer;
static int g_EntityId = 0;
class Entity {
    int mId;

protected:
    mutable std::mutex mLock;

public:
    Entity()
        : mId(g_EntityId++) {}
    virtual ~Entity() {}
    virtual void render(const Renderer& renderer, const bool drawBbox) const = 0;
    inline bool  operator==(const Entity& other) { return mId == other.mId; }
    inline bool  operator!=(const Entity& other) { return mId != other.mId; }
};

YACHT_NAMESPACE_END
