cmake_minimum_required(VERSION 3.16)
project(ex2_main)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ex2_main
        Card.cpp
        Card.h
        Mtmchkin.cpp
        Mtmchkin.h
        Player.cpp
        Player.h
        test.cpp
        utilities.cpp
        utilities.h)
