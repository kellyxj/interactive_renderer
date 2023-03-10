#include "window.hpp"
Window::Window() {
    width = 640;
    height = 480;
    activeCam = 0;
}

void Window::setRenderer(Renderer* _renderer) {
    renderer = _renderer;
}

void Window::setScene(Scene _scene) {
    scene = _scene;
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
    scene.context = context;
    scene.initVbos();
    return true;
}

void Window::render() {
    renderer->takeAPicture(scene, activeCam);
}

void Window::free() {
    if(window != NULL) {
        SDL_DestroyWindow(window);
    }
}