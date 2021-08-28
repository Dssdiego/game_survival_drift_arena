cmake_minimum_required(VERSION 3.6)
project(survival_drift_arena)

set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

# Windows Builds
if(WIN32)
    set(VCPKG_ROOT "C:/vcpkg/")

    # automatically use vcpkg if VCPKG_ROOT is defined
    if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
      message(STATUS "Using VCPKG_ROOT $ENV{VCPKG_ROOT}")
      set(CMAKE_TOOLCHAIN_FILE
          "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
          CACHE STRING "")
    endif()

    find_package(glew REQUIRED)
endif()

# SDL2 / SDL2_TTF / GLM
find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(glm REQUIRED)

# OpenGL
#if(APPLE)
find_package(OpenGL REQUIRED)
#endif()

# Include directories
include_directories(
        ${SDL2_INCLUDE_DIR}
        ${GLEW_INCLUDE_DIR}
        ${SDL2TTF_INCLUDE_DIR}
        libs
)

message("\nIncludes:")
message(SDL2_INCLUDE_DIR: ${SDL2_INCLUDE_DIR})
message(GLEW_INCLUDE_DIR: ${GLEW_INCLUDE_DIR})
message(SDL2TTF_INCLUDE_DIR: ${SDL2TTF_INCLUDE_DIR})
message("")

# Add cpp/h files
file(GLOB_RECURSE CPP_HEADERS ${PROJECT_SOURCE_DIR}/src/*.h)
file(GLOB_RECURSE CPP_SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)

message("Source Code:")
message(CPP_HEADERS: ${CPP_HEADERS})
message(CPP_SOURCES: ${CPP_SOURCES})
message("")

# Define the executable
add_executable(
        ${PROJECT_NAME}
        ${CPP_HEADERS}
        ${CPP_SOURCES}
        )

message("Libraries:")
message(SDL2_LIBRARY: ${SDL2_LIBRARY})
message(GLEW_LIBRARY: ${GLEW_LIBRARY})
message(SDL2TTF_LIBRARY: ${SDL2TTF_LIBRARY})
message(OPENGL_LIBRARIES: ${OPENGL_LIBRARIES})
message("")


# Copy asset folder using a python script
file(REMOVE_RECURSE ${CMAKE_BINARY_DIR}/assets/)
execute_process(COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/assets assets)

# Link libraries
target_link_libraries(${PROJECT_NAME}
        ${SDL2_LIBRARY}
        ${GLEW_LIBRARY}
        ${SDL2TTF_LIBRARY}
        ${OPENGL_LIBRARIES})