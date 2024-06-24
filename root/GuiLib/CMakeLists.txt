cmake_minimum_required(VERSION 3.10)
project(GuiLib)

file(GLOB guiLib_src *.cpp)
target_sources(Pacman PRIVATE ${guiLib_src})