#ifndef __RENDERER_H__
#define __RENDERER_H__

#include "../scene.hpp"

class Renderer {
public:
    virtual void takeAPicture(Scene & scene, int camIndex) = 0;
};

#endif