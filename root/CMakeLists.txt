cmake_minimum_required(VERSION 3.10)
project(Pacman)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR} ${PROJECT_SOURCE_DIR})

add_executable(Pacman main.cpp)
add_subdirectory(GuiLib)
add_subdirectory(CoreLib)
add_subdirectory(PacmanApp)

target_link_libraries(Pacman ${SDL2_LIBRARIES} "-lSDL2_image")