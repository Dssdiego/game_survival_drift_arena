//
// Created by dss-d on 05/10/2021.
//

#pragma once

#include "../maths/vector2.h"

class Entity {
public:
    Entity();
    Entity(Vec2 position);

private:
    Vec2 mPosition;
};
