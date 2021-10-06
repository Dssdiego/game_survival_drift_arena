//
// Created by dss-d on 04/10/2021.
//

#pragma once

#include "../../engine/game.h"

class Pong : public Game {
public:
    void init() override;
    void update() override;
    void draw() override;
    void cleanUp() override;
};
