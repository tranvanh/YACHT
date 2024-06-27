cmake_minimum_required(VERSION 3.10)
project(CoreLib)

file(GLOB coreLib_src *.cpp)
target_sources(Pacman PRIVATE ${coreLib_src})