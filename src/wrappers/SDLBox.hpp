#ifndef __SDLBOX_H__
#define __SDLBOX_H__

#include "window.hpp"
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>
#include "../renderers/renderer.hpp"

class SDLBox {
public:
    bool renderOn;

    SDLBox();
    bool init();
    void render();
    void free();

private:
    Window window;
};

#endif