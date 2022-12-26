#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <iostream>

void printProgramLog( GLuint program );
void printShaderLog(GLuint shader);

#endif