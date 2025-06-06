#pragma once
#include "CoreLib/SceneNode.h"
#include "CoreLib/Texture.h"
#include "CoreLib/BoundingBox.h"
#include <list>
#include <optional>

YACHT_NAMESPACE_BEGIN
class Tile : public SceneNode {
    const int                mTileSize;
    std::shared_ptr<Surface> mSurface;

public:
    Tile(const Pos position, const int width) : SceneNode(position), mTileSize(width){}
    Tile(const Pos position, const int width, const char* path);
    virtual void render(const Renderer& renderer, const bool drawBbox) const override;
    virtual BoundingBox getBoundingBox() const override;
    virtual std::shared_ptr<SceneNode> clone() const override;
};

class TileMap : public Entity {
protected:
    std::list<std::shared_ptr<Tile>> mTileList;
    std::list<std::shared_ptr<Tile>> mObstacleList;

public:
    virtual void render(const Renderer& renderer, const bool drawBbox) const override;

    void addTile(const std::shared_ptr<Tile>& tile);
    void addObstacle(const std::shared_ptr<Tile>& tile);

    std::list<std::shared_ptr<Tile>> getCollisionTiles() const { return mObstacleList; }
};

YACHT_NAMESPACE_END