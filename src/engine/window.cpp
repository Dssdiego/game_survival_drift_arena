//
// Created by Diego Santos Seabra on 27/06/21.
//

#include "window.h"

bool Window::createWindow()
{
    mWindow = SDL_CreateWindow(
            gameName.c_str(),
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            SCREEN_WIDTH, SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI
    );
}
