#include <SDL2/SDL.h>

class Window {
public:
    Window();
    bool init();
    void free();

private:
    SDL_Window* window;
    SDL_GLContext context;
    int width;
    int height;

    bool mouseFocus;
    bool keyboardFocus;
    bool fullscreen;
    bool minimized;
};