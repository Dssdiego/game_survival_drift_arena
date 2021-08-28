//
// Created by Diego Santos Seabra on 27/06/21.
//

#pragma once

#include <iostream>

#if UNIX
#include <SDL_opengl.h>
#include <SDL_opengl_glext.h>
#else
#include <gl/glew.h>
#endif

#include <fstream>
#include <vector>

class Shader
{
public:
    Shader();

    Shader(std::string vertexShaderName, std::string fragmentShaderName);

    void use();
    void cleanUp();

    inline GLuint getProgram() const { return mProgram; }
private:
    GLuint mProgram;
    GLuint mVertexShader;
    GLuint mFragmentShader;
};


