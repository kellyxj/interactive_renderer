#include "wrappers/runner.hpp"
#include <stdio.h>
#include <string>
#include <iostream>
#include <unistd.h>

int main( int argc, char* args[] ) {
    Runner runner;
    runner.init();
    runner.run();
    return 0;
}