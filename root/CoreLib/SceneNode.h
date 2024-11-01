#pragma once
#include "CoreLib/Entity.h"
#include "CoreLib/BoundingBox.h"
#include "CoreLib/Position.h"

class SceneNode : public Entity {
protected:
    Pos mPosition;

public:
    SceneNode() {}
    SceneNode(Pos position)
        : mPosition(position) {}

    Pos                 getPos() { return mPosition; }
    void                setPos(const Pos position) { mPosition = position; }
    virtual BoundingBox getBoundingBox() const = 0;
};