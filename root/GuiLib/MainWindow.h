
class SDL_Window;

class MainWindow
{
private:
    SDL_Window* mWindow;

public:
    MainWindow(const char* title, int x, int y, int w, int h);
    ~MainWindow();

    void show();
};