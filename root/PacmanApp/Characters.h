#pragma once

#include "CoreLib/SceneNode.h"
#include "CoreLib/Texture.h"
#include "PacmanApp/Style.h"

class GameEntity : public SceneNode {
protected:
    // \todo Bi 2024-07 Move to parent inheritance and with general resources list
    std::shared_ptr<Surface> mSurface;

public:
    GameEntity(Pos position)
        : SceneNode(position) {}
    bool collidesWith(const GameEntity& other) const;

    virtual void render(const Renderer& renderer, const bool drawBbox) const override;
protected:
    Style& style() const { return Style::instance(); }
};

class StaticItem : public GameEntity {
public:
    StaticItem(Pos position)
        : GameEntity(position) {
        mSurface = std::make_shared<Surface>(style().RESOURCES.ITEM_SURFACE, *this);
    }

    virtual BoundingBox getBoundingBox() const override;
};

class Player : public GameEntity {
public:
    Player(Pos position)
        : GameEntity(position) {
        mSurface = std::make_shared<Surface>(style().RESOURCES.PLAYER_SURFACE, *this);
    }

    virtual BoundingBox getBoundingBox() const override;
};