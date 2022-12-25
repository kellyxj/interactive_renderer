#include "window.hpp"
Window::Window() {
    width = 640;
    height = 480;
}

bool Window::init() {
    window = SDL_CreateWindow("window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    if(window == NULL) {
        printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
		return false;
    }
    else {
        context = SDL_GL_CreateContext( window );
		if( context == NULL )
		{
			printf( "OpenGL context could not be created! SDL Error: %s\n", SDL_GetError() );
			return false;
		}
    }
    return true;
}

void Window::free() {
    if(window != NULL) {
        SDL_DestroyWindow(window);
    }
}