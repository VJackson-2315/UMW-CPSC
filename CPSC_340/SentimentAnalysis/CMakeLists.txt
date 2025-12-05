cmake_minimum_required(VERSION 4.0)
project(SentimentAnalysis)

set(CMAKE_CXX_STANDARD 20)

add_executable(SentimentAnalysis main.cpp
        SentimentAnalyzer.cpp
        SentimentAnalyzer.h
)
