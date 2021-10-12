cmake_minimum_required(VERSION 3.7)
project(loki_engine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_VERBOSE_MAKEFILE ON)

file(GLOB_RECURSE ENGINE_FILES
        ${PROJECT_SOURCE_DIR}/*.h
        ${PROJECT_SOURCE_DIR}/*.cpp
        )

add_library(${PROJECT_NAME}
        ${ENGINE_FILES}
)

target_include_directories(${PROJECT_NAME}
    PUBLIC

    PRIVATE

)

target_link_libraries(${PROJECT_NAME}
    PUBLIC

    PRIVATE

)