cmake_minimum_required(VERSION 3.10)
project(PacmanApp)

file(GLOB pacmanApp_src *.cpp)
target_sources(Pacman PRIVATE ${pacmanApp_src})