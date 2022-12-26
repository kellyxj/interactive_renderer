#ifndef __SCENE_H__
#define __SCENE_H__

#include "geometry/geometryIncludes.hpp"
#include "cameras/camera.hpp"
#include <vector>

class Scene {
public:
    SDL_GLContext context;
    std::vector<Geometry*> items;
    std::vector<Camera*> cameras;
    std::vector<Geometry*> lights;

    void initVbos();
    void save();
    void load(std::string filepath);
};

#endif