#include "wrappers/runner.hpp"
#include <stdio.h>
#include <string>
#include <iostream>
#include <unistd.h>

int main( int argc, char* args[] ) {
    Runner runner;
    Scene scene;
    //add stuff to scene here
    //scene.items.push_back(...)
    //scene.cameras.push_back(...)

    MeshRenderer previewRenderer;
    runner.setRenderer((Renderer*)(&previewRenderer));
    runner.setScene(scene);
    
    runner.init();
    runner.run();
    return 0;
}