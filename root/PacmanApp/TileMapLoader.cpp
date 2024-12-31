#include "PacmanApp/TileMapLoader.h"
#include "CoreLib/ITileMapLoader.h"
#include "PacmanApp/Style.h"
#include <fstream>
#include <list>
#include <sstream>
#include <string>
#include <unordered_map>

PACMAN_NAMESPACE_BEGIN

TileMapLoader::TileMapLoader(const int tileSize, const int tileMapWidth, const int tileMapHeight)
    : ITileMapLoader(tileSize, tileMapWidth, tileMapHeight) {}

std::shared_ptr<YACHT::TileMap> TileMapLoader::parse() const {
    auto&                                style     = Style::instance();
    auto&                                resources = style.RESOURCES;
    std::unordered_map<int, const char*> tileResources;

    auto tileMap = std::make_shared<TileMap>();

    // \todo 2024-10 Can we improve this so it wouldn't be so manual?
    tileResources.insert({ resources.GRASS.tileId, resources.GRASS.resource });
    tileResources.insert({ resources.GROUND.tileId, resources.GROUND.resource });

    Pos currentPos = Pos(0.f, 0.f);

    std::ifstream mapFile(style.LEVEL.TEST_LEVEL);
    CASSERT(mapFile.is_open(), "Failed to open file");
    std::string line;
    while (mapFile >> line) {
        CASSERT(line.length() / 2 == mTileMapWidth, "Parsing error: tile map width mismatch");
        std::istringstream iss(line);
        int                tile;
        char               delim;
        // \ todo 2024-10 Needs clean up and better design
        while (iss >> tile >> delim) {
            auto tileInfo = tileResources.find(tile);
            CASSERT(tileInfo != tileResources.end(), "Parsing error: tile id not found");
            tileMap->addTile(std::make_shared<Tile>(currentPos, 50, tileInfo->second));
            currentPos.x += 50;
        }
        currentPos.x = 0.f;
        currentPos.y += 50;
    }
    mapFile.close();
    return tileMap;
}

PACMAN_NAMESPACE_END