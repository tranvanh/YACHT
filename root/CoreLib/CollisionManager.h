#pragma once
#include <unordered_map>
#include <list>

YACHT_NAMESPACE_BEGIN

class SceneNode;

class CollisionManager{
    std::unordered_map<EntityId, std::list<std::shared_ptr<SceneNode>>> mRegisteredCollisions;

public:
    void registerCollision(const std::list<std::shared_ptr<SceneNode>>& nodes);

    // Test collision of single entity and return first colliding object
    //
    // \todo Bi 2025-01 if needed return all collision not only first
    std::shared_ptr<SceneNode> testCollision(const std::shared_ptr<SceneNode>& node) const;
    std::shared_ptr<SceneNode> collideAndClip(const std::shared_ptr<SceneNode>& node);
};

YACHT_NAMESPACE_END