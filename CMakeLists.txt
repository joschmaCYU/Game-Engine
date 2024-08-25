cmake_minimum_required(VERSION 3.0.0)
project(game_engine VERSION 0.1.0)

set(OpenGL_GL_PREFERENCE GLVND)

set(SOURCE_FILES 
    src/main.cpp
    src/window.cpp
    src/game_loop.cpp)

add_executable(game_engine ${SOURCE_FILES})

target_include_directories(game_engine PUBLIC "src/include")

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

target_link_libraries(game_engine glfw OpenGL::GL)