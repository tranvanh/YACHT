#include "CoreLib/CollisionManager.h"
#include "CoreLib/SceneNode.h"

YACHT_NAMESPACE_BEGIN

void CollisionManager::registerCollision(const std::list<std::shared_ptr<SceneNode>>& nodes) {
    for (const auto& node : nodes) {
        for (const auto& other : nodes) {
            if(node == other){
                continue;
            }
            mRegisteredCollisions[node->getId()].emplace_back(other);
        }
    }
}

// separate function, test and clip
std::shared_ptr<SceneNode> CollisionManager::testCollision(const std::shared_ptr<SceneNode>& node) const{
    const auto registeredNode = mRegisteredCollisions.find(node->getId());
    // Check if node has any registered collisions
    if (registeredNode == mRegisteredCollisions.end()) {
        return nullptr;
    }

    for(const auto& collisionNode: registeredNode->second){
        if(BoundingBox::collision(node->getBoundingBox(), collisionNode->getBoundingBox())){
            return collisionNode;
        }
    }
    return nullptr;
}

YACHT_NAMESPACE_END