//
// Created by dss-d on 05/10/2021.
//

#pragma once

#include <vector>
#include "scene.h"

class Game {
public:
    virtual void init();
    virtual void draw();
    virtual void update();
    virtual void cleanUp();
private:
    std::vector<Scene> mScenes;
    Scene mCurrentScene;

    void addScene(Scene scene);
    void removeScene(Scene scene);
//    void removeScene(int sceneIdx);
    void goToScene(Scene scene);
//    void goToScene(int sceneIndex);
};
