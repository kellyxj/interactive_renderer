#include "meshRenderer.hpp"

void MeshRenderer::takeAPicture(Scene & scene, int camIndex) {
    for(Geometry* item : scene.items) {
        item->drawPreview();
    }
}