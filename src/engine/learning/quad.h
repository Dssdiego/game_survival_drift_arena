//
// Created by Diego Santos Seabra on 09/07/21.
//

#pragma once

#include <SDL_opengl.h>
#include "../shader.h"

class Quad
{
public:
    Quad();

    void draw();
    void cleanUp();
private:
    GLuint vao, vbo, ebo;
    Shader mShader;
};


