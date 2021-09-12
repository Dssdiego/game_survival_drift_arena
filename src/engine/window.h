//
// Created by Diego Santos Seabra on 27/06/21.
//

#pragma once

#include <SDL.h>

class Window
{
public:
    Window();

    bool shouldClose();
    void pollEvents();
    void clear(SDL_Color color);
    void draw();
    void cleanUp();

    void toggleFullscreen();

    bool mShouldClose = false;
private:
    SDL_Window* mWindow;
    SDL_GLContext mContext;

    SDL_Event mSDLEvent;

    bool mIsFullScreen = false;

    void createEngineIcon();
};


