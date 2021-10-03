//
// Created by Diego Santos Seabra on 10/07/21.
//

#pragma once

#if UNIX || __APPLE__
#include <SDL_opengl.h>
#else
#include <gl/glew.h>
#endif

#include <string>
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


