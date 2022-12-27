#ifndef __VBOBOX_H__
#define __VBOBOX_H__

#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <vector>
#include <string>
#include "../utils/logger.hpp"

class VBOBox {
public:
    bool initialized;
    VBOBox();
    bool init(SDL_GLContext _context, std::vector<float> & vboContents, std::string _vertexShaderSource, std::string _fragmentShaderSource);
    void switchToMe();
    bool isReady();
    void adjust(); //Adjust values of uniforms. Input must match shader program
    void draw();
    void reload();

private:
    SDL_GLContext context;
    GLuint programID;
};

#endif