#pragma once
#include "CoreLib/Entity.h"
#include "CoreLib/BoundingBox.h"
#include "CoreLib/Position.h"
#include <mutex>

class SceneNode : public Entity {
private:
    Pos mPosition;

public:
    SceneNode() {}
    SceneNode(Pos position)
        : mPosition(position) {}

    Pos getPos() const {
        std::lock_guard<std::mutex> lock(mLock);
        return mPosition;
    }
    void setPos(const Pos position) {
        std::lock_guard<std::mutex> lock(mLock);
        mPosition = position;
    }
    virtual BoundingBox getBoundingBox() const = 0;
};