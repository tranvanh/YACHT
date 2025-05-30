#pragma once
#include "CoreLib/BoundingBox.h"
#include "CoreLib/Entity.h"
#include "CoreLib/Position.h"
#include <mutex>

YACHT_NAMESPACE_BEGIN

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
void moveBy(const Pos& pos) {
        Pos currentPos = getPos();
        currentPos += pos;
        setPos(currentPos);
    }
    virtual BoundingBox getBoundingBox() const = 0;
};

YACHT_NAMESPACE_END
