#include "plane.hpp"

vec4 Plane::getNormal(vec4 & pos, ray & inRay) {
    vec4 v(0,0,1,0);
    if(v.dot(inRay.direction) > 0) {
        v.z = -1;
    }
    return (this->normalToWorld).transform(v);
}

Hit Plane::trace(ray & inRay) {
    vec4 origin = (this->worldToModel).transform(inRay.origin);
    vec4 dir = (this->worldToModel).transform(inRay.direction);

    ray ray(origin, dir);

    double t0 = -origin.z/dir.z;
    Hit hit;
    if(t0 >= 0) {
        hit.t = t0;
        hit.pos = inRay.origin + (inRay.direction * t0);
        hit.modelSpacePos = origin + (dir * t0);
        hit.normal = this->getNormal(hit.pos, ray);
        hit.material = this->material;
        hit.inRay = inRay;
    }
    return hit;
}

void Plane::initVbo(SDL_GLContext context) {
    std::vector<double> vboContents;
    std::string vertexShaderSource = loadShaderFromFile("data/shaders/wireframe.vert");
    std::string fragmentShaderSource = loadShaderFromFile("data/shaders/wireframe.frag");
    vboBox.init(context, vboContents, vertexShaderSource, fragmentShaderSource);
}