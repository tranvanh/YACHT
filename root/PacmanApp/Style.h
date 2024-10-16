#pragma once

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
        const char* PLAYER_SURFACE = "/home/tranvanh/coding/pacman/root/resources/player.png";
        const char* ITEM_SURFACE   = "/home/tranvanh/coding/pacman/root/resources/item.png";
    } RESOURCES;
    static Style& instance() {
        static Style style;
        return style;
    }
};