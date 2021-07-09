//
// Created by Diego Santos Seabra on 06/07/21.
//

#pragma once

#include <SDL_opengl.h>

class Triangle
{
public:
    Triangle();

    virtual ~Triangle();

    void draw();
private:
    GLuint vbo;
    GLuint vao;
};


