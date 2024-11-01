#pragma once
#include "CoreLib/ITileMapLoader.h"
#include "CoreLib/TileMap.h"

class TileMapLoader : public ITileMapLoader {
public:
    TileMapLoader(const int tileSize, const int tileMapWidth, const int tileMapHeight);
    virtual std::shared_ptr<TileMap> parse() const override;
};