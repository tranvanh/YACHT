#pragma once

class SDL_Renderer;
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