#include "wrappers/runner.hpp"
#include <stdio.h>
#include <string>
#include <iostream>
#include <unistd.h>

int main( int argc, char* args[] ) {
    Runner runner;
    runner.init();

    MeshRenderer previewRenderer;
    runner.setRenderer((Renderer*)(&previewRenderer));

    Scene scene;
    Plane plane;

    scene.items.push_back(&plane);
    scene.initVbos();
    //scene.cameras.push_back(...)
    runner.setScene(scene);
    
    runner.run();
    return 0;
}