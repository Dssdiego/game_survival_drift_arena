#include "scene.h"

Scene::Scene(const std::string &name) : mName(name) {}

void Scene::start() {
    std::cout << "Starting scene " << mName << std::endl;
}

void Scene::dispose() {
    std::cout << "Cleaning the scene " << mName << std::endl;
}

void Scene::draw() {
    std::cout << "Drawing the contents of the scene " << mName << std::endl;
}
