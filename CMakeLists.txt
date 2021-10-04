cmake_minimum_required(VERSION 3.7)
project(loki_engine)

set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

# Windows Builds

# SDL2 / SDL2_TTF / GLM
find_package(SDL2 REQUIRED)
#find_package(SDL2_ttf REQUIRED)
find_package(GLM REQUIRED)

# GLEW (Windows only)
if (WIN32)
    find_package(GLEW REQUIRED)
endif ()

# OpenGL
#if(APPLE)
find_package(OpenGL REQUIRED)
#endif()

# Include directories
include_directories(
        ${SDL2_INCLUDE_DIRS}
        ${GLEW_INCLUDE_DIRS}
        #        ${SDL2TTF_INCLUDE_DIR}
        libs
)

message("\nIncludes:")
message(SDL2_INCLUDE_DIR: ${SDL2_INCLUDE_DIRS})
message(GLEW_INCLUDE_DIR: ${GLEW_INCLUDE_DIRS})
#message(SDL2TTF_INCLUDE_DIR: ${SDL2TTF_INCLUDE_DIR})
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
message(SDL2_LIBRARY: ${SDL2_LIBRARIES})
message(GLEW_LIBRARY: ${GLEW_LIBRARIES})
#message(SDL2TTF_LIBRARY: ${SDL2TTF_LIBRARY})
message(OPENGL_LIBRARIES: ${OPENGL_LIBRARIES})
message("")

# Copy asset folder using a python script
file(REMOVE_RECURSE ${CMAKE_BINARY_DIR}/assets/)
execute_process(COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/assets assets)

# Link libraries
target_link_libraries(${PROJECT_NAME}
        ${SDL2_LIBRARIES}
        ${GLEW_LIBRARIES}
        #        ${SDL2TTF_LIBRARY}
        ${OPENGL_LIBRARIES})