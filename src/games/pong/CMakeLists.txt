cmake_minimum_required(VERSION 3.7)
project(pong)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_VERBOSE_MAKEFILE ON)

file(GLOB_RECURSE GAME_FILES
        ${PROJECT_SOURCE_DIR}/*.h
        ${PROJECT_SOURCE_DIR}/*.cpp
)

add_executable(
        ${PROJECT_NAME}
        ${GAME_FILES}
)