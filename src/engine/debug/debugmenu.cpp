//
// Created by dss-d on 09/10/2021.
//

#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "debugmenu.h"
#include "../scenes/scenesystem.h"

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
//        ImGui::ShowDemoWindow();

        ImGui::Begin("Debug Menu");
        ImGui::Separator();
        if (ImGui::BeginTabBar("#tabs"))
        {
            if (ImGui::BeginTabItem("Scenes"))
            {
                auto scenes = SceneSystem::getScenes();

                if (ImGui::Button("Previous Scene"))
                {
                    SceneSystem::previousScene();
                }

                ImGui::SameLine();
                if (ImGui::Button("Next Scene"))
                {
                    SceneSystem::nextScene();
                }


                ImGui::EndTabItem();
            }

            if (ImGui::BeginTabItem("Marketing"))
            {
                if (ImGui::Button("Take screenshot"))
                {
                    takeScreenshot();
                }
                ImGui::EndTabItem();
            }

            if (ImGui::BeginTabItem("Options"))
            {
                ImGui::EndTabItem();
            }

            ImGui::EndTabBar();
        }

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

void DebugMenu::takeScreenshot() {
    int width = 800, height = 600; // TODO: Get these values from the window, directly
    int comp = 4;
    auto* pixels = malloc(width * height * comp);
    glReadPixels(0, 0, width, height, GL_RGBA, GL_UNSIGNED_BYTE, pixels);

    time_t theTime = time(nullptr);
    struct tm *curTime = localtime(&theTime);
    int day = curTime->tm_mday;
    int month = curTime->tm_mon + 1;
    int year = curTime->tm_year + 1900;
    int hour = curTime->tm_hour;
    int min = curTime->tm_min;
    int sec = curTime->tm_sec;

    std::string screenFileName = "screenshot_" + std::to_string(year) + "_" +
            std::to_string(month) + "_" +
            std::to_string(day) + "_" +
            std::to_string(hour) + std::to_string(min) + std::to_string(sec) +
            ".png";

    // Flips the framebuffer vertically
    stbi_flip_vertically_on_write(true);
    stbi_write_png(screenFileName.c_str(), width, height, comp, pixels, width * comp);
    Log::info("Screenshot saved successfully!");
}
