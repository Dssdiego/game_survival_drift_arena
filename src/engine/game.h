//
// Created by dss-d on 05/10/2021.
//

#pragma once

class Game {
public:
    virtual void init();
    virtual void draw();
    virtual void update();
    virtual void cleanUp();
};
