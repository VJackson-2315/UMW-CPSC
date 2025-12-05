cmake_minimum_required(VERSION 4.0)
project(ImageConversion)

set(CMAKE_CXX_STANDARD 20)

add_executable(ImageConversion main.cpp
        ArrayList.cpp
        ArrayList.h
        Pixel.cpp
        Pixel.h)
