#include "CoreLib/Renderer.h"
#include "PacmanApp/Characters.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

void Player::render(const Renderer& renderer, const bool drawBbox){
    SDL_Rect rectangle;
    BoundingBox bbox = getBoundingBox();
    rectangle.x = bbox.x1;
    rectangle.y = bbox.y1;
    rectangle.w = abs(bbox.x1 - bbox.x2);
    rectangle.h = abs(bbox.y1 - bbox.y2);
    if(drawBbox){
        SDL_RenderDrawRect(renderer.sdl(), &rectangle);
    }
    auto texture = std::make_shared<Texture>(mSurface, renderer);
    SDL_RenderCopy(renderer.sdl(),texture->sdl(),NULL,&rectangle);
}