#ifndef __SDLBOX_H__
#define __SDLBOX_H__

#include "window.hpp"
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>

class SDLBox {
public:
    bool renderOn;

    SDLBox();
    void setRenderer(Renderer* renderer);
    void setScene(Scene scene);
    bool init();
    void render();
    void free();

private:
    Window window;
};

#endif