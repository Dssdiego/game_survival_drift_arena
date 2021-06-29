//
// Created by Diego Santos Seabra on 27/06/21.
//

#pragma once

#include <SDL2/SDL_opengl.h>

class Text
{
private:
    const GLchar* quadVertexSource;
    const GLchar* quadFragmentSource;

    void init();
};


