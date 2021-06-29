cmake_minimum_required(VERSION 3.6)
project(marathon_game_jam)

set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

# SDL2 / SDL2_TTF
find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)

# OpenGL
find_package(OpenGL REQUIRED)

# Include directories
include_directories(
        ${SDL2_INCLUDE_DIR}
        ${SDL2TTF_INCLUDE_DIR}
)

message(SDL2_INCLUDE_DIR: ${SDL2_INCLUDE_DIR})
message(SDL2TTF_INCLUDE_DIR: ${SDL2TTF_INCLUDE_DIR})

# Add cpp/h files
file(GLOB_RECURSE CPP_HEADERS ${PROJECT_SOURCE_DIR}/src/*.h)
file(GLOB_RECURSE CPP_SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)

message(CPP_HEADERS: ${CPP_HEADERS})
message(CPP_SOURCES: ${CPP_SOURCES})

# Define the executable
add_executable(
        ${PROJECT_NAME}
        ${CPP_HEADERS}
        ${CPP_SOURCES}
)

message(SDL2_LIBRARY: ${SDL2_LIBRARY})
message(SDL2TTF_LIBRARY: ${SDL2TTF_LIBRARY})
message(OPENGL_LIBRARIES: ${OPENGL_LIBRARIES})

# Link libraries
target_link_libraries(${PROJECT_NAME}
        ${SDL2_LIBRARY}
        ${SDL2TTF_LIBRARY}
        ${OPENGL_LIBRARIES})