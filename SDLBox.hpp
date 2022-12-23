#ifndef __SDLBOX_H__
#define __SDLBOX_H__

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>

class SDLBox {
public:
    bool renderOn;

    SDLBox() {
        window = NULL;
        renderOn = true;
    }
    bool init();
    void render();

private:
    SDL_Window* window;
}

#endif