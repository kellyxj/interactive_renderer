#include "geometry.hpp"

class Plane : public Geometry {
    vec4 getNormal(vec4 & pos, ray & inRay);
    Hit trace(ray & inRay);
    void initVbo(SDL_GLContext context);
};