//#define GL_GLEXT_PROTOTYPES
//#define GL_SILENCE_DEPRECATION

#include <iostream>
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_ttf.h>
#include "engine.h"
#include "engine/triangle.h"

bool closeWindow = false;

int main()
{
    Log::info("Game engine starting...");

    // Window creation
    Window window = Window();

    // Enable textures and blending
//    glEnable(GL_TEXTURE_2D);
//    glEnable(GL_BLEND);

    // Triangle test creation
    Triangle triangle = Triangle();

    // Shader creation
    // REVIEW: This should be here?
    Shader shader = Shader();

    // Main loop
    while(!window.shouldClose()) {
        window.pollEvents();
        window.clear({0,0,0,1});
        triangle.draw();
        window.draw();
    }

    // Cleanup
    window.cleanUp();

    // Exit
    Log::info("Game engine exiting...");
    return EXIT_SUCCESS;
}
