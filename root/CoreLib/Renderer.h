#pragma once
#include <unordered_map>
#include <mutex>

struct SDL_Renderer;

YACHT_NAMESPACE_BEGIN

class Application;
class TextureManager;
class SceneNode;

constexpr bool SHOW_BOUNDING_BOX = true;
class Renderer {
    SDL_Renderer* mRenderer = nullptr;
    Application*  mApplication;

    struct{
        std::unordered_map<std::shared_ptr<SceneNode>, std::shared_ptr<SceneNode>> list;
        std::mutex lock;
    } mEntities;
public:
    Renderer(Application* application);
    ~Renderer() = default;

    // \todo use flags and generalize the solution
    void          synchronize(const bool dirtyOnly = true);
    void          render();
    SDL_Renderer* sdl() const;

private:
    void drawBoundingBoxes();
};

YACHT_NAMESPACE_END
