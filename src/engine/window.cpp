//
// Created by Diego Santos Seabra on 27/06/21.
//

#define STB_IMAGE_IMPLEMENTATION

#include <iostream>
#include "window.h"
#include "constants.h"
#include "log.h"
#include <string>

#if WIN32

#include <gl/glew.h>
#include <stb_image.h>

#endif

#include "input/input.h"

struct WindowIcon {
    int format;
    unsigned char *data;
    int width;
    int height;
    int depth;
    int pitch;
    int nChannels;
    Uint32 rmask;
    Uint32 gmask;
    Uint32 bmask;
    Uint32 amask;
};

Window::Window() {
    Log::info("Creating window context...");

    // Init SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
//        std::string sdlErrorStr = "SDL could not initialize! SDL_Error: " + std::to_string(SDL_GetError());
        Log::error("SDL could not be initialized!");
    } else {
        Log::info("SDL initialized successfully");
    }

    // Init SDL Joystick module
    if (SDL_Init(SDL_INIT_JOYSTICK | SDL_INIT_GAMECONTROLLER) < 0) {
        Log::error("SDL joystick module could not be initialized!");
    } else {
        Log::info("SDL joystick module initialized successfully");
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

    // Creates the engine icon from the default texture
    createEngineIcon();

    // FIXME: Change to log class
    std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLSL Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;

    // GLEW init (Windows only)
#if WIN32
    if (glewInit() != GLEW_OK) {
        Log::error("GLEW could not be initialized!");
    }
#endif


}

bool Window::shouldClose() {
    return mShouldClose;
}

void Window::pollEvents() {
    while (SDL_PollEvent(&mSDLEvent) != 0) {
        // If the user clicked on the "close" button of the window
        if (mSDLEvent.type == SDL_QUIT) {
            mShouldClose = true;
        }

        // If the user pressed the escape key
        if (mSDLEvent.type == SDL_KEYDOWN && mSDLEvent.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
            mShouldClose = true;
        }

        // If the user pressed the F11 key
        if (mSDLEvent.type == SDL_KEYDOWN && mSDLEvent.key.keysym.scancode == SDL_SCANCODE_F11) {
            toggleFullscreen();
        }

        //if (mSDLEvent.type == SDL_WINDOWEVENT && mSDLEvent.window.event == SDL_WINDOWEVENT_ENTER) {
        //    Log::info("Mouse inside window");
        //}

        //if (mSDLEvent.type == SDL_WINDOWEVENT && mSDLEvent.window.event == SDL_WINDOWEVENT_LEAVE) {
        //    Log::info("Mouse leave window");
        //}

        // Get mouse current position
        //int mouseX, mouseY;
        //SDL_GetMouseState(&mouseX, &mouseY);
        //Log::info(std::to_string(mouseX).c_str());
        //Log::info(std::to_string(mouseY).c_str());
        //Log::info("Mouse Y:" + mouseY);
    }
}

void Window::draw() {
    /* Swap our back buffer to the front (i.e. draw to the screen) */
    SDL_GL_SwapWindow(mWindow);
}

void Window::cleanUp() {
    Log::info("Cleaning up window context...");

    /* Delete our opengl context, destroy our window, and shutdown SDL */
    SDL_GL_DeleteContext(mContext);
    SDL_DestroyWindow(mWindow);
    SDL_Quit();
}

void Window::toggleFullscreen() {
    SDL_SetWindowFullscreen(mWindow, mIsFullScreen);
    mIsFullScreen = !mIsFullScreen;
}

void Window::clear(SDL_Color color) {
    /* Clear our buffer with a red background */
    glClearColor(color.r, color.g, color.b, color.a);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Window::createEngineIcon() {
    WindowIcon icon;
    icon.format = STBI_rgb_alpha;
    icon.data = stbi_load("assets/game_icon.png", &icon.width, &icon.height, &icon.nChannels, icon.format);

    // Check for errors
    if(icon.data == NULL)
        Log::error("Error loading game icon!");

    // Set up the pixel format color masks for RGB(A) byte arrays.
    // Only STBI_rgb (3) and STBI_rgb_alpha (4) are supported here!
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
    int shift = (icon.format == STBI_rgb) ? 8 : 0;
    icon.rmask = 0xff000000 >> shift;
    icon.gmask = 0x00ff0000 >> shift;
    icon.bmask = 0x0000ff00 >> shift;
    icon.amask = 0x000000ff >> shift;
#else // little endian, like x86
    icon.rmask = 0x000000ff;
    icon.gmask = 0x0000ff00;
    icon.bmask = 0x00ff0000;
    icon.amask = (icon.format == STBI_rgb) ? 0 : 0xff000000;
#endif

    if (icon.format == STBI_rgb) {
        icon.depth = 24;
        icon.pitch = 3 * icon.width; // 3 bytes per pixel * pixels per row
    } else { // STBI_rgb_alpha (RGBA)
        icon.depth = 32;
        icon.pitch = 4 * icon.width;
    }

    SDL_Surface *surface = SDL_CreateRGBSurfaceFrom((void *) icon.data, icon.width, icon.height, icon.depth, icon.pitch,
                                                    icon.rmask, icon.gmask, icon.bmask, icon.amask);

    // Check for errors
    if (surface == NULL) {
        Log::error("Error loading game icon! (surface creation)");
        stbi_image_free(icon.data);
    }

    // Apply the icon
    SDL_SetWindowIcon(mWindow, surface);

    // Cleaning
    SDL_FreeSurface(surface);
    stbi_image_free(icon.data);
}
