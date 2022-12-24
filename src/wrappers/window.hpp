#include <SDL2/SDL.h>

class Window {
public:
    Window();
    bool init();
    SDL_Renderer* createRenderer();

private:
    SDL_Window* window;
    int width;
    int height;

    bool mouseFocus;
    bool keyboardFocus;
    bool fullscreen;
    bool minimized;
};