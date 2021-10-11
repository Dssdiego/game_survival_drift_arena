//
// Created by dss-d on 08/10/2021.
//

#include "audiosystem.h"
#include "../logging/log.h"

void AudioSystem::init() {
    FMOD::System_Create(&system);

    if (isSystemOnline() && system->init(512, FMOD_INIT_NORMAL, 0) == FMOD_OK)
    {
        Log::info("FMOD initialized successfully");

        // Play test sound on game engine init
//        createSound();
//        playSound();
    } else
    {
        Log::error("Error initializing FMOD!");
    }
}

// NOTE: FMOD should be ticked once per game update!
void AudioSystem::update() {
    if (isSystemOnline())
        system->update();
}

void AudioSystem::dispose() {
    if (isSystemOnline())
        system->release();
    system = nullptr;
}

void AudioSystem::createSound() {
    if (isSystemOnline())
        system->createSound("assets/sounds/win_xp_start_sound.mp3", FMOD_DEFAULT, nullptr, &testSound);
}

void AudioSystem::playSound() {
    if (isSystemOnline())
        system->playSound(testSound, nullptr, false, nullptr); // will play on master
}

bool AudioSystem::isSystemOnline() {
    if (system == nullptr)
    {
        Log::warn("FMOD system offline");
        return false;
    } else {
        return true;
    }
}
