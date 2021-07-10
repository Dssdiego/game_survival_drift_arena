//
// Created by Diego Santos Seabra on 10/07/21.
//

#pragma once

#include <SDL_opengl.h>
#include "../shader.h"

class QuadTextured
{
public:
    QuadTextured();

    void draw();
    void cleanUp();
private:
    GLuint vao, vbo, ebo;
    unsigned int texture;
    Shader mShader;
};


