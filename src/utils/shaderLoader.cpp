#include "shaderLoader.hpp"

std::string loadShaderFromFile(std::string filepath) {
    std::ifstream file(filepath);

    std::string line;
    std::string output;

    if(file.is_open()) {
        while(getline(file, line)) {
            output += line + "\n";
        }
    }
    return output;
}