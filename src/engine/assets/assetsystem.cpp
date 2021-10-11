//
// Created by dss-d on 11/10/2021.
//

#include "assetsystem.h"

void AssetSystem::dispose() {
    mSounds.clear();
    mTextures.clear();
}

void AssetSystem::init() {
    std::cout << "Current Path: " << std::filesystem::current_path() << std::endl;
    std::cout << "Root Path: " << std::filesystem::current_path().root_path() << std::endl;
    std::cout << "Root Directory: " << std::filesystem::current_path().root_directory() << std::endl;
    std::cout << "Root Name: " << std::filesystem::current_path().root_name() << std::endl;
}

