//
// Created by dss-d on 27/09/2021.
//

#include "tiled.h"
#include "../logging/log.h"

void Tiled::loadMap() {
    auto map = tiled.parse("assets/tiled/tiled_monkey_game_test.json");
    if (map->getStatus() == tson::ParseStatus::OK)
    {
        auto layers = map->getLayers();

        Log::info("Tiled JSON Map loaded!");
    } else {
        Log::error("Error on read Tiled map!");
    }
}
