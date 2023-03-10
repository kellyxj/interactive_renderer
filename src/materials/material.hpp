#ifndef __MATERIAL_H__
#define __MATERIAL_H__

#include "../defines.hpp"
#include "../primitives/vec4.hpp"
#include "../primitives/color.hpp"
#include "../primitives/ray.hpp"
#include <cmath>

class Material {
public:
    float brightness;
    virtual Color getColor(vec4 & pos) = 0;
    virtual ray scatter(ray & inRay, vec4 & pos, vec4 & normal) = 0;
};

#endif