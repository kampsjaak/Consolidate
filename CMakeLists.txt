cmake_minimum_required(VERSION 3.18)

project(Consolidate)

add_executable(meow)

file(GLOB_RECURSE meow_sources
    "src/*.h"
    "src/*.cpp"
)
target_sources(meow PUBLIC ${meow_sources})

find_package(OpenGL REQUIRED)
target_include_directories(meow PUBLIC ${OPENGL_INCLUDE_DIR})
target_link_libraries(meow PUBLIC ${OPENGL_LIBRARIES})

