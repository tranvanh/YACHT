#include "CoreLib/TileMap.h"

Tile::Tile(const Pos position, const int width, const char* path)
    : SceneNode(position), mTileSize(width) {
    mSurface = std::make_shared<Surface>(path, *this);
}

BoundingBox Tile::getBoundingBox() const{
    Pos position = getPos();
    return BoundingBox(Pos(position.x, position.y),
                       Pos(position.x + mTileSize, position.y + mTileSize));
}
void Tile::render(const Renderer& renderer, const bool drawBbox) const {
    mSurface->render(renderer, drawBbox);
}

void TileMap::render(const Renderer& renderer, const bool drawBbox) const {
    for (const auto& tile : mTileList) {
        tile->render(renderer, drawBbox);
    }
}

void TileMap::addTile(std::shared_ptr<Tile> tile){
    mTileList.push_back(tile);
}
