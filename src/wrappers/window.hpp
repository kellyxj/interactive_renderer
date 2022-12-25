#include <SDL2/SDL.h>
#include "../scene.hpp"

class Window {
public:
    Window();
    bool init();
    void render();
    void free();

private:
    SDL_Window* window;
    SDL_GLContext context;
    Scene* scene;
    Renderer* renderer;
    int width;
    int height;

    bool mouseFocus;
    bool keyboardFocus;
    bool fullscreen;
    bool minimized;

    int activeCam;
};