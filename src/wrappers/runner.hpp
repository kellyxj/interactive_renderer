#include "SDLBox.hpp"

class Runner {
public:
    Runner();
    void setRenderer(Renderer* renderer);
    void setScene(Scene scene);
    bool init();
    void run();
    void close();

private:
    SDLBox sdl;
};