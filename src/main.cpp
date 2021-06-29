//#define GL_GLEXT_PROTOTYPES
//#define GL_SILENCE_DEPRECATION

#include <iostream>
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_ttf.h>
#include "engine.h"

bool closeWindow = false;

int main()
{
    Log::info("Game engine starting...");

    Window wnd = Window();

    // Enable textures and blending
//    glEnable(GL_TEXTURE_2D);
//    glEnable(GL_BLEND);

    //

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
