#pragma once

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
        const float PLAYER_SIZE = 30.f;
        const int   WINDOW_W    = 640;
        const int   WINDOW_H    = 480;
    } METRICS;
    const struct {
        // \todo 2024-10 Improve the resources path
        const char* PLAYER_SURFACE = "../root/resources/player.png";
        const char* ITEM_SURFACE   = "../root/resources/item.png";
        const TileInfo  GROUND         = { 0, "../root/resources/ground.png" };
        const TileInfo  GRASS          = { 1, "../root/resources/grass.png" };
    } RESOURCES;

    const struct { const char* TEST_LEVEL = "../root/resources/test8x8.map"; } LEVEL;

    static Style& instance() {
        static Style style;
        return style;
    }
};