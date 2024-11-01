#pragma once
#include "CoreLib/SceneNode.h"
#include "CoreLib/Texture.h"
#include <list>


class Tile : public SceneNode {
    const int                mTileSize;
    std::shared_ptr<Surface> mSurface;

public:
    Tile(const Pos position, const int width, const char* path);
    virtual void render(const Renderer& renderer, const bool drawBbox) const override;
    virtual BoundingBox getBoundingBox() const override;
};

class TileMap : public Entity {
    std::list<std::shared_ptr<Tile>> mTileList;

public:
    virtual void render(const Renderer& renderer, const bool drawBbox) const override;
    void addTile(std::shared_ptr<Tile> tile);
};