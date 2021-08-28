//
// Created by Diego Santos Seabra on 27/06/21.
//

#include <iostream>
#include "window.h"
#include "constants.h"
#include "log.h"
#include <string>

#if WIN32
#include <gl/glew.h>
#endif

Window::Window()
{
    Log::info("Creating window context...");

    // Init SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
//        std::string sdlErrorStr = "SDL could not initialize! SDL_Error: " + std::to_string(SDL_GetError());
        Log::error("SDL could not be initialized!");
    }

    SDL_version sdlVersion;
    SDL_GetVersion(&sdlVersion);
    auto sdlVersionStr = "SDL Version: " +
                         std::to_string(sdlVersion.major) + "." +
                         std::to_string(sdlVersion.minor) + "." +
                         std::to_string(sdlVersion.patch);
    Log::info(sdlVersionStr.c_str());
    // TODO: Get Error and throw if exists

    // Use the most recent OpenGL Version available in the machine
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    // Window creation
    mWindow = SDL_CreateWindow(
            CONST_GAME_NAME,
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            CONST_WINDOW_SIZE.width, CONST_WINDOW_SIZE.height,
            SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI
    );

    // OpenGL context creation
    mContext = SDL_GL_CreateContext(mWindow);

    // Make current context
    SDL_GL_MakeCurrent(mWindow, mContext);

    // FIXME: Change to log class
    std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLSL Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;

    // GLEW init (Windows only)
#if WIN32
    if (glewInit() != GLEW_OK) 
    {
        Log::error("GLEW could not be initialized!");
    }
#endif
        

}


bool Window::shouldClose()
{
    return mShouldClose;
}

void Window::pollEvents()
{
    while(SDL_PollEvent(&mSDLEvent) != 0) {
        // If the user clicked on the "close" button of the window
        if(mSDLEvent.type == SDL_QUIT) {
            mShouldClose = true;
        }

        // If the user pressed the escape key
        if(mSDLEvent.type == SDL_KEYDOWN && mSDLEvent.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
            mShouldClose = true;
        }
    }
}

void Window::draw()
{
    /* Swap our back buffer to the front (i.e. draw to the screen) */
    SDL_GL_SwapWindow(mWindow);
}

void Window::cleanUp()
{
    Log::info("Cleaning up window context...");

    /* Delete our opengl context, destroy our window, and shutdown SDL */
    SDL_GL_DeleteContext(mContext);
    SDL_DestroyWindow(mWindow);
    SDL_Quit();
}

void Window::clear(SDL_Color color)
{
    /* Clear our buffer with a red background */
    glClearColor(color.r, color.g, color.b, color.a);
    glClear(GL_COLOR_BUFFER_BIT);
}
