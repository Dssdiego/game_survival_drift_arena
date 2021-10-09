//
// Created by dss-d on 08/10/2021.
//

#pragma once

#include "fmod.hpp"

class AudioSystem {
public:
    static void init();
    static void update();
    static void dispose();

    static void createSound();
    static void playSound();
private:
    inline static FMOD::Sound *testSound = nullptr;
    inline static FMOD::System *system = nullptr;

    static bool isSystemOnline();
};
