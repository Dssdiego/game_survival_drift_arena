//
// Created by dss-d on 09/10/2021.
//

#pragma once

#include "SDL.h"
#include "imgui.h"
#include "imgui_impl_opengl3.h"
#include "imgui_impl_sdl.h"
#include "stb_image_write.h"
#include "../logging/log.h"

#include <ctime>
#include <filesystem>
#include <string>

#if WIN32
#include <gl/glew.h>
#endif

// REVIEW: Everything in this class is static. Should we use a struct???
class DebugMenu {
public:
    static void init();
    static void bindRenderer(SDL_Window* window, SDL_GLContext context);
    static void processEvent(SDL_Event* event);
    static void draw();
    static void dispose();

    // Show/hide the debug menu
    inline static void toggleMenu() { mShowMenu = !mShowMenu; }
private:
    // Marketing/Media
    static void takeScreenshot();

    inline static ImGuiContext* mContext = nullptr;
    inline static bool mShowMenu = false;
};
