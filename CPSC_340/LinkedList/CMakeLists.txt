cmake_minimum_required(VERSION 4.0)
project(LinkedList)

set(CMAKE_CXX_STANDARD 20)

add_executable(LinkedList main.cpp
        DoublyLinkedList.cpp
        DoublyLinkedList.h
        cmake-build-debug/Node.cpp
        cmake-build-debug/Node.h)
