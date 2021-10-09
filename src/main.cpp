#include <iostream>
#include <SDL.h>
#include "games/pong/pong.h"
#include "./engine.h"
#include "engine/learning/quad_textured.h"

#if WIN32
#undef main
#else
#include <SDL_opengl.h>
#endif

int main()
{
    Log::initLogFile();
    Log::info("Game engine starting...");

    // Window creation
    Window window = Window("Pong", {800,600});

    // Audio System init
    AudioSystem::init();

    // Input init
    Input::init();
//    Input::vibrateJoystick(0.5f, 5);

    QuadTextured quad = QuadTextured();
    // Game creating
//    Pong game = Pong();
//    game.init();

    // Main loop
    while(!window.shouldClose()) {
        window.pollEvents();
        window.clear({0,0,0,1});
//        game.update();
//        game.draw();
        quad.draw();
        window.draw();
    }

    // Cleanup
    Input::dispose();
    AudioSystem::dispose();
//    game.cleanUp();
    quad.cleanUp();
    window.cleanUp();

    // Exit
    Log::info("Game engine exiting...");
    return EXIT_SUCCESS;
}
