#pragma once

struct SDL_Renderer;

YACHT_NAMESPACE_BEGIN

class Application;
class TextureManager;

constexpr bool SHOW_BOUNDING_BOX = true;
class Renderer {
    SDL_Renderer* mRenderer = nullptr;
    Application*  mApplication;

public:
    Renderer(Application* application);
    ~Renderer() = default;

    // \todo use flags and generalize the solution
    void          synchronize();
    SDL_Renderer* sdl() const;

private:
    void drawBoundingBoxes();
};

YACHT_NAMESPACE_END
