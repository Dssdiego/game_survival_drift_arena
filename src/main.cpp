#include <iostream>
#include <SDL.h>
#include "games/pong/pong.h"

#if WIN32
#undef main
#else
#include <SDL_opengl.h>
#endif

int main()
{
    Pong pong = Pong();
    return EXIT_SUCCESS;
}
