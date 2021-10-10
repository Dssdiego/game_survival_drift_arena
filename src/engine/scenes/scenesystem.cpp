//
// Created by dss-d on 10/10/2021.
//

#include "scenesystem.h"

void SceneSystem::nextScene() {
    // TODO: Check if is final scene (aka, can't go further in the map)
    mCurrentSceneId++;
    getCurrentScene().start();  // starts the new scene
    getLastScene().dispose();   // clears the last scene
}

void SceneSystem::previousScene() {
    // TODO: Check if is first scene (aka, can't go back in the map)
    mCurrentSceneId--;
    getCurrentScene().start();  // starts the new scene
    getLastScene().dispose();   // clears the last scene
}

void SceneSystem::addScene(Scene scene) {
    mScenes.push_back(scene);
}

void SceneSystem::removeScene(int id) {
    mScenes.erase(mScenes.begin() + id);
}

Scene SceneSystem::getCurrentScene() {
    return mScenes.at(mCurrentSceneId);
}

Scene SceneSystem::getLastScene() {
    return mScenes.at(mLastSceneId);
}

void SceneSystem::goToScene(int id) {
    // TODO: Check if the scene id is valid
    mCurrentSceneId = id;
    getCurrentScene().start(); // FIXME: This code is repeating!
    getLastScene().dispose();
}

std::vector<Scene> SceneSystem::getScenes() {
    return mScenes;
}
