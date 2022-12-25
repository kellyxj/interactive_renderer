#include "runner.hpp"

Runner::Runner() {

}

bool Runner::init() {
    bool success = true;

	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
    else {
        success = sdl.init();

    }
    return success;
}

void Runner::run() {
    bool quit = false;
    SDL_Event e;

    while(!quit) {
        while(SDL_PollEvent(&e) != 0) {
            if( e.type == SDL_QUIT ) {
				quit = true;
			}
        }
        //sdl.render();
    }
    close();
}

void Runner::close() {
    sdl.free();
    SDL_Quit();
}