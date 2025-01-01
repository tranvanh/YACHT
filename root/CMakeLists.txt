cmake_minimum_required(VERSION 3.10)
include(FetchContent)
FetchContent_Declare(
    SDL2
    URL https://github.com/libsdl-org/SDL/archive/refs/heads/SDL2.zip
)
FetchContent_Declare(
    SDL2Image
    URL https://github.com/libsdl-org/SDL_image/archive/refs/heads/SDL2.zip
)
FetchContent_MakeAvailable(SDL2 SDL2Image)

project(Pacman)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(SDL_LIBRARIES ${SDL_LIBRARIES} SDL2 SDL2_image)

include_directories( ${PROJECT_SOURCE_DIR})
add_executable(Pacman main.cpp)
add_subdirectory(GuiLib)
add_subdirectory(CoreLib)
add_subdirectory(PacmanApp)
add_definitions(-include CoreLib/Common.h)
target_compile_options(Pacman PRIVATE -Wall -Wextra -Wpedantic -Werror)
target_link_libraries(Pacman PRIVATE ${SDL_LIBRARIES})