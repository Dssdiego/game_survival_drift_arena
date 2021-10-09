//
// Created by Diego Santos Seabra on 16/08/21.
//

#include "input.h"
#include "../logging/log.h"

void Input::init() {
    // Init game controller (a.k.a joystick)
    mController = SDL_GameControllerOpen(0);
    if (mController == NULL) {
        Log::warn("Unable to find a game controller (joystick) device");
    }

    // Get controller haptic device
    mHaptic = SDL_HapticOpen(0);
    if (mHaptic == NULL) {
        Log::warn("No haptic support");
    } else {
        // Initialize rumble module
        if (SDL_HapticRumbleInit(mHaptic) < 0) {
            Log::warn("Unable to initialize the joystick rumble module");
        }
    }
}

void Input::dispose() {
    SDL_HapticClose(mHaptic);
    SDL_GameControllerClose(mController);

    mHaptic = nullptr;
    mController = nullptr;
}

void Input::vibrateJoystick(float force, int seconds) {
    if (mHaptic != nullptr) {
        SDL_HapticRumblePlay(mHaptic, force, seconds * 1000);
    }
}

bool Input::getKeyPressed(Key key) {
    return false;
}
