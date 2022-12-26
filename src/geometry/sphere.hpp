#include "geometry.hpp"

class Sphere : public Geometry {
    vec4 getNormal(vec4 & pos, ray & inRay);
    Hit trace(ray & inRay);
    void initVbo(SDL_GLContext context);
};