//
// Created by Diego Santos Seabra on 09/07/21.
//

#pragma once

#if UNIX || __APPLE__
#include <SDL_opengl.h>
#else
#include <gl/glew.h>
#endif

#include "../graphics/shader.h"

class Quad
{
public:
    Quad();

    void draw();
    void cleanUp();
private:
    GLuint vao, vbo, ebo;
    Shader mShader;
    float alpha = 0.0f;
};


