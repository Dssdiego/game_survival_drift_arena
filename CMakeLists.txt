cmake_minimum_required(VERSION 3.7)
project(app)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_VERBOSE_MAKEFILE ON)

add_subdirectory(src/engine)
add_subdirectory(src/games/pong)

# TODO: Continue here >> https://www.youtube.com/watch?v=MHbGmGUvwVg&t=238s