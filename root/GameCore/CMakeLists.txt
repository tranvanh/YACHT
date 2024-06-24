cmake_minimum_required(VERSION 3.10)
project(GameCore)

file(GLOB gameCore_src *.cpp)
target_sources(Pacman PRIVATE ${gameCore_src})