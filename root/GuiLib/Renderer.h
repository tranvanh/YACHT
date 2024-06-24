#pragma once

class SDL_Renderer;
class Application;

class Renderer {
    SDL_Renderer* mRenderer = nullptr;
    Application* mApplication;
public:
    Renderer(Application* mainWindow);
    ~Renderer() = default;
    void update();
    void draw();
};