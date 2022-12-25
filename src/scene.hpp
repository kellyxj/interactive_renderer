#ifndef __SCENE_H__
#define __SCENE_H__

#include "geometry/geometry.hpp"
#include "cameras/camera.hpp"
#include <vector>

class Scene {
public:
    std::vector<Geometry*> items;
    std::vector<Camera*> cameras;
    std::vector<Geometry*> lights;

    void save();
    void load(std::string filepath);
};

#endif