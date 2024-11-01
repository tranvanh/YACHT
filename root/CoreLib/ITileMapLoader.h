#pragma once
#include <memory>

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