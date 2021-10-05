//
// Created by dss-d on 04/10/2021.
//

#include "../../engine.h"
#include "pong.h"

Pong::Pong() {
    Log::initLogFile();
    Log::info("Game engine starting...");

    // Window creation
    Window window = Window("Pong", {800,600});

    // Main loop
    while(!window.shouldClose()) {
        window.pollEvents();
        window.clear({0,0,0,1});
        window.draw();
    }

    // Cleanup
    window.cleanUp();

    // Exit
    Log::info("Game engine exiting...");
}
