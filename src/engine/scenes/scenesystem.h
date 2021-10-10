//
// Created by dss-d on 10/10/2021.
//

#pragma once

#include <vector>
#include "scene.h"

class SceneSystem {
public:
    static void addScene(Scene scene);
    static void removeScene(int id);
    static void nextScene();
    static void previousScene();
    static void goToScene(int id);

    static std::vector<Scene> getScenes();
private:
    inline static std::vector<Scene> mScenes = {};
    inline static int mCurrentSceneId = 0;
    inline static int mLastSceneId = 0;

    static Scene getCurrentScene();
    static Scene getLastScene();
};
