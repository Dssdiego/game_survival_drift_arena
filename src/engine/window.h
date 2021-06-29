//
// Created by Diego Santos Seabra on 27/06/21.
//

#pragma once

#include <SDL.h>

class Window
{
public:
    bool createWindow();

//    SDL_Window& getWindow();

private:
    SDL_Window* mWindow;
};


