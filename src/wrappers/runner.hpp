#include "SDLBox.hpp"

class Runner {
public:
    Runner();
    bool init();
    void run();
    void close();

private:
    SDLBox sdl;
};