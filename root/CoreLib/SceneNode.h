#pragma once
#include "CoreLib/BoundingBox.h"
#include "CoreLib/Entity.h"
#include "CoreLib/Position.h"
#include <mutex>
#include <atomic>

YACHT_NAMESPACE_BEGIN

class SceneNode : public Entity {
    Pos mPosition;
    
protected:
    mutable std::atomic_bool dirty = false;
    void resetDirty() const {dirty = false;}

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
        dirty = true;
    }
    void moveBy(const Pos& pos) {
        Pos currentPos = getPos();
        currentPos += pos;
        setPos(currentPos);
    }
    virtual BoundingBox getBoundingBox() const = 0;
    virtual std::shared_ptr<SceneNode> clone() const = 0;
    bool isDirty() { return dirty;}
};

YACHT_NAMESPACE_END
