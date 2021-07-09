//#define GL_GLEXT_PROTOTYPES
//#define GL_SILENCE_DEPRECATION

#include <iostream>
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_ttf.h>
#include "engine.h"
#include "engine/learning/triangle.h"
#include "engine/learning/triangle_colors.h"

bool closeWindow = false;

int main()
{
    Log::info("Game engine starting...");

    // Window creation
    Window window = Window();

    // Enable textures and blending
//    glEnable(GL_TEXTURE_2D);
//    glEnable(GL_BLEND);

    // Draw testing
//    Triangle triangle = Triangle();
    TriangleColors triangleColors = TriangleColors();
    triangleColors.setWireframe(false);

    // TODO: Check >> Is possible to pass position and color in the same layout?
    // TODO: Create a quad
    // TODO: Create 2 triangles/quads using EBO

    // Main loop
    while(!window.shouldClose()) {
        window.pollEvents();
        window.clear({0,0,0,1});
//        triangle.draw();
        triangleColors.draw();
        window.draw();
    }

    // Cleanup
    triangleColors.cleanUp();
    window.cleanUp();

    // Exit
    Log::info("Game engine exiting...");
    return EXIT_SUCCESS;
}
