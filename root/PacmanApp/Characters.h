#pragma once

#include "CoreLib/Entity.h"
#include "CoreLib/Texture.h"

class Player : public Entity {
    
    // \todo Bi 2024-07 Move to parent inheritance and with general resources list
    std::shared_ptr<Surface> mSurface = std::make_shared<Surface>("../root/resources/test.png");
public:
    Player(float x, float y)
        : Entity(x, y) {
    }

    virtual void render(const Renderer& renderer, const bool drawBbox) override;
};