#pragma once

#include "../GuiLib/Control.h"

class Player;
class Application;

// \todo Game will have several screen types?
class Game : public Control {
    Player* mPlayer;
    Application& mApplication;
    
public:
    Game(Application& application);
    ~Game();
    virtual void onKeyboard(SDL_Keycode key) override;
    Player& getPlayer() const;
private:
    void onMoveLeft();
    void onMoveRight();
    void onMoveUp();
    void onMoveDown();
};