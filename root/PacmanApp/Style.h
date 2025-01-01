#pragma once

PACMAN_NAMESPACE_BEGIN

struct TileInfo {
    int         tileId;
    const char* resource;
    TileInfo(int id, const char* path)
        : tileId(id)
        , resource(path) {}
};
class Style {
private:
    Style() {}

public:
    const char* NAME = "PACMAN VOLE";
    const struct {
        const float PLAYER_SIZE = 44.f;
        const float MONSTER_SIZE = 34.f;
        const int   WINDOW_W    = 640;
        const int   WINDOW_H    = 480;
    } METRICS;
    const struct {
        // \todo 2024-10 Improve the resources path
        const char* PLAYER_SURFACE = "../root/resources/player.jpg";
        const char* ITEM_SURFACE   = "../root/resources/item.png";
        const TileInfo  GROUND         = { 0, "../root/resources/ground.png" };
        const TileInfo  GRASS          = { 1, "../root/resources/grass.png" };
    } RESOURCES;

    const struct {
        const char* TEST_LEVEL  = "../root/resources/test8x8.map";
        const int   TILE_SIZE   = 50;
        const int   MAP_WIDTH  = 11;
        const int   MAP_HEIGHT = 8;
    } LEVEL;

    static Style& instance() {
        static Style style;
        return style;
    }
};

PACMAN_NAMESPACE_END