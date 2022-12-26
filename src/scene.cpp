#include "scene.hpp"

void Scene::initVbos() {
    for(Geometry* item : items) {
        item->initVbo(context);
    }
    for(Geometry* light : lights) {
        light->initVbo(context);
    }
}

void Scene::save() {

}

void Scene::load(std::string filepath) {
    
}