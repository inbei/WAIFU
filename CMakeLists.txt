cmake_minimum_required(VERSION 3.10)

project(WAIFU)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED true)

find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)

FILE(GLOB CXXSRCS src/*.cpp)
add_executable(WAIFU ${CXXSRCS})

target_include_directories(WAIFU PUBLIC ${SDL2_INCLUDE_DIRS})
target_include_directories(WAIFU PUBLIC ${OPENGL_INCLUDE_DIRS})

target_link_libraries(WAIFU ${SDL2_LIBRARIES})
target_link_libraries(WAIFU ${OPENGL_LIBRARIES})

add_library(imgui
    imgui/imgui.cpp imgui/imgui_draw.cpp
    imgui/imgui_tables.cpp imgui/imgui_widgets.cpp
    imgui/misc/cpp/imgui_stdlib.cpp

    imgui/backends/imgui_impl_sdl.cpp
    imgui/backends/imgui_impl_opengl3.cpp
)

target_include_directories(imgui PUBLIC ${SDL2_INCLUDE_DIRS})
target_include_directories(imgui PUBLIC imgui/ imgui/backends/ imgui/misc/cpp/)
target_compile_definitions(imgui PUBLIC IMGUI_IMPL_OPENGL_LOADER_CUSTOM=<SDL_opengl.h> GL_GLEXT_PROTOTYPES=1)

target_link_libraries(WAIFU imgui)

add_library(lunasvg
    imgui/imgui.cpp imgui/imgui_draw.cpp
    imgui/imgui_tables.cpp imgui/imgui_widgets.cpp
    imgui/misc/cpp/imgui_stdlib.cpp

    imgui/backends/imgui_impl_sdl.cpp
    imgui/backends/imgui_impl_opengl3.cpp
)

target_include_directories(WAIFU PUBLIC include)
