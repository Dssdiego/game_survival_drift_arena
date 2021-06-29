//
// Created by Diego Santos Seabra on 27/06/21.
//

#include <iostream>
#include "window.h"
#include "constants.h"
#include "log.h"

Window::Window()
{
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

    mWindow = SDL_CreateWindow(
            CONST_GAME_NAME,
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            CONST_WINDOW_SIZE.width, CONST_WINDOW_SIZE.height,
            SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI
    );

    mContext = SDL_GL_CreateContext(mWindow);

    // Make current context
    SDL_GL_MakeCurrent(mWindow, mContext);

    // FIXME: Change to log class
    std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLSL Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;

    // FIXME: Change this to render on while loop
    /* Clear our buffer with a red background */
    glClearColor ( 1.0, 0.0, 0.0, 1.0 );
    glClear ( GL_COLOR_BUFFER_BIT );
    /* Swap our back buffer to the front */
    SDL_GL_SwapWindow(mWindow);
    /* Wait 2 seconds */
    SDL_Delay(2000);

    /* Same as above, but green */
    glClearColor ( 0.0, 1.0, 0.0, 1.0 );
    glClear ( GL_COLOR_BUFFER_BIT );
    SDL_GL_SwapWindow(mWindow);
    SDL_Delay(2000);

    /* Same as above, but blue */
    glClearColor ( 0.0, 0.0, 1.0, 1.0 );
    glClear ( GL_COLOR_BUFFER_BIT );
    SDL_GL_SwapWindow(mWindow);
    SDL_Delay(2000);

    /* Delete our opengl context, destroy our window, and shutdown SDL */
    SDL_GL_DeleteContext(mContext);
    SDL_DestroyWindow(mWindow);
    SDL_Quit();
}
