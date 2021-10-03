//
// Created by dss-d on 27/09/2021.
//

#pragma once

#include <tileson.hpp>

class Tiled {
public:
    void loadMap();

private:
    tson::Tileson tiled;
};
