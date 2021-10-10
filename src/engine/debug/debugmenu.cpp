//
// Created by dss-d on 09/10/2021.
//

#include "debugmenu.h"
#include "../logging/log.h"

void DebugMenu::init() {
    IMGUI_CHECKVERSION();

    // Creating context and starting
    mContext = ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();

    if (mContext != nullptr)
    {
        Log::info("IMGUI initialized successfully");
    } else
    {
        Log::error("Error loading IMGUI module!");
    }

    // Setting color styles
    ImGui::StyleColorsDark();
}

void DebugMenu::bindRenderer(SDL_Window *window, SDL_GLContext context) {
    ImGui_ImplSDL2_InitForOpenGL(window, context);
    ImGui_ImplOpenGL3_Init("#version 330 core");
}

void DebugMenu::processEvent(SDL_Event* event) {
    ImGui_ImplSDL2_ProcessEvent(event);
}

void DebugMenu::draw() {
    // feed inputs to dear imgui, start new frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();

    // render the GUI
    if (mShowMenu)
    {
        ImGui::Begin("Debug Menu");
        ImGui::Button("Hello!");
        ImGui::End();
    }

    // Render dear imgui into screen
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void DebugMenu::dispose() {
    ImGui_ImplSDL2_Shutdown();
    ImGui_ImplOpenGL3_Shutdown();
    ImGui::DestroyContext(mContext);

    mContext = nullptr;
}
