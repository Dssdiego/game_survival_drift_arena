//
// Created by dss-d on 11/10/2021.
//

#pragma once

#include <filesystem>
#include <iostream>
#include <map>
#include "../graphics/texture.h"
#include "../audio/sound.h"

class AssetSystem {
public:
    static void init();     // load all assets in memory
    static void dispose();  // clears all assets from memory

    static Sound getSound(std::string name);
    static Texture getTexture(std::string name);
private:
    inline static std::map<std::string, Texture> mTextures = {};
    inline static std::map<std::string, Sound> mSounds = {};
};
