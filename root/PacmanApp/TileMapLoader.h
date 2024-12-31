#pragma once
#include "CoreLib/ITileMapLoader.h"
#include "CoreLib/TileMap.h"

PACMAN_NAMESPACE_BEGIN

class TileMapLoader : public ITileMapLoader {
public:
    TileMapLoader(const int tileSize, const int tileMapWidth, const int tileMapHeight);
    virtual std::shared_ptr<YACHT::TileMap> parse() const override;
};

PACMAN_NAMESPACE_END