cmake_minimum_required(VERSION 4.0)
project(Playlist)

set(CMAKE_CXX_STANDARD 20)

add_executable(Playlist main.cpp
        Playlist.cpp
        Playlist.h
        Song.cpp
        Song.h)
