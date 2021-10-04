//#define GL_GLEXT_PROTOTYPES
//#define GL_SILENCE_DEPRECATION

#include <iostream>
#include <SDL.h>

#if WIN32
#undef main
#else
#include <SDL_opengl.h>
#endif
#include "engine.h"
#include "engine/learning/triangle.h"
#include "engine/learning/triangle_colors.h"
#include "engine/learning/quad.h"
#include "engine/learning/quad_textured.h"
#include "engine/graphics/aseprite.h"
#include "engine/graphics/tiled.h"

int main()
{
    Log::initLogFile();
    Log::info("Game engine starting...");

//    Aseprite ase = Aseprite();
//    ase.read("assets/aseprite/test1.ase");

    // Window creation
    Window window = Window();

//    Tiled tiled = Tiled();
//    tiled.loadMap();

    // Enable textures and blending
//    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Draw testing
//    Triangle triangle = Triangle();
//    TriangleColors triangleColors = TriangleColors();
//    triangleColors.setWireframe(false);
    Quad quad = Quad();
    QuadTextured quadTextured = QuadTextured();

    // TODO: Create a textured quad (multiplied with color)
    // TODO: Read aseprite file to textured data
    // TODO: Create 2 triangles/quads using EBO
    // TODO: Check >> Is possible to pass position and color in the same layout?

    // Main loop
    while(!window.shouldClose()) {
        window.pollEvents();
        window.clear({0,0,0,1});
//        triangle.draw();
//        triangleColors.draw();
        quadTextured.draw();
        quad.draw();
        window.draw();
    }

    // Cleanup
//    triangleColors.cleanUp();
    quad.cleanUp();
    quadTextured.cleanUp();
    window.cleanUp();

    // Exit
    Log::info("Game engine exiting...");
    return EXIT_SUCCESS;
}
