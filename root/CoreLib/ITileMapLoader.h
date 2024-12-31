#pragma once
#include <memory>

YACHT_NAMESPACE_BEGIN

class TileMap;
class ITileMapLoader {
protected:
    const int mTileSize;
    const int mTileMapWidth;
    const int mTileMapHeight;

public:
    ITileMapLoader(const int tileSize, const int tileMapWidth, const int tileMapHeight)
        : mTileSize(tileSize)
        , mTileMapWidth(tileMapWidth)
        , mTileMapHeight(tileMapHeight) {}
    virtual std::shared_ptr<TileMap> parse() const = 0;
};

YACHT_NAMESPACE_END
