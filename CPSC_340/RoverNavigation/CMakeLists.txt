cmake_minimum_required(VERSION 4.0)
project(RoverNavigation)

set(CMAKE_CXX_STANDARD 20)

add_executable(RoverNavigation main.cpp
        Code.cpp
        Code.h
        PathFinder.cpp
        PathFinder.h)
