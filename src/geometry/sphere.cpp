#include "sphere.hpp"

vec4 Sphere::getNormal(vec4 & pos, ray & inRay) {
    vec4 normVec(pos.x, pos.y, pos.z, 0);
    normVec = (this->worldToModel).transform(normVec);
    if(normVec.dot(inRay.direction) > 0) {
        normVec = normVec * -1;
    }
    return normVec;
}

Hit Sphere::trace(ray & inRay) {
    vec4 origin = (this->worldToModel).transform(inRay.origin);
    vec4 dir = (this->worldToModel).transform(inRay.direction);

    ray ray(origin, dir);

    vec4 center(0,0,0,1);
    vec4 r2s = center-origin;

    float L2 = r2s.length();
    float tcaS = dir.dot(r2s);

    Hit hit;
    //rays originating inside sphere
    if(L2 <= 1) {
        float DL2 = dir.length();

        float tca2 = tcaS * tcaS/DL2;
        float LM2 = L2 - tca2;

        float L2hc = 1-LM2;
        float t0 = tcaS/DL2 + sqrt(L2hc/DL2);

        hit.t = t0;
        hit.pos = inRay.origin + (inRay.direction * t0);
        hit.modelSpacePos = origin + (dir * t0);
        hit.normal = this->getNormal(hit.modelSpacePos, ray);
        hit.material = this->material;
        hit.inRay = inRay;
    }
    //if tcaS < 0, sphere is behind the camera
    else if(tcaS >= 0) {
        float DL2 = dir.length();

        float tca2 = tcaS * tcaS/DL2;
        float LM2 = L2 - tca2;

        if(LM2 <= 1) {
            float L2hc = 1-LM2;
            float t0 = tcaS/DL2 - sqrt(L2hc/DL2);
            float t1 = tcaS/DL2 + sqrt(L2hc/DL2);

            hit.t = t0;
            hit.pos = inRay.origin + (inRay.direction * t0);
            hit.modelSpacePos = origin + (dir * t0);
            hit.normal = this->getNormal(hit.modelSpacePos, ray);
            hit.material = this->material;
            hit.inRay = inRay;
        }
    }
    return hit;
}

void Sphere::initVbo(SDL_GLContext context) {
    std::vector<float> vboContents;
    std::string vertexShaderSource = loadShaderFromFile("../../data/shaders/wireframe.vert");
    std::string fragmentShaderSource = loadShaderFromFile("../../data/shaders/wireframe.frag");
    vboBox.init(context, vboContents, vertexShaderSource, fragmentShaderSource);
}