#ifndef __GEOMETRY_H__
#define __GEOMETRY_H__

#include "../primitives/mat4.hpp"
#include "../materials/material.hpp"
#include "../primitives/hit.hpp"
#include "../primitives/vec4.hpp"
#include "../wrappers/VBOBox.hpp"

class Geometry {
public:
    mat4 modelMatrix;
    mat4 worldToModel;
    mat4 normalToWorld;

    Material* material;
    VBOBox VBOBox;

    bool isLight = false;
    double brightness;

    void setMaterial(Material & m);
    virtual vec4 getNormal(vec4 & pos, ray & inRay) = 0;

    void setIdentity() {
        modelMatrix.setIdentity();
        worldToModel.setIdentity();
        normalToWorld.setIdentity();
    }

    void translate(vec4 & v);
    void rotate(double angle, vec4 & axis);
    void scale(vec4 & v);

    virtual Hit trace(ray & inRay) = 0;
    virtual ~Geometry() {}
    virtual int getType() = 0;

    virtual void drawPreview() = 0;
};

#endif