#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include "../defines.hpp"

class GLUniform {
public:
    GLuint index;
    GLenum type;
    GLint size;
    GLchar name[MAX_NAME_SIZE];
};